#include "GameScene.h"
#include "Player.h"
#include "GameLine.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_gameLine = make_shared<GameLine>(Pos(0, SCREEN_HEIGHT / 2 - 3), SCREEN_WIDTH, 6);

	if (m_gameLine)
		m_gameLine->Init();
}

void GameScene::Update()
{
	if (m_gameLine)
		m_gameLine->Update();
}

void GameScene::Render()
{
	if (m_gameLine)
		m_gameLine->Render();
}

void GameScene::Release()
{
	if (m_gameLine)
		m_gameLine->Release();
}
