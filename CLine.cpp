#include "CLine.h"
#include <math.h>
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	type = 4;

	if(Point2.x-Point1.x!=0)
	{
	slope=(Point2.y-Point1.y)/(double)(Point2.x-Point1.x);
	}
	else if(Point2.x-Point1.x==0)
	{
		slope=9999999999;
	}
	float d2=(Point1.x-Point2.x)*(Point1.x-Point2.x)+(Point1.y-Point2.y)*(Point1.y-Point2.y);
	distance=sqrt(d2);
	Area = distance;
	tempFigGfxInfo = FigureGfxInfo;

}
void CLine::Draw(Output* pOut) const
{
	if(istemp())
		pOut->DrawLine(temp1, temp2, tempFigGfxInfo, Selected);
	else
	//Call Output::DrawTri to draw a rectangle on the screen	
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}
void CLine::Resize(float size)
{
	int xnew=(Point2.x-Point1.x)*size+Point1.x;
	int ynew=(Point2.y-Point1.y)*size+Point1.y;
	int oldx=Point2.x;
	int oldy=Point2.y;
	Point2.x=xnew;
	Point2.y=ynew;
	if (Point1.y <= UI.ToolBarHeight || Point2.y <= UI.ToolBarHeight || Point1.y >= (UI.height - UI.StatusBarHeight) || Point2.y >= (UI.height - UI.StatusBarHeight)||Point1.x<0||Point1.x>UI.width||Point2.x<0||Point2.x>UI.width)
	{
		Point2.x=oldx;
		Point2.y=oldy;
	}

}
bool CLine::GetFigure(int x,int y)
{
	Point Q1;
	Point Q2;
	if (istemp()){
		Q1 = temp1;
		Q2 = temp2;

	}
	else{
		Q1 = Point1;
		Q2 = Point2;

	}


	if (((Q2.x - Q1.x) != 0) && (((x - Q1.x) != 0)))
	{

		float slope1 = (Q2.y - Q1.y) / (float)(Q2.x - Q1.x);
		float slope2 = (y - Q1.y) / (float)(x - Q1.x);
		slope1 = slope1 * 100;
		slope1 = (int)slope1;
		slope1 = slope1 / 100;
		slope2 = slope2 * 100;
		slope2 = (int)slope2;
		slope2 = slope2 / 100;
		if ((slope1 == slope2) || (abs(slope1 - slope2) <= 0.08))
		{
			if ((x >= Q1.x) && (x <= Q2.x))
			{
				if ((y >= Q1.y) && (y <= Q2.y))
				{
					return true;
				}
				else if ((y <= Q1.y) && (y >= Q2.y))
				{
					return true;
				}
			}
			else if ((x <= Q1.x) && (x >= Q2.x))
			{
				if ((y <= Q1.y) && (y >= Q2.y))
				{
					return true;
				}
				else if ((y >= Q1.y) && (y <= Q2.y))
				{
					return true;
				}
			}
		}
	}
	else if (((Q2.x - Q1.x) == 0))
	{
		if ((x >= Q1.x) && (x <= Q2.x))
		{

			if ((y >= Q1.y) && (y <= Q2.y))
			{
				return true;
			}
			else if ((y <= Q1.y) && (y >= Q2.y))
			{
				return true;
			}

		}
		else if ((x <= Q1.x) && (x >= Q2.x))
		{
			if ((y <= Q1.y) && (y >= Q2.y))
			{
				return true;
			}
			else if ((y >= Q1.y) && (y <= Q2.y))
			{
				return true;
			}
		}
	}
	return false;
}
void CLine::PrintInfo(Output* pOut)
{
	string s="Slope =";
	std::string s1 = std::to_string(slope);
	string s2=" ";
	string s3="ID= ";
	string s4= std::to_string(ID);
	string s5="  Distance=";
	string s6= std::to_string(distance);
	string s7="  point1=(";
	string s8= std::to_string(Point1.x);
	string s71=",";
	string s72=std::to_string(Point1.y);
	string s73=")";
	string s9="  Point2=(";
	string s10= std::to_string(Point2.x);
	string s11=",";
	string s12= std::to_string(Point2.y);
	string s13=")";


	std::stringstream ss;
	ss <<s3<<s4<<s2<<s<<s1<<s2<<s5<<s6<<s7<<s8<<s71<<s72<<s73<<s9<<s10<<s11<<s12<<s13;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
}
void CLine::Save(ofstream &OutFile)
{
	this->notSaved=false;
	int x = this->getID();

	OutFile << "LINE           ";
	OutFile << x << "  ";
	OutFile << Point1.x << "  ";
	OutFile << Point1.y << "  ";
	OutFile << Point2.x << "  ";
	OutFile << Point2.y << "  ";
	color c;
	c.ucBlue=FigGfxInfo.DrawClr.ucBlue;
	c.ucGreen=FigGfxInfo.DrawClr.ucGreen;
	c.ucRed=FigGfxInfo.DrawClr.ucRed;
	OutFile<<checkColor(c);
	OutFile<<" "<<FigGfxInfo.BorderWdth;



}
void CLine::Load(ifstream &inputfile)
{
	inputfile>>ID;
	inputfile>>Point1.x>>Point1.y>>Point2.x>>Point2.y;
	string c;
	inputfile>>c;
	FigGfxInfo.DrawClr=inverseCheckColor(c);
	if(Point2.x-Point1.x!=0)
	{
	slope=(Point2.y-Point1.y)/(Point2.x-Point1.x);
	}
	else if(Point2.x-Point1.x==0)
	{
		slope=9999999999;
	}
	inputfile>>FigGfxInfo.BorderWdth;
}
void CLine::Move(Point p,bool IsFirst,Point &dp,bool &allGood)
{
	if(IsFirst==true)
	{
		if(Point1.x==getTopPoint().x&&Point1.y==getTopPoint().y)
		{
		dp=Get2ndPoint(p,Point1);
		Point1=p;
		Point2.x=Point2.x+dp.x;
		Point2.y=Point2.y+dp.y;
		}
		if(Point2.x==getTopPoint().x&&Point2.y==getTopPoint().y)
		{
		dp=Get2ndPoint(p,Point2);
		Point2=p;
		Point1.x=Point1.x+dp.x;
		Point1.y=Point1.y+dp.y;
		}
		if (Point1.y <= UI.ToolBarHeight || Point2.y <= UI.ToolBarHeight || Point1.y >= (UI.height - UI.StatusBarHeight) || Point2.y >= (UI.height - UI.StatusBarHeight)||Point1.x<0||Point1.x>UI.width||Point2.x<0||Point2.x>UI.width)
		{
			allGood=false;
		}
		else allGood=true;

	}
	else
	{
		Point1.x=Point1.x+dp.x;
		Point1.y=Point1.y+dp.y;
		Point2.x=Point2.x+dp.x;
		Point2.y=Point2.y+dp.y;
		if (Point1.y <= UI.ToolBarHeight || Point2.y <= UI.ToolBarHeight || Point1.y >= (UI.height - UI.StatusBarHeight) || Point2.y >= (UI.height - UI.StatusBarHeight)||Point1.x<0||Point1.x>UI.width||Point2.x<0||Point2.x>UI.width)
		{
			allGood=false;
		}
		else allGood=true;
	}
}
Point CLine::getTopPoint()
{
	double d1=sqrt((Point1.x)*(Point1.x)+(Point1.y)*(Point1.y));
	double d2=sqrt((Point2.x)*(Point2.x)+(Point2.y)*(Point2.y));
	if(d1<d2)
	{
		return Point1;
	}
	else if(d1>d2)
	{
		return Point2;
	}
	else
	{
		return Point1;
	}
}
CFigure* CLine:: CPY()
{
	CFigure* ptr = new CLine(*this);
	return ptr;
}
void CLine::Rotate(int angle) {}
void CLine::zoom(Point p, double r) {

	//double r = 0.5;//ratio
	double s;//slope
	Point d;//destination point
	Point c;//center point
	Point o;//original point
	int sign;

	if (istemp())
		o = temp1;
	else
	{o = Point1;	
	tempFigGfxInfo = FigGfxInfo;
    }


	/*o.x = Point1.x;
	o.y = Point1.y;*/
	c.x = p.x;
	c.y = p.y;
	s = (double)(o.y - c.y) / (o.x - c.x);
	if (c.x<o.x)sign = 1;
	if (c.x >= o.x)sign = -1;

	d.x = c.x + sign* (sqrt((r*r*(((o.x - c.x)*(o.x - c.x)) + ((o.y - c.y)*(o.y - c.y)))) / (s*s + 1)));
	d.y = (s*(d.x - c.x)) + c.y;
	temp1.y = d.y;
	temp1.x = d.x;

	if (istemp())
		o = temp2;
	else
		o = Point2;
	/*o.x = Point2.x;
	o.y = Point2.y;*/
	s = (double)(o.y - c.y) / (o.x - c.x);
	if (c.x<o.x)sign = 1;
	if (c.x >= o.x)sign = -1;
	d.x = c.x + sign* (sqrt((r*r*(((o.x - c.x)*(o.x - c.x)) + ((o.y - c.y)*(o.y - c.y)))) / (s*s + 1)));
	d.y = (s*(d.x - c.x)) + c.y;
	temp2.y = d.y;
	temp2.x = d.x;

	if (istemp())
	{
		tempFigGfxInfo.BorderWdth = tempFigGfxInfo.BorderWdth*r;
	}


	else
	{
		tempFigGfxInfo.BorderWdth = FigGfxInfo.BorderWdth*r;
	}


	settemp(1);

}