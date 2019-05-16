; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTrapView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Trap.h"
LastPage=0

ClassCount=7
Class1=CTrapApp
Class2=CTrapDoc
Class3=CTrapView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDD_TRAP_FORM
Class6=CScan
Resource4=IDD_CONFIG
Class7=CMessage
Resource5=IDD_DIALOG1

[CLS:CTrapApp]
Type=0
HeaderFile=Trap.h
ImplementationFile=Trap.cpp
Filter=N

[CLS:CTrapDoc]
Type=0
HeaderFile=TrapDoc.h
ImplementationFile=TrapDoc.cpp
Filter=N

[CLS:CTrapView]
Type=0
HeaderFile=TrapView.h
ImplementationFile=TrapView.cpp
Filter=W
LastObject=CTrapView
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
LastObject=ID_CONFIG
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Trap.cpp
ImplementationFile=Trap.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_START
Command3=ID_END
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_TRAP_FORM]
Type=1
Class=CTrapView
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1353777156

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_START
Command2=ID_END
Command3=ID_APP_ABOUT
CommandCount=3

[DLG:IDD_CONFIG]
Type=1
Class=CScan
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control7=IDC_FINISH,button,1342242816

[CLS:CScan]
Type=0
HeaderFile=Scan.h
ImplementationFile=Scan.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_FINISH

[DLG:IDD_DIALOG1]
Type=1
Class=CMessage
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308364
Control3=IDC_EDIT1,edit,1352728580

[CLS:CMessage]
Type=0
HeaderFile=Message.h
ImplementationFile=Message.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

