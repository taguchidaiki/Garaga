#pragma once
#ifdef _DEBUG
#include <memory>
#include <common/VECTOR2.h>


class _DebugGraph
{
public:
	static _DebugGraph& GetInstance(void)
	{
		return (*s_Instance);
	}

	void _debugDrawPixel(Vector2 pos, int color);

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

	static std::unique_ptr<_DebugGraph,_DebugGraph::_DebugGraphDeleter> s_Instance;
};
#else
#endif

