#if !defined(AFX_MESSAGE_H__CFD76115_8376_4E2D_919B_DCB53E06334D__INCLUDED_)
#define AFX_MESSAGE_H__CFD76115_8376_4E2D_919B_DCB53E06334D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Message.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMessage dialog

class CMessage : public CDialog
{
// Construction
public:
	CMessage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMessage)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_txt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMessage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGE_H__CFD76115_8376_4E2D_919B_DCB53E06334D__INCLUDED_)
