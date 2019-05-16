#if !defined(AFX_MERDLG_H__18F909BD_D182_46CC_9F03_AEC32C5D072C__INCLUDED_)
#define AFX_MERDLG_H__18F909BD_D182_46CC_9F03_AEC32C5D072C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MerDlg.h : header file
//
#include "LineChart.h"
#include "MyStringArray.h"
#include "AfxTempl.h"
/////////////////////////////////////////////////////////////////////////////
// CMerDlg dialog

class CMerDlg : public CDialog
{
// Construction
public:
	CMerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMerDlg)
	enum { IDD = IDD_MER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	MyStringArray m_snmp;
	CLineChart *pDay;
    CStdioFile DataFile;
	CString fName;
	// Generated message map functions
	//{{AFX_MSG(CMerDlg)
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MERDLG_H__18F909BD_D182_46CC_9F03_AEC32C5D072C__INCLUDED_)
