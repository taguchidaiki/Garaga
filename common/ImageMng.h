#pragma once
#include <map>

class ImageMng
{
public:
	ImageMng();
	~ImageMng();

	int GetID(std::string key);

private:
	std::map<std::string, int> imgMap;
};

