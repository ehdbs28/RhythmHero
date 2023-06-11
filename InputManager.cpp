#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Init()
{
	m_states.resize(KEY_TYPE_COUNT, KEY_STATE::NONE);

	for (UINT key = 0; key < KEY_TYPE_COUNT; ++key)
		m_states[key] = KEY_STATE::NONE;
}

void InputManager::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (UINT key = 0; key < KEY_TYPE_COUNT; ++key) {
		if (asciiKeys[key] & 0x80) {
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
