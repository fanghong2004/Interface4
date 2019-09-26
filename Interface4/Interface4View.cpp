
// Interface4View.cpp: CInterface4View 类的实现
//

#include "stdafx.h"
#include "CMyPropertySheet.h"
#include "CString"
#include "PIFS.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Interface4.h"
#endif

#include "Interface4Doc.h"
#include "Interface4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInterface4View

IMPLEMENT_DYNCREATE(CInterface4View, CView)

BEGIN_MESSAGE_MAP(CInterface4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PROPERTIES, &CInterface4View::OnFileProperties)
	ON_COMMAND(ID_IMPORT, &CInterface4View::OnFileOpen)
	ON_COMMAND(ID_32775, &CInterface4View::On32775)
	ON_COMMAND(ID_32776, &CInterface4View::On32776)
	ON_COMMAND(ID_32780, &CInterface4View::On32780)
	ON_COMMAND(ID_32777, &CInterface4View::On32777)
	ON_COMMAND(ID_32778, &CInterface4View::On32778)
	ON_COMMAND(ID_32779, &CInterface4View::On32779)
END_MESSAGE_MAP()

// CInterface4View 构造/析构

CInterface4View::CInterface4View() noexcept
{
	// TODO: 在此处添加构造代码

}

CInterface4View::~CInterface4View()
{
}

BOOL CInterface4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CInterface4View 绘图

void CInterface4View::OnDraw(CDC* /*pDC*/)
{
	CInterface4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CInterface4View 打印

BOOL CInterface4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CInterface4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CInterface4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CInterface4View 诊断

#ifdef _DEBUG
void CInterface4View::AssertValid() const
{
	CView::AssertValid();
}

void CInterface4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInterface4Doc* CInterface4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInterface4Doc)));
	return (CInterface4Doc*)m_pDocument;
}
#endif //_DEBUG


// CInterface4View 消息处理程序


void CInterface4View::OnFileProperties()
{
	// TODO: 在此添加命令处理程序代码
	CMyPropertySheet ps(TEXT("参数设置"));
	ps.m_timeSetting.m_S_Start = 1960;
	ps.m_timeSetting.m_S_StartMonth = 1;
	ps.m_timeSetting.m_S_StartDate = 1;
	ps.m_timeSetting.m_S_StartTime = 1;

	ps.m_timeSetting.m_S_End = 1972;
	ps.m_timeSetting.m_S_EndMonth = 12;
	ps.m_timeSetting.m_S_EndDate = 31;
	ps.m_timeSetting.m_S_EndTime = 24;

	ps.m_timeSetting.m_O_Start = 1962;
	ps.m_timeSetting.m_O_StartMonth = 1;
	ps.m_timeSetting.m_O_StartDate = 1;
	ps.m_timeSetting.m_O_StartTime = 1;

	ps.m_timeSetting.m_O_End = 1963;
	ps.m_timeSetting.m_O_EndMonth = 12;
	ps.m_timeSetting.m_O_EndDate = 31;
	ps.m_timeSetting.m_O_EndTime = 24;

	ps.m_timeSetting.SpinYear = 0;
	ps.m_timeSetting.SpinInterval = 6;

	/*if(ps.DoModal()==IDOK);
	{
		WinExec("c:\\TestEXE.exe", SW_SHOW);
	}*/
	ps.DoModal() == IDOK;
}



void CInterface4View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, _T("文本文件(*.txt)|*.*"), this);
	/*CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,Interface4View, this);*/
	
	if (dlg.DoModal() == IDOK)
	{
		//MessageBox(dlg.GetPathName());
		CString strText;
		/*TCHAR exepath[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, exepath, MAX_PATH);*/
		strText = dlg.GetPathName();
		//MessageBox(strText);
		strText = strText.Left(strText.ReverseFind('\\'));
		//MessageBox(strText);
		//strText = strText.Left(strText.ReverseFind('\\'));
		//MessageBox(strText);
		strText += _T("\\");
		//strText += _T("db");
		//MessageBox(strText);

		const char* filename = "c:\\file2.txt";
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, filename, "wb");

		fwrite(strText, (strText.GetLength() + 1) * 2, 1, fp);
		fclose(fp);

	}
	
}


void CInterface4View::On32775()
{
	// TODO: 在此添加命令处理程序代码

	WinExec("c:\\Users\\PC\\Desktop\\Test\\TestEXE.exe", SW_SHOW);
}


void CInterface4View::On32776()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, _T("文本文件(*.txt)|*.*"), this);

	if (dlg.DoModal() == IDOK)
	{
		CString strText;
		CString strTextOut;

		strText = dlg.GetPathName();
		strTextOut = strText.Left(strText.ReverseFind('\\'));

		strTextOut += _T("\\");
		strTextOut = strTextOut + _T("xf.resample_fill");

		const char* filename = "c:\\file3.txt";
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, filename, "wb");

		char strText_ansi[120];
		char strTextOut_ansi[120];
		sprintf_s(strText_ansi,"%S", strText);
		sprintf_s(strTextOut_ansi,"%S", strTextOut);
		fwrite(strText_ansi, 120, 1, fp);
		fwrite("\r\n", 1, 2, fp);
		fwrite(strTextOut_ansi, 120, 1, fp);
		

		fclose(fp);

		WinExec("c:\\Users\\PC\\Desktop\\Test\\Create_East_Windows.exe", SW_SHOW);
	}
}


void CInterface4View::On32780()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, _T("文本文件(*.txt)|*.*"), this);

	if (dlg.DoModal() == IDOK)
	{
		CString strText;
		CString strTextOut;
		strText = dlg.GetPathName();
		strTextOut = strText.Left(strText.ReverseFind('\\'));
		/*strTextOut = strText.Left(strText.ReverseFind('\\'));*/
		strTextOut += _T("\\");
		strTextOut = strTextOut + _T("xf.east");

		const char* filename = "c:\\file4.txt";
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, filename, "wb");

		char strText_ansi[120];
		char strTextOut_ansi[120];
		sprintf_s(strText_ansi, "%S", strText);
		sprintf_s(strTextOut_ansi, "%S", strTextOut);
		fwrite(strText_ansi, 120, 1, fp);
		fwrite("\r\n", 1, 2, fp);
		fwrite(strTextOut_ansi, 120, 1, fp);


		fclose(fp);

		WinExec("c:\\Users\\PC\\Desktop\\Test\\Create_East_Windows.exe", SW_SHOW);
	}
}


void CInterface4View::On32777()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, _T("文本文件(*.txt)|*.*"), this);

	if (dlg.DoModal() == IDOK)
	{
		CString strText;
		CString strTextOut;
		strText = dlg.GetPathName();

		const char* filename = "c:\\file5.txt";
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, filename, "wb");

		char strText_ansi[120];
		char strTextOut_ansi[120];
		sprintf_s(strText_ansi, "%S", strText);
		sprintf_s(strTextOut_ansi, "%S", strTextOut);
		fwrite(strText_ansi, 120, 1, fp);
		fwrite("\r\n", 1, 2, fp);
		fwrite(strTextOut_ansi, 120, 1, fp);


		fclose(fp);

		WinExec("c:\\Users\\PC\\Desktop\\Test\\Create_East_Windows.exe", SW_SHOW);
	}
}


void CInterface4View::On32778()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, _T("文本文件(*.txt)|*.*"), this);

	if (dlg.DoModal() == IDOK)
	{
		CString strText;
		CString strTextOut;
		strText = dlg.GetPathName();

		const char* filename = "c:\\file6.txt";
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, filename, "wb");

		char strText_ansi[120];
		char strTextOut_ansi[120];
		sprintf_s(strText_ansi, "%S", strText);
		sprintf_s(strTextOut_ansi, "%S", strTextOut);
		fwrite(strText_ansi, 120, 1, fp);
		fwrite("\r\n", 1, 2, fp);
		fwrite(strTextOut_ansi, 120, 1, fp);


		fclose(fp);

		WinExec("c:\\Users\\PC\\Desktop\\Test\\Create_East_Windows.exe", SW_SHOW);
	}
}


void CInterface4View::On32779()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, _T("文本文件(*.txt)|*.*"), this);

	if (dlg.DoModal() == IDOK)
	{
		CString strText;
		CString strTextOut;
		strText = dlg.GetPathName();
		
		const char* filename = "c:\\file7.txt";
		FILE* fp = NULL;
		errno_t err = 0;
		err = fopen_s(&fp, filename, "wb");

		char strText_ansi[120];
		char strTextOut_ansi[120];
		sprintf_s(strText_ansi, "%S", strText);
		sprintf_s(strTextOut_ansi, "%S", strTextOut);
		fwrite(strText_ansi, 120, 1, fp);
		fwrite("\r\n", 1, 2, fp);
		fwrite(strTextOut_ansi, 120, 1, fp);


		fclose(fp);

		WinExec("c:\\Users\\PC\\Desktop\\Test\\Create_East_Windows.exe", SW_SHOW);
	}
}
