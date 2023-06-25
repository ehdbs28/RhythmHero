#pragma once
#include "Define.h"

class Fever;
class FeverManager
{
	DECLARE_SINGLE(FeverManager)

public:
	void	Setting(shared_ptr<Fever> fever);

public:
	void	SetGauge(float value);

public:
	float	GetGauge();

private:
	shared_ptr<Fever>		m_fever;

};

