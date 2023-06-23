#pragma once
#include "Define.h"
#include "Console.h"

class Player;
class GameLine
{
public:
	GameLine();
	GameLine(Pos pos, int width, int height, string name);
	~GameLine();

public:
	void	Init();
	void	Update(float dt);
	void	Render();
	void	Release();

public:
	Pos&	GetPos() { return m_linePos; }
	int		GetWidth() { return m_width; }
	int		GetHeight() { return m_height; }

public:
	void	SetPos(Pos pos) { m_linePos = pos; }
	void	SetWidth(int width) { m_width = width; }
	void	SetHeight(int height) { m_height = height; }

public:
	void	DrawLine();

private:
	Pos					m_linePos;

	int					m_width;
	int					m_height;

	string				m_name;

	shared_ptr<Player>	m_player;
};

