#ifndef CCIRC_H
#define CCIRC_H

#include "Figures\CFigure.h"

#include<string>
class CCircle : public CFigure
{
private:
	Point p1;	
	Point p2;
	int Radius;
	int Circum;
	Point temp1;
	int tempR;
public:
	CCircle(Point , int Radius, GfxInfo FigureGfxInfo );
	/*CCircle(const CCircle &c);*/
	virtual void Draw(Output* pOut) const;
	virtual bool GetFigure(int x,int y);
	virtual void Rotate(int angle);
	virtual void zoom(Point p,double r);
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream &OutFile);
	void Load(ifstream &inputfile);
	virtual void Resize(float);

	virtual void Move(Point p,bool IsFirst,Point &dp,bool &allGood);
	virtual Point getTopPoint();
	virtual CFigure* CPY();
};



#endif
