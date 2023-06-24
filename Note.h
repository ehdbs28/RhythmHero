#pragma once
#include "Define.h"
#include "Console.h"

enum class NOTE_TYPE {
	NORMAL,
	LONG,
	REVERSE,
};

class Note
{
public:
	Note();
	Note(Pos pos, float delay, NOTE_TYPE type, float lenght = 1.0f, float speed = 80.0f);
	~Note();


public:
	void	Init();
	void	Update(float dt);
	void	Render();
	void	Release();

public:
	Pos&			GetPos() { return m_pos; }
	NOTE_TYPE		GetType() { return m_type; }
	ConsoleColor	GetColor() { return m_color; }
	float			GetLenght() { return m_length; }
	float			GetDelay() { return m_delay; }
	float			GetSpeed() { return m_noteSpeed; }

private:
	Pos				m_pos;
	NOTE_TYPE		m_type;

	ConsoleColor	m_color;

	float			m_length;
	float			m_delay;

	float			m_noteSpeed;

};

