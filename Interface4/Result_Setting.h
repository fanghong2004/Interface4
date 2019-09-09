#pragma once


// Result_Setting 对话框

class Result_Setting : public CPropertyPage
{
	DECLARE_DYNAMIC(Result_Setting)

public:
	Result_Setting();
	virtual ~Result_Setting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChange();
};
