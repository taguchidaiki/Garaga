#include <DxLib.h>
#include "ImageMng.h"

ImageMng *ImageMng::s_instance = nullptr;

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}

const VecInt& ImageMng::GetID(const std::string& key)
{
	GetID(key, key);
	return imgMap[key];
}

//Ç±Ç±ÇÕLoadDivGraphî≈Ç…èëÇ´ä∑Ç¶â¬
const VecInt & ImageMng::GetID(const std::string& key, const std::string& fileName)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(1);
		imgMap[key][0] = LoadGraph(fileName.c_str());
	}
	return imgMap[key];

}

const VecInt& ImageMng::GetID(const std::string& key, const Vector2& divSize, const Vector2& divCnt)
{
	GetID(key, key, divSize, divCnt);
	
	return imgMap[key];
}

const VecInt & ImageMng::GetID(const std::string& key, const std::string& fileName, const Vector2& divSize, const Vector2& divCnt)
{
	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(divCnt.x * divCnt.y);
		LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imgMap[key][0]);
	}
	return imgMap[key];
}
