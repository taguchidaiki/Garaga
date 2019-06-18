#include <DxLib.h>
#include <main.h>
#include <Obj.h>
#include <Player.h>
#include <Enemy.h>
#include <common/ImageMng.h>

constexpr int SCREEN_SIZE_X = 800;
constexpr int SCREEN_SIZE_Y = 600;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	SetWindowText("1701320_“cŒû‘å‹M");
	if (DxLib_Init() == -1)
	{
		return 0;
	}

	Obj *objs[2];
	ImageMng *imgMng;

	imgMng = new ImageMng();
	objs[0] = new Player();
	objs[1] = new Enemy();

	imgMng->GetID("image/flag.png");
	SetDrawScreen(DX_SCREEN_BACK);



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