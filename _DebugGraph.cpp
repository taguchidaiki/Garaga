#ifdef _DEBUG
#include "_DebugGraph.h"

std::unique_ptr<_DebugGraph, _DebugGraph::_DebugGraphDeleter>_DebugGraph::s_Instance(new _DebugGraph);

_DebugGraph::_DebugGraph()
{
}


_DebugGraph::~_DebugGraph()
{
}
#endif
