#pragma once
#include "Define.h"

enum class NOTE_TYPE {
	NORMAL,
	LONG,
	REVERSE,
};

class Note
{
public:
	Note();
	Note(Pos pos, float delay, NOTE_TYPE type, float lenght);
	~Note();

public:
	void	Init();
	void	Update();
	void	Render();
	void	Release();

private:
	Pos			m_pos;
	NOTE_TYPE	m_type;

	float		m_length;
	float		m_delay;

};

