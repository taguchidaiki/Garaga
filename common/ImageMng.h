#pragma once
#include <map>
#include <vector>
#include "VECTOR2.h"

#define IMAGE_ID(X) ImageMng::GetInstance().GetID(X)

using VecInt = std::vector<int>;

class ImageMng
{
public:
	~ImageMng();

	static ImageMng&GetInstance(void)
	{
		static ImageMng instance;
		return instance;
	}

	static ImageMng&Getinstance(void)
	{
		if (s_instance == nullptr)
		{
			s_instance = new ImageMng();
		}
		return (*s_instance);
	}

	//‰æ‘œˆê–‡“Ç‚İ‚İ—p
	const VecInt& GetID(std::string key);
	const VecInt& GetID(std::string key, std::string fileName);

	//‰æ‘œ•ªŠ„“Ç‚İ‚İ—p
	const VecInt& GetID(std::string key, Vector2 divSize, Vector2 divCnt);
	const VecInt& GetID(std::string key,std::string fileName, Vector2 divSize, Vector2 divCnt);

private:
	ImageMng();
	ImageMng(const ImageMng&) {};
	ImageMng& operator=(const ImageMng&) {};

	std::map<std::string, VecInt> imgMap;

	static ImageMng *s_instance;
};

