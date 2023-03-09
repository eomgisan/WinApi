#pragma once

#define SINGLE(type) public: static type* GetInstance(){static type mgr; return &mgr;} private: type(); ~type();

#define DT CTimeMgr::GetInstance()->GetDT();





enum class OBJ_GROUP {
	PLAYER,
	ENEMY,
	EFFECT,
	END,
};