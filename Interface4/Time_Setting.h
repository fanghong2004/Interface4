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
	int SpinYear;
	int SpinInterval;
//	CString m_S_StartMonth;
	int m_S_StartDate;
	int m_S_StartTime;
	int m_S_StartMonth;
//	CString m_S_EndMonth;
	int m_S_EndMonth;
	int m_S_EndDate;
	int m_S_EndTime;
	int m_O_StartMonth;
	int m_O_StartDate;
	int m_O_StartTime;
	int m_O_EndMonth;
	int m_O_EndDate;
	int m_O_EndTime;
};
