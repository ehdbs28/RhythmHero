#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	virtual ~TitleScene();

public:
	void			Init() override;
	void			Update() override;
	void			Render() override;
	void			Release() override;

private:
	void			DrawAsciiTitle();
	void			DrawMenu();
	void			MenuSelect();

private:
	int				m_titlePosY;
	int				m_titlePosX;

	int				m_menuPosY;
	int				m_menuPosX;

	int				m_cursor;

	vector<string>	m_menus;
	vector<wstring>	m_titleAscii;
};

