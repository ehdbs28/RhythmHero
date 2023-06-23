#include "GameScene.h"
#include "Player.h"
#include "GameLine.h"
#include "Combo.h"
#include "ProgressBar.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_combo = make_shared<Combo>(Pos(SCREEN_WIDTH / 2 - 11, 5));
	m_gameLine = make_shared<GameLine>(Pos(0, SCREEN_HEIGHT / 2 - 3), SCREEN_WIDTH, 10, "VIichan - DAYBREAK FRONTLINE");
	m_feverBar = make_shared<ProgressBar>(Pos(SCREEN_WIDTH / 2 - 28, SCREEN_HEIGHT / 2 + 7), 60, 1, 0, 1, "");

	if (m_combo)
		m_combo->Init();

	if (m_feverBar)
		m_feverBar->Init();

	if (m_gameLine)
		m_gameLine->Init();
}

void GameScene::Update(float dt)
{
	if (m_combo)
		m_combo->Update(dt);

	if (m_feverBar)
		m_feverBar->Update(dt);

	if (m_gameLine)
		m_gameLine->Update(dt);
}

void GameScene::Render()
{
	if (m_combo)
		m_combo->Render();

	if (m_feverBar)
		m_feverBar->Render();

	if (m_gameLine)
		m_gameLine->Render();
}

void GameScene::Release()
{
	if (m_combo)
		m_combo->Release();

	if (m_gameLine)
		m_gameLine->Release();

	if (m_feverBar)
		m_feverBar->Release();
}

void GameScene::Setting(string song, string author)
{
	m_song = song;
	m_author = author;
}
