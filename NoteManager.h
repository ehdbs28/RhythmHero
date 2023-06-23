#pragma once
#include "Define.h"

// ����Ž������ ã���� �ɵ�
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
	void			Update();
	void			Render();
	void			Release();

public:
	JUDGEMENT_TYPE	Judgement(float judgement);


private:
	float			m_judgementLength;
	float			m_songStartDelay;

	float			m_timer;

};

