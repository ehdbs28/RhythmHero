#pragma once
#include "Define.h"

class Console 
{
	DECLARE_SINGLE(Console);

public:
	void	SetScreenSize(int x, int y);
	void	SetConsoleFont(const WCHAR *font, COORD dwSize, BOOL bold);
	void	FullScreen();
	BOOL	Gotoxy(int,int);
	void	ConsoleCursor(bool, DWORD);
	int		SetColor(int, int);
	int		GetColor();
	int		GetBgColor();
};


