// MyStringArray.cpp: implementation of the MyStringArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Rsh.h"
#include "MyStringArray.h"
#include "snmp_pp.h"
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




void MyStringArray::GetOne(CString &ip,CString &community,
						   CString &oid_str,CString &reply)
{
Snmp::socket_startup(); 
UdpAddress address((LPCTSTR)ip); 
address.set_port(161);
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
 else
    reply="";
Snmp::socket_cleanup(); 
}


bool MyStringArray::GetTwo(CString &ip,CString &community,CString &oid1,CString oid2,
							  unsigned long&r1,unsigned long &r2)
{
bool res;
r1=0;
r2=0;
Snmp::socket_startup(); 
UdpAddress address((LPCTSTR)ip); 
address.set_port(161);
Oid cpu_oid,mem_oid;
cpu_oid=oid1;
mem_oid=oid2;
snmp_version version=version1;                 
int status;
Snmp snmp(status, 0, false);
 Pdu pdu;                             
 Vb vb;                           
 vb.set_oid(cpu_oid);                    
 pdu += vb;            
 vb.set_oid(mem_oid);                    
 pdu += vb;       
 CTarget ctarget(address); 
 ctarget.set_version(version);         
 ctarget.set_retry(1);           
 ctarget.set_timeout(300); 
 ctarget.set_readcommunity((LPCTSTR)community); 
 SnmpTarget *target;
 target = &ctarget;
 status = snmp.get(pdu, *target); 
 /**
 if (status == SNMP_CLASS_SUCCESS)   
    {  
     pdu.get_vb(vb,0);
	 vb.get_value(r1);
     pdu.get_vb(vb,1);
	 vb.get_value(r2);
	 res=true;
   	}
***/

 if (status == SNMP_CLASS_SUCCESS)   
 {
	 const char* reply_value;
	 pdu.get_vb(vb,0);
	 reply_value=vb.get_printable_value();
	 r1=atoi(reply_value);
	 pdu.get_vb(vb,1);
	 vb.get_value(r2);
	 res=true;
   	}


 else
    res=false;
	
Snmp::socket_cleanup();
return res; 
}


