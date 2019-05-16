// MyStringArray.cpp: implementation of the MyStringArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Trap.h"
#include "snmp_pp.h"
#include "MyStringArray.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
MyStringArray::MyStringArray()
{
err="";
}

MyStringArray::~MyStringArray()
{

}
void MyStringArray::Add(CString &s_Oid,CString &s_Value)
{
OidStr.Add(s_Oid);
Value.Add(s_Value);
}
CString MyStringArray::GetOid(int index)
{
	if (index<OidStr.GetSize())
	return OidStr.GetAt(index);
	else
	return err;
}	
CString MyStringArray::GetValue(int index)
{
	if (index<Value.GetSize())
	return Value.GetAt(index);
	else
	return err;
}
void MyStringArray::SetValue(int index,CString Str)
{
	Value.SetAt(index,(LPCTSTR)Str);
}
int MyStringArray::GetCount()
{
	return OidStr.GetSize();
}
void MyStringArray::clear()
{
	OidStr.RemoveAll();
	Value.RemoveAll();
}
void MyStringArray::GetTree(CString &ip,CString &community,CString &oid_str)           
{
	Snmp::socket_startup(); 
	UdpAddress address((LPCTSTR)ip); 
	address.set_port(161);//161
	//构造一个地址对象；
	Oid Baseoid((LPCTSTR)oid_str);
	//构造一个OID对象；
	snmp_version version=version1;                 
	int status;
	Snmp snmp(status, 0, false);
	//构造一个snmp对象；
	Pdu pdu;                             
	Vb vb;                           
	vb.set_oid(Baseoid);                    
	pdu += vb;          
	//构造PDU并设置vb；
	CTarget ctarget(address); 
	ctarget.set_version( version);         
	ctarget.set_retry(1);           
	ctarget.set_timeout(100); 
	ctarget.set_readcommunity((LPCTSTR)community);
	//构造一个CTarget对象并设置相应的参数；
	SnmpTarget *target;
	target = &ctarget;
	Oid NextOid(Baseoid);
	//构造一个辅助OID；
	NextOid+=".1";
	CString reply_oid;
	CString reply_value;
	//返回值；
	while (Baseoid.nCompare(Baseoid.len(),NextOid)==0) 
	//如果NextOid以Baseoid开始，进行getnext操作；
	{
		status=snmp.get_next(pdu, *target); 
		if (status == SNMP_CLASS_SUCCESS)   
		{  
            pdu.get_vb(vb,0);
			//取出第一个（仅有一个）VB；
	        vb.get_oid(NextOid);
			//取出返回的OID，存放到NextOid；
			reply_oid=vb.get_printable_oid();
			reply_value=vb.get_printable_value();
			if (reply_value.GetLength()==0)
				reply_value="NULL";
            //如操作成功，取出返回的OID以及值；
             if (Baseoid.nCompare(Baseoid.len(),NextOid)==0)
			 {
				 reply_oid.TrimLeft();
				 reply_oid.TrimRight();
				 reply_value.TrimLeft();
				 reply_value.TrimRight();
				 OidStr.Add(reply_oid);
				 Value.Add(reply_value);
				 //s2s.Add(reply_oid,reply_value);
			 }
			//保存到CMapStringToString对象中；
		 }
		else
		{
         AfxMessageBox("读取操作失败，请检查配置!");
		 return;
		}
		vb.set_oid(NextOid);
		vb.set_null();
		pdu.set_vb(vb,0);
		//重新设置vb，准备进入下一循环；
	}
Snmp::socket_cleanup(); 
}
void MyStringArray::GetOne(CString &ip,CString &community,
						   CString &oid_str,CString &reply)
{
Snmp::socket_startup(); 
UdpAddress address((LPCTSTR)ip); 
address.set_port(161);//161
Oid oid((LPCTSTR)oid_str); 
snmp_version version=version1;                 
int status;
Snmp snmp(status, 0, false);
 Pdu pdu;                             
 Vb vb;                           
 vb.set_oid(oid);                    
 pdu += vb;                           
 CTarget ctarget(address); 
 ctarget.set_version(version);         
 ctarget.set_retry(1);           
 ctarget.set_timeout(100); 
 ctarget.set_readcommunity((LPCTSTR)community); 
 SnmpTarget *target;
 target = &ctarget;
 status = snmp.get(pdu, *target); 
 if (status == SNMP_CLASS_SUCCESS)   
    {  
     pdu.get_vb(vb,0);
     reply=vb.get_printable_value();
	 reply.TrimLeft();
	 reply.TrimRight();
	}
Snmp::socket_cleanup(); 
}

void MyStringArray::GetNextOne(CString &ip,CString &community,
							   CString &oid_str,CString &reply)
{
//ip+=":161";
Snmp::socket_startup(); 
UdpAddress address((LPCTSTR)ip); 
address.set_port(161);//161
Oid oid((LPCTSTR)oid_str); 
snmp_version version=version1;                 
int status;
Snmp snmp(status, 0, false);
 Pdu pdu;                             
 Vb vb;                           
 vb.set_oid(oid);                    
 pdu += vb;                           
 CTarget ctarget(address); 
 ctarget.set_version(version);         
 ctarget.set_retry(1);           
 ctarget.set_timeout(100); 
 ctarget.set_readcommunity((LPCTSTR)community); 
 SnmpTarget *target;
 target = &ctarget;
 status = snmp.get(pdu, *target); 
 if (status == SNMP_CLASS_SUCCESS)   
    {  
     pdu.get_vb(vb,0);
	 oid_str=vb.get_printable_oid();
     reply=vb.get_printable_value();
	 oid_str.TrimLeft();
	 oid_str.TrimRight();
	 reply.TrimLeft();
	 reply.TrimRight();
	}
Snmp::socket_cleanup(); 

}

