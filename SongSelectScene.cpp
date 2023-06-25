#include "SongSelectScene.h"
#include "InputManager.h"
#include "SceneManager.h"

SongSelectScene::SongSelectScene()
{
	m_currentSelect = 0;
}

SongSelectScene::~SongSelectScene()
{
}

void SongSelectScene::Init()
{
}

void SongSelectScene::Update(float dt)
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::SPACE)) {
		GET_SINGLE(SceneManager)->LoadScene(L"InGame");
	}
}

void SongSelectScene::Render()
{
	GET_SINGLE(Console)->Gotoxy(SCREEN_WIDTH / 2 - 5, SCREEN_HEIGHT / 2 - 1);

	cout << "SELECT SONG";

	GET_SINGLE(Console)->Gotoxy(SCREEN_WIDTH / 2 - 4, SCREEN_HEIGHT / 2 + 1);

	cout << "■ □ □ □ □";

	GET_SINGLE(Console)->Gotoxy(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2 + 3);

	cout << "NAME: YOASOBI - IDOL";
}

void SongSelectScene::Release()
{
}
