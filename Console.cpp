#include "Console.h"

void Console::SetScreenSize(int x, int y)
{
//	string str = "mode con cols=50 lines=50"
	char buf[1024];
	sprintf_s(buf, "mode con lines=%d cols=%d", x, y);
	system(buf);
//	system("mode con lines=35 cols=125");
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

void Console::SetColor(int _color, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (_bgcolor << 4) | _color);
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
