#include "Pos.h"

Pos::Pos()
{
    m_PosX = 0;
    m_PosY = 0;
}

Pos::Pos(int x, int y)
{
    m_PosX = x;
    m_PosY = y;
}

Pos::~Pos()
{
}

Pos Pos::operator+(const Pos& other)
{
    return Pos(this->m_PosX + other.m_PosX, this->m_PosY + other.m_PosY);
}

Pos Pos::operator-(const Pos& other)
{
    return Pos(this->m_PosX - other.m_PosX, this->m_PosY - other.m_PosY);
}

bool Pos::operator==(const Pos& other)
{
    return (this->m_PosX == other.m_PosX && this->m_PosY == other.m_PosY);
}

bool Pos::operator!=(const Pos& other)
{
    return !(this->m_PosX == other.m_PosX && this->m_PosY == other.m_PosY);
}
