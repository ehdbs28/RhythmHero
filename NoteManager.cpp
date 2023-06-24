#include "NoteManager.h"
#include "Note.h"

void NoteManager::Init() {
	m_noteSheet.clear();
	m_notes.clear();

	m_right = Pos(SCREEN_WIDTH - 1, SCREEN_HEIGHT / 2);
	m_left = Pos(1, SCREEN_HEIGHT / 2);

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.8, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.8, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.8, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.5, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.8, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.5, NOTE_TYPE::LONG, 3.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.5, NOTE_TYPE::LONG, 3.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.4, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.3, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 2.8, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.5, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.2, NOTE_TYPE::LONG, 15.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.2, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.2, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.5, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.4, NOTE_TYPE::LONG, 15.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.3, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.8, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::LONG, 20.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.8, NOTE_TYPE::LONG, 15.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.35, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.35, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.4, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.15, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.15, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.15, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.45, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.35, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.35, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.35, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.35, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::LONG, 15.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::LONG, 15.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::LONG, 15.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::LONG, 5.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::REVERSE, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::REVERSE, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.8, NOTE_TYPE::REVERSE, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::REVERSE, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::REVERSE, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.8, NOTE_TYPE::REVERSE, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.4, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 1.7, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 1.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 2.5, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.3, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::REVERSE, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::REVERSE, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::REVERSE, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::REVERSE, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.7, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.3, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.2, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.2, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.2, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.4, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.3, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 2, NOTE_TYPE::LONG, 50.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 3, NOTE_TYPE::LONG, 50.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.0, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.6, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 1, NOTE_TYPE::LONG, 15.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.6, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 1, NOTE_TYPE::LONG, 15.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 1.5, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 0.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.25, NOTE_TYPE::NORMAL, 1.0f, 40.0f));
	m_noteSheet.push_back(make_shared<Note>(m_right, 2.25, NOTE_TYPE::NORMAL, 1.0f, -20.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.7, NOTE_TYPE::NORMAL, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.5, NOTE_TYPE::NORMAL, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0.35, NOTE_TYPE::REVERSE, 1.0f, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.35, NOTE_TYPE::REVERSE, 1.0f, 40.0f));

	m_noteSheet.push_back(make_shared<Note>(m_right, 0, NOTE_TYPE::LONG, 10, -20.0f));
	m_noteSheet.push_back(make_shared<Note>(m_left, 0.2, NOTE_TYPE::LONG, 10, 40.0f));
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
			note->Init();
			m_notes.push_back(note);

			if (m_noteSheet.size() != 0)
			{
				while (note->GetDelay() <= 0)
				{
					note = m_noteSheet.front();
					m_noteSheet.pop_front();
					note->Init();
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
		if (m_notes[i]->GetType() == NOTE_TYPE::LONG) {
			for (int j = 0; j < m_notes[i]->GetLenght(); j++) {
				if (m_notes[i]->GetSpeed() > 0) {
					if (m_notes[i]->GetPos().X() - j == x) {
						return m_notes[i];
					}
				}
				else {
					if (m_notes[i]->GetPos().X() + j == x) {
						return m_notes[i];
					}
				}
			}
		}
		else {
			if (m_notes[i]->GetPos().X() == x) {
				return m_notes[i];
			}
		}
	}

	return nullptr;
}
