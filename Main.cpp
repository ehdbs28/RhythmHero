#include "Game.h"

Game* game;

LARGE_INTEGER g_liPrevCount;
LARGE_INTEGER g_liCurCount;
LARGE_INTEGER g_liFrequency;

float g_fDT;
float g_fAcc;

void MainLoop()
{
	QueryPerformanceCounter(&g_liCurCount);
	g_fDT = (float)(g_liCurCount.QuadPart - g_liPrevCount.QuadPart) /
		(float)(g_liFrequency.QuadPart);

	g_liPrevCount = g_liCurCount;

	g_fAcc += g_fDT;

	if (g_fAcc >= 1.0f)
	{
		g_fAcc = 0.0f;
	}
}

int main() {
	game = new Game();

	game->Init();

	while (game->GetGameRunning()) {
		MainLoop();
		game->Update(g_fDT);
		game->Render();
	}

	game->Release();
}