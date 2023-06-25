#include "Fever.h"

Fever::Fever() 
	: ProgressBar()
{
	m_feverDuration = 1.0f;
	m_feverStartTime = 0.0f;
	m_currentTime = 0.0f;
	m_progressingFever = false;
}

Fever::Fever(Pos pos, int width, int height, float left, float right, string name, float duration)
	: ProgressBar(pos, width, height, left, right, name)
{
	m_feverDuration = duration;
	m_feverStartTime = 0.0f;
	m_currentTime = 0.0f;
	m_progressingFever = false;
}

Fever::~Fever()
{
}

void Fever::Init()
{
	ProgressBar::Init();
}

void Fever::Update(float dt)
{
	ProgressBar::Update(dt);
	if (m_progressingFever) {
		m_currentTime = (UINT)time(nullptr);

		if (m_currentTime - m_feverStartTime >= m_feverDuration) {
			m_progressingFever = false;
		}
	}
}

void Fever::Render()
{
	ProgressBar::Render();
}

void Fever::Release()
{
	ProgressBar::Release();
}

void Fever::StartFever()
{
	m_currentValue = 0.0f;
	m_feverStartTime = (UINT)time(nullptr);
	m_currentTime = 0.0f;
	m_progressingFever = true;
}
