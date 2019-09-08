#pragma once


// File_Setting 对话框

class File_Setting : public CPropertyPage
{
	DECLARE_DYNAMIC(File_Setting)

public:
	File_Setting();
	virtual ~File_Setting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILE};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
