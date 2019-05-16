// Message.cpp : implementation file
//

#include "stdafx.h"
#include "Trap.h"
#include "Message.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMessage dialog


CMessage::CMessage(CWnd* pParent /*=NULL*/)
	: CDialog(CMessage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessage)
	//}}AFX_DATA_INIT
}


void CMessage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessage)
	DDX_Control(pDX, IDC_EDIT1, m_txt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMessage, CDialog)
	//{{AFX_MSG_MAP(CMessage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessage message handlers



