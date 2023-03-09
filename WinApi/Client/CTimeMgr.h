#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr)
private:

	// ���� ī��Ʈ
	LARGE_INTEGER	m_llCurCount;

	// ���� ī��Ʈ
	LARGE_INTEGER	m_llPrevCount;

	// �ʴ� ī��Ʈ�� �󸶳� �ö󰡴���
	LARGE_INTEGER	m_llFrequency;

	// ��Ÿ Ÿ��
	double			m_dDt;

	// ��Ÿ Ÿ�� ������ ���� 1�� ���� -> �̸� ���� FPS ���
	double			m_dAcc;

	// ȣ�� Ƚ��
	UINT			m_iCallCount;

	// FPS
	UINT			m_iFPS;


public:
	void init();
	
	void update();

	void render(const HWND& _hWnd);


	const double& GetDT() { return m_dDt; }
};

