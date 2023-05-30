#pragma once

#include "Define.h"

class Console 
{
public:
	Console();
	~Console();

public:
	void	FullScreen();
	BOOL	Gotoxy(int,int);
	void	ConsoleCursor(bool, DWORD);
	void	SetColor(int, int);
	int		GetColor();
	int		GetBgColor();
};


