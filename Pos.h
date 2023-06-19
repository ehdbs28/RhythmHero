#pragma once
class Pos
{
public:
	Pos();
	Pos(int x, int y);
	~Pos();

public:
	int		X() { return m_PosX; }
	int		Y() { return m_PosY; }

public:
	void	SetX(int x) { m_PosX = x; }
	void	SetY(int y) { m_PosY = y; }

	void	Set(int x, int y) { m_PosX = x; m_PosY = y; }

public:
	Pos		operator+(const Pos& other);
	Pos		operator-(const Pos& other);
	bool	operator==(const Pos& other);
	bool	operator!=(const Pos& other);

private:
	int		m_PosX;
	int		m_PosY;

};

