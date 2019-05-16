// Scan.cpp : implementation file
//

#include "stdafx.h"
#include "Trap.h"
#include "Scan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScan dialog


CScan::CScan(CWnd* pParent /*=NULL*/)
	: CDialog(CScan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScan)
	m_community = _T("");
	//}}AFX_DATA_INIT
}


void CScan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScan)
	DDX_Control(pDX, IDC_IPADDRESS1, m_ipaddress);
	DDX_Text(pDX, IDC_EDIT1, m_community);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScan, CDialog)
	//{{AFX_MSG_MAP(CScan)
	ON_BN_CLICKED(IDC_FINISH, OnFinish)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScan message handlers


void CScan::OnFinish() 
{
m_ipaddress.GetWindowText(ip1);	
}
