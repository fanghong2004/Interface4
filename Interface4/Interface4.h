﻿
// Interface4.h: Interface4 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CInterface4App:
// 有关此类的实现，请参阅 Interface4.cpp
//

class CInterface4App : public CWinApp
{
public:
	CInterface4App() noexcept;


protected:
	int m_S_Start;
	int m_S_End;
	int m_O_Start;
	int m_O_End;

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInterface4App theApp;
