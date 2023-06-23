#include "Player.h"

Player::Player()
{
	m_pos = Pos();
	m_thickness = 1;
}

Player::Player(Pos pos, int width)
{
	m_pos = pos;
	m_thickness = width;
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
}

void Player::Render()
{
	int lastColor = GET_SINGLE(Console)->SetColor((int)ConsoleColor::LIGHT_GRAY, (int)ConsoleColor::SKYBLUE);
	int lastBg = lastColor >> 4;
	int lastCo = (lastBg << 4) ^ lastColor;

	for (int i = 0; i < m_thickness; i++) {
		GET_SINGLE(Console)->Gotoxy(m_pos.X(), m_pos.Y() + i);
		cout << " ";
	}

	GET_SINGLE(Console)->SetColor(lastCo, lastBg);
}

void Player::Release()
{
}
