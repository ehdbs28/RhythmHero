#pragma once
#include "Scene.h"

class InfomationScene : public Scene
{
public:
	InfomationScene();
	virtual ~InfomationScene();

public:
	void		Init() override;
	void		Update(float dt) override;
	void		Render() override;
	void		Release() override;

private:
	void		DrawAscii();
	void		DrawInfo();

private:
	int				m_titlePosX;
	int				m_titlePosY;

	int				m_infoPosX;
	int				m_infoPosY;

	vector<wstring>	m_titleAscii;

};

