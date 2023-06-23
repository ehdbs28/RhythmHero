#include "InfomationScene.h"
#include "InputManager.h"
#include "SceneManager.h"

InfomationScene::InfomationScene()
{
	m_titlePosX = SCREEN_WIDTH / 2 - 15;
	m_titlePosY = 4;

	m_infoPosX = SCREEN_WIDTH / 2 - 40;
	m_infoPosY = 12;

	m_titleAscii = {
		L"██╗███╗   ██╗███████╗ ██████╗",
		L"██║████╗  ██║██╔════╝██╔═══██╗",
		L"██║██╔██╗ ██║█████╗  ██║   ██║",
		L"██║██║╚██╗██║██╔══╝  ██║   ██║",
		L"██║██║ ╚████║██║     ╚██████╔╝",
		L"╚═╝╚═╝  ╚═══╝╚═╝      ╚═════╝"
	};
}

InfomationScene::~InfomationScene()
{
}

void InfomationScene::Init()
{
}

void InfomationScene::Update(float dt)
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::BACK)) {
		GET_SINGLE(SceneManager)->LoadScene(L"Title");
	}
}

void InfomationScene::Render()
{
	DrawAscii();
	DrawInfo();
}

void InfomationScene::Release()
{
	system("cls");
}

void InfomationScene::DrawAscii()
{
	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);

	for (int i = 0; i < m_titleAscii.size(); ++i) {
		GET_SINGLE(Console)->Gotoxy(m_titlePosX, m_titlePosY + i);
		wcout << m_titleAscii[i];
	}

	int curMode = _setmode(_fileno(stdout), prevMode);
}

void InfomationScene::DrawInfo()
{

}
