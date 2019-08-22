#pragma once
#include "BaseScene.h"
#include <vector>
#include <unit/Obj.h>
#include <Input/KeyState.h>

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();

	unique_Base Update(unique_Base own)override;
	void Draw(void);
	SCN_ID GetScnID(void)override;

private:
	bool Init(void);
	bool AddPlayer();
	bool AddEne(Vector2D endPos, int movTime);
	bool CreateFom();
	
	bool RectVsRect(STATUS stateA, STATUS stateB, bool flagA, bool flagB);
	std::unique_ptr<InputState> _input;

	Vector2D _addPList[6];

	std::pair<Vector2D, int> _endList[40];

	std::vector<shared_Obj> _objList;
	int _count;										//敵のカウンタ
	int _createTimer;								//敵出現用のカウンタ
};

