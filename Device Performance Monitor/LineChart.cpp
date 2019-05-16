// LineChart.cpp: implementation of the CLineChart class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Rsh.h"
#include "LineChart.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//   CLineChart 初始化显示
//////////////////////////////////////////////////////////////////////

CLineChart::CLineChart(CSize cs,int row,int c_m)
{
	m_move=0;
	StartPos=0;
	oldX=-1;
	oldY=-1;
 title="";
 tFont.CreatePointFont(70,"楷体_GB2132",NULL);
 interval=50;
 Number=0;
 xAverage=0;
 yAverage=0;
 x_Max=0;
 y_Max=0;
 x_Min=1000000;
 y_Min=1000000;
 Count=row;
 ChartSize=cs;
 C_or_M=c_m;
 LineData ld;
 for (int i=0;i<=Count;i++)
 {
	 ld.x=0;
	 ld.y=0;
	 ld.xTime="";
     ld.show=false;
	 ArrayData.Add(ld);
 }
 yMax=5;
 Temp_yMax=0;
}


CLineChart::~CLineChart()
{
}
BEGIN_MESSAGE_MAP(CLineChart, CStatic)
	//{{AFX_MSG_MAP(CLineChart)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineChart message handlers
/////////////////////////////////////////////////////////////////////////////





void CLineChart::MoveSubs()
{
	m_move--;
}



void CLineChart::Append(unsigned long x1,unsigned long y1,CString tt,int ux,int uy)
{   

if(!C_or_M)
{
	if (yMax<100)
	   yMax=0;
	while (yMax<x1)
		yMax+=500;
}	
if ( C_or_M)
{
	if (y1>100) //如果CPU利用率超过100%，则数据非法
	      y1=0;
	while(yMax<y1)
		yMax+=3;
}
	if (x1>x_Max) 
		x_Max=x1;
	if (x1<x_Min)
		x_Min=x1;
	if (y1>y_Max) 
		y_Max=y1;
	if (y1<y_Min)
		y_Min=y1;
	for(int i=0;i<Count;i++)
	{
        ArrayData[i]=ArrayData[i+1];
	}
	ArrayData[Count].x=x1;
	ArrayData[Count].y=y1;
	ArrayData[Count].xTime=tt;
	ArrayData[Count].xUse=ux;
	ArrayData[Count].yUse=uy;
	ArrayData[Count].show=false;
	if ((Number % interval)==0)
        ArrayData[Count].show=true;
	Number+=1;
	xAverage=(x1+xAverage*(Number-1))/Number;
    yAverage=(y1+yAverage*(Number-1))/Number;
	this->Invalidate();
}


void CLineChart::SetTitle(CString str)
{
	title=str;
	this->Invalidate();
}


void CLineChart::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.Rectangle(0,0,ChartSize.cx,ChartSize.cy);

	////////////////////////////画动态网格背景///////////////////////////////////
	CRect rect(62,48,ChartSize.cx-38,ChartSize.cy-19);
	CBrush br(RGB(0,0,100));
	dc.FillRect(rect,&br);
	rect.left+=(m_move%10);
	rect.right+=(m_move%10);
	int i;
	CPen pen1(PS_SOLID,1,RGB(0,0,255));
	dc.SelectObject(pen1);
	for(i=rect.left;i<rect.right;i+=10)
	{
		
		dc.MoveTo(CPoint(i,rect.top));
		dc.LineTo(CPoint(i,rect.bottom));
	}
	for(i=rect.top;i<=rect.bottom;i+=10)
	{
		dc.MoveTo(CPoint(462,i));
		dc.LineTo(CPoint(62,i));
	}
	
	/////////////////////////////////////////////////////////////////////

    CString str;
	int height,width;

    CPoint Start,xEnd,yEnd,temp;
	//确定坐标系，画X轴；
	Start.x=60;
	Start.y=ChartSize.cy-20;
	dc.MoveTo(Start);
	xEnd.x=60+Count;
	//X轴表示数据的宽度为Count+1=289个像素,一个像素对应数组
	//中的一个元素；
   	xEnd.y=Start.y;
	width=xEnd.x-Start.x;
	dc.LineTo(xEnd.x+5,xEnd.y);
	dc.TextOut(xEnd.x+8,xEnd.y-8,"时间");
	//画X轴箭头；
	dc.LineTo(xEnd.x,xEnd.y-3);
	dc.MoveTo(xEnd.x+5,xEnd.y);
	dc.LineTo(xEnd.x,xEnd.y+3);
	//画Y轴；
	dc.MoveTo(Start);
	yEnd.y=40;
	yEnd.x=Start.x;
	height=Start.y-yEnd.y;
	//计算Y轴每点对应的数值，这里如使用整型会影响精度；
    float n=(float)yMax/(height-10);
	height=(height-10)/5;
	//Y轴以及箭头；
	dc.LineTo(yEnd);
    dc.LineTo(yEnd.x-3,yEnd.y+5);
	dc.MoveTo(yEnd);
	dc.LineTo(yEnd.x+3,yEnd.y+5);
	dc.TextOut(yEnd.x-10,yEnd.y-20,"数据");
    //画Y轴虚线，标注刻度值；
	CPen pen,*pPen;
   pen.CreatePen(PS_DOT,1,RGB(100,100,100));
   pPen=dc.SelectObject(&pen);
    dc.TextOut(60-9,Start.y-7,"0");
	CString yText;

	

    dc.SelectObject(pPen);
	pen.DeleteObject();
	dc.MoveTo(Start.x+Count+1,Start.y-5*height);
    dc.LineTo(Start.x+Count+1,Start.y);
	//画X轴坐标线；
	int xW=(width/20+0.5);
	for ( i=1;i<=20;i++)
	{
      dc.MoveTo(Start.x+i*xW,Start.y-3);
	  dc.LineTo(Start.x+i*xW,Start.y+3);
	}


if (C_or_M)
{
	//纵坐标刻度
	float yCo;
	for (  i=0;i<5;i++)
	{
		yCo=(i+1)*((float)yMax/5);
		yText.Format("%.1f",yCo);
		dc.TextOut(60-yText.GetLength()*9,Start.y-(i+1)*height-7,yText);
	}

	//画曲线CPU
	temp.y=Start.y-(int)(ArrayData[StartPos].y/n+0.5);
	temp.x=Start.x;
	pen.CreatePen(PS_SOLID,1,RGB(0,255,0));
    pPen=dc.SelectObject(&pen);
    dc.MoveTo(temp);
	for ( i=0;i<=Count;i++)
	{
		temp.y=Start.y-(int)(ArrayData[i+StartPos].y/n+0.5);
		temp.x+=1;
		dc.LineTo(temp);
		if (ArrayData[i+StartPos].show)
		{   
			int n=dc.SetBkMode(TRANSPARENT);
			CFont* pOld=dc.SelectObject(&tFont);
			dc.TextOut(temp.x-4,Start.y+6,ArrayData[i+StartPos].xTime);
			dc.SelectObject(pOld);
			dc.SetBkMode(n);
		}
		
	}
	
	dc.SelectObject(pPen);
	pen.DeleteObject();
}
if(!C_or_M)
{

	//纵坐标刻度
	int yCo;
	for (  i=0;i<5;i++)
	{
		yCo=(i+1)*(yMax/5);
		yText.Format("%d",yCo);
		dc.TextOut(60-yText.GetLength()*9,Start.y-(i+1)*height-7,yText);
	}

		//画曲线MER
		temp.y=Start.y-(int)(ArrayData[StartPos].x/n+0.5);
		temp.x=Start.x;
		pen.CreatePen(PS_SOLID,1,RGB(0,255,0));
		pPen=dc.SelectObject(&pen);
		dc.MoveTo(temp);
		for (int i=1;i<=Count;i++)
		{
			temp.y=Start.y-(int)(ArrayData[i+StartPos].x/n+0.5);
			temp.x+=1;
			dc.LineTo(temp);

			if (ArrayData[i+StartPos].show)
			{   
				int n=dc.SetBkMode(TRANSPARENT);
				CFont* pOld=dc.SelectObject(&tFont);
				dc.TextOut(temp.x-4,Start.y+6,ArrayData[i+StartPos].xTime);
				dc.SelectObject(pOld);
				dc.SetBkMode(n);
			}
		}
		dc.SelectObject(pPen);
    	pen.DeleteObject();
}


	//如果标住了时间，画一条虚竖线；
 pen.CreatePen(PS_DOT,1,RGB(100,100,100));
 pPen=dc.SelectObject(&pen);
  for ( i=0;i<=Count;i++)
  {
     if (ArrayData[i+StartPos].show)
	  {   
		  dc.MoveTo(Start.x+i,Start.y);
		  dc.LineTo(Start.x+i,Start.y-5*height);
	  }
	}
 dc.SelectObject(pPen);
  pen.DeleteObject();










	//画标题；  
	dc.TextOut(yEnd.x+20+ChartSize.cx/4,10,title);
	CPoint Message;
	Message.x=ChartSize.cx;
	Message.y=0;
    dc.Rectangle(Message.x,Message.y,Message.x+140,Message.y+150);
	dc.TextOut(Message.x+30,Message.y+4,"信息显示区");

if (C_or_M)
{
	dc.TextOut(Message.x+1,Message.y+25,"☆☆  单位:  % ☆☆");

	str.Format("%d",ArrayData[Count+StartPos].y);
	str="当前CPU值: "+str;
	dc.TextOut(Message.x+18,Message.y+52,str);

	str.Format("%d",y_Min);
	str="最小CPU值: "+str;
	dc.TextOut(Message.x+18,Message.y+73,str);

	str.Format("%d",y_Max);
	str="最大CPU值: "+str;
	dc.TextOut(Message.x+18,Message.y+94,str);

	str.Format("%.1f",yAverage);
	str="平均CPU值: "+str;
	dc.TextOut(Message.x+18,Message.y+115,str);
} 
else
{
    dc.TextOut(Message.x+1,Message.y+25,"☆☆ 单位:MB ☆☆");

	str.Format("%d",ArrayData[Count+StartPos].x);
	str="当前内存值: "+str;
	dc.TextOut(Message.x+18,Message.y+52,str);

	str.Format("%d",x_Min);
	str="最小内存值: "+str;
	dc.TextOut(Message.x+18,Message.y+73,str);

	str.Format("%d",x_Max);
	str="最大内存值: "+str;
	dc.TextOut(Message.x+18,Message.y+94,str);

	str.Format("%d",xAverage);
	str="平均内存值: "+str;
	dc.TextOut(Message.x+18,Message.y+115,str);

}

}










