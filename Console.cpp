#include "Console.h"

Console::Console()
{
}

Console::~Console()
{
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
