#include "CTriangle.h"
#include<math.h>
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	type = 3;

	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	double s=(Corner1.x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-Corner2.y))/(double)2;
	Area=sqrt(s*s);
	float d1,d2,d3;
	d1=(Corner1.x-Corner2.x)*(Corner1.x-Corner2.x)+(Corner1.y-Corner2.y)*(Corner1.y-Corner2.y);
	distance1=sqrt(d1);
	d2=(Corner2.x-Corner3.x)*(Corner2.x-Corner3.x)+(Corner2.y-Corner3.y)*(Corner2.y-Corner3.y);
	distance2=sqrt(d2);
	d3=(Corner3.x-Corner1.x)*(Corner3.x-Corner1.x)+(Corner3.y-Corner1.y)*(Corner3.y-Corner1.y);
	distance3=sqrt(d3);
	perimeter=distance1+distance2+distance3;
	if((Corner1.x-Corner2.x)!=0)
	{
	slope1=(Corner1.y-Corner2.y)/(double)(Corner1.x-Corner2.x);
	}
	else slope1=99999999;
	if((Corner2.x-Corner3.x)!=0)
	{
	slope2=(Corner2.y-Corner3.y)/(double)(Corner2.x-Corner3.x);
	}
	else slope2=99999999;
	if((Corner3.x-Corner1.x)!=0)
	{
	slope1=(Corner3.y-Corner1.y)/(double)(Corner3.x-Corner1.x);
	}
	else slope3=99999999;
	tempFigGfxInfo = FigureGfxInfo;
}
	

void CTriangle::Draw(Output* pOut) const
{
	if (istemp())
		pOut->DrawTriangle(temp1, temp2,temp3, tempFigGfxInfo, Selected);
	else
	//Call Output::DrawTri to draw a rectangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::GetFigure(int x, int y)
{
	Point Q1;
	Point Q2;
	Point Q3;
	double a;
	if (istemp()) {
		Q1 = temp1;
		Q2 = temp2;
		Q3 = temp3;
		
	}
	else {
		Q1 = Corner1;
		Q2 = Corner2;
		Q3 = Corner3;
	

	}

	double s = (Q1.x*(Q2.y - Q3.y) + Q2.x*(Q3.y - Q1.y) + Q3.x*(Q1.y - Q2.y)) / (double)2;
	a = sqrt(s*s);
	double s1=(x*(Q2.y-Q3.y)+Q2.x*(Q3.y-y)+Q3.x*(y-Q2.y))/(double)2;
	double s2=(Q1.x*(y-Q3.y)+x*(Q3.y-Q1.y)+Q3.x*(Q1.y-y))/(double)2;
	double s3=(Q1.x*(Q2.y-y)+Q2.x*(y-Q1.y)+x*(Q1.y-Q2.y))/(double)2;

	double a1=sqrt(s1*s1);
	double a2=sqrt(s2*s2);
	double a3=sqrt(s3*s3);
	if((a1+a2+a3)==a)
	{
		return true;
	}
	return false;
}
void CTriangle::PrintInfo(Output* pOut)
{
	/*pOut->PrintMessage("perimeter =");*/
	string s="ID =";
	std::string s1 = std::to_string(ID);
	string s2=" ";
	string s3="Perimeter= ";
	string s4= std::to_string(perimeter);
	string s5=" Area=";
	string s6= std::to_string(Area);
	string s7="  point1=(";
	string s8= std::to_string(Corner1.x);
	string s71=",";
	string s72=std::to_string(Corner1.y);
	string s73=")";
	string s9="  Point2=(";
	string s10= std::to_string(Corner2.x);
	string s11=",";
	string s12= std::to_string(Corner2.y);
	string s13=")";

	string s14="  Point3=(";
	string s15= std::to_string(Corner3.x);
	string s16=",";
	string s17= std::to_string(Corner3.y);
	string s18=")";


	std::stringstream ss;
	ss <<s3<<s4<<s2<<s<<s1<<s2<<s5<<s6<<s7<<s8<<s71<<s72<<s73<<s9<<s10<<s11<<s12<<s13<<s14<<s15<<s16<<s17<<s18;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
}
void CTriangle::Save(ofstream &OutFile) {
	CFigure*fig;
	this->notSaved=false;
	int x = this->getID();

	OutFile << "TRIANGLE       ";
	OutFile << x<<"   ";
	OutFile << Corner1.x<<"  ";
	OutFile << Corner1.y << "  ";
	OutFile << Corner2.x << "  ";
	OutFile << Corner2.y << "  ";
	OutFile << Corner3.x << "  ";
	OutFile << Corner3.y << "  ";

	color c=FigGfxInfo.DrawClr;
		
	OutFile<<checkColor(c);
	color fc=FigGfxInfo.FillClr;
	if(FigGfxInfo.isFilled==true)
	{
		OutFile<<checkColor(fc);

	}
	else if(FigGfxInfo.isFilled==false)OutFile<< "   NO_FILL";

	OutFile<<" "<<FigGfxInfo.BorderWdth;



}
void CTriangle::Load(ifstream &inputfile)
{
	inputfile>>ID;
	inputfile>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y>>Corner3.x>>Corner3.y;
	string c;
	inputfile>>c;
	FigGfxInfo.DrawClr=inverseCheckColor(c);
	string fc;
	inputfile>>fc;
	if(fc!="NO_FILL")
	{
	FigGfxInfo.FillClr=inverseCheckColor(fc);
	FigGfxInfo.isFilled=true;
	}
	else if(fc=="NO_FILL")
	{
		FigGfxInfo.isFilled=false;
	}
	inputfile>>FigGfxInfo.BorderWdth;
}
void CTriangle::Resize(float size)
{
	int xnew=(Corner2.x-Corner1.x)*size+Corner1.x;
	int ynew=(Corner2.y-Corner1.y)*size+Corner1.y;
	int oldx2=Corner2.x;
	int oldy2=Corner2.y;
	Corner2.x=xnew;
	Corner2.y=ynew;
	int xnew1=(Corner3.x-Corner1.x)*size+Corner1.x;
	int ynew1=(Corner3.y-Corner1.y)*size+Corner1.y;
	int oldx3=Corner3.x;
	int oldy3=Corner3.y;
	Corner3.x=xnew1;
	Corner3.y=ynew1;
	if (Corner1.y <= UI.ToolBarHeight || Corner2.y <= UI.ToolBarHeight || Corner3.y <= UI.ToolBarHeight || Corner1.y >= (UI.height - UI.StatusBarHeight) || Corner2.y >= (UI.height - UI.StatusBarHeight) || Corner3.y >= (UI.height - UI.StatusBarHeight)||Corner1.x<0||Corner1.x>UI.width||Corner2.x<0||Corner2.x>UI.width||Corner3.x<0||Corner3.x>UI.width)
	{
		Corner2.x=oldx2;
		Corner2.y=oldy2;
		Corner3.x=oldx3;
		Corner3.y=oldy3;
	}

}
void CTriangle::Move(Point p,bool IsFirst,Point &dp,bool &allGood)
{
	if(IsFirst==true)
	{
		if(Corner1.x==getTopPoint().x&&Corner1.y==getTopPoint().y)
		{
		dp=Get2ndPoint(p,Corner1);
		Corner1=p;
		Corner2.x=Corner2.x+dp.x;
		Corner2.y=Corner2.y+dp.y;
		Corner3.x=Corner3.x+dp.x;
		Corner3.y=Corner3.y+dp.y;
		}
		else if(Corner2.x==getTopPoint().x&&Corner2.y==getTopPoint().y)
		{
			dp=Get2ndPoint(p,Corner3);
		Corner2=p;
		Corner1.x=Corner1.x+dp.x;
		Corner1.y=Corner1.y+dp.y;
		Corner3.x=Corner3.x+dp.x;
		Corner3.y=Corner3.y+dp.y;
		}
		else if(Corner3.x==getTopPoint().x&&Corner3.y==getTopPoint().y)
		{
			dp=Get2ndPoint(p,Corner3);
		Corner3=p;
		Corner1.x=Corner1.x+dp.x;
		Corner1.y=Corner1.y+dp.y;
		Corner2.x=Corner2.x+dp.x;
		Corner2.y=Corner2.y+dp.y;
		}
		if (Corner1.y <= UI.ToolBarHeight || Corner2.y <= UI.ToolBarHeight || Corner3.y <= UI.ToolBarHeight || Corner1.y >= (UI.height - UI.StatusBarHeight) || Corner2.y >= (UI.height - UI.StatusBarHeight) || Corner3.y >= (UI.height - UI.StatusBarHeight)||Corner1.x<0||Corner1.x>UI.width||Corner2.x<0||Corner2.x>UI.width||Corner3.x<0||Corner3.x>UI.width)
		{
			allGood=false;
		}
		else allGood=true;
	}
	else
	{
		Corner1.x=Corner1.x+dp.x;
		Corner1.y=Corner1.y+dp.y;
		Corner2.x=Corner2.x+dp.x;
		Corner2.y=Corner2.y+dp.y;
		Corner3.x=Corner3.x+dp.x;
		Corner3.y=Corner3.y+dp.y;
		if (Corner1.y <= UI.ToolBarHeight || Corner2.y <= UI.ToolBarHeight || Corner3.y <= UI.ToolBarHeight || Corner1.y >= (UI.height - UI.StatusBarHeight) || Corner2.y >= (UI.height - UI.StatusBarHeight) || Corner3.y >= (UI.height - UI.StatusBarHeight)||Corner1.x<0||Corner1.x>UI.width||Corner2.x<0||Corner2.x>UI.width||Corner3.x<0||Corner3.x>UI.width)
		{
			allGood=false;
		}
		else allGood=true;
	}
}
Point CTriangle::getTopPoint()
{
	double d1=sqrt((Corner1.x)*(Corner1.x)+(Corner1.y)*(Corner1.y));
	double d2=sqrt((Corner2.x)*(Corner2.x)+(Corner2.y)*(Corner2.y));
	double d3=sqrt((Corner3.x)*(Corner3.x)+(Corner3.y)*(Corner3.y));
	if(d1<=d2&&d1<=d3)
	{
		if(d1==d2)
		{
			return Corner1;
		}
		else if(d1==d3)
		{
			return Corner1;
		}
		else return Corner1;

		
	}
	else if(d2<=d1&&d2<=d3)
	{
		if(d2==d1)
		{
			return Corner1;
		}
		else if(d2==d3)
		{
			return Corner2;
		}
		else return Corner2;
	}
	else if(d3<=d2&&d3<=d1)
	{
		if(d3==d1)
		{
			return Corner1;
		}
		else if(d2==d3)
		{
			return Corner2;
		}
		else return Corner3;
	}
}
CFigure* CTriangle:: CPY()
{
	CFigure* ptr = new CTriangle(*this);
	return ptr;
}
void CTriangle::Rotate(int angle) {}
void CTriangle::zoom(Point p, double r) {

		//double r = 0.5;//ratio
		double s;//slope
		Point d;//destination point
		Point c;//center point
		Point o;//original point
		int sign;

		if (istemp())
			o = temp1;
		else
		{o = Corner1;
		tempFigGfxInfo = FigGfxInfo;
		}
		/*o.x = Corner1.x;
		o.y = Corner1.y;*/
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
			o = Corner2;
		/*o.x = Corner2.x;
		o.y = Corner2.y;*/
		s = (double)(o.y - c.y) / (o.x - c.x);
		if (c.x<o.x)sign = 1;
		if (c.x >= o.x)sign = -1;
		d.x = c.x + sign* (sqrt((r*r*(((o.x - c.x)*(o.x - c.x)) + ((o.y - c.y)*(o.y - c.y)))) / (s*s + 1)));
		d.y = (s*(d.x - c.x)) + c.y;
		temp2.y = d.y;
		temp2.x = d.x;

		if (istemp())
			o = temp3;
		else
			o = Corner3;
		/*o.x = Corner3.x;
		o.y = Corner3.y;*/
		s = (double)(o.y - c.y) / (o.x - c.x);
		if (c.x<o.x)sign = 1;
		if (c.x >= o.x)sign = -1;
		d.x = c.x + sign* (sqrt((r*r*(((o.x - c.x)*(o.x - c.x)) + ((o.y - c.y)*(o.y - c.y)))) / (s*s + 1)));
		d.y = (s*(d.x - c.x)) + c.y;
		temp3.y = d.y;
		temp3.x = d.x;
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