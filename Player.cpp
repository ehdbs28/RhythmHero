#include "Player.h"

Player::Player()
{
	m_playerPos = Pos();
	m_thickness = 1;
}

Player::Player(Pos pos, int width)
{
	m_playerPos = pos;
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

	cout << " ";

	GET_SINGLE(Console)->SetColor(lastCo, lastBg);
}

void Player::Release()
{
}
