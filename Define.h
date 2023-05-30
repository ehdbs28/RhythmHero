#pragma once

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <io.h>
#include <conio.h>
#include<fcntl.h>

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

#define SCREEN_WIDTH		50
#define SCREEN_HEIGHT		10

enum class ConsoleColor {
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY,
	LIGHT_BLUE, LIGHT_GREEN, MINT, LIGHT_RED,
	LIGHT_VIOLET, LIGHT_YELLOW, WHITE
};