#include <DxLib.h>
#include <main.h>
#include<common/SceneMng.h>

constexpr int SCREEN_SIZE_X = 800;
constexpr int SCREEN_SIZE_Y = 600;


int SysInit(void);

int SysInit(void)
{
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	SetWindowText("1701320_“cŒû‘å‹M");
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	return 0;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SysInit();

	lpSceneMng.Run();

	return 0;
}

