// CMyPropertySheet.cpp: 实现文件
//

#include "stdafx.h"
#include "Interface4.h"
#include "CMyPropertySheet.h"
#include "Time_Setting.h"
#include <stdio.h>


// CMyPropertySheet

IMPLEMENT_DYNAMIC(CMyPropertySheet, CPropertySheet)

CMyPropertySheet::CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	//AddPage(&m_fileSetting);
	AddPage(&m_timeSetting);
	AddPage(&m_resultSetting);
}

CMyPropertySheet::CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	//AddPage(&m_fileSetting);
	AddPage(&m_timeSetting);
	AddPage(&m_resultSetting);
}

CMyPropertySheet::~CMyPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CMyPropertySheet, CPropertySheet)
	ON_BN_CLICKED(ID_APPLY_NOW,OnPageApply)
END_MESSAGE_MAP()


// CMyPropertySheet 消息处理程序
void CMyPropertySheet::OnPageApply()
{
	GetActivePage()->UpdateData(TRUE);
	int Check1 = NULL;
	int Check2 = NULL;
	int Check3 = NULL;
	int Check4 = NULL;
	int Check5 = NULL;
	int Check6 = NULL;

	char buf_SStart[20];
	char buf_SEnd[20];
	char buf_OStart[20];
	char buf_OEnd[20];

	char buf_Check1[5];
	char buf_Check2[5];
	char buf_Check3[5];
	char buf_Check4[5];
	char buf_Check5[5];
	char buf_Check6[5];

	const char* filename = "d:\\file.txt";
	FILE* fp = NULL;
	errno_t err = 0;
	err = fopen_s(&fp, filename, "wb");
	/*if (err == 1)
	{
		MessageBox(TEXT("failed to open file!"));
	}*/
	//int M_S_Start = m_S_Start;
	ELLPROP ep;
	GetParent()->SendMessage(WM_USER_PAGE_APPLY, 0, (LPARAM)&ep);
	ep.nSStart = m_timeSetting.m_S_Start;
	ep.nSEnd = m_timeSetting.m_S_End;
	ep.nOStart= m_timeSetting.m_O_Start;
	ep.nOEnd = m_timeSetting.m_O_End;

	_itoa_s(ep.nSStart, buf_SStart, 10);
	_itoa_s(ep.nSEnd, buf_SEnd, 10);
	_itoa_s(ep.nOStart, buf_OStart, 10);
	_itoa_s(ep.nOEnd, buf_OEnd, 10);

	strcat_s(buf_SStart, ",");
	strcat_s(buf_SEnd, ",");
	strcat_s(buf_OStart, ",");
	strcat_s(buf_OEnd, ",");

	fwrite(buf_SStart, strlen(buf_SStart), 1, fp);
	fwrite(buf_SEnd, strlen(buf_SEnd), 1, fp);
	fwrite(buf_OStart, strlen(buf_OStart), 1, fp);
	fwrite(buf_OEnd, strlen(buf_OEnd), 1, fp);

	if (m_resultSetting.IsDlgButtonChecked(IDC_CHECK1))
	{
		Check1 = 1;
	}

	if (m_resultSetting.IsDlgButtonChecked(IDC_CHECK2))
	{
		Check2 = 1;
	}

	if (m_resultSetting.IsDlgButtonChecked(IDC_CHECK3))
	{
		Check3 = 1;
	}

	if (m_resultSetting.IsDlgButtonChecked(IDC_CHECK4))
	{
		Check4 = 1;
	}

	if (m_resultSetting.IsDlgButtonChecked(IDC_CHECK5))
	{
		Check5 = 1;
	}

	if (m_resultSetting.IsDlgButtonChecked(IDC_CHECK6))
	{
		Check6 = 1;
	}

	_itoa_s(Check1, buf_Check1, 10);
	_itoa_s(Check2, buf_Check2, 10);
	_itoa_s(Check3, buf_Check3, 10);
	_itoa_s(Check4, buf_Check4, 10);
	_itoa_s(Check5, buf_Check5, 10);
	_itoa_s(Check6, buf_Check6, 10);

	strcat_s(buf_Check1, ",");
	strcat_s(buf_Check2, ",");
	strcat_s(buf_Check3, ",");
	strcat_s(buf_Check4, ",");
	strcat_s(buf_Check5, ",");
	strcat_s(buf_Check6, ",");

	fwrite(buf_Check1, strlen(buf_Check1), 1, fp);
	fwrite(buf_Check2, strlen(buf_Check2), 1, fp);
	fwrite(buf_Check3, strlen(buf_Check3), 1, fp);
	fwrite(buf_Check4, strlen(buf_Check4), 1, fp);
	fwrite(buf_Check5, strlen(buf_Check5), 1, fp);
	fwrite(buf_Check6, strlen(buf_Check6), 1, fp);

	m_timeSetting.SetModified(FALSE);
	m_resultSetting.SetModified(FALSE);

	fclose(fp);
	
}