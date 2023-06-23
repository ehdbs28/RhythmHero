#pragma once
#include "Define.h"
#include "Console.h"

class Fever
{
public:
	Fever();
	Fever(float duration);
	~Fever();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

public:
	float	GetPercent() { return m_percent; }
	bool	IsProgressing() { return m_progressingFever; }

public:
	void	SetPercent(float increase);
	
public:
	void	StartFever();

private:
	UINT	m_feverDuration;

	UINT	m_feverStartTime;
	UINT	m_currentTime;

	float	m_percent;
	bool	m_progressingFever;

};	

