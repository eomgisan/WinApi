#include "pch.h"
#include "CTimeMgr.h"




void CTimeMgr::init()
{
	QueryPerformanceCounter(&m_llCurCount);
	m_llPrevCount = m_llCurCount;
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	++m_iCallCount;
	m_llPrevCount = m_llCurCount;
	QueryPerformanceCounter(&m_llCurCount);
	m_dDt = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	m_dAcc += m_dDt;
	
	if (m_dAcc >= 1.) {
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;

		m_dAcc = 0.;
	}
	
}


void CTimeMgr::render(const HWND& _hWnd)
{
	wchar_t szBuffer[255] = {};

	swprintf_s(szBuffer, L"FPS : %d", m_iFPS);

	SetWindowText(_hWnd, szBuffer);
}


CTimeMgr::CTimeMgr()
	:	m_iCallCount(0)
	,	m_iFPS(0)
	,	m_dAcc(0.)
	,	m_dDt(0.)
	,	m_llCurCount{}
	,	m_llFrequency{}
	,	m_llPrevCount{}
{}

CTimeMgr::~CTimeMgr()
{
}