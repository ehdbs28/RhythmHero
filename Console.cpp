#include "Console.h"

void Console::SetScreenSize(int x, int y)
{
	char buf[1024];
	sprintf_s(buf, "mode con cols=%d lines=%d", x, y);
	system(buf);
}

void Console::SetConsoleFont(const WCHAR *font, COORD dwSize, BOOL bold)
{
	HANDLE hcsb = CreateFileA("CONOUT$", GENERIC_WRITE | GENERIC_READ, FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };

	GetCurrentConsoleFontEx(hcsb, false, &cfi);

	wcscpy_s(cfi.FaceName, font);
	cfi.FontWeight = (bold ? 700 : 400);
	cfi.dwFontSize = dwSize;

	SetCurrentConsoleFontEx(hcsb, false, &cfi);

	CloseHandle(hcsb);
}

void Console::FullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

BOOL Console::Gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x, y };
	return SetConsoleCursorPosition(hOut, Cur);
}

void Console::ConsoleCursor(bool _bvis, DWORD _dwsize)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = _bvis;
	curinfo.dwSize = _dwsize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

int Console::SetColor(int _color, int _bgcolor)
{
	int lastColor = GetBgColor() << 4 | GetColor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (_bgcolor << 4) | _color);
	return lastColor;
}

int Console::GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	int color = info.wAttributes;
	return color;
}

int Console::GetBgColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	int color = info.wAttributes >> 4;
	return color;
}
