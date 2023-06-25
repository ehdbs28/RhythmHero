#include "FeverManager.h"
#include "Fever.h"

void FeverManager::Setting(shared_ptr<Fever> fever) {
	m_fever = fever;
}

void FeverManager::SetGauge(float value)
{
	m_fever->SetPercent(value);
}

float FeverManager::GetGauge()
{
	return m_fever->GetCurrentValue();
}
