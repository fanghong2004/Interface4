// PIFS.cpp: 实现文件
//

#include "stdafx.h"
#include "Interface4.h"
#include "PIFS.h"
#include "afxdialogex.h"


// PIFS 对话框

IMPLEMENT_DYNAMIC(PIFS, CDialogEx)

PIFS::PIFS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PIFS, pParent)
{

}

PIFS::~PIFS()
{
}

void PIFS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PIFS, CDialogEx)
END_MESSAGE_MAP()


// PIFS 消息处理程序
