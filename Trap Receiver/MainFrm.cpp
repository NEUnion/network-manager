// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Trap.h"
#include "Scan.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
    ON_MESSAGE(WM_NOTIFYICON, OnNotifyIcon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
    m_hIcon=AfxGetApp()->LoadIcon(IDI_ICON1);;
    NOTIFYICONDATA ndata;
	ndata.cbSize= sizeof (NOTIFYICONDATA);
	ndata.hWnd= m_hWnd;
	ndata.uID= IDI_ICON1;
	ndata.uFlags= NIF_ICON|NIF_MESSAGE|NIF_TIP;
	ndata.uCallbackMessage=WM_NOTIFYICON;
	ndata.hIcon= m_hIcon;
	strcpy(ndata.szTip, "线路监视");
	
	Shell_NotifyIcon(NIM_ADD, &ndata);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    cs.x=10;
	cs.y=10;
	cs.cx=1000;
	cs.cy=800;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers



void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if (nID==SC_MINIMIZE)
		ShowWindow(SW_HIDE);
	else
    CFrameWnd::OnSysCommand(nID, lParam);
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
    NOTIFYICONDATA ndata;
	ndata.cbSize= sizeof (NOTIFYICONDATA);
	ndata.hWnd= m_hWnd;
	Shell_NotifyIcon(NIM_DELETE, &ndata); 			
	
}
void CMainFrame::OnNotifyIcon(WPARAM wParam, LPARAM lParam)
{
	// 响应在托盘图标上的单击
	if ((wParam == IDI_ICON1)&&(lParam == WM_LBUTTONDOWN))
		ShowWindow(SW_SHOWNORMAL);
}
