#include "ProgressBar.h"
#include "InputManager.h"

ProgressBar::ProgressBar()
{
	m_pos = Pos(0, 0);
	m_width = 5;
	m_height = 1;
	m_leftValue = 0.0f;
	m_rightValue = 1.0f;
	m_currentValue = 0.0f;
	m_name = "";
}

ProgressBar::ProgressBar(Pos pos, int width, int height, float left, float right, string name)
{
	m_pos = pos;
	m_width = width;
	m_height = height;
	m_leftValue = left;
	m_rightValue = right;
	m_currentValue = 0.0f;
	m_name = name;
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::Init()
{
	SetPercent(0.0f);
}

void ProgressBar::Update(float dt)
{
}

void ProgressBar::Render()
{
	GET_SINGLE(Console)->Gotoxy(m_pos.X(), m_pos.Y() - 1);
	cout << m_name;

	for (int y = 0; y < m_height; y++) {
		GET_SINGLE(Console)->Gotoxy(m_pos.X(), m_pos.Y() + y);
		for (int x = 0; x < m_width; x++) {
			if(x < (0 * (1.0f - m_currentValue) + m_width * m_currentValue))
				GET_SINGLE(Console)->SetColor((int)ConsoleColor::LIGHT_BLUE, (int)ConsoleColor::LIGHT_BLUE);
			else
				GET_SINGLE(Console)->SetColor((int)ConsoleColor::LIGHT_GRAY, (int)ConsoleColor::LIGHT_GRAY);

			cout << " ";
		}
	}
}

void ProgressBar::Release()
{
}

void ProgressBar::SetPercent(float percent)
{
	m_currentValue += percent;

	if (m_currentValue < m_leftValue)
		m_currentValue = m_leftValue;

	if (m_currentValue > m_rightValue)
		m_currentValue = m_rightValue;
}
