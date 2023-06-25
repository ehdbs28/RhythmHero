#pragma once
#include "Define.h"

class Combo;
class ComboManager
{
	DECLARE_SINGLE(ComboManager);

public:
	void	Setting(shared_ptr<Combo> combo);

public:
	int		GetCombo();

public:
	void	SetCombo(int combo);

private:
	shared_ptr<Combo>		m_combo;
};

