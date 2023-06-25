#include "GameLine.h"
#include "Player.h"
#include "Note.h"
#include "NoteManager.h"
#include "InputManager.h"

GameLine::GameLine()
{
	m_linePos = Pos();
	m_width = 0;
	m_height = 0;
	m_name = "";
	m_judgementWidth = 10;
}

GameLine::GameLine(Pos pos, int width, int height, string name)
{
	m_linePos = pos;
	m_width = width;
	m_height = height;
	m_name = name;
	m_judgementWidth = 10;
}

GameLine::~GameLine()
{
}

void GameLine::Init()
{
	m_player = make_shared<Player>(Pos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 1), 2);

	GET_SINGLE(NoteManager)->Setting(0);
	GET_SINGLE(NoteManager)->Init();

	if (m_player)
		m_player->Init();

	DrawEdge();
}

void GameLine::Update(float dt)
{
	bool value = false;

	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::KEY_F)
		|| GET_SINGLE(InputManager)->GetButton(KEY_TYPE::KEY_F)) {
		NoteInput(false);
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KEY_TYPE::KEY_J)
		|| GET_SINGLE(InputManager)->GetButton(KEY_TYPE::KEY_J)) {
		NoteInput(true);
	}

	if (m_player)
		m_player->Update();

	GET_SINGLE(NoteManager)->Update(dt);
}

void GameLine::Render()
{
	GET_SINGLE(Console)->Gotoxy(m_linePos.X(), m_linePos.Y() - 1);
	GET_SINGLE(Console)->SetColor((int)ConsoleColor::BLACK, (int)ConsoleColor::LIGHT_GRAY);
	cout << m_name;

	DrawLine();
}

void GameLine::Release()
{
}

void GameLine::DrawEdge()
{
	int y;
	int x;

	GET_SINGLE(Console)->SetColor((int)ConsoleColor::WHITE, (int)ConsoleColor::BLACK);

	for (y = m_linePos.Y(); y < m_linePos.Y() + m_height; y++) {
		int x = m_linePos.X();
		GET_SINGLE(Console)->Gotoxy(x, y);
		for (x = m_linePos.X(); x < m_linePos.X() + m_width; x++) {
			if (x == 0 || x == m_width - 1 || y == m_linePos.Y() || y == m_linePos.Y() + m_height - 1) {
				cout << "¢Ã";
			}
			else {
				cout << " ";
			}
		}
	}
}

void GameLine::NoteInput(bool right)
{
	if (right) {
		for (int x = SCREEN_WIDTH / 2; x <= SCREEN_WIDTH / 2 + m_judgementWidth; x++) {
			shared_ptr<Note> note = GET_SINGLE(NoteManager)->EqualNotePos(x);

			if (note) {
				if (note->GetType() == NOTE_TYPE::REVERSE) {
					GET_SINGLE(NoteManager)->NoteMiss(note);
				}
				else {
					if (note->GetLenght() == 1) {
						GET_SINGLE(NoteManager)->Judgement(note);
					}
					else {
						note->SetLenght(note->GetLenght() - 1);
						note->GetPos().SetX(note->GetPos().X() + 1);
					}
				}
			}
		}
	}
	else {
		for (int x = SCREEN_WIDTH / 2; x >= SCREEN_WIDTH / 2 - m_judgementWidth; x--) {
			shared_ptr<Note> note = GET_SINGLE(NoteManager)->EqualNotePos(x);

			if (note) {
				if (note->GetType() == NOTE_TYPE::REVERSE) {
					GET_SINGLE(NoteManager)->NoteMiss(note);
				}
				else {
					if (note->GetLenght() == 1) {
						GET_SINGLE(NoteManager)->Judgement(note);
					}
					else {
						note->SetLenght(note->GetLenght() - 1);
						note->GetPos().SetX(note->GetPos().X() - 1);
					}
				}
			}
		}
	}
}

void GameLine::DrawLine() {
	int x = m_linePos.X();
	GET_SINGLE(Console)->Gotoxy(x, SCREEN_HEIGHT / 2);
	for (x = 1; x < m_width - 1; x++) {
		shared_ptr<Note> note = GET_SINGLE(NoteManager)->EqualNotePos(x);

		if (m_player->GetPos().X() == x) {
			m_player->Render();
		}
		else if (note) {
			GET_SINGLE(Console)->SetColor((int)note->GetColor(), (int)note->GetColor());
			note->Render();
		}
		else {
			GET_SINGLE(Console)->SetColor((int)ConsoleColor::BLACK, (int)ConsoleColor::BLACK);
			for (int i = 0; i < 4; i++) {
				GET_SINGLE(Console)->Gotoxy(x, SCREEN_HEIGHT / 2 + i);
				cout << " ";
			}
		}
	}
}
