#include "Combo.h"
#include "NumberAscii.h"

Combo::Combo()
{
	m_pos = Pos();
	m_combo = 0;
	m_maxCombo = 0;
}

Combo::Combo(Pos pos)
{
	m_pos = pos;
	m_combo = 0;
	m_maxCombo = 0;
}

Combo::~Combo()
{
}

void Combo::Init()
{
}

void Combo::Update(float dt)
{
}

void Combo::Render()
{
	GET_SINGLE(Console)->SetColor((int)ConsoleColor::WHITE, (int)ConsoleColor::BLACK);

	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);

	char combo[4];
	sprintf_s(combo, "%03d", m_combo);

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < WORD_HEIGHT; y++) {
			GET_SINGLE(Console)->Gotoxy(m_pos.X() + i * WORD_WIDTH, m_pos.Y() + y);
			wcout << NUMBER_WORDS[combo[i] - '0'][y];
		}
	}

	int curMode = _setmode(_fileno(stdout), prevMode);
}

void Combo::Release()
{
}

void Combo::SetCombo(int combo)
{
	m_combo += combo;

	if (m_combo > m_maxCombo) {
		m_maxCombo = m_combo;
	}
}
