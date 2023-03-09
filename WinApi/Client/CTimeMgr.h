#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr)
private:

	// 현재 카운트
	LARGE_INTEGER	m_llCurCount;

	// 이전 카운트
	LARGE_INTEGER	m_llPrevCount;

	// 초당 카운트가 얼마나 올라가는지
	LARGE_INTEGER	m_llFrequency;

	// 델타 타임
	double			m_dDt;

	// 델타 타임 누적을 통한 1초 세기 -> 이를 통해 FPS 계산
	double			m_dAcc;

	// 호출 횟수
	UINT			m_iCallCount;

	// FPS
	UINT			m_iFPS;


public:
	void init();
	
	void update();

	void render(const HWND& _hWnd);


	const double& GetDT() { return m_dDt; }
};

