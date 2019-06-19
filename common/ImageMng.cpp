#include <DxLib.h>
#include "ImageMng.h"

ImageMng *ImageMng::s_instance = nullptr;

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}

std::vector<int> ImageMng::GetID(std::string key)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(1);
		imgMap[key][0] = LoadGraph(key.c_str());
	}

	return imgMap[key];
}

std::vector<int> ImageMng::GetID(std::string key, Vector2 divSize, Vector2 divCnt)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(divCnt.x * divCnt.y);
		LoadDivGraph(key.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imgMap[key][0]);
	}
	return imgMap[key];
}
