#ifdef _DEBUG
#include "_DebugGraph.h"
#include <common/SceneMng.h>

std::unique_ptr<_DebugGraph, _DebugGraph::_DebugGraphDeleter>_DebugGraph::s_Instance(new _DebugGraph);

int _DebugGraph::DrawString(int x, int y, const char * String, unsigned int Color, bool InFlag)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	int rtnFlg;
	if (InFlag)
	{
		rtnFlg = DxLib::DrawString(x + lpSceneMng.gameScreenPos.x, y + lpSceneMng.gameScreenPos.y, String, Color);
	}
	else
	{
		rtnFlg = DxLib::DrawString(x, y, String, Color);
	}
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);
	return rtnFlg;
}

int _DebugGraph::DrawPixel(int x, int y, unsigned int Color)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	int rtnFlg = DxLib::DrawPixel(x + lpSceneMng.gameScreenPos.x, y + lpSceneMng.gameScreenPos.y, Color);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);
	return rtnFlg;
}

int _DebugGraph::DrawLine(int x1, int y1, int x2, int y2, unsigned int Color)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	int rtnFlg = DxLib::DrawLine(x1 + lpSceneMng.gameScreenPos.x, y1 + lpSceneMng.gameScreenPos.y,
								  x2 + lpSceneMng.gameScreenPos.x, y2 + lpSceneMng.gameScreenPos.y,
								 Color);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);
	return rtnFlg;
}

int _DebugGraph::DrawBox(int x1, int y1, int x2, int y2, unsigned int Color, int FillFlag)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	int rtnFlg = DxLib::DrawBox(x1 + lpSceneMng.gameScreenPos.x, y1 + lpSceneMng.gameScreenPos.y,
								 x2 + lpSceneMng.gameScreenPos.x, y2 + lpSceneMng.gameScreenPos.y,
								 Color,
								 FillFlag);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);
	return rtnFlg;
}

int _DebugGraph::DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	int rtnFlg = DxLib::DrawCircle(x + lpSceneMng.gameScreenPos.x, y + lpSceneMng.gameScreenPos.y, r, Color, FillFlag);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);
	return rtnFlg;
}

bool _DebugGraph::StartDbgGraph(void)
{
	int ghBuffer;
	ghBuffer = GetDrawScreen();

	SetDrawScreen(_dbScreen);
	ClsDrawScreen();
	SetDrawScreen(ghBuffer);

	return true;
}

bool _DebugGraph::AddDbgScreen(void)
{
	if (CheckHitKey(KEY_INPUT_PGUP))
	{
		_rtnFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_PGDN))
	{
		_rtnFlag = false;
	}
	if (_rtnFlag)
	{
		lpSceneMng.AddDrawQue({ _dbScreen, 0, 0 });
	}
	return true;
}

bool _DebugGraph::SetUpGraph(int alpha)
{
	if (_dbScreen == -1)
	{
		_dbScreen = MakeScreen(lpSceneMng.screenSize.x, lpSceneMng.screenSize.y,true);
	}
	SetAlpha(alpha);

	return true;
}

bool _DebugGraph::SetAlpha(int alpha)
{
	_alpha = alpha;
	return true;
}

_DebugGraph::_DebugGraph()
{
	_dbScreen = -1;
	_rtnFlag = true;
}


_DebugGraph::~_DebugGraph()
{
}

bool _DebugGraph::SetScreen(void)
{
	_ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	return true;
}

bool _DebugGraph::RevScreen(void)
{
	SetDrawScreen(_ghBuffer);
	return true;
}
#endif
