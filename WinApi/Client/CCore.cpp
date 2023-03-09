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

	// �ʿ��� âũ��
	RECT rt = { 0,0,_ptResolution.x, _ptResolution.y };

	// â ũ�� ����
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);

	// â ��ġ ����
	SetWindowPos(_hWnd, nullptr, 100, 10, rt.right - rt.left, rt.bottom - rt.top, 0);

	// DC ����
	m_hDc = GetDC(m_hWnd);


	// ���� ���۸� �뵵�� ��Ʈ�ʰ� dc�� �����.
	m_hBit = CreateCompatibleBitmap(m_hDc, m_ptResolution.x, m_ptResolution.y);
	m_memDc = CreateCompatibleDC(m_hDc);

	// ��Ʈ���� dc �ٲٱ�
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDc, m_hBit);
	DeleteObject(hOldBit);

	

	// ========================
	//		Manger �ʱ�ȭ
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