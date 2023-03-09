#pragma once


//==================
// 키 입력 관련 def
//==================
enum class KEY {
	LEFT, RIGHT, UP, DOWN,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,

	ALT,
	CTRL,
	LSHIFT,

	ENTER,
	SPACE,
	ESC,

	END,
};

enum class KEY_STATE {
	TAP,
	HOLD,
	AWAY,
	NONE,

	END,
};

struct tKeyInfo {
	KEY_STATE	key_state;
	bool		bPrevPush;
};



//==================
//	 class 선언부
//==================

class CKeyMgr
{
	SINGLE(CKeyMgr)

private:
	vector<tKeyInfo*> m_vecInfo;

public:
	void init();

	void update();

	KEY_STATE GetKeyState(KEY _key);
};

