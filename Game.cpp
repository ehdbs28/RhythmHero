#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "InfomationScene.h"
#include "GameScene.h"

bool Game::m_gameRunning = true;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	GET_SINGLE(Console)->ConsoleCursor(false, 5);

	GET_SINGLE(Console)->SetScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	COORD dwSize;
	dwSize.X = 17;
	dwSize.Y = 17;
	GET_SINGLE(Console)->SetConsoleFont(L"D2Coding", dwSize, true);

	GET_SINGLE(InputManager)->Init();
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->RegisterScene(L"Title", make_shared<TitleScene>());
	GET_SINGLE(SceneManager)->RegisterScene(L"Infomation", make_shared<InfomationScene>());
	GET_SINGLE(SceneManager)->RegisterScene(L"InGame", make_shared<GameScene>());

	GET_SINGLE(SceneManager)->LoadScene(L"Title");

	m_gameRunning = true;
}

void Game::Update()
{
	GET_SINGLE(InputManager)->Update();
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
