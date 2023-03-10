#include "pch.h"
#include "CKeyMgr.h"
#include "CCore.h"
#include "CTimeMgr.h"


int g_arrVK[(int)KEY::END] = {
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	'Q',	'W',	'E',	'R',	'T',	'Y',	'U',	'I',	'O',	'P',
	'A',	'S',	'D',	'F',	'G',	'H',	'J',	'K',	'L',
	'Z',	'X',	'C',	'V',	'B',	'N',	'M',

	VK_MENU,	// alt
	VK_CONTROL, // ctl
	VK_LSHIFT,

	VK_RETURN,	// enter
	VK_SPACE,
	VK_ESCAPE	// esc
};

KEY_STATE CKeyMgr::GetKeyState(KEY _key)
{
	return m_vecInfo[(UINT)_key]->key_state;
}


void CKeyMgr::init()
{
	for (UINT i = 0; i < (UINT)KEY::END; ++i) {
		tKeyInfo* temp = new tKeyInfo;
		temp->dHoldTime = 0.;
		temp->key_state = KEY_STATE::NONE;
		m_vecInfo.push_back(temp);
	}
}

void CKeyMgr::update()
{
	HWND hWndMain = CCore::GetInstance()->GetHwnd();

	HWND hWndFocus = GetFocus();

	if (hWndMain == hWndFocus) {
		// 프로그램이 포커싱일 경우

		for (UINT i = 0; i < (UINT)KEY::END; ++i) {
			
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000) {
				// 눌렸을 경우
				if (m_vecInfo[i]->dHoldTime >= 1. && m_vecInfo[i]->key_state == KEY_STATE::TAP) {
   					m_vecInfo[i]->key_state = KEY_STATE::HOLD;
				}
				else {
					m_vecInfo[i]->key_state = KEY_STATE::TAP;
				}
				
				m_vecInfo[i]->dHoldTime += DT;
			}
			else {
				// 안눌렸을 경우
				if (m_vecInfo[i]->key_state == KEY_STATE::HOLD || m_vecInfo[i]->key_state == KEY_STATE::TAP) {
					m_vecInfo[i]->key_state = KEY_STATE::AWAY;
				}
				else {
					m_vecInfo[i]->key_state = KEY_STATE::NONE;
				}

				m_vecInfo[i]->dHoldTime = 0.;
			}
		}
	}
	else {
		for (int i = 0; i < (int)KEY::END; ++i) {
			m_vecInfo[i]->dHoldTime = 0.;
			if (m_vecInfo[i]->key_state == KEY_STATE::TAP || m_vecInfo[i]->key_state == KEY_STATE::HOLD) {
				m_vecInfo[i]->key_state = KEY_STATE::AWAY;
			}
			else if (m_vecInfo[i]->key_state == KEY_STATE::AWAY) {
				m_vecInfo[i]->key_state = KEY_STATE::NONE;
			}
		}
	}
}

CKeyMgr::CKeyMgr() 
{
}
CKeyMgr::~CKeyMgr() 
{
	Safe_Delete_Vector(m_vecInfo);
}