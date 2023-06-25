#include "GameScene.h"
#include "Player.h"
#include "GameLine.h"
#include "Combo.h"
#include "Fever.h"
#include "NoteManager.h"
#include "ComboManager.h"
#include "InputManager.h"
#include "FeverManager.h"
#include "SceneManager.h"
#include "AudioManager.h"

GameScene::GameScene()
{
	m_playing = false;
	m_currentTime = 0.0f;
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_combo = make_shared<Combo>(Pos(SCREEN_WIDTH / 2 - 11, 5));
	m_gameLine = make_shared<GameLine>(Pos(0, SCREEN_HEIGHT / 2 - 3), SCREEN_WIDTH, 10, " YOASOBI - IDOL");
	m_feverBar = make_shared<Fever>(Pos(SCREEN_WIDTH / 2 - 28, SCREEN_HEIGHT / 2 + 7), 60, 1, 0, 1, "", 3);

	GET_SINGLE(ComboManager)->Setting(m_combo);
	GET_SINGLE(FeverManager)->Setting(m_feverBar);

	if (m_combo)
		m_combo->Init();

	if (m_feverBar)
		m_feverBar->Init();

	if (m_gameLine)
		m_gameLine->Init();
}

void GameScene::Update(float dt)
{
	if (m_playing == false) {
		m_currentTime += dt;
		if (m_currentTime >= 2) 
		{
			m_playing = true;
			GET_SINGLE(AudioManager)->PlaySource("IDOL");
		}
	}

	if (m_combo)
		m_combo->Update(dt);

	if (m_feverBar)
		m_feverBar->Update(dt);

	if (m_gameLine) {
		m_gameLine->Update(dt);
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::SPACE)) {
		if (m_feverBar) {
			if (m_feverBar->GetCurrentValue() >= 1.0f) {
				m_feverBar->StartFever();
			}
		}
	}
}

void GameScene::Render()
{
	if (m_combo)
		m_combo->Render();

	if (m_feverBar)
		m_feverBar->Render();

	if (m_gameLine)
		m_gameLine->Render();

	DrawJudgement();

	if (GET_SINGLE(NoteManager)->IsClear()) {
		GET_SINGLE(SceneManager)->LoadScene(L"Title");
	}
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

void GameScene::DrawJudgement()
{
	GET_SINGLE(Console)->SetColor((int)ConsoleColor::WHITE, (int)ConsoleColor::BLACK);
	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);

	for (int y = 0; y < 5; y++) {
		GET_SINGLE(Console)->Gotoxy(SCREEN_WIDTH / 2 - 27, SCREEN_HEIGHT / 2 + 10 + y);
		switch (GET_SINGLE(NoteManager)->GetLastJudgement())
		{
		case JUDGEMENT_TYPE::PERFECT:
			GET_SINGLE(Console)->Gotoxy(SCREEN_WIDTH / 2 - 27, SCREEN_HEIGHT / 2 + 10 + y);
			wcout << JUDGEMENTS[0][y];
			break;
		case JUDGEMENT_TYPE::GREAT:
			wcout << JUDGEMENTS[1][y];
			break;
		case JUDGEMENT_TYPE::GOOD:
			wcout << JUDGEMENTS[2][y];
			break;
		case JUDGEMENT_TYPE::BREAK:
			wcout << JUDGEMENTS[3][y];
			break;
		}
	}

	int curMode = _setmode(_fileno(stdout), prevMode);
}
