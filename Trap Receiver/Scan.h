#if !defined(AFX_SCAN_H__CFA5F9C4_6A40_4DE4_9E88_53352497F176__INCLUDED_)
#define AFX_SCAN_H__CFA5F9C4_6A40_4DE4_9E88_53352497F176__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Scan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScan dialog

class CScan : public CDialog
{
// Construction
public:
	CScan(CWnd* pParent = NULL);   // standard constructor
    CString ip1;
// Dialog Data
	//{{AFX_DATA(CScan)
	enum { IDD = IDD_CONFIG };
	CListCtrl	m_list1;
	CIPAddressCtrl	m_ipaddress;
	CString	m_community;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScan)
	afx_msg void OnFinish();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCAN_H__CFA5F9C4_6A40_4DE4_9E88_53352497F176__INCLUDED_)
