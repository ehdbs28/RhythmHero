#pragma once
#include "Define.h"
#include "Console.h"
#include "ProgressBar.h"

class Fever : public ProgressBar
{
public:
	Fever();
	Fever(Pos pos, int width, int height, float left, float right, string name, float duration);
	~Fever();

public:
	void 	Init() override;
	void	Update(float dt) override;
	void	Render() override;
	void	Release() override;

	bool	IsProgressing() { return m_progressingFever; }
	
public:
	void	StartFever();

private:
	UINT	m_feverDuration;

	UINT	m_feverStartTime;
	UINT	m_currentTime;

	bool	m_progressingFever;

};	

