#pragma once
#ifdef _DEBUG
#include <memory>
#include <common/VECTOR2.h>

//Draw�֐��Q
#define _dbgDrawPixel(fmt, ...) _DebugGraph::GetInstance().DrawPixel(fmt, __VA_ARGS__);
#define _dbgDrawBox(fmt, ...) _DebugGraph::GetInstance().DrawBox(fmt, __VA_ARGS__);

//_DebugGraph�ݒ�֐��Q
#define _dbgStartGraph		_DebugGraph::GetInstance().StartDbgGraph();
#define _dbgAddScreen		_DebugGraph::GetInstance().AddDbgScreen();
#define _dbgSetUpGraph(A)	_DebugGraph::GetInstance().SetUpGraph(A);
#define _dbgSetAlpha(A)		_DebugGraph::GetInstance().SetAlpha(A);

class _DebugGraph
{
public:
	static _DebugGraph& GetInstance(void)
	{
		return (*s_Instance);
	}

	int DrawPixel(int x, int y, unsigned int Color);
	int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color);
	int DrawBox(int x1, int y1, int x2, int y2, unsigned int Color, int FillFlag);
	int DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag);
	
	bool StartDbgGraph(void);
	bool AddDbgScreen(void);
	bool SetUpGraph(int alpha);
	bool SetAlpha(int alpha);


private:
	struct _DebugGraphDeleter
	{
		void operator()(_DebugGraph* _debugGraph)const
		{
			delete _debugGraph;
		}
	};

	_DebugGraph();
	~_DebugGraph();

	int _alpha;
	int _dbScreen;
	bool _rtnFlag;

	static std::unique_ptr<_DebugGraph,_DebugGraph::_DebugGraphDeleter> s_Instance;
};
#else
#define _dbgDrawPixel(fmt, ...)
#define _dbgDrawBox(fmt, ...)

#define _dbgStartGraph
#define _dbgAddScreen
#define _dbgSetUpGraph(A)
#define _dbgSetAlpha(A)
#endif

