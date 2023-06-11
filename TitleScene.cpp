#include "TitleScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update()
{
}

void TitleScene::Render()
{
	GET_SINGLE(Console)->Gotoxy(0, 0);
	DrawAsciiTitle();
}

void TitleScene::Release()
{
}

void TitleScene::DrawAsciiTitle()
{
	int prevMode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << " ________  ___  ___      ___    ___ _________  ___  ___  _____ ______           ___  ___  _______   ________  ________     " << "\n";
	wcout << "|\\   __  \\|\\  \\|\\  \\    |\\  \\  /  /|\\___   ___\\\\  \\|\\  \\|\\   _ \\  _   \\        |\\  \\|\\  \\|\\  ___ \\ |\\   __  \\|\\   __  \\" << "\n";
	wcout << "\\ \\  \\|\\  \\ \\  \\\\\\  \\   \\ \\  \\/  / ||___ \\  \\_\\ \\  \\\\\\  \\ \\  \\\\\__\\\\ \\  \\       \\ \\  \\\\\\  \\ \\   __/|\\ \\  \\|\\  \\ \\  \\|\\  \\" << "\n";
	wcout << " \\ \\   _  _\\ \\   __  \\   \\ \\    / /     \\ \\  \\ \\ \\   __  \\ \\  \\\\|__| \\  \\       \\ \\   __  \\ \\  \\_|/_\\ \\   _  _\\ \\  \\\\\\  \\" << "\n";
	wcout << "  \\ \\  \\\\  \\\\ \\  \\ \\  \\   \\/  /  /       \\ \\  \\ \\ \\  \\ \\  \\ \\  \\    \\ \\  \\       \\ \\  \\ \\  \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\  \\\\\\  \\ " << "\n";
	wcout << "   \\ \\__\\\\ _\\\\ \\__\\ \\__\\__/  / /          \\ \\__\\ \\ \\__\\ \\__\\ \\__\\    \\ \\__\\       \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\_______\\" << "\n";
	wcout << "    \\|__|\\|__|\\|__|\\|__|\\___/ /            \\|__|  \\|__|\\|__|\\|__|     \\|__|        \\|__|\\|__|\\|_______|\\|__|\\|__|\\|_______|" << "\n";
	wcout << "                       \\|___|/" << "\n";

	int curMode = _setmode(_fileno(stdout), prevMode);
}
