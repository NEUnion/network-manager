// LineChart.h: interface for the CLineChart class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINECHART_H__754AC4E3_07E2_4566_8B88_16C1ACC0BDDB__INCLUDED_)
#define AFX_LINECHART_H__754AC4E3_07E2_4566_8B88_16C1ACC0BDDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AfxTempl.h"
class CLineChart : public CStatic
{
public:
	CLineChart(CSize cs,int row,int C_or_M);

// Attributes
protected:

	int StartPos;
int oldX,oldY;
CString title;
CFont tFont; 
CSize ChartSize; 
int Count;
unsigned long Number,yMax,Temp_yMax;
unsigned long xAverage;
float yAverage;
unsigned long x_Max,x_Min,y_Max,y_Min;
int interval;
int C_or_M;  //显示CPU或MER的标识
struct LineData
{
	unsigned long x;
	unsigned long y;
	int xUse;
	int yUse;
	CString xTime;
	bool show;
};

CArray <LineData,LineData&> ArrayData;
// Operations
public:
void Append(unsigned long  x1,unsigned long  y1,CString tt,int ux,int uy);
void SetTitle(CString str);
	void MoveSubs();
//void ChangeInt(int x);


// Implementation
public:
	virtual ~CLineChart();

	// Generated message map functions
protected:
	UINT m_move;
	//{{AFX_MSG(CLineChart)
	afx_msg void OnPaint();
	//}}AFX_MSG

DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_LINECHART_H__754AC4E3_07E2_4566_8B88_16C1ACC0BDDB__INCLUDED_)
