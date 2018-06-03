#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <string>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int ClipCount;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool BKGDc;
	CFigure* Clipboard[MaxFigCount];
public:	
	ApplicationManager(); 
	~ApplicationManager();
	bool CheckBeforeLoad();
	bool checkbeforeexit();
	bool checkbeforeexit2();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType &) ; //Creates an action and executes it
	void DeleteSelected();
    void sendbselected();
	void bringfselected();
	void rotateselected(double angle);
	void zoomall( Point p, double r);
	void ChangeDrawingColor(ActionType);
	void ChangeDrawingColorSelected(ActionType);
	void ChangeFillingColor(ActionType);
	void ChangeFillingColorSelected(ActionType);
	void ChangeBkColor(ActionType);
	void ResizeSelected(ActionType);
	void ChangeBorder(ActionType);
	void ChangeBorderSelected(ActionType);
	void undo();
	void redo();
	void MoveSelected(Point P);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void insertfigfirst(CFigure* pFig); //Adds a new figure to the begining of FigList

	
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void Print();	
	void SaveAll(ofstream &OutFile);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void load(string );

	bool SeeSelected();
	CFigure* getFirstToMove();
	void CpyToClipboard();
	void PasteSelected(Point P);
	void dropFig();

	//playmode functions///////////////////////////////////////////////////////////
	void typecounter(int & r, int & c, int & t, int & l) const;
	pickgame *fillcorollist(int& n)const;
	int* areaorder(bool x)const;
	void movetoleft();
	void scramblefig();
	void undohidden();
	void undotemp();
	bool* saveselected()const;
	void unselectall();
	void undoselected(bool* list);
	CFigure* randomselect(  );
	void deletedublicate();
	//////////////////////////////////////////////////////////////////////////////////

};

#endif