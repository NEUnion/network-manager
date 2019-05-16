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
	//����һ����ַ����
	Oid Baseoid((LPCTSTR)oid_str);
	//����һ��OID����
	snmp_version version=version1;                 
	int status;
	Snmp snmp(status, 0, false);
	//����һ��snmp����
	Pdu pdu;                             
	Vb vb;                           
	vb.set_oid(Baseoid);                    
	pdu += vb;          
	//����PDU������vb��
	CTarget ctarget(address); 
	ctarget.set_version( version);         
	ctarget.set_retry(1);           
	ctarget.set_timeout(100); 
	ctarget.set_readcommunity((LPCTSTR)community);
	//����һ��CTarget����������Ӧ�Ĳ�����
	SnmpTarget *target;
	target = &ctarget;
	Oid NextOid(Baseoid);
	//����һ������OID��
	NextOid+=".1";
	CString reply_oid;
	CString reply_value;
	//����ֵ��
	while (Baseoid.nCompare(Baseoid.len(),NextOid)==0) 
	//���NextOid��Baseoid��ʼ������getnext������
	{
		status=snmp.get_next(pdu, *target); 
		if (status == SNMP_CLASS_SUCCESS)   
		{  
            pdu.get_vb(vb,0);
			//ȡ����һ��������һ����VB��
	        vb.get_oid(NextOid);
			//ȡ�����ص�OID����ŵ�NextOid��
			reply_oid=vb.get_printable_oid();
			reply_value=vb.get_printable_value();
			if (reply_value.GetLength()==0)
				reply_value="NULL";
            //������ɹ���ȡ�����ص�OID�Լ�ֵ��
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
			//���浽CMapStringToString�����У�
		 }
		else
		{
         AfxMessageBox("��ȡ����ʧ�ܣ���������!");
		 return;
		}
		vb.set_oid(NextOid);
		vb.set_null();
		pdu.set_vb(vb,0);
		//��������vb��׼��������һѭ����
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

