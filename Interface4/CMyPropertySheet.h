#pragma once

#include "File_Setting.h"
#include "Time_Setting.h"
#include "Result_Setting.h"

// CMyPropertySheet

class CMyPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMyPropertySheet)
public:
	File_Setting m_fileSetting;
	Time_Setting m_timeSetting;
	Result_Setting m_resultSetting;

public:
	CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	virtual ~CMyPropertySheet();

protected:
	DECLARE_MESSAGE_MAP()
};


