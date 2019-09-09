// Result_Setting.cpp: 实现文件
//

#include "stdafx.h"
#include "Interface4.h"
#include "Result_Setting.h"
#include "afxdialogex.h"


// Result_Setting 对话框

IMPLEMENT_DYNAMIC(Result_Setting, CPropertyPage)

Result_Setting::Result_Setting()
	: CPropertyPage(IDD_RESULT)
{

}

Result_Setting::~Result_Setting()
{
}

void Result_Setting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Result_Setting, CPropertyPage)
	ON_BN_CLICKED(IDC_CHECK1, &Result_Setting::OnChange)
	ON_BN_CLICKED(IDC_CHECK2, &Result_Setting::OnChange)
	ON_BN_CLICKED(IDC_CHECK3, &Result_Setting::OnChange)
	ON_BN_CLICKED(IDC_CHECK4, &Result_Setting::OnChange)
	ON_BN_CLICKED(IDC_CHECK5, &Result_Setting::OnChange)
	ON_BN_CLICKED(IDC_CHECK6, &Result_Setting::OnChange)
END_MESSAGE_MAP()


// Result_Setting 消息处理程序


void Result_Setting::OnChange()
{
	// TODO: 在此添加控件通知处理程序代码
	SetModified(TRUE);
}





