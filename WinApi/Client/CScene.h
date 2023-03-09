#pragma once


class CObject;


class CScene
{
private:
	wstring				m_strStageName;
	vector<CObject*>	m_vObject[(UINT)OBJ_GROUP::END];

public:

	virtual void SceneEnter() = 0;
	virtual void SceneExit();

	virtual void update();
	virtual void render(HDC _hDc);


	CScene();
	virtual ~CScene();

};

