#include "Fever.h"

Fever::Fever()
{
	m_feverDuration = 1.0f;
	m_feverStartTime = 0.0f;
	m_currentTime = 0.0f;
	m_percent = 0.0f;
	m_progressingFever = false;
}

Fever::Fever(float duration)
{
	m_feverDuration = duration;
	m_feverStartTime = 0.0f;
	m_currentTime = 0.0f;
	m_percent = 0.0f;
	m_progressingFever = false;
}

Fever::~Fever()
{
}

void Fever::Init()
{
}

void Fever::Update()
{
	if (m_progressingFever) {
		m_currentTime = (UINT)time(nullptr);

		if (m_currentTime - m_feverStartTime >= m_feverDuration) {
			m_progressingFever = false;
		}
	}
}

void Fever::Render()
{
}

void Fever::Release()
{
}

void Fever::SetPercent(float increase)
{
	m_percent += increase;

	if (m_percent >= 1.0f) {
		m_percent = 0.0f;
		m_feverStartTime = (UINT)time(nullptr);
		m_currentTime = 0.0f;
		m_progressingFever = true;
	}
}

void Fever::StartFever()
{
}
