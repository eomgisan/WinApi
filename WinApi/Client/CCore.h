#pragma once
class CCore
{
	SINGLE(CCore)

private:
	HWND	m_hWnd;			// 메인 윈도우 핸들러
	HDC		m_hDc;			// 메인 DC
	POINT	m_ptResolution;	// 해상도

	HBITMAP	m_hBit;
	HDC		m_memDc;

public:
	int init(HWND _hWnd, POINT _ptResolution);
	HWND	GetHwnd() { return m_hWnd; }

private:
	void update();
	void render();

public:
	void process();


};

