#pragma once
#include "Define.h"
#include "Console.h"

class ProgressBar
{
public:
	ProgressBar();
	ProgressBar(Pos pos, int width, int height, float left, float right, string name);
	~ProgressBar();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

public:
	Pos&	GetPos() { return m_pos; }
	int		GetWidth() { return m_width; }
	int		GetHeight() { return m_height; }
	float	GetCurrentValue() { return m_currentValue; }

public:
	void	SetPercent(float percent);

private:
	Pos		m_pos;

	int		m_width;
	int		m_height;

	float	m_leftValue;
	float	m_rightValue;
	float	m_currentValue;

	string	m_name;

};

