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
	void				Judgement(shared_ptr<Note> note);
	shared_ptr<Note>	EqualNotePos(int x);
	void				NoteMiss(shared_ptr<Note> note);

public:
	bool				IsClear() { return m_noteSheet.empty() && m_notes.empty(); }

public:
	JUDGEMENT_TYPE		GetLastJudgement() { return m_lastJudgement; }

private:
	JUDGEMENT_TYPE				m_lastJudgement;

	float						m_judgementLength;
	float						m_delay;

	float						m_timer;
	float						m_defaultNoteSpeed;

	list<shared_ptr<Note>>		m_noteSheet;
	vector<shared_ptr<Note>>	m_notes;

	Pos							m_right;
	Pos							m_left;

};

