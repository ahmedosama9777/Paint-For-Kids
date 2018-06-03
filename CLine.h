#ifndef CLINE_H
#define CLINE_H
#include "Figures\CFigure.h"
class CLine : public CFigure
{
private:
	Point Point1;	
	Point Point2;
	double slope;
	int distance;
	Point temp1;
	Point temp2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);
	virtual bool GetFigure(int x,int y);
	virtual void Rotate(int angle);

	virtual void zoom(Point p, double r);

	virtual void Save(ofstream &OutFile);
	void Load(ifstream &inputfile);
	virtual void Resize(float);

	virtual void Move(Point p,bool IsFirst,Point &dp,bool &allGood);
	virtual Point getTopPoint();
	virtual CFigure* CPY();
};
#endif