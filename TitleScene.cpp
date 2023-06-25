#include "TitleScene.h"
#include "InputManager.h"
#include "Game.h"
#include "SceneManager.h"

TitleScene::TitleScene()
{
	m_titlePosX = 8;
	m_titlePosY = 3;

	m_menuPosX = SCREEN_WIDTH / 2 - 8;
	m_menuPosY = SCREEN_HEIGHT / 2 + 2;
	
	m_cursor = 0;
	m_menus = { "게임 시작", "게임 설명", "게임 종료" };

	m_titleAscii = {
		L" ________  ___  ___      ___    ___ _________  ___  ___  _____ ______           ___  ___  _______   ________  ________",
		L"|\\   __  \\|\\  \\|\\  \\    |\\  \\  /  /|\\___   ___\\\\  \\|\\  \\|\\   _ \\  _   \\        |\\  \\|\\  \\|\\  ___ \\ |\\   __  \\|\\   __  \\",
		L"\\ \\  \\|\\  \\ \\  \\\\\\  \\   \\ \\  \\/  / ||___ \\  \\_\\ \\  \\\\\\  \\ \\  \\\\\__\\\\ \\  \\       \\ \\  \\\\\\  \\ \\   __/|\\ \\  \\|\\  \\ \\  \\|\\  \\",
		L" \\ \\   _  _\\ \\   __  \\   \\ \\    / /     \\ \\  \\ \\ \\   __  \\ \\  \\\\|__| \\  \\       \\ \\   __  \\ \\  \\_|/_\\ \\   _  _\\ \\  \\\\\\  \\",
		L"  \\ \\  \\\\  \\\\ \\  \\ \\  \\   \\/  /  /       \\ \\  \\ \\ \\  \\ \\  \\ \\  \\    \\ \\  \\       \\ \\  \\ \\  \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\  \\\\\\  \\ ",
		L"   \\ \\__\\\\ _\\\\ \\__\\ \\__\\__/  / /          \\ \\__\\ \\ \\__\\ \\__\\ \\__\\    \\ \\__\\       \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\_______\\",
		L"    \\|__|\\|__|\\|__|\\|__|\\___/ /            \\|__|  \\|__|\\|__|\\|__|     \\|__|        \\|__|\\|__|\\|_______|\\|__|\\|__|\\|_______|",
		L"                       \\|___|/"
	};
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update(float dt)
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::DOWN)) {
		if (m_cursor != 2)
			++m_cursor;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::UP)) {
		if (m_cursor != 0)
			--m_cursor;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::SPACE)) {
		MenuSelect();
	}
}

void TitleScene::Render()
{
	DrawAsciiTitle();
	DrawMenu();
}

void TitleScene::Release()
{
	system("cls");
}

void TitleScene::DrawAsciiTitle()
{
	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);

	for (int i = 0; i < m_titleAscii.size(); ++i) {
		GET_SINGLE(Console)->Gotoxy(m_titlePosX, m_titlePosY + i);
		wcout << m_titleAscii[i];
	}

	int curMode = _setmode(_fileno(stdout), prevMode);
}

void TitleScene::DrawMenu()
{
	for (int i = 0; i < 3; i++) {
		GET_SINGLE(Console)->Gotoxy(m_menuPosX, m_menuPosY + i * 2);
		if (i == m_cursor) {
			cout << "> ";
		}
		else {
			cout << "  ";
		}
		cout << m_menus[i];
	}
}

void TitleScene::MenuSelect()
{
	if (m_cursor == 0) {
		GET_SINGLE(SceneManager)->LoadScene(L"SongSelect");
	}
	else if (m_cursor == 1) {
		GET_SINGLE(SceneManager)->LoadScene(L"Infomation");
	}
	else if (m_cursor == 2) {
		Game::SetGameRunning(false);
	}
}
