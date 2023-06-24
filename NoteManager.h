#pragma once
#include "Define.h"

enum class JUDGEMENT_TYPE {
	PERFECT,
	GREAT,
	GOOD,
	BREAK
};

class Note;
class NoteManager
{
	DECLARE_SINGLE(NoteManager)

public:
	void			Init();
	void			Update(float dt);
	void			Render();
	void			Release();

public:
	void				Setting(float startDelay, float judgementLenght = 10.0f, float defaultNoteSpeed = 80.0f);
	JUDGEMENT_TYPE		Judgement();
	shared_ptr<Note>	EqualNotePos(int x);

private:
	float						m_judgementLength;
	float						m_delay;

	float						m_timer;
	float						m_defaultNoteSpeed;

	list<shared_ptr<Note>>		m_noteSheet;
	vector<shared_ptr<Note>>	m_notes;

	Pos							m_right;
	Pos							m_left;

};

