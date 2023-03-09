#pragma once
#include "CScene.h"
class CSceneFightStage :
    public CScene
{
private:


public:
	virtual void SceneEnter();
	virtual void SceneExit();

	virtual void update();
	virtual void render(HDC _hDc);


	CSceneFightStage();
	virtual ~CSceneFightStage();
};

