// CpuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Rsh.h"
#include "CpuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



extern  CString ip,community,oid1,oid2;
  extern	unsigned long interval;

/////////////////////////////////////////////////////////////////////////////
// CCpuDlg dialog

CCpuDlg::CCpuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCpuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCpuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCpuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCpuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCpuDlg, CDialog)
	//{{AFX_MSG_MAP(CCpuDlg)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCpuDlg message handlers


void CCpuDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	pDay->MoveSubs();
	unsigned long Memory;
    unsigned long CPUUse;
	CTime t=CTime::GetCurrentTime();
	CString time=t.Format("%H:%M:%S");
	CString s,line;
	line="";
	DataFile.Open(fName,CFile::modeWrite);
	if (m_snmp.GetTwo(ip,community,oid1,oid2,CPUUse,Memory))
	{  
        Memory=Memory/1024;
		pDay->Append(Memory,CPUUse,time,0,0);
		s.Format("%d",CPUUse);
		line=line+"@"+s;
		s.Format("%d",Memory);
		line=line+"#"+s;
		line=line+"$0&0\r\n";
		DataFile.SeekToEnd();
		DataFile.WriteString(line);	
	}
	DataFile.Close();
	CDialog::OnTimer(nIDEvent);
}

BOOL CCpuDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect cr(22,34,600,150);
	CSize c(500,150);
	pDay=NULL;
	pDay=new CLineChart(c,400,1);
	pDay->Create(NULL,WS_CHILD|WS_VISIBLE|SS_NOTIFY|SS_BLACKFRAME, cr,this,50000);
	pDay->SetTitle("实时数据曲线图");
	

	unsigned long Memory;
    unsigned long CPUUse; 
	CTime t=CTime::GetCurrentTime();
	CString time=t.Format("%H:%M:%S");
	fName=t.Format("%m-%d-%H");
	fName=fName+"CPUMemory.txt";
	CString s,line;
	line="";
	DataFile.Open(fName,CFile::modeWrite|CFile::modeCreate);
	if (m_snmp.GetTwo(ip,community,oid1,oid2,CPUUse,Memory))
	{   
		Memory=Memory/1024;
		s.Format("%d",CPUUse);
		line=line+"@"+s;
		s.Format("%d",Memory);
		line=line+"#"+s;
		line=line+"$0&0\r\n";
		DataFile.SeekToEnd();
		DataFile.WriteString(line);
		pDay->Append(Memory,CPUUse,time,0,0);
	}
	else
		MessageBox("读取数据失败，请检查OID或网络是否有错误!");

	DataFile.Close();
	if (interval>=300)
		SetTimer(1,interval,NULL);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCpuDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	delete pDay;	
	
}


