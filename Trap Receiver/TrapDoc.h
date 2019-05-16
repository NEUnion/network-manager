// TrapDoc.h : interface of the CTrapDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAPDOC_H__F4D1F2DD_E2A9_4129_A2E0_AECFCBAC7E61__INCLUDED_)
#define AFX_TRAPDOC_H__F4D1F2DD_E2A9_4129_A2E0_AECFCBAC7E61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTrapDoc : public CDocument
{
protected: // create from serialization only
	CTrapDoc();
	DECLARE_DYNCREATE(CTrapDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrapDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTrapDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTrapDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAPDOC_H__F4D1F2DD_E2A9_4129_A2E0_AECFCBAC7E61__INCLUDED_)
