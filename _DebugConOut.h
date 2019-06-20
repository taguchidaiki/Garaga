#pragma once
#ifdef _DEBUG
#include <memory>

#define TRACE(fmt, ...) printf(fmt, __VA_ARGS__)

class _DebugConOut
{
public:

	static _DebugConOut&GetInstance(void)
	{
		return (*s_Instance);
	}

	
private:
	struct _DebugConOutDeleter 
	{
		//�����Ŋ֐��̌Ăяo��������
		void operator()(_DebugConOut* debugConOut)const
		{
			delete debugConOut;
		}
	};

	_DebugConOut();
	~_DebugConOut();

	//static _DebugConOut *s_Instance;
	static std::unique_ptr<_DebugConOut, _DebugConOutDeleter> s_Instance;

	FILE* _debugFp = nullptr;					//�f�o�b�N�p�̃t�@�C���̃|�C���^
};
#else
#define TRACE(fmt, ...)
#endif //_DEBUG