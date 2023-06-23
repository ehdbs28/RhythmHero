#include "InputManager.h"

void InputManager::Init()
{
	m_states.resize(KEY_TYPE_COUNT, KEY_STATE::NONE);
}

void InputManager::Update(float dt)
{
	for (UINT key = 0; key < KEY_TYPE_COUNT; ++key) {
		if (GetKeyState(key) & 0x80) {
			KEY_STATE& state = m_states[key];

			if (state == KEY_STATE::PRESS || state == KEY_STATE::DOWN)
				state = KEY_STATE::PRESS;
			else
				state = KEY_STATE::DOWN;
		}
		else {
			KEY_STATE& state = m_states[key];

			if (state == KEY_STATE::PRESS || state == KEY_STATE::DOWN)
				state = KEY_STATE::UP;
			else
				state = KEY_STATE::NONE;
		}
	}
}
