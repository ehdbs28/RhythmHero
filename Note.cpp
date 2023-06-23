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

	if (m_pos.X() >= SCREEN_WIDTH / 2 - 2 && m_pos.X() <= SCREEN_WIDTH / 2 + 2) {
		Release();
	}
}

void Note::Render()
{
	GET_SINGLE(Console)->SetColor((int)m_color, (int)m_color);

	for (int i = 0; i < 4; i++) {
		GET_SINGLE(Console)->Gotoxy(m_pos.X(), m_pos.Y() + i);
		cout << " ";
	}
}

void Note::Release()
{
	GET_SINGLE(NoteManager)->Judgement();
}
