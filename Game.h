#pragma once
#include "Define.h"
#include "InputManager.h"

class Game : public enable_shared_from_this<Game>
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
	bool						GetGameRunning() { return m_gameRunning; }
	shared_ptr<InputManager>	GetInput() { return m_input; }

public:
	void						SetGameRunning(bool gameRunning) { m_gameRunning = gameRunning; }

private:
	bool						m_gameRunning;
	shared_ptr<InputManager>	m_input;

};

