// File_Setting.cpp: 实现文件
//

#include "stdafx.h"
#include "Interface4.h"
#include "File_Setting.h"
#include "afxdialogex.h"


// File_Setting 对话框

IMPLEMENT_DYNAMIC(File_Setting, CPropertyPage)

File_Setting::File_Setting()
	: CPropertyPage()
{

}

File_Setting::~File_Setting()
{
}

void File_Setting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(File_Setting, CPropertyPage)
END_MESSAGE_MAP()


// File_Setting 消息处理程序
