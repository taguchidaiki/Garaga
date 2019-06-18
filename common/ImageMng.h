#pragma once
#include <map>
#include <vector>
#include "VECTOR2.h"

#define IMAGE_ID(X) ImageMng::GetInstance().GetID(X)

class ImageMng
{
public:
	~ImageMng();

	static ImageMng&GetInstance(void)
	{
		static ImageMng instance;
		return instance;
	}

	std::vector<int> GetID(std::string key);
	std::vector<int> GetID(std::string key, Vector2 divSize, Vector2 divCnt);

private:
	ImageMng();
	ImageMng(const ImageMng&) {};
	ImageMng& operator=(const ImageMng&) {};

	std::map<std::string, std::vector<int>> imgMap;
};

