#pragma once
#include "Scene.h"

class GameLine;
class Combo;
class Fever;
class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();
	
public:
	void	Init() override;
	void	Update(float dt) override;
	void	Render() override;
	void	Release() override;

public:
	void	Setting(string song, string author);
	void	DrawJudgement();

private:
	string					m_song;
	string					m_author;

	shared_ptr<Combo>		m_combo;
	shared_ptr<GameLine>	m_gameLine;
	shared_ptr<Fever>		m_feverBar;
		
	bool					m_playing;
	float					m_currentTime;

};

