#include "pch.h"
#include "CScene.h"

void CScene::SceneExit()
{
	for (UINT i = 0; i < (UINT)OBJ_GROUP::END; ++i) {
		Safe_Delete_Vector(m_vObject[i]);
	}
	m_vObject->clear();
}

CScene::CScene()
	:	m_strStageName()
	,	 m_vObject{}
{
}

CScene::~CScene()
{
}
