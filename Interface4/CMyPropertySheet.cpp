// CMyPropertySheet.cpp: 实现文件
//

#include "stdafx.h"
#include "Interface4.h"
#include "CMyPropertySheet.h"


// CMyPropertySheet

IMPLEMENT_DYNAMIC(CMyPropertySheet, CPropertySheet)

CMyPropertySheet::CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_fileSetting);
	AddPage(&m_timeSetting);
	AddPage(&m_resultSetting);
}

CMyPropertySheet::CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_fileSetting);
	AddPage(&m_timeSetting);
	AddPage(&m_resultSetting);
}

CMyPropertySheet::~CMyPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CMyPropertySheet, CPropertySheet)
END_MESSAGE_MAP()


// CMyPropertySheet 消息处理程序
