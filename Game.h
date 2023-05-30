#pragma once

#include "Define.h"

class Game
{
public:
	Game();
	~Game();

public:
	bool	Init();
	void	Update();
	void	Render();

private:
	void	DrawTitle();
	void	DrawMenu();

};

