// Trap.h : main header file for the TRAP application
//

#if !defined(AFX_TRAP_H__03D97072_E2A5_44BC_9BFE_E0391653C63E__INCLUDED_)
#define AFX_TRAP_H__03D97072_E2A5_44BC_9BFE_E0391653C63E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrapApp:
// See Trap.cpp for the implementation of this class
//

class CTrapApp : public CWinApp
{
public:
	CTrapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTrapApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAP_H__03D97072_E2A5_44BC_9BFE_E0391653C63E__INCLUDED_)
