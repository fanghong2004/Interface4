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
{

}

Time_Setting::~Time_Setting()
{
}

void Time_Setting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_S_START, m_S_Start);
	DDX_Text(pDX, IDC_S_END, m_S_End);
	DDX_Text(pDX, IDC_O_START, m_O_Start);
	DDX_Text(pDX, IDC_O_END, m_O_End);
}


BEGIN_MESSAGE_MAP(Time_Setting, CPropertyPage)
	ON_EN_CHANGE(IDC_S_START, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_S_END, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_START, &Time_Setting::OnChange)
	ON_EN_CHANGE(IDC_O_END, &Time_Setting::OnChange)
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
