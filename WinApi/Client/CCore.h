#pragma once
class CCore
{
	SINGLE(CCore)

private:
	HWND	m_hWnd;			// ���� ������ �ڵ鷯
	HDC		m_hDc;			// ���� DC
	POINT	m_ptResolution;	// �ػ�

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

