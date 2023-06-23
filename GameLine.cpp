#include "GameLine.h"
#include "Player.h"

GameLine::GameLine()
{
	m_linePos = Pos();
	m_width = 0;
	m_height = 0;
	m_name = "";
}

GameLine::GameLine(Pos pos, int width, int height, string name)
{
	m_linePos = pos;
	m_width = width;
	m_height = height;
	m_name = name;
}

GameLine::~GameLine()
{
}

void GameLine::Init()
{
	m_player = make_shared<Player>(Pos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 1), 2);

	if (m_player)
		m_player->Init();
}

void GameLine::Update()
{
	if (m_player)
		m_player->Update();
}

void GameLine::Render()
{
	GET_SINGLE(Console)->Gotoxy(m_linePos.X(), m_linePos.Y() - 1);
	GET_SINGLE(Console)->SetColor((int)ConsoleColor::BLACK, (int)ConsoleColor::LIGHT_GRAY);
	cout << m_name;

	if (m_player) {
		DrawLine();
	}
}

void GameLine::Release()
{
}

void GameLine::DrawLine()
{
	GET_SINGLE(Console)->SetColor((int)ConsoleColor::BLACK, (int)ConsoleColor::WHITE);
	
	int y;
	int x;

	for (y = m_linePos.Y(); y < m_linePos.Y() + m_height; y++) {
		int x = m_linePos.X();
		GET_SINGLE(Console)->Gotoxy(x, y);
		for (x = m_linePos.X(); x < m_linePos.X() + m_width; x++) {
			if (x >= m_player->GetPos().X() && x <= m_player->GetPos().X() - 1 + m_player->GetThickness() &&
				y >= m_player->GetPos().Y() && y <= m_player->GetPos().Y() - 1 + m_player->GetThickness()
				) {
				m_player->Render();
			}
			else {
				cout << " ";
			}
		}
	}
	GET_SINGLE(Console)->SetColor((int)ConsoleColor::WHITE, (int)ConsoleColor::BLACK);
}
