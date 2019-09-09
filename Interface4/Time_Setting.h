#pragma once


// Time_Setting 对话框

class Time_Setting : public CPropertyPage
{
	DECLARE_DYNAMIC(Time_Setting)

public:
	Time_Setting();
	virtual ~Time_Setting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIME};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_S_Start;
	int m_S_End;
	int m_O_Start;
	int m_O_End;
	afx_msg void OnChange();
};
