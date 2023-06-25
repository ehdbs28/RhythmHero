#include "Note.h"
#include "NoteManager.h"

Note::Note()
{
	m_pos = Pos();
	m_type = NOTE_TYPE::NORMAL;
	m_color = ConsoleColor::WHITE;
	m_length = 1;
	m_delay = 0;
	m_noteSpeed = 80.0f;
}

Note::Note(Pos pos, float delay, NOTE_TYPE type, float lenght, float speed)
{
	m_pos = pos;
	m_type = type;
	m_color = ConsoleColor::WHITE;
	m_length = lenght;
	m_delay = delay;
	m_noteSpeed = speed;
}

Note::~Note()
{
}

void Note::Init()
{
	switch (m_type)
	{
	case NOTE_TYPE::NORMAL:
		m_color = ConsoleColor::WHITE;
		break;
	case NOTE_TYPE::LONG:
		m_color = ConsoleColor::YELLOW;
		break;
	case NOTE_TYPE::REVERSE:
		m_color = ConsoleColor::LIGHT_RED;
		break;
	}
}

void Note::Update(float dt)
{
	float next = m_pos.X() + dt * m_noteSpeed;
	m_pos.SetX(next);

	if (m_noteSpeed > 0) {
		if (m_pos.X() >= SCREEN_WIDTH / 2 - 2) {
			if (m_type == NOTE_TYPE::LONG) {
				if (m_pos.X() - m_length >= SCREEN_WIDTH / 2 - 2) {
					Release();
				}
				m_length--;
				m_pos.SetX(m_pos.X() - 1);
			}
			else {
				Release();
			}
		}
	}
	else {
		if (m_pos.X() <= SCREEN_WIDTH / 2 + 2) {
			if (m_type == NOTE_TYPE::LONG) {
				if (m_pos.X() + m_length <= SCREEN_WIDTH / 2 + 2) {
					Release();
				}
				m_length--;
				m_pos.SetX(m_pos.X() + 1);
			}
			else {
				Release();
			}
		}
	}
}

void Note::Render()
{
	for (int i = 0; i < 4; i++) {
		GET_SINGLE(Console)->Gotoxy(m_pos.X(), m_pos.Y() + i);
		cout << " ";
	}
}

void Note::Release()
{
	GET_SINGLE(NoteManager)->NoteMiss(shared_from_this());
}
