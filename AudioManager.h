#pragma once
#include "Define.h"

class AudioManager
{
	DECLARE_SINGLE(AudioManager)

public:
	void	RegisterSource(string name, LPCWSTR address);
	void	PlaySource(string name);

private:
	MCI_OPEN_PARMS			m_openParam;
	MCI_PLAY_PARMS			m_playParam;

	UINT					m_dwID;

	map<string, LPCWSTR>	m_sources;
};

