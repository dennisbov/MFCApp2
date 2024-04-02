
// MFCApp2View.cpp: реализация класса CMFCApp2View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApp2.h"
#endif

#include "Drawables.h"
#include "PolyIntersectoinator.h"
#include "Commands.h"
#include "MFCApp2Doc.h"
#include "MFCApp2View.h"
#include <vector>
#include "FlickerFreeDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


using namespace Gdiplus;

PolyIntersectoinator polyIntersectoinator;
bool isEditMode = false;
Color polygonMainColor = Color(155,155,155);
Color polygonBorderColor = Color(40, 40, 40);
Color dotColor = Color(0, 0, 0);
REAL dotRadius{ 10 };
float polygonBorderWidth{ 7 };

vector<vector<PointMath>>* intersections;

void CMFCApp2View::UpdateScreen()
{
	Invalidate();
	UpdateWindow();
}

// CMFCApp2View

IMPLEMENT_DYNCREATE(CMFCApp2View, CView)

BEGIN_MESSAGE_MAP(CMFCApp2View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApp2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCApp2View::UpdateScreen)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_EDIT_MODE_SWITHC_BUTTON, OnEditModeSwitchButtonClicked)
	ON_BN_CLICKED(IDC_UNDO_BUTTON, OnUndoButtonClicked)
	ON_BN_CLICKED(IDC_REDO_BUTTON, OnRedoButtonClicked)
	ON_BN_CLICKED(IDC_ACTIVATE_EDIT_MODE_BUTTON, OnActivateButtonClicked)
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApp2View

CMFCApp2View::CMFCApp2View() noexcept
{
	// TODO: добавьте код создания

}

CMFCApp2View::~CMFCApp2View()
{
}

BOOL CMFCApp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}


// Рисование CMFCApp2View


void CMFCApp2View::OnDraw(CDC* pDC)
{
	CMFCApp2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных

	FFDC::CMemDC dc{ pDC };

	Graphics graphics(dc->GetSafeHdc());
 	polyIntersectoinator.drawer.UpdateDrawer(graphics);
	/*
	SolidBrush brush(Color(255, 0, 0));
	if (polyIntersectoinator.triangleAssembler.isEditing == true) {
		return;
	}
	for (int i = 10; i < 3000; i+=10)
	{
		for (int j = 10; j < 3000; j+=10)
		{
			PointMath point(i, j);
			int intersectedPolygons = 0;
			for (int k = 0; k < polyIntersectoinator.triangleAssembler.triangleCount; k++)
			{
				vector<PointMath> points(polyIntersectoinator.triangleAssembler.TriangleList[k].lastElementIndex, PointMath());
				for (int l = 0; l < polyIntersectoinator.triangleAssembler.TriangleList[k].lastElementIndex; l++)
				{
					points[l] = polyIntersectoinator.triangleAssembler.TriangleList[k].EdgesArray[l].point;
				}
				polyIntersectoinator.triangleAssembler.interseptionCalculator.polarSorting(points);
				if (polyIntersectoinator.triangleAssembler.interseptionCalculator.even_odd_rule(point, points)) {
					intersectedPolygons++;
				}
				if (intersectedPolygons > 1) {
					graphics.FillEllipse(&brush, (INT)point.x, (INT)point.y, 10, 10);
				}
			}
		}
	}
	*/
}




// Печать CMFCApp2View


void CMFCApp2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApp2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApp2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApp2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CMFCApp2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApp2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}




// Диагностика CMFCApp2View

#ifdef _DEBUG
void CMFCApp2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp2Doc* CMFCApp2View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp2Doc)));
	return (CMFCApp2Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCApp2View




void CMFCApp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	polyIntersectoinator.commandConstructor.TryAddCommand(new PrintDotCommand(
		(float)point.x, (float)point.y, dotColor, dotRadius));

	UpdateScreen();
	CView::OnLButtonDown(nFlags, point);
}


int CMFCApp2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	intersections = &polyIntersectoinator.triangleAssembler.interseptionCalculator.interseptions;

	EditModeSwitcherButton.Create(_T("finish drawing polygon"), 
		BS_PUSHBUTTON, CRect(10, 10, 300, 90), this, IDC_EDIT_MODE_SWITHC_BUTTON);
	
	UndoButton.Create(_T("Undo"),
		BS_PUSHBUTTON, CRect(10, 100, 150, 180), this, IDC_UNDO_BUTTON);

	RedoButton.Create(_T("Redo"),
		BS_PUSHBUTTON, CRect(10, 190, 150, 270), this, IDC_REDO_BUTTON);

	ActivateButton.Create(_T("start drawing polygon"),
		BS_PUSHBUTTON, CRect(310, 10, 600, 90), this, IDC_ACTIVATE_EDIT_MODE_BUTTON);

	EditModeSwitcherButton.ShowWindow(SW_SHOW);
	UndoButton.ShowWindow(SW_SHOW);
	RedoButton.ShowWindow(SW_SHOW);
	ActivateButton.ShowWindow(SW_SHOW);

	return 0;
}

void CMFCApp2View::OnEditModeSwitchButtonClicked()
{
	polyIntersectoinator.commandConstructor.TryAddCommand(new ConfirmTriangleCommand(
			polygonBorderWidth, polygonMainColor, polygonBorderColor));
	UpdateScreen();
}

void CMFCApp2View::OnUndoButtonClicked()
{
	polyIntersectoinator.commandConstructor.undoCommand();
	UpdateScreen();
}
void CMFCApp2View::OnRedoButtonClicked()
{
	polyIntersectoinator.commandConstructor.reduCommand();
	UpdateScreen();
}

void CMFCApp2View::OnActivateButtonClicked()
{
	polyIntersectoinator.commandConstructor.TryAddCommand(new SetTriangleCommand());
	UpdateScreen();
}

DrawableText mouseInfoText;
PointMath currentPoint;
std::string currentIntersectionInfo;

void CMFCApp2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	
	currentPoint = PointMath(point.x, point.y);
	
	mouseInfoText.Text = (std::string)"[ x: " + std::to_string((double)point.x) + 
		(std::string)" y: " + std::to_string((double)point.y) + (std::string)" ]";
	mouseInfoText.point = currentPoint;
	
	currentIntersectionInfo = "";

	for (int i = 0; i < (*intersections).size(); i++)
	{
		currentPoint = PointMath(point.x, point.y);
		if (MathFunctions::even_odd_rule(currentPoint, (*intersections)[i])) {
			currentIntersectionInfo = std::to_string(MathFunctions::so_called_shoelace_formula((*intersections)[i]));
		}
	}
	if(currentIntersectionInfo != "")
		mouseInfoText.Text += (std::string)" square: " + currentIntersectionInfo;
	
	polyIntersectoinator.drawer.RemoveDrawable(&mouseInfoText);
	polyIntersectoinator.drawer.AddDrawable(&mouseInfoText);

	UpdateScreen();
	CView::OnMouseMove(nFlags, point);
}


BOOL CMFCApp2View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	return FALSE;
}
