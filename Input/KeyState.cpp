#include "KeyState.h"

KeyState::KeyState()
{
	//try
	//{
	//	FILE *file;
	//	_keyCon.resize(static_cast<size_t>(end(INPUT_ID())));
	//	fopen_s(&file,"data/key.dat","rb");
	//	fread(&_keyCon[0], sizeof(_keyCon[0]), _keyCon.size(), file);
	//	fclose(file);
	//}
	//catch(...)
	//{
	//	for (auto key : _keyTbl)
	//	{
	//		_keyCon.emplace_back(key);
	//	}
	//}
	_keyConDef.reserve(static_cast<size_t>(end(INPUT_ID())));
	for (auto key : _keyTbl)
	{
		_keyConDef.emplace_back(key);
	}

	FILE* file;
	fopen_s(&file, "data/key.dat", "rb");
	if (file == nullptr)
	{
		_keyCon = _keyConDef;
	}
	else
	{
		_keyCon.resize(static_cast<size_t>(end(INPUT_ID())));
		//読み込み処理
		fread(_keyCon.data(), _keyCon.size() * sizeof(_keyCon[0]), 1, file);
		fclose(file);
	}
	

	func = &KeyState::RefKeyData;
	
}


KeyState::~KeyState()
{
}

void KeyState::Update(void)
{
	SetOld();
	GetHitKeyStateAll(_buf);
	(this->*func)();

}

void KeyState::RefKeyData(void)
{
	if (_buf[KEY_INPUT_F1])
	{
		_confID = begin(INPUT_ID());
		TRACE("キーコンフィグモード\n");
		TRACE("設定キー%d\n", _confID);
		func = &KeyState::SetKeyConfig;
	}

	for (auto key : INPUT_ID())
	{
		state(key, _buf[_keyCon[static_cast<int>(key)]]);
	}
	/*state(INPUT_ID::LEFT, _buf[KEY_INPUT_LEFT]);
	state(INPUT_ID::RIGHT, _buf[KEY_INPUT_RIGHT]);
	state(INPUT_ID::UP, _buf[KEY_INPUT_UP]);
	state(INPUT_ID::DOWN, _buf[KEY_INPUT_DOWN]);*/
}

void KeyState::SetKeyConfig(void)
{
	for (auto key : INPUT_ID())
	{
		state(key, 0);
	}

	for (int key = 0; key < sizeof(_buf)/sizeof(_buf[0]); key++)
	{
		if ((_buf[key]) && (_lastKeyID != key) && (key != KEY_INPUT_F1) && (key != KEY_INPUT_DELETE))
		{
			_keyCon[static_cast<int>(_confID)] = key;
			_lastKeyID = key;
			++_confID;
			TRACE("設定キー%d\n", _confID);
			if (_confID == end(INPUT_ID()))
			{
				/*try
				{
					FILE *file;
					fopen_s(&file,"data/key.dat","wb");
					t = _keyCon[0];
					fwrite(&_keyCon[0],sizeof(_keyCon[0]),_keyCon.size(),file);
					fclose(file);
					
				}
				catch(...)
				{
					for (auto key : _keyTbl)
					{
						_keyCon.emplace_back(key);
					}
				}*/
				FILE* file;
				fopen_s(&file, "data/key.dat", "wb");
				if (file == nullptr)
				{
					TRACE("保存に失敗しました\n");
				}
				else
				{
					fwrite(_keyCon.data()/*配列の先頭へのポインタ*/,
						   _keyCon.size() * sizeof(_keyCon[0])/*データの総要素数*/, 
						   1, 
						   file);
					//こちらも上と同じ意味を持つ
					//fwrite(_keyCon.data, sizeof(_keyCon[0]), _keyCon.size(), file);
					fclose(file);
				}

				TRACE("キーコンフィグ終了\n");
				func = &KeyState::RefKeyData;
			}
			break;
		}
	}
}
