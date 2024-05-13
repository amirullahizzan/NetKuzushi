#include "WinMain.h"
#include <ctime>

//#define DEBUG

void SpawnConsole()
{
	if (AllocConsole()) {
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);
		SetConsoleTitle("Debug Console");
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#ifdef DEBUG
	SpawnConsole();
#endif

	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("DeathGame");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	SRand((int)time(NULL));

	KeyInputInit();
	PadInputInit();
	MouseInputInit();
	GameInit();
	while (ProcessMessage() == 0)
	{
		KeyInputUpdate();
		PadInputUpdate();
		MouseInputUpdate();
		GameUpdate();

		ClearDrawScreen();

#ifdef DEBUG
		clsDx();
#endif

		GameDraw();
		ScreenFlip();
	}



	GameExit();

	DxLib_End();

	return 0;
}