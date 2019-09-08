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
{

}

Time_Setting::~Time_Setting()
{
}

void Time_Setting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Time_Setting, CPropertyPage)
END_MESSAGE_MAP()


// Time_Setting 消息处理程序
