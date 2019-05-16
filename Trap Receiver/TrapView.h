// TrapView.h : interface of the CTrapView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAPVIEW_H__3A2AFE6A_FA6A_4AF3_B834_A74E7F704B6C__INCLUDED_)
#define AFX_TRAPVIEW_H__3A2AFE6A_FA6A_4AF3_B834_A74E7F704B6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_USERDEFMSG (WM_USER + 101)

#include "snmp_pp.h"
#include "snmp_pp/collect.h"
#include "snmp_pp/notifyqueue.h"
//#include "Mainfrm.h"
#include "TrapDoc.h"
#include "AfxTempl.h"
#include "TrapView.h"
#include "Scan.h"
#include "Message.h"
//#include "MyStringArray.h"
class CTrapView : public CFormView
{
protected: // create from serialization only
	CTrapView();
	DECLARE_DYNCREATE(CTrapView)
  //  void callback( int reason, Snmp *snmp, Pdu &pdu, SnmpTarget &target, void *cd)
public:
	//{{AFX_DATA(CTrapView)
	enum { IDD = IDD_TRAP_FORM };
	CEdit	m_text;
	//}}AFX_DATA
//static CString mymessage;
// Attributes
struct Line
{
	CString Index;
	CString Name;
	CString State;
	CString Descr;
	CString Ip;
	HTREEITEM Ht;
	bool Selected;
	CString Type;
};
Line * pLine;
CTypedPtrArray <CPtrArray,Line *> LineArray,TempArray;
//int number;
CString TrapMessage;
CImageList m_iImageList;
public:
CTrapDoc* GetDocument();
volatile bool Recive;
CMessage dlg;
//   friend void callme (int reason, Snmp *snmp, Pdu &pdu, SnmpTarget &target, void *cd);
//static void callme (int reason, Snmp *snmp, Pdu &pdu, SnmpTarget &target, void *cd);
// Operations
public:

//void call( int reason, Snmp *snmp, Pdu &pdu, SnmpTarget &target, void *cd);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrapView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTrapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// MyStringArray m_snmp;
// Generated message map functions
protected:
	//{{AFX_MSG(CTrapView)
	afx_msg void OnStart();
	afx_msg void OnEnd();
	afx_msg void OnFinish();
	afx_msg void OnConfig();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TrapView.cpp
inline CTrapDoc* CTrapView::GetDocument()
   { return (CTrapDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAPVIEW_H__3A2AFE6A_FA6A_4AF3_B834_A74E7F704B6C__INCLUDED_)
