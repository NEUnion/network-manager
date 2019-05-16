// RshDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Rsh.h"
#include "RshDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString ip,community,oid1,oid2;
	unsigned long interval;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRshDlg dialog

CRshDlg::CRshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRshDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRshDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRshDlg)
	DDX_Control(pDX, IDC_COMBO1, m_oid1);
	DDX_Control(pDX, IDC_COMBO2, m_type);
	DDX_Control(pDX, IDC_COMBO3, m_oid2);
	DDX_Control(pDX, IDC_EDIT2, m_interval);
	DDX_Control(pDX, IDC_EDIT1, m_community);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ipadd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRshDlg, CDialog)
	//{{AFX_MSG_MAP(CRshDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnScan)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON2, OnCpu)
	ON_BN_CLICKED(IDC_BUTTON3, OnMer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRshDlg message handlers

BOOL CRshDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

    CRect cr(22,34,600,150);
	CString   str; 
	str.Format( "127.0.0.1 "); 
	m_ipadd.SetWindowText(str);
    m_community.SetWindowText("public");
	m_type.SetWindowText("路由器");
	m_interval.SetWindowText("1");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRshDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRshDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRshDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRshDlg::OnScan() 
{
	CString oid;
	m_ipadd.GetWindowText(ip);
	m_community.GetWindowText(community);
	CString type,rv;
	m_type.GetWindowText(type);
	m_oid1.ResetContent();
	m_oid2.ResetContent();
	NameToOid.RemoveAll();
	if (type=="主机")
	{ 
		//路由器cpu利用率的OID
	//	oid="1.3.6.1.4.1.9600.1.1.5.1.5.1.48";  
	    oid="1.3.6.1.2.1.25.3.3.1.2";  //主机cpu利用率的OID
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid1.AddString("CPU利用率");
			NameToOid.SetAt("CPU利用率",oid);
		}
		oid="1.3.6.1.4.1.9600.1.1.2.1.0";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("可用物理内存（Bytes）");
			NameToOid.SetAt("可用物理内存（Bytes）",oid);
		}
		oid="1.3.6.1.4.1.9600.1.1.2.2.0";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("可用物理内存（KBytes）");
			NameToOid.SetAt("可用物理内存（KBytes）",oid);
		}
		oid="1.3.6.1.4.1.9600.1.1.2.3.0";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("可用物理内存（MBytes）");
			NameToOid.SetAt("可用物理内存（MBytes）",oid);
		}
	}
	else
	{
		oid="1.3.6.1.4.1.9.2.1.56.0";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid1.AddString("CPU 5秒内平均利用率");
			NameToOid.SetAt("CPU 5秒内平均利用率",oid);
		}

		oid="1.3.6.1.4.1.9.2.1.57.0";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid1.AddString("CPU 1分钟内平均利用率");
			NameToOid.SetAt("CPU 1分钟内平均利用率",oid);
		}
		oid="1.3.6.1.4.1.9.2.1.58.0";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid1.AddString("CPU 5分钟内平均利用率");
			NameToOid.SetAt("CPU 5分钟内平均利用率",oid);
		}
		oid="1.3.6.1.4.1.9.9.48.1.1.1.5.2";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("I/O内存(已经使用字节KByts)");
			NameToOid.SetAt("I/O内存(已经使用字节KByts)",oid);
		}
		oid="1.3.6.1.4.1.9.9.48.1.1.1.6.2";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("I/O(内存空闲字节KByts)");
			NameToOid.SetAt("I/O(内存空闲字节KByts)",oid);
		}
		oid="1.3.6.1.4.1.9.9.48.1.1.1.5.4";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("FAST内存(已经使用字节KByts)");
			NameToOid.SetAt("FAST内存(已经使用字节KByts)",oid);
		}
		oid="1.3.6.1.4.1.9.9.48.1.1.1.6.4";
		m_snmp.GetOne(ip,community,oid,rv);
		if (rv.GetLength()>0)
		{
			m_oid2.AddString("FAST内存(空闲字节KByts)");
			NameToOid.SetAt("FAST内存(空闲字节KByts)",oid);
		}
	}

	CString t;
	m_interval.GetWindowText(t);
	if (t.GetLength()==0)
	{
		MessageBox("采样时间错误!");
		return;
	}
	interval=atoi((LPCTSTR)t);
	if (interval<1)
	{
		MessageBox("采样时间要大于或等于1分钟!");
		return;
	}
	interval=interval*300;
	MessageBox("操作完成!");
}


void CRshDlg::OnCpu() 
{
	CString temp;
	m_oid1.GetWindowText(oid1);
	if (oid1.Find("1.3.6.1")==-1)
	{
		NameToOid.Lookup(oid1,temp);
		oid1=temp;
	}


	m_oid2.GetWindowText(oid2);
	if (oid2.Find("1.3.6.1")==-1)
	{
		NameToOid.Lookup(oid2,temp);
		oid2=temp;
	}


   //MessageBox("点“开始”按钮开始测试!");
	cpu.Create( IDD_CPU_DIALOG,GetDesktopWindow());
	cpu.ShowWindow(SW_SHOW);
 
}



void CRshDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CRshDlg::OnMer() 
{

	CString temp;


	m_oid2.GetWindowText(oid2);
	if (oid2.Find("1.3.6.1")==-1)
	{
		NameToOid.Lookup(oid2,temp);
		oid2=temp;
	}

	m_oid1.GetWindowText(oid1);
	if (oid1.Find("1.3.6.1")==-1)
	{
		NameToOid.Lookup(oid1,temp);
		oid1=temp;
	}

	  mer.Create(IDD_MER_DIALOG,GetDesktopWindow());
	  mer.ShowWindow(SW_SHOW);
}
