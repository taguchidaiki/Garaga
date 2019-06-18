#include <DxLib.h>
#include "ImageMng.h"



ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}

int ImageMng::GetID(std::string key)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key] = LoadGraph(key.c_str());
		//LoadDivGraph("image/char.png", 10 * 10, 10, 10, 30, 32, &imgMap[key]);
	}

	return imgMap[key];
}