#if !defined(AFX_DISPDLG_H__932C3876_E613_4A74_9BC9_3A545FC5799C__INCLUDED_)
#define AFX_DISPDLG_H__932C3876_E613_4A74_9BC9_3A545FC5799C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LineChart.h"
#include "MyStringArray.h"
#include "AfxTempl.h"
// DispDlg.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CCpuDlg dialog

class CCpuDlg : public CDialog
{
// Construction
public:
	CCpuDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCpuDlg)
	enum { IDD = IDD_DISP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCpuDlg)
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
	//{{AFX_MSG(CCpuDlg)
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPDLG_H__932C3876_E613_4A74_9BC9_3A545FC5799C__INCLUDED_)
