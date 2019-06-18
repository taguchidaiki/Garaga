#include <DxLib.h>
#include <main.h>
#include <Obj.h>
#include <Player.h>
#include <Enemy.h>
#include <common/ImageMng.h>

constexpr int SCREEN_SIZE_X = 800;
constexpr int SCREEN_SIZE_Y = 600;


int SysInit(void);


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SysInit();
	Obj *objs[2];
	
	objs[0] = new Player({300,200});
	objs[1] = new Enemy({500,200});

	objs[0]->Init("image/char.png", { 30,32 }, { 10,10 },0);
	objs[1]->Init("image/char.png", { 30,32 }, { 10,10 },10);


	while ((ProcessMessage() == 0) && (CheckHitKey(KEY_INPUT_ESCAPE)) == 0)
	{
		ClsDrawScreen();

		for (auto obj : objs)
		{
			obj->Draw();
		}

		ScreenFlip();
	}

	for (auto obj : objs)
	{
		delete obj;
	}

	return 0;
}

int SysInit(void)
{
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	SetWindowText("1701320_“cŒû‘å‹M");
	if (DxLib_Init() == -1)
	{
		return 0;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return 0;
}

