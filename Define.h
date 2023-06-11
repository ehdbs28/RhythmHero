#pragma once

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <io.h>
#include <conio.h>
#include <fcntl.h>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

#define SAFE_DELETE(p)				if(p) { delete p; p = nullptr; }

#define SCREEN_WIDTH				125
#define SCREEN_HEIGHT				30

#define DECLARE_SINGLE(type)		\
private:							\
	type() {}						\
	~type() {}						\
public:								\
	static type* GetInstance() {	\
		static type instance;		\
		return &instance;			\
	}								\

#define GET_SINGLE(type)			type::GetInstance()

enum class ConsoleColor {
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY,
	LIGHT_BLUE, LIGHT_GREEN, MINT, LIGHT_RED,
	LIGHT_VIOLET, LIGHT_YELLOW, WHITE
};