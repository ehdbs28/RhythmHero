#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"

Game::Game()
{
	m_gameRunning = false;
}

Game::~Game()
{
}

void Game::Init()
{
	GET_SINGLE(Console)->ConsoleCursor(false, 5);

	GET_SINGLE(Console)->SetScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	GET_SINGLE(Console)->SetConsoleFont(L"D2Coding", true);

	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->RegisterScene(L"Title", make_shared<TitleScene>());
	GET_SINGLE(SceneManager)->LoadScene(L"Title");

	m_gameRunning = true;
}

void Game::Update()
{
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	GET_SINGLE(SceneManager)->Render();
}

void Game::Release()
{
	GET_SINGLE(SceneManager)->Release();
}
