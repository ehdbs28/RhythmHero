#include "AudioManager.h"

void AudioManager::RegisterSource(string name, LPCWSTR address) {
	m_sources.insert({ name, address });
}

void AudioManager::PlaySource(string name)
{
	LPCWSTR address = m_sources.at(name);

	m_openParam.lpstrElementName = address;
	m_openParam.lpstrDeviceType = L"mpegvideo";

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&m_openParam);
	m_dwID = m_openParam.wDeviceID;
	mciSendCommand(m_dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&m_playParam);
}
