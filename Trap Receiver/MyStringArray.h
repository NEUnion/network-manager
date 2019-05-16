// MyStringArray.h: interface for the MyStringArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTRINGARRAY_H__A11E0101_CFC7_4F60_9BD3_0566AFE49170__INCLUDED_)
#define AFX_MYSTRINGARRAY_H__A11E0101_CFC7_4F60_9BD3_0566AFE49170__INCLUDED_

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
    void GetTree(CString &ip,CString &community,CString &oid_str);
    void GetOne(CString &ip,CString &community,CString &oid_str,CString &reply);
	void GetNextOne(CString &ip,CString &community,CString &oid_str,CString &reply);
	void Add(CString &s_Oid,CString &s_Value);
	CString GetOid(int index);	
    CString GetValue(int index);
	void SetValue(int index,CString Str);
	int GetCount();
	void clear();
};


#endif // !defined(AFX_MYSTRINGARRAY_H__A11E0101_CFC7_4F60_9BD3_0566AFE49170__INCLUDED_)
