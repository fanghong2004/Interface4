
// Interface4View.cpp: CInterface4View 类的实现
//

#include "stdafx.h"
#include "CMyPropertySheet.h"
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

	ps.DoModal();
}
