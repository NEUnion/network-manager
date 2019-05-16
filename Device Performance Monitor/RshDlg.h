// RshDlg.h : header file
//

#if !defined(AFX_RSHDLG_H__1C92CA15_1112_483C_B89A_2F428BB24400__INCLUDED_)
#define AFX_RSHDLG_H__1C92CA15_1112_483C_B89A_2F428BB24400__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LineChart.h"
#include "MyStringArray.h"
#include "AfxTempl.h"
#include "CpuDlg.h"	// Added by ClassView
#include "MerDlg.h"	// Added by ClassView
/////////////////////////////////////////////////////////////////////////////
// CRshDlg dialog

class CRshDlg : public CDialog
{
// Construction
public:
	CRshDlg(CWnd* pParent = NULL);	// standard constructor
  // Dialog Data
	//{{AFX_DATA(CRshDlg)
	enum { IDD = IDD_RSH_DIALOG };
	CComboBox	m_oid1;
	CComboBox	m_type;
	CComboBox	m_oid2;
	CEdit	m_interval;
	CEdit	m_community;
	CIPAddressCtrl	m_ipadd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRshDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	MyStringArray m_snmp;
   
    CMapStringToString NameToOid;

	// Generated message map functions
	//{{AFX_MSG(CRshDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnScan();
	afx_msg void OnCpu();
	afx_msg void OnDestroy();
	afx_msg void OnMer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMerDlg mer;
	CCpuDlg cpu;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSHDLG_H__1C92CA15_1112_483C_B89A_2F428BB24400__INCLUDED_)
