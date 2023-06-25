#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "InfomationScene.h"
#include "SongSelectScene.h"
#include "GameScene.h"
#include "AudioManager.h"

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
	GET_SINGLE(SceneManager)->RegisterScene(L"SongSelect", make_shared<SongSelectScene>());
	GET_SINGLE(SceneManager)->RegisterScene(L"InGame", make_shared<GameScene>());

	GET_SINGLE(AudioManager)->RegisterSource("IDOL", TEXT("YOASOBI_IDOL.mp3"));

	GET_SINGLE(SceneManager)->LoadScene(L"Title");

	m_gameRunning = true;
}

void Game::Update(float dt)
{
	GET_SINGLE(InputManager)->Update(dt);
	GET_SINGLE(SceneManager)->Update(dt);
}

void Game::Render()
{
	GET_SINGLE(SceneManager)->Render();
}

void Game::Release()
{
	GET_SINGLE(SceneManager)->Release();
}
