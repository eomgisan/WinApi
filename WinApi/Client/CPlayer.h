#pragma once
#include "CObject.h"
class CPlayer :
    public CObject
{
private:

public:

	virtual void update();
	virtual void render(HDC _hDc);

public:
	CPlayer();
	virtual ~CPlayer();
};

