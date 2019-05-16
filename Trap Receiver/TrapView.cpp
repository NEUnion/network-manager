// TrapView.cpp : implementation of the CTrapView class
//

#include "stdafx.h"
#include "Trap.h"
#include "TrapDoc.h"
#include "TrapView.h"
#include "MainFrm.h"
#include <String.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrapView
//extern   protected:  static  int   CNotifyEventQueue::m_listen_por;   

IMPLEMENT_DYNCREATE(CTrapView, CFormView)

BEGIN_MESSAGE_MAP(CTrapView, CFormView)
	//{{AFX_MSG_MAP(CTrapView)
	ON_COMMAND(ID_START, OnStart)
	ON_COMMAND(ID_END, OnEnd)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
//	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrapView construction/destruction

CTrapView::CTrapView()
	: CFormView(CTrapView::IDD)
{
	//{{AFX_DATA_INIT(CTrapView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here
 
}

CTrapView::~CTrapView()
{
}

void CTrapView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrapView)
	DDX_Control(pDX, IDC_EDIT1, m_text);
	//}}AFX_DATA_MAP
}

BOOL CTrapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
   	return CFormView::PreCreateWindow(cs);
}

void CTrapView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
 //  m_hIcon=AfxGetApp()->LoadIcon(IDI_ICON1);;
	//pMain->pTrapView=this;
	TrapMessage="";
    m_iImageList.Create(16, 16, TRUE,1, 0);
	HICON hIcon;
	hIcon= NULL;
	//0,root;
	hIcon = (HICON)::LoadImage(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDI_ROUTER), IMAGE_ICON, 32, 32, 0);
	m_iImageList.Add(hIcon);
	//1,closed box;
	hIcon = (HICON)::LoadImage(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDI_LINE), IMAGE_ICON, 16, 16, 0);
	m_iImageList.Add(hIcon);
	hIcon = (HICON)::LoadImage(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDI_DOWN), IMAGE_ICON, 16, 16, 0);
	m_iImageList.Add(hIcon);
//    m_tree.SetImageList (&m_iImageList,TVSIL_NORMAL);
	dlg.Create(IDD_DIALOG1);
    Recive=true;
}

/////////////////////////////////////////////////////////////////////////////
// CTrapView printing

BOOL CTrapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTrapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTrapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTrapView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CTrapView diagnostics

#ifdef _DEBUG
void CTrapView::AssertValid() const
{
	
	CFormView::AssertValid();
}

void CTrapView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTrapDoc* CTrapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrapDoc)));
	return (CTrapDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrapView message handlers
//回调函数，当有TRAP到达时，调用该函数进行进一步处理；
void callme (int reason, Snmp *snmp, Pdu &pdu, SnmpTarget &target, void *cd)
{  
    CString str="";
	CTime time=CTime::GetCurrentTime();
	CString time_str=time.Format("%Y-%m-%d:%H:%M:%S");
	CTrapView *p;
	p=(CTrapView *)cd;
	Vb nextVb;
	GenAddress addr;
    target.get_address(addr);
	
	UdpAddress from(addr);
	CString ipadd=from.get_printable();
	char *p1=strstr(ipadd,"127.0.0.1");
	//if(p)
	//	return;	
	//结束监听时本机发送的TRAP退出循环，不做任何处理；
	Oid id,ent,timestamp;
	pdu.get_notify_id(id);
	pdu.get_notify_enterprise(ent);
	CString TrapId=id.get_printable();
	switch(atoi(TrapId.Right(1)))
	{
	case 1:
		TrapId="ColdStart";
		break;
	case 2:
		TrapId="WarmStart";
		break;
	case 3:
		TrapId="LingDown";
		break;
	case 4:
		TrapId="LingUp";
		break;
	case 5:
		TrapId="AnthenticationFailure";
		break;
	case 6:
		TrapId="EgpNeighborLoss";
		break;
	default:
		TrapId="EnterpriseSpecific";
		break;

	}

	
	CString EnterPrise=ent.get_printable();
	//取得TRAP的ID以及enterprise ；
    //AfxMessageBox(EnterPrise);
	TimeTicks ts;
	pdu.get_notify_timestamp(ts);
	CString Timestamp=ts.get_printable();
	int pdu_level;
    pdu_level=pdu.get_security_level();
	
	CString level;
	level.Format("%d",pdu_level);
	
	CString index,name;
	pdu.get_vb(nextVb, 0);
	//索引号
	index=nextVb.get_printable_value();
    pdu.get_vb(nextVb, 1);
	//接口
    name=nextVb.get_printable_value();
	if (EnterPrise!="")
	{
		p->TrapMessage+=time_str+"\r\n Device："+ipadd+" OID:"+EnterPrise+" Timestamp:"+
			Timestamp+"\r\n SecurityLevel:"+level+" Trap-Type:"+TrapId+" Enterprise:"+EnterPrise;
        p->TrapMessage+="\r\n";
		p->m_text.SetWindowText(p->TrapMessage); 
	}
}

//监听TRAP线程的处理函数，接受一个指针作为参数；
UINT WorkerThreadProc(LPVOID Param)
{ 
  Oid linkUp("1.3.6.1.6.3.1.1.5.4");
  Oid linkDown("1.3.6.1.6.3.1.1.5.3");
  CTrapView *pCV;
  pCV=(CTrapView *)Param;
  //将指针类型转换为CTrapView *类型指针；
  int trap_port;
  trap_port =162; 
  //指定监听端口号；
  int status; 
  Snmp::socket_startup();  
  Snmp snmp( status, 0);   
  // 创建Snmp对象；
  if ( status != SNMP_CLASS_SUCCESS)
  {
   AfxMessageBox("出现错误 No 0123!");
   return TRUE;
  }
   OidCollection oidc;
   TargetCollection targetc;
   //创建过滤TRAP的对象；
   snmp.notify_set_listen_port(162);
   //设置端口号；
   status=snmp.notify_register(oidc, targetc,callme,Param);
   //注册过滤条件，回调函数，并将Param，也就是指向CTrapView
   //对象的this指针，传递给回调函数，以方便在回调函数中访问
   //处理CTrapView对象中的成员变量；
   if (status != SNMP_CLASS_SUCCESS)
   {
    AfxMessageBox("出现错误! No 0234");
    return TRUE;
   }
 while (pCV->Recive)
 snmp.eventListHolder->SNMPProcessEvents();
 //进入SNMPProcessEvents()函数，等待TRAP触发回调用函数；
 Snmp::socket_cleanup();  
AfxMessageBox("停止接收!");
return TRUE;
}

void CTrapView::OnStart() 
{ 
// m_list1.DeleteAllItems();
if (Recive==false)
  Recive=true;
  AfxBeginThread(WorkerThreadProc,this,THREAD_PRIORITY_NORMAL,0,0,NULL);
 //创建一个新线程，用来在指定端口监听TRAP；将this指针作为参数传递给新线程；
CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
pF->m_wndStatusBar.SetPaneText(0,"开始接收......");
}

void CTrapView::OnEnd() 
{
if (Recive==true)
  Recive=false;
  
  Snmp::socket_startup();  
  UdpAddress address("127.0.0.1:162");      
    int status;
   Snmp snmp(status, "0.0.0.0") ;
   Pdu pdu;                               
   pdu.set_notify_id("1.3.6.1");               
   pdu.set_notify_enterprise( "test");     
   CTarget ctarget(address);             
   ctarget.set_version( version1);        
   ctarget.set_readcommunity("public"); 
   SnmpTarget *target=&ctarget;
   status = snmp.trap(pdu,*target);
   Snmp::socket_cleanup();  
   //发送一个TRAP，结束监听状态；
}

void CTrapView::OnDestroy() 
{
	CFormView::OnDestroy();
for (int i=0;i<LineArray.GetSize();i++)
{
	delete LineArray[i];
}		
}

