// TrapDoc.cpp : implementation of the CTrapDoc class
//

#include "stdafx.h"
#include "Trap.h"

#include "TrapDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrapDoc

IMPLEMENT_DYNCREATE(CTrapDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrapDoc, CDocument)
	//{{AFX_MSG_MAP(CTrapDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrapDoc construction/destruction

CTrapDoc::CTrapDoc()
{
	// TODO: add one-time construction code here

}

CTrapDoc::~CTrapDoc()
{
}

BOOL CTrapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTrapDoc serialization

void CTrapDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTrapDoc diagnostics

#ifdef _DEBUG
void CTrapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrapDoc commands
