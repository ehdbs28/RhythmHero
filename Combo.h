#pragma once
#include "Define.h"
#include "Console.h"

class Combo
{
public:
	Combo();
	Combo(Pos pos);
	~Combo();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

public:
	Pos&	GetPos() { return m_pos; }
	int		GetCombo() { return m_combo; }

public:
	void	SetCombo(int combo);

private:
	Pos		m_pos;
	int		m_combo;
	int		m_maxCombo;

};

