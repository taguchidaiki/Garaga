#ifdef _DEBUG
#include <windows.h>
#include "_DebugConOut.h"

std::unique_ptr<_DebugConOut, _DebugConOut::_DebugConOutDeleter> _DebugConOut::s_Instance(new _DebugConOut);

_DebugConOut::_DebugConOut()
{
	//表示順番の固定
	//HWND hWnd = GetForegroundWindow();				//前にあるウインドウのハンドルを取得

	//コンソール表示用の関数
	AllocConsole();

	//コンソールへの文字の出力
	freopen_s(&_debugFp,"CONOUT$","w",stdout);		//第2 CONOUT$, 第3 "w"writeの略, 第4　stdout

	//コンソールへの文字の入力
	freopen_s(&_debugFp, "CONIN$", "r", stdin);

	//ハンドルの設定
	//SetForegroundWindow(hWnd);
}


_DebugConOut::~_DebugConOut()
{
	//コンソール解放用の関数
	FreeConsole();
}
#endif //_DEBUG