
// MFCApp2View.h: интерфейс класса CMFCApp2View
//

#pragma once

constexpr UINT IDC_EDIT_MODE_SWITHC_BUTTON{ 101 };
constexpr UINT IDC_UNDO_BUTTON{ 102 };
constexpr UINT IDC_REDO_BUTTON{ 103 };
constexpr UINT IDC_ACTIVATE_EDIT_MODE_BUTTON{104};

class CMFCApp2View : public CView
{
	
protected: // создать только из сериализации
	CMFCApp2View() noexcept;
	DECLARE_DYNCREATE(CMFCApp2View)

// Атрибуты
public:
	CMFCApp2Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMFCApp2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditModeSwitchButtonClicked();
	afx_msg void OnUndoButtonClicked();
	afx_msg void OnRedoButtonClicked();
	afx_msg void OnActivateButtonClicked();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void UpdateScreen();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:

	CButton EditModeSwitcherButton;
	CButton UndoButton;
	CButton RedoButton;
	CButton ActivateButton;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // версия отладки в MFCApp2View.cpp
inline CMFCApp2Doc* CMFCApp2View::GetDocument() const
   { return reinterpret_cast<CMFCApp2Doc*>(m_pDocument); }
#endif

