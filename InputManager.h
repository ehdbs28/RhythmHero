#pragma once
#include "Define.h"

enum class KEY_TYPE {
	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,
	SPACE = VK_SPACE,
	BACK = VK_BACK,
};

enum class KEY_STATE {
	NONE,
	PRESS,
	DOWN,
	UP,
	END
};

enum {
	KEY_TYPE_COUNT = static_cast<int>(UINT8_MAX + 1),
	KEY_STATE_COUNT = static_cast<int>(KEY_STATE::END),
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void				Init();
	void				Update(float dt);

public:
	bool				GetButton(KEY_TYPE key) { return GetState(key) == KEY_STATE::PRESS; }
	bool				GetButtonDown(KEY_TYPE key) { return GetState(key) == KEY_STATE::DOWN; }
	bool				GetButtonUp(KEY_TYPE key) { return GetState(key) == KEY_STATE::UP; }

private:
	inline KEY_STATE	GetState(KEY_TYPE key) { return m_states[static_cast<UINT8>(key)]; }

private:
	vector<KEY_STATE>	m_states;

};

