#include "NoteManager.h"
#include "Note.h"

void NoteManager::Init() {
	m_noteSheet.clear();
	m_notes.clear();

	m_noteSheet.push_back(make_shared<Note>(Pos(1, SCREEN_HEIGHT / 2), 0, NOTE_TYPE::NORMAL, 1.0f, 30.0f));
	m_noteSheet.push_back(make_shared<Note>(Pos(SCREEN_WIDTH - 1, SCREEN_HEIGHT / 2), 1, NOTE_TYPE::NORMAL, 1.0f, -10.0f));
}

void NoteManager::Update(float dt)
{
	m_timer += dt;

	if (m_timer >= m_delay)
	{
		m_timer = 0;

		if (m_noteSheet.size() != 0)
		{
			shared_ptr<Note> note = m_noteSheet.front();
			m_noteSheet.pop_front();
			m_notes.push_back(note);

			if (m_noteSheet.size() != 0)
			{
				while (note->GetDelay() <= 0)
				{
					note = m_noteSheet.front();
					m_noteSheet.pop_front();
					m_notes.push_back(note);
				}
			}

			m_delay = note->GetDelay();
		}
	}

	for (int i = 0; i < m_notes.size(); i++) {
		m_notes[i]->Update(dt);
	}
}

void NoteManager::Render()
{
	for (int i = 0; i < m_notes.size(); i++) {
		m_notes[i]->Render();
	}
}

void NoteManager::Release()
{
	m_notes.clear();
	m_noteSheet.clear();
}

void NoteManager::Setting(float startDelay, float judgementLenght, float defaultNoteSpeed)
{
	m_judgementLength = judgementLenght;
	m_delay = startDelay;
	m_defaultNoteSpeed = defaultNoteSpeed;

	m_timer = 0.0f;
}

JUDGEMENT_TYPE NoteManager::Judgement()
{
	m_notes.erase(m_notes.begin());
	return JUDGEMENT_TYPE::PERFECT;
}

shared_ptr<Note> NoteManager::EqualNotePos(int x)
{
	for (int i = 0; i < m_notes.size(); i++) {
		if (m_notes[i]->GetPos().X() == x) {
			return m_notes[i];
		}
	}

	return nullptr;
}
