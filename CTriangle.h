#ifndef CTRI_H
#define CTRI_H

#include "Figures\CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
	Point temp1;
	Point temp2;
	Point temp3;
	int perimeter;
	float distance1;//distance between corner1 and corner 2
	float distance2;// distance between corner2 and corner 3
	float distance3;//distance between corner 3 and corner 1
	double slope1;
	double slope2;
	double slope3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool GetFigure(int x,int y);
	virtual void Rotate(int angle);
	virtual void zoom(Point p, double r);

	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream &OutFile);
	void Load(ifstream &inputfile);
  virtual void Resize(float);

	virtual void Move(Point p,bool IsFirst,Point &dp,bool &allGood);
	virtual Point getTopPoint();
	virtual CFigure* CPY();
};
#endif