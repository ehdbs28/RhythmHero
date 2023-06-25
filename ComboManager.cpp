#include "ComboManager.h"
#include "Combo.h"

void ComboManager::Setting(shared_ptr<Combo> combo)
{
	m_combo = combo;
}

int ComboManager::GetCombo()
{
	return m_combo->GetCombo();
}

void ComboManager::SetCombo(int combo)
{
	m_combo->SetCombo(combo);
}
