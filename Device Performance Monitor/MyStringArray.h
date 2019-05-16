// MyStringArray.h: interface for the MyStringArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTRINGARRAY_H__F75B7090_EF17_43C0_94E0_44412F0FE955__INCLUDED_)
#define AFX_MYSTRINGARRAY_H__F75B7090_EF17_43C0_94E0_44412F0FE955__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MyStringArray  
{
public:
	MyStringArray();
	virtual ~MyStringArray();
protected:
	CStringArray OidStr;
	CStringArray Value;
	CString err;
public:
    void GetOne(CString &ip,CString &community,CString &oid_str,CString &reply);
     bool GetTwo(CString &ip,CString &community,CString &oid1,CString oid2,
		       unsigned long &r1,unsigned long &r2);
	void Add(CString &s_Oid,CString &s_Value);
};

#endif // !defined(AFX_MYSTRINGARRAY_H__F75B7090_EF17_43C0_94E0_44412F0FE955__INCLUDED_)
