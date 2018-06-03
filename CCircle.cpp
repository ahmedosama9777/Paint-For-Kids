#include "CCircle.h"
#include <math.h>
#include <sstream>
#include <string>
#include<fstream>
#include<cmath>
#include<iostream>
using namespace std;
CCircle::CCircle(Point P1, int radius, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo),Radius(radius)
{
	p1 = P1;
	Area=(3.14)*Radius*Radius;
	Circum=(3.14)*2*Radius;
	type = 2;
	tempFigGfxInfo = FigureGfxInfo;
}
	

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	if (istemp())
		pOut->DrawCircle(temp1, tempR, tempFigGfxInfo, Selected);
	else
		pOut->DrawCircle(p1, Radius, FigGfxInfo, Selected);


}
bool CCircle::GetFigure(int x, int y)
{
	int r;
	Point g;
	if (istemp())
	{
		g = temp1; r = tempR;
     }

	else
	{
		g = p1;
		r = Radius;
	}

	float d=(g.x-x)*(g.x-x)+(g.y-y)*(g.y-y);
	float distance=sqrt(d);

	if(distance<=r)
	{
		return true;
	}
	else return false;
	

}
void CCircle::PrintInfo(Output* pOut)
{
	string s="Radius :";
	std::string s1 = std::to_string(Radius);
	string s2=" ";
	string s3="ID= ";
	string s4= std::to_string(ID);
	string s5="  Area=";
	string s6= std::to_string(Area);
	string s7="  Circum=";
	string s8= std::to_string(Circum);
	string s9="  Center=(";
	string s10= std::to_string(p1.x);
	string s11=",";
	string s12= std::to_string(p1.y);
	string s13=")";


	std::stringstream ss;
	ss <<s3<<s4<<s2<<s<<s1<<s2<<s5<<s6<<s7<<s8<<s9<<s10<<s11<<s12<<s13;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
	/*string radius;
	stringstream ss;
	ss << (char)Radius;
	ss >> radius;
	pOut->PrintMessage(radius);
	cout<<Radius<<endl;
	cout<<radius<<endl;*/
}
void CCircle::Save(ofstream &OutFile) {

	this->notSaved=false;
	int x = this->getID();
	OutFile << "CIRCLE         ";
	OutFile <<x << "  " ;
	OutFile << p1.x << "  ";
	OutFile << p1.y << "  ";
	OutFile << Radius << "  ";


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
void CCircle::Load(ifstream &inputfile)
{
	inputfile>>ID;
	inputfile>>p1.x>>p1.y>>Radius;
	string c;
	string fc;
	inputfile>>c>>fc;
	FigGfxInfo.DrawClr=inverseCheckColor(c);
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
void CCircle::Resize(float size)
{
	Radius*=size;
	if ((p1.x - Radius) <= 0 ||(p1.x + Radius) >= UI.width || (p1.y - Radius) <= UI.ToolBarHeight || (p1.y + Radius) >= (UI.height - UI.StatusBarHeight) || p1.y <= UI.ToolBarHeight || p1.y >= (UI.height - UI.StatusBarHeight)||Radius <= UI.ToolBarHeight || Radius >= (UI.height - UI.StatusBarHeight) )
	{
		Radius=Radius/size;
	}
}

void CCircle::Move(Point p,bool IsFirst,Point &dp,bool &allGood)
{
	if(IsFirst==true)
	{
		dp=Get2ndPoint(p,p1);
		p1=p;
		if ((p1.x - Radius) <= 0 ||(p1.x + Radius) >= UI.width || (p1.y - Radius) <= UI.ToolBarHeight || (p1.y + Radius) >= (UI.height - UI.StatusBarHeight) || p1.y <= UI.ToolBarHeight || p1.y >= (UI.height - UI.StatusBarHeight)||Radius <= UI.ToolBarHeight || Radius >= (UI.height - UI.StatusBarHeight) )
		{
			allGood=false;
			

		}
		else allGood=true;
	}
	else
	{
		p1.x=p1.x+dp.x;
		p1.y=p1.y+dp.y;
		if ((p1.x - Radius) <= 0 || (p1.x + Radius) >= UI.width || (p1.y - Radius) <= UI.ToolBarHeight || (p1.y + Radius) >= (UI.height - UI.StatusBarHeight) || p1.y <= UI.ToolBarHeight || p1.y >= (UI.height - UI.StatusBarHeight)||Radius <= UI.ToolBarHeight || Radius >= (UI.height - UI.StatusBarHeight) )
		{
			allGood=false;
		}
		else allGood=true;
	}
}
Point CCircle::getTopPoint()
{
	return p1;
}
CFigure* CCircle:: CPY()
{
	CFigure* ptr = new CCircle(*this);
	return ptr;
}
void CCircle::Rotate(int angle) {}
void CCircle::zoom(Point p, double r) {
	//double r = 0.5;//ratio
	double s;//slope
	Point d;//destination point
	Point c;//center point
	Point o;//original point
	int sign;


	if (istemp())
		o = temp1;
	else
	{
		o = p1;
		tempFigGfxInfo = FigGfxInfo;
	}


/*	o.x = p1.x;
	o.y =p1.y;*/
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
	{
		tempR = tempR *r;
		tempFigGfxInfo.BorderWdth = tempFigGfxInfo.BorderWdth*r;
	}

	
	else
	{
		tempR = Radius *r;
		tempFigGfxInfo.BorderWdth = FigGfxInfo.BorderWdth*r;
	}
	settemp(1);

}