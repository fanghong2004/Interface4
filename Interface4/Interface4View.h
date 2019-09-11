
// Interface4View.h: CInterface4View 类的接口
//

#pragma once


class CInterface4View : public CView
{
protected: // 仅从序列化创建
	CInterface4View() noexcept;
	DECLARE_DYNCREATE(CInterface4View)

// 特性
public:
	CInterface4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CInterface4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileProperties();
	afx_msg void OnFileOpen();
	afx_msg void On32775();
};

#ifndef _DEBUG  // Interface4View.cpp 中的调试版本
inline CInterface4Doc* CInterface4View::GetDocument() const
   { return reinterpret_cast<CInterface4Doc*>(m_pDocument); }
#endif

