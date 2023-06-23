#pragma once
#include "Define.h"
#include "Console.h"

class Player
{
public:
	Player();
	Player(Pos pos, int width);
	~Player();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

public:
	Pos&	GetPos() { return m_playerPos; }
	int		GetThickness() { return m_thickness; }

private:
	Pos				m_playerPos;
	int				m_thickness;

};