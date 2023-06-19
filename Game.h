#pragma once
#include "Define.h"

class Game
{
public:
	Game();
	~Game();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

public:
	static bool		GetGameRunning() { return m_gameRunning; }

public:
	static void		SetGameRunning(bool gameRunning) { m_gameRunning = gameRunning; }

private:
	static bool		m_gameRunning;

};

