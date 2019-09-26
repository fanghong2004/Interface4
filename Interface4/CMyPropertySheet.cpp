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
	char buf_SStartMonth[20];
	char buf_SStartDate[20];
	char buf_SStartTime[20];

	char buf_SEnd[20];
	char buf_SEndMonth[20];
	char buf_SEndDate[20];
	char buf_SEndTime[20];

	char buf_OStart[20];
	char buf_OStartMonth[20];
	char buf_OStartDate[20];
	char buf_OStartTime[20];

	char buf_OEnd[20];
	char buf_OEndMonth[20];
	char buf_OEndDate[20];
	char buf_OEndTime[20];

	char buf_SpinYear[5];
	char buf_SpinInterval[5];

	char buf_Check1[5];
	char buf_Check2[5];
	char buf_Check3[5];
	char buf_Check4[5];
	char buf_Check5[5];
	char buf_Check6[5];

	const char* filename = "c:\\file1.txt";
	FILE* fp = NULL;
	errno_t err = 0;
	err = fopen_s(&fp, filename, "wb");
	/*if (err == 0)
	{
		MessageBox(TEXT("failed to open file!"));
	}*/
	ELLPROP ep;
	GetParent()->SendMessage(WM_USER_PAGE_APPLY, 0, (LPARAM)&ep);
	ep.nSStart = m_timeSetting.m_S_Start;
	ep.nSStartMonth = m_timeSetting.m_S_StartMonth;
	ep.nSStartDate = m_timeSetting.m_S_StartDate;
	ep.nSStartTime = m_timeSetting.m_S_StartTime;

	ep.nSEnd = m_timeSetting.m_S_End;
	ep.nSEndMonth = m_timeSetting.m_S_EndMonth;
	ep.nSEndDate = m_timeSetting.m_S_EndDate;
	ep.nSEndTime = m_timeSetting.m_S_EndTime;

	ep.nOStart= m_timeSetting.m_O_Start;
	ep.nOStartMonth = m_timeSetting.m_O_StartMonth;
	ep.nOStartDate = m_timeSetting.m_O_StartDate;
	ep.nOStartTime = m_timeSetting.m_O_StartTime;

	ep.nOEnd = m_timeSetting.m_O_End;
	ep.nOEndMonth = m_timeSetting.m_O_EndMonth;
	ep.nOEndDate = m_timeSetting.m_O_EndDate;
	ep.nOEndTime = m_timeSetting.m_O_EndTime;

	ep.nSpinYear = m_timeSetting.SpinYear;
	ep.nSpinInterval = m_timeSetting.SpinInterval;

	_itoa_s(ep.nSStart, buf_SStart, 10);
	_itoa_s(ep.nSStartMonth, buf_SStartMonth, 10);
	_itoa_s(ep.nSStartDate, buf_SStartDate, 10);
	_itoa_s(ep.nSStartTime, buf_SStartTime, 10);

	_itoa_s(ep.nSEnd, buf_SEnd, 10);
	_itoa_s(ep.nSEndMonth, buf_SEndMonth, 10);
	_itoa_s(ep.nSEndDate, buf_SEndDate, 10);
	_itoa_s(ep.nSEndTime, buf_SEndTime, 10);

	_itoa_s(ep.nOStart, buf_OStart, 10);
	_itoa_s(ep.nOStartMonth, buf_OStartMonth, 10);
	_itoa_s(ep.nOStartDate, buf_OStartDate, 10);
	_itoa_s(ep.nOStartTime, buf_OStartTime, 10);

	_itoa_s(ep.nOEnd, buf_OEnd, 10);
	_itoa_s(ep.nOEndMonth, buf_OEndMonth, 10);
	_itoa_s(ep.nOEndDate, buf_OEndDate, 10);
	_itoa_s(ep.nOEndTime, buf_OEndTime, 10);

	_itoa_s(ep.nSpinYear, buf_SpinYear, 10);
	_itoa_s(ep.nSpinInterval, buf_SpinInterval, 10);

	/*strcat_s(buf_SStart, ",");
	strcat_s(buf_SEnd, ",");
	strcat_s(buf_OStart, ",");
	strcat_s(buf_OEnd, ",");*/

	fprintf(fp, "%s\r\n", buf_SStart);
	fprintf(fp, "%s\r\n", buf_SStartMonth);
	fprintf(fp, "%s\r\n", buf_SStartDate);
	fprintf(fp, "%s\r\n", buf_SStartTime);

	fprintf(fp, "%s\r\n", buf_SEnd);
	fprintf(fp, "%s\r\n", buf_SEndMonth);
	fprintf(fp, "%s\r\n", buf_SEndDate);
	fprintf(fp, "%s\r\n", buf_SEndTime);

	fprintf(fp, "%s\r\n", buf_OStart);
	fprintf(fp, "%s\r\n", buf_OStartMonth);
	fprintf(fp, "%s\r\n", buf_OStartDate);
	fprintf(fp, "%s\r\n", buf_OStartTime);

	fprintf(fp, "%s\r\n", buf_OEnd);
	fprintf(fp, "%s\r\n", buf_OEndMonth);
	fprintf(fp, "%s\r\n", buf_OEndDate);
	fprintf(fp, "%s\r\n", buf_OEndTime);

	fprintf(fp, "%s\r\n", buf_SpinYear);
	fprintf(fp, "%s\r\n", buf_SpinInterval);
	/*fwrite(buf_SStart, strlen(buf_SStart), 1, fp);
	fwrite(buf_SEnd, strlen(buf_SEnd), 1, fp);
	fwrite(buf_OStart, strlen(buf_OStart), 1, fp);
	fwrite(buf_OEnd, strlen(buf_OEnd), 1, fp);*/

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

	/*_itoa_s(Check1, buf_Check1, 10);
	_itoa_s(Check2, buf_Check2, 10);
	_itoa_s(Check3, buf_Check3, 10);
	_itoa_s(Check4, buf_Check4, 10);
	_itoa_s(Check5, buf_Check5, 10);
	_itoa_s(Check6, buf_Check6, 10);*/

	/*fwrite(buf_Check1, strlen(buf_Check1), 1, fp);
	fwrite(buf_Check2, strlen(buf_Check2), 1, fp);
	fwrite(buf_Check3, strlen(buf_Check3), 1, fp);
	fwrite(buf_Check4, strlen(buf_Check4), 1, fp);
	fwrite(buf_Check5, strlen(buf_Check5), 1, fp);
	fwrite(buf_Check6, strlen(buf_Check6), 1, fp);*/

	fprintf(fp, "%d\r\n", Check1);
	fprintf(fp, "%d\r\n", Check2);
	fprintf(fp, "%d\r\n", Check3);
	fprintf(fp, "%d\r\n", Check4);
	fprintf(fp, "%d\r\n", Check5);
	fprintf(fp, "%d\r\n", Check6);

	m_timeSetting.SetModified(FALSE);
	m_resultSetting.SetModified(FALSE);

	
	fclose(fp);

	
	
}