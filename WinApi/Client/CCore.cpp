#include "pch.h"
#include "CCore.h"


CCore::CCore() 
	:	m_hWnd(0)
	,	m_hDc(0)
	,	m_ptResolution{}
	,	m_hBit(0)
	,	m_memDc(0)
{
}

CCore::~CCore() {
	ReleaseDC(m_hWnd, m_hDc);

	DeleteDC(m_memDc);
	DeleteObject(m_hBit);
}



int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 필요한 창크기
	RECT rt = { 0,0,_ptResolution.x, _ptResolution.y };

	// 창 크기 적용
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);

	// 창 위치 적용
	SetWindowPos(_hWnd, nullptr, 100, 10, rt.right - rt.left, rt.bottom - rt.top, 0);

	// DC 생성
	m_hDc = GetDC(m_hWnd);


	// 더블 버퍼링 용도의 비트맵과 dc를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDc, m_ptResolution.x, m_ptResolution.y);
	m_memDc = CreateCompatibleDC(m_hDc);

	// 비트멤의 dc 바꾸기
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDc, m_hBit);
	DeleteObject(hOldBit);

	

	// ========================
	//		Manger 초기화
	// ========================

	

	return S_OK;
}

void CCore::process()
{
	update();


	render();
}


void CCore::update()
{
	int a = 0;
}

void CCore::render()
{
	int b = 0;
}