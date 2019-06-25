#pragma once
#include <map>
#include <vector>
#include <common/VECTOR2.h>

#define IMAGE_ID(KEY) (ImageMng::GetInstance().GetID(KEY))
#define SET_IMAGE_ID(KEY,F_NAME) (ImageMng::GetInstance().GetID(KEY,F_NAME))

using VecInt = std::vector<int>;

class ImageMng
{
public:
	~ImageMng();

	static ImageMng& GetInstance(void)
	{
		static ImageMng instance;
		return instance;
	}

	static ImageMng& Getinstance(void)
	{
		if (s_instance == nullptr)
		{
			s_instance = new ImageMng();
		}
		return (*s_instance);
	}

	//‰æ‘œˆê–‡“Ç‚İ‚İ—p
	const VecInt& GetID(const std::string &key);
	const VecInt& GetID(const std::string &key, const std::string &fileName);

	//‰æ‘œ•ªŠ„“Ç‚İ‚İ—p
	const VecInt& GetID(const std::string &key, 
						const Vector2 &divSize, const Vector2 &divCnt);
	const VecInt& GetID(const std::string &key, const std::string &fileName, 
						const Vector2 &divSize, const Vector2 &divCnt);

private:
	ImageMng();
	ImageMng(const ImageMng&) {};
	ImageMng& operator=(const ImageMng&) {};

	std::map<std::string, VecInt> imgMap;

	static ImageMng *s_instance;
};

