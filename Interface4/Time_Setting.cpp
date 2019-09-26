// Time_Setting.cpp: 实现文件
//

#include "stdafx.h"
#include "Interface4.h"
#include "Time_Setting.h"
#include "afxdialogex.h"


// Time_Setting 对话框

IMPLEMENT_DYNAMIC(Time_Setting, CPropertyPage)

Time_Setting::Time_Setting()
	: CPropertyPage(IDD_TIME)
	, m_S_Start(0)
	, m_S_End(0)
	, m_O_Start(0)
	, m_O_End(0)
	, SpinYear(0)
	, SpinInterval(0)
	, m_S_StartDate(0)
	, m_S_StartTime(0)
	, m_S_StartMonth(0)
	, m_S_EndMonth(0)
	, m_S_EndDate(0)
	, m_S_EndTime(0)
	, m_O_StartMonth(0)
	, m_O_StartDate(0)
	, m_O_StartTime(0)
	, m_O_EndMonth(0)
	, m_O_EndDate(0)
	, m_O_EndTime(0)
{

}

Time_Setting::~Time_Setting()
{
}

void Time_Setting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_S_START, m_S_Start);
	DDX_Text(pDX, IDC_S_STARTMONTH, m_S_StartMonth);
	DDX_Text(pDX, IDC_S_STARTDATE, m_S_StartDate);
	DDX_Text(pDX, IDC_S_STARTTIME, m_S_StartTime);

	DDX_Text(pDX, IDC_S_END, m_S_End);
	DDX_Text(pDX, IDC_S_ENDMONTH, m_S_EndMonth);
	DDX_Text(pDX, IDC_S_ENDDATE, m_S_EndDate);
	DDX_Text(pDX, IDC_S_ENDTIME, m_S_EndTime);

	DDX_Text(pDX, IDC_O_START, m_O_Start);
	DDX_Text(pDX, IDC_O_END, m_O_End);
	
	DDX_Text(pDX, IDC_O_STARTMONTH, m_O_StartMonth);
	DDX_Text(pDX, IDC_O_STARTDATE, m_O_StartDate);
	DDX_Text(pDX, IDC_O_STARTTIME, m_O_StartTime);
	DDX_Text(pDX, IDC_O_ENDMONTH, m_O_EndMonth);
	DDX_Text(pDX, IDC_O_ENDDATE, m_O_EndDate);
	DDX_Text(pDX, IDC_O_ENDTIME, m_O_EndTime);

	DDX_Text(pDX, IDC_SPINYEAR, SpinYear);
	DDX_Text(pDX, IDC_INTERVAL, SpinInterval);
}


BEGIN_MESSAGE_MAP(Time_Setting, CPropertyPage)
	ON_EN_CHANGE(IDC_S_START, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_STARTMONTH, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_STARTDATE, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_STARTTIME, &Time_Setting::OnChange)

	ON_EN_CHANGE(IDC_S_END, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_ENDMONTH, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_ENDDATE, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_ENDTIME, &Time_Setting::OnChange)

	ON_EN_CHANGE(IDC_O_START, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_STARTMONTH, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_STARTDATE, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_STARTTIME, &Time_Setting::OnChange)

	ON_EN_CHANGE(IDC_O_END, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_ENDMONTH, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_ENDDATE, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_ENDTIME, &Time_Setting::OnChange)

	ON_EN_CHANGE(IDC_SPINYEAR, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_INTERVAL, &Time_Setting::OnChange)
END_MESSAGE_MAP()


// Time_Setting 消息处理程序


void Time_Setting::OnChange()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CPropertyPage::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}
