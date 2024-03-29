﻿#pragma once

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
#include <mmsystem.h>
#include <Digitalv.h>
#include "Pos.h"

using namespace std;

#pragma comment(lib, "winmm.lib")

#define SAFE_DELETE(p)				if(p) { delete p; p = nullptr; }

#define WORD_WIDTH					8
#define WORD_HEIGHT					5

#define SCREEN_WIDTH				140
#define SCREEN_HEIGHT				35

#define DECLARE_SINGLE(type)		\
private:							\
	type() {}						\
	~type() {}						\
public:								\
	static type* GetInstance() {	\
		static type instance;		\
		return &instance;			\
	}								

#define GET_SINGLE(type)			type::GetInstance()

enum class ConsoleColor {
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY,
	LIGHT_BLUE, LIGHT_GREEN, MINT, LIGHT_RED,
	LIGHT_VIOLET, LIGHT_YELLOW, WHITE
};

static wstring NUMBER_WORDS[10][5] = {
	{
		{L"██████"},
		{L"██  ██"},
		{L"██  ██"},
		{L"██  ██"},
		{L"██████"},
	},
	{
		{L"   ██ "},
		{L" ████ "},
		{L"   ██ "},
		{L"   ██ "},
		{L"   ██ "},
	},
	{
		{L"██████"},
		{L"    ██"},
		{L"██████"},
		{L"██    "},
		{L"██████"},
	},
	{
		{L"██████"},
		{L"    ██"},
		{L" █████"},
		{L"    ██"},
		{L"██████"},
	},
	{
		{L"██  ██"},
		{L"██  ██"},
		{L"██████"},
		{L"    ██"},
		{L"    ██"},
	},
	{
		{L"██████"},
		{L"██    "},
		{L"██████"},
		{L"    ██"},
		{L"██████"},
	},
	{
		{L"██████"},
		{L"██    "},
		{L"██████"},
		{L"██  ██"},
		{L"██████"},
	},
	{
		{L"██████"},
		{L"    ██"},
		{L"    ██"},
		{L"    ██"},
		{L"    ██"},
	},
	{
		{L"██████"},
		{L"██  ██"},
		{L"██████"},
		{L"██  ██"},
		{L"██████"},
	},
	{
		{L"██████"},
		{L"██  ██"},
		{L"██████"},
		{L"    ██"},
		{L"██████"},
	}
};
static wstring JUDGEMENTS[4][5] = {
	{
		L"██████  ███████ ██████  ███████ ███████  ██████ ████████",
		L"██   ██ ██      ██   ██ ██      ██      ██         ██	  ",
		L"██████  █████   ██████  █████   █████   ██         ██	  ",
		L"██      ██      ██   ██ ██      ██      ██         ██	  ",
		L"██      ███████ ██   ██ ██      ███████  ██████    ██	  ",
	},
	{
		L"	  ██████  ██████  ███████  █████  ████████",
		L"	 ██       ██   ██ ██      ██   ██    ██   ",
		L"	 ██   ███ ██████  █████   ███████    ██   ",
		L"	 ██    ██ ██   ██ ██      ██   ██    ██   ",
		L"	  ██████  ██   ██ ███████ ██   ██    ██   ",
	},
	{
		L"	  ██████   ██████   ██████  ██████	",
		L"	 ██       ██    ██ ██    ██ ██   ██",
		L"	 ██   ███ ██    ██ ██    ██ ██   ██",
		L"	 ██    ██ ██    ██ ██    ██ ██   ██",
		L"	  ██████   ██████   ██████  ██████	",
	},
	{
		L"	 ██████  ██████  ███████  █████  ██   ██",
		L"	 ██   ██ ██   ██ ██      ██   ██ ██  ██ ",
		L"	 ██████  ██████  █████   ███████ █████	 ",
		L"	 ██   ██ ██   ██ ██      ██   ██ ██  ██ ",
		L"	 ██████  ██   ██ ███████ ██   ██ ██   ██",
	}
};