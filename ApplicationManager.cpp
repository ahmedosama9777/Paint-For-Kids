#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "SelectAction.h"
#include "DeleteAction.h"
#include "AddCircleAction.h"
#include "AddLineAction.h"
#include "AddTriAction.h"
#include "SaveAction.h"
#include"CCircle.h"
#include "CTriangle.h"
#include "CLine.h"
#include"Figures\CRectangle.h"
#include"LoadAction.h"
#include <sstream>
#include<iostream>
#include "PickAction.h"
#include "SwitchplayAction.h"
#include"ChangeDrawColor.h"
#include "ChangeFillColor.h"
#include"ChangeBackgroundColor.h"
#include"ResizeAction.h"
#include"ChangeWidthAction.h"
#include"MoveAction.h"
#include "PasteAction.h"
#include "CutAction.h"
#include "CopyAction.h"
#include "SendBAction.h"
#include "BringFAction.h"
#include "RotateAction.h"
#include "ZoomAction.h"
#include "ScrambleAction.h"
#include"RedoStack.h"
#include"UndoStack.h"
#include"UndoAction.h"
#include "RedoAction.h"
#include <time.h>  
#include <stdlib.h>     /* srand, rand */
#include"ExitAction.h"
using namespace std;
//#include"CMUgraphicsLib\colors.h"
#include<fstream>
UndoStack us;
RedoStack rs;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
		BKGDc=false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType &ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRC:
			pAct=new AddCircleAction(this);
			break;
		case DRAW_TRI:
			pAct=new AddTriAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here
			pAct=new AddLineAction(this);
			break;

		case CHNG_DRAW_CLR:
				pOut->CreateDrawColorPalette();
				pOut->PrintMessage("Action: Change Drawing color, select a color from the palette");
				pAct=new ChangeDrawColor(this);
				break;

		case CHNG_FILL_CLR:
				pOut->CreateFillColorPalette();
				pOut->PrintMessage("Action: Change Fill color , Click anywhere");
				pAct=new ChangeFillColor(this);
				break;
			
		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;


		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pAct = new SwitchplayAction(this);
				break;

		case CHNG_BK_CLR:
			pOut->CreateBkColorPalette();
			pOut->PrintMessage("Action: Change Background color, Click anywhere");
			pAct=new ChangeBackgroundColor(this); 
			break;

		case CHNG_BorderWidth:
			pOut->CreateWidthPalette();
			pOut->PrintMessage("Action: Change Border Width, Click anywhere");
			pAct=new ChangeWidthAction(this);
			break;

		case Select:
			pOut->PrintMessage("Action: Select figure, Click anywhere");
			pAct= new SelectAction(this);
			
			break;

		case RESIZE:
			pOut->CreateResizePalette();
			pOut->PrintMessage("Action: RESIZE figure, choose a size from the palette");
			pAct=new ResizeAction(this);
			break;

		case Zoom:

			pOut->CreatezoomToolBar();
			pOut->CreateZoomPalette();

			pAct = new ZoomAction(this);
					
			break;

		

		case DEL:
			pOut->PrintMessage("Action: DELETE figure, Click anywhere");
			pAct=new DeleteAction(this);
			break;

		case MOVE:
			pOut->PrintMessage("Action: MOVE figure, Click anywhere");
			pAct=new MoveAction(this);
			break;

		case Copy:
			pOut->PrintMessage("Action: Copy figure, Click anywhere");
			pAct = new CopyAction(this);
			break;

		case Cut:
			pOut->PrintMessage("Action: Cut figure, Click anywhere");
			pAct = new CutAction(this);
			break;

		case Paste:
			pOut->PrintMessage("Action: Paste figure, Click anywhere");
			pAct = new PasteAction(this);
			break;
		case SAVE:
			pOut->PrintMessage("Action: SAVE, Click anywhere");
			pAct=new SaveAction(this);
			break;

		case LOAD:
			pOut->PrintMessage("Action: LOAD, Click anywhere");
			pAct= new LoadAction(this);
			break;
		case ROTATE:
			pOut->PrintMessage("Action: ROTATE figure, Click anywhere");
		
			pAct = new RotateAction(this);

			break;

		case SEND_BACK:
			pOut->PrintMessage("Action: SEND figure BACK , Click anywhere");
			pAct = new SendBAction(this);

	    	break;

		case BRNG_FRNT:
			pOut->PrintMessage("Action: BRNG figure FRONT , Click anywhere");
			
			pAct = new BringFAction(this);

			break;

		case scramble:
			pOut->PrintMessage("Action:  scramble and find Mode, Click anywhere");
			pAct = new ScrambleAction(this);

			break;

		case pick:
			pOut->PrintMessage("Action: Pick and Hide Mode");
			pOut->CreatePickAndHideBar();
			//pOut->CreatePlayToolBar();
			break;
		case Type:

			pAct = new PickAction(this, Type);
			break;
				
		case Fill:

			pAct = new PickAction(this, Fill);
			break;
		case Type_Fill:
			pAct = new PickAction(this, Type_Fill);
			break;
		case Area:
			pAct = new PickAction(this, Area);

				
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
	
		case EXIT:
			pAct = new ExitAction(this, ActType);
			break;
		case EXITZOOM:
				undotemp();
				ActionType a=TO_DRAW;
				ExecuteAction(a);
				UpdateInterface();
				break;

	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
	CFigure*s = pFig->CPY();
	s->setUdnoDraw(true);
	us.PushUstack(s);
}


void ApplicationManager::insertfigfirst(CFigure* pFig)
{

	if (FigCount < MaxFigCount)
	{
		for (int i = FigCount; i > 0; i--) {
			FigList[i] = FigList[i - 1];
		}

					
		FigList[0] = pFig;
		FigCount++;
	}

}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->GetFigure(x,y)==true)
		{

			pOut->PrintMessage("a figure selected");
			return FigList[i];
		}
	}
	///Add your code here to search for a figure given a point x,y	
	pOut->PrintMessage("No figure selected");
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();

	for(int i=0; i<FigCount; i++)
		if (FigList[i]->Drawthis() == 1)		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
bool ApplicationManager::checkbeforeexit()
{
	return BKGDc;
}
bool ApplicationManager::checkbeforeexit2()
{
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->getNotsaved()==true)
		{
			return true;
		}
	}
	return false;
}
void ApplicationManager::DeleteSelected()
{
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->IsSelected()==true)
		{
			pOut->PrintMessage("deleted");
			for(int k=i;k<FigCount;k++)
			{
				FigList[k]=FigList[k+1];
			}
			SelectAction::Decrement();
			i--;
			FigCount--;
		}
	}
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}

void ApplicationManager::sendbselected()
{
	CFigure*fig;
	for (int i = 0; i<FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			fig = FigList[i];
			DeleteSelected();
			insertfigfirst(fig);
			fig->SetSelected(0);
		}
	}
}
void ApplicationManager::bringfselected()
{
	CFigure*fig;
	for (int i = 0; i<FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			fig = FigList[i];
			DeleteSelected();
			AddFigure(fig);
			fig->SetSelected(0);
		}
	}
}

void ApplicationManager::Print()
{
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->IsSelected()==true)
		{
			FigList[i]->PrintInfo(pOut);
		}
	}
}
CFigure* ApplicationManager::getFirstToMove()
{
	CFigure*temp=NULL;
	double td=1470;
	int count=0;
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->IsSelected()==true)
		{
			count++;
			double d1=sqrt((FigList[i]->getTopPoint().x)*(FigList[i]->getTopPoint().x)+(FigList[i]->getTopPoint().y)*(FigList[i]->getTopPoint().y));
			
			if(td>d1)
			{
				td=d1;
			}
		}
	}
if(count==1)
{
	for(int i=0;i<FigCount;i++)
	{
		if((FigList[i]->IsSelected()==true))
		{
			temp=FigList[i];
		}
	}
}
else if(count>1)
{
	for(int i=0;i<FigCount;i++)
	{
		double d1=sqrt((FigList[i]->getTopPoint().x)*(FigList[i]->getTopPoint().x)+(FigList[i]->getTopPoint().y)*(FigList[i]->getTopPoint().y));
		if((FigList[i]->IsSelected()==true)&&(td==d1))
		{
			temp=FigList[i];
		}
	}
}
else if(count==0)
{
	temp=NULL;
}
return temp;
}
void ApplicationManager::MoveSelected(Point P)
{
	CFigure*temp=getFirstToMove();
	bool IsFirst=true;
	double slope=0;
	int dist=0;
	Point dp;
	bool allnotgood=false;
	bool allgood=true;
	if(temp!=NULL)
	{
	temp->Move(P,IsFirst,dp,allgood);
	}
	if(allgood==false)
	{
		allnotgood=true;
	}
	IsFirst=false;
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->IsSelected()==true&&FigList[i]->getID()!=temp->getID())
		{
			FigList[i]->Move(P,IsFirst,dp,allgood);
			if(allgood==false)
			{
				allnotgood=true;
			}
			
		}
	}
	IsFirst=true;
	if(allnotgood==true)
	{
		P.x=P.x-dp.x;
		P.y=P.y-dp.y;
		/*dp.x=0-dp.x;
		dp.y=0-dp.y;*/
		temp->Move(P,IsFirst,dp,allgood);
		IsFirst=false;
		for(int i=0;i<FigCount;i++)
		{
		if(FigList[i]->IsSelected()==true&&FigList[i]->getID()!=temp->getID())
		{
			FigList[i]->Move(P,IsFirst,dp,allgood);
		}

		}
	}
	if(allnotgood==true)
	{
		pOut->PrintMessage("Move Action is invalid and it was undone");
	}
	if(temp==NULL)
	{
		pOut->PrintMessage("No figure selected");
	}
	UpdateInterface();
}
void ApplicationManager::SaveAll(ofstream &OutFile) {
	//OutFile <<"BLUE   GREEN   YELLOW ";
	BKGDc=false;
	color c=pOut->getCrntDrawColor();
	OutFile<<checkColor(c)<<"  ";
	color fc=pOut->getCrntFillColor();
	OutFile<<checkColor(fc)<<"  ";
	color fcc=UI.BkGrndColor;
	OutFile<<checkColor(fcc)<<"   ";
	OutFile << endl;
	OutFile<<FigCount;
	OutFile << endl;
	for (int i = 0; i < FigCount; i++) {
		//color x = pOut->getCrntDrawColor();
		//OutFile << VNAME(pOut->getCrntDrawColor());
		

		FigList[i]->Save(OutFile);

		OutFile << endl;
	}

}


void  ApplicationManager::rotateselected( double angle) {
	 for (int i = 0; i<FigCount; i++)
			{
				if(FigList[i]->IsSelected()==true)
				{
					FigList[i]->Rotate(angle);
				}
			}

}
void  ApplicationManager::zoomall(Point p, double r) {
	for (int i = 0; i<FigCount; i++)
	{
			FigList[i]->zoom(p,r);
	}
}

bool ApplicationManager::CheckBeforeLoad()
{
	if(FigCount==0) return true;
	return false;
}
void ApplicationManager::load(string file)
{
	std::stringstream ss;
	ss <<file<<".txt";
	std::string file1 = ss.str();
	ifstream InputFile(file1);
	if (InputFile.is_open()==true)
	{
		
		string c,c1,c2;
		InputFile>>c>>c1>>c2;
		UI.DrawColor=inverseCheckColor(c);
		UI.FillColor=inverseCheckColor(c1);
		UI.BkGrndColor=inverseCheckColor(c2);
		int N;
		InputFile>>N;
		FigCount=N;
		string Type;
		Point p1,p2;
		GfxInfo info;
		for(int i=0;i<FigCount;i++)
		{
			InputFile>>Type;
			if(Type=="CIRCLE")
			{
				FigList[i]= new CCircle(p1,3,info);
			}
			if(Type=="TRIANGLE")
			{
				FigList[i]= new CTriangle(p1,p2,p2,info);
			}
			if(Type=="LINE")
			{
				FigList[i]= new CLine(p1,p2,info);
			}
			if(Type=="RECTANGLE")
			{
				FigList[i]= new CRectangle(p1,p2,info);
			}
			FigList[i]->Load(InputFile);
		}

	}
}


////play   mode   functions //////////////////////////////////////////////////////////////////

bool* ApplicationManager::saveselected() const {
	bool *list = new bool[FigCount];
	for (int i = 0; i<FigCount; i++)
	{
		list[i]=FigList[i]->IsSelected();
	}
	return list;
}

void ApplicationManager::unselectall() {
	for (int i = 0; i<FigCount; i++)
	{
		FigList[i]->SetSelected(0);
	}
}
CFigure* ApplicationManager::randomselect()  {
	int v;
	bool done=0;
	int un = 0;
	for (int i = 0; i < FigCount / 2; i++) {
		if (!FigList[i]->IsSelected())
			un++ ;
		
	}
	if (un==0)return NULL;
	do {

		v = rand() % (FigCount / 2);
		if (!FigList[v]->IsSelected()) {
			FigList[v]->SetSelected(1);
			done = 1;

		}
	} while (!done);

	return FigList[v];

}
void ApplicationManager::deletedublicate() {
	/*int halfway = FigCount / 2;
	for (int i = 0 ; i < halfway; i++) {
		FigCount--;
	}*/

	FigCount = FigCount / 2;
}

void ApplicationManager::undoselected(bool * list)  {
	for (int i = 0; i<FigCount; i++)
	{
		  FigList[i]->SetSelected(list[i]);
	}
}

void ApplicationManager::typecounter(int & r, int & c, int & t, int & l) const
{
	r = c = t = l = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->gettype() == 1)
			r++;
		if (FigList[i]->gettype() == 2)
			c++;
		if (FigList[i]->gettype() == 3)
			t++;
		if (FigList[i]->gettype() == 4)
			l++;
	}

}
void ApplicationManager::movetoleft() {
	Point p;
	
	for (int i = 0; i<FigCount/2; i++)
	{

		p=FigList[i]->getTopPoint();
		p.x = 0;
		FigList[i]->zoom(p,0.5);

	}
	UpdateInterface();
}


void ApplicationManager::undohidden() {
	for (int i = 0; i<FigCount; i++)
	{

		FigList[i]->setDrawthis(1);

	}
	UpdateInterface();
}
void ApplicationManager::undotemp() {
	for (int i = 0; i<FigCount; i++)
	{

		FigList[i]->settemp(0);

	}
	UpdateInterface();
}

void ApplicationManager::scramblefig() {

	
	int count = FigCount;
	//Dublicate figures
	for (int i = 0; i<count; i++)
	{
		CFigure* ptr = FigList[i]->CPY();
		AddFigure(ptr);
	}

	Point p;
	srand(time(NULL));
	for (int i = count; i<FigCount; i++)
	{

	    p.y =  rand() % UI.height; 
		//p.x = (rand() % UI.width*0.75)+ (UI.width*0.75+UI.width*0.25);
		p.x = UI.width;
		FigList[i]->zoom(p,0.5);

	}

	UpdateInterface();

	
}


pickgame*  ApplicationManager::fillcorollist(int &n)const {

	n = 0;
	bool found = 0;
	pickgame *list = new pickgame[FigCount];
	for (int i = 0; i < FigCount; i++) {
		for (int j = 0; j < 4; j++) {
			list->type[j] = 0;
		}

	}
	for (int i = 0; i<FigCount; i++)
	{
		//found = 0;
		for (int j = 0; j < i; j++)
		{

			if (FigList[i]->getFillClr() == list[j].colorname&& FigList[i]->gettype()!=4)
			{
				found = 1;
				list[j].colorcount++;
				(list[j].type[(FigList[i]->gettype()) - 1])++;

				break;
			}
			else found = 0;

		}


		if (!found&& FigList[i]->gettype() != 4)
		{
			list[n].colorname = FigList[i]->getFillClr();
			list[n].colorcount = 1;
			list[n].type[(FigList[i]->gettype()) - 1] = 1;
			n++;
		}


	}
	for (int i = 0; i < n; i++) {
		cout << list[i].colorname << endl;
		cout << list[i].colorcount << endl;
		for (int j = 0; j < 4; j++) {
			cout << list->type[j] << endl;
		}
	}
	return list;

}
int*  ApplicationManager::areaorder(bool x)const {
	int* list = new int[FigCount];
	//x=1 for descending order
	//x=0 for ascending order
	struct area_id {
		int area;
		int id;
	};
	area_id* list1 = new area_id[FigCount];
	
	for (int i = 0; i < FigCount; i++) {
		list1[i].area = FigList[i]->getArea();
		list1[i].id = FigList[i]->getID();
	}

	for (int i = 0; i < FigCount; i++)
	{
		for (int j = 0; j < FigCount - i-1; j++)
		{
			if (list1[j].area > list1[j+1].area )
			{
				int temp = list1[j].area;
				list1[j].area = list1[j+1].area;
				list1[j+1].area = temp;
				 temp = list1[j].id;
				list1[j].id = list1[j + 1].id;
				list1[j + 1].id = temp;
			}

			
		}
	}
	
	
		for (int i = 0; i < FigCount; i++) {
			list[i] = list1[i].id;
		}
	
		if (x) {
			for (int i = 0; i < FigCount / 2; i++)
			{
				int temp = list[i];
				list[i] = list[FigCount - i - 1];
				list[FigCount - i - 1] = temp;
			}
		}

	return list;




}

void ApplicationManager::ChangeDrawingColor(ActionType DrawColor)
{
	switch(DrawColor)
	{
		case DIndigo:
			pOut->PrintMessage("Selected Color: Indigo");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DBlue:
			pOut->PrintMessage("Selected Color: Blue");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DYellow:
			pOut->PrintMessage("Selected Color: Yellow");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DGreen:
			pOut->PrintMessage("Selected Color: Green");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DPink:
			pOut->PrintMessage("Selected Color: Pink");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DOrange:
			pOut->PrintMessage("Selected Color: Orange");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DRed:
			pOut->PrintMessage("Selected Color: Red");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DViolet:
			pOut->PrintMessage("Selected Color: Violet");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DBrown:
			pOut->PrintMessage("Selected Color: Brown");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case DBlack:
			pOut->PrintMessage("Selected Color: Black");
			pOut->setcrntdrawcolor(DrawColor);
			break;
		case EMPTY:
			pOut->PrintMessage("Drawing color not changed!");
			break;
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
void ApplicationManager::ChangeDrawingColorSelected(ActionType DrawColor)
{
	for (int i = 0; i<FigCount; i++)
	{

		if(FigList[i]->IsSelected())
		{
			CFigure *s = FigList[i]->CPY();
			s->setUdnoDraw(false);
			us.PushUstack(s);
	switch(DrawColor)
	{
		case DIndigo:
			pOut->PrintMessage("Selected Color: Indigo");
			FigList[i]->ChngDrawClr(LIGHTBLUE);
			break;
		case DBlue:
			pOut->PrintMessage("Selected Color: Blue");
			FigList[i]->ChngDrawClr(BLUE);
			break;
		case DYellow:
			pOut->PrintMessage("Selected Color: Yellow");
			FigList[i]->ChngDrawClr(YELLOW);
			break;
		case DGreen:
			pOut->PrintMessage("Selected Color: Green");
			FigList[i]->ChngDrawClr(GREEN);
			break;
		case DPink:
			pOut->PrintMessage("Selected Color: Pink");
			FigList[i]->ChngDrawClr(PINK);
			break;
		case DOrange:
			pOut->PrintMessage("Selected Color: Orange");
			FigList[i]->ChngDrawClr(ORANGE);
			break;
		case DRed:
			pOut->PrintMessage("Selected Color: Red");
			FigList[i]->ChngDrawClr(RED);
			break;
		case DViolet:
			pOut->PrintMessage("Selected Color: Violet");
			FigList[i]->ChngDrawClr(VIOLET);
			break;
		case DBrown:
			pOut->PrintMessage("Selected Color: Brown");
			FigList[i]->ChngDrawClr(BROWN);
			break;
		case DBlack:
			pOut->PrintMessage("Selected Color: Black");
			FigList[i]->ChngDrawClr(BLACK);
			break;
		case EMPTY:
			pOut->PrintMessage("Drawing color not changed!");
			break;
	
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
		}
	}

}
	
void ApplicationManager::ChangeFillingColor(ActionType FillColor)
{
	switch(FillColor)
	{
		case FIndigo:
			pOut->PrintMessage("Selected Color: Indigo");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FBlue:
			pOut->PrintMessage("Selected Color: Blue");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FYellow:
			pOut->PrintMessage("Selected Color: Yellow");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FGreen:
			pOut->PrintMessage("Selected Color: Green");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FPink:
			pOut->PrintMessage("Selected Color: Pink");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FOrange:
			pOut->PrintMessage("Selected Color: Orange");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FRed:
			pOut->PrintMessage("Selected Color: Red");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FViolet:
			pOut->PrintMessage("Selected Color: Violet");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FBrown:
			pOut->PrintMessage("Selected Color: Brown");
			pOut->setcrntfillcolor(FillColor);
			break;
		case FNo:
			pOut->PrintMessage("No Filling!");
			pOut->setcrntfillcolor(FillColor);
			break;
		case EMPTY:
			pOut->PrintMessage("Drawing color not changed!");
			break;
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
void ApplicationManager::ChangeFillingColorSelected(ActionType FillColor)
{
	for (int i = 0; i<FigCount; i++)
	{

		if(FigList[i]->IsSelected())
		{
			CFigure *s = FigList[i]->CPY();
			s->setUdnoDraw(false);
			us.PushUstack(s);
	switch(FillColor)
	{
		case FIndigo:
			pOut->PrintMessage("Selected Color: Indigo");
			FigList[i]->ChngFillClr(LIGHTBLUE);
			break;
		case FBlue:
			pOut->PrintMessage("Selected Color: Blue");
			FigList[i]->ChngFillClr(BLUE);
			break;
		case FYellow:
			pOut->PrintMessage("Selected Color: Yellow");
			FigList[i]->ChngFillClr(YELLOW);
			break;
		case FGreen:
			pOut->PrintMessage("Selected Color: Green");
			FigList[i]->ChngFillClr(GREEN);
			break;
		case FPink:
			pOut->PrintMessage("Selected Color: Pink");
			FigList[i]->ChngFillClr(PINK);
			break;
		case FOrange:
			pOut->PrintMessage("Selected Color: Orange");
			FigList[i]->ChngFillClr(ORANGE);
			break;
		case FRed:
			pOut->PrintMessage("Selected Color: Red");
			FigList[i]->ChngFillClr(RED);
			break;
		case FViolet:
			pOut->PrintMessage("Selected Color: Violet");
			FigList[i]->ChngFillClr(VIOLET);
			break;
		case FBrown:
			pOut->PrintMessage("Selected Color: Brown");
			FigList[i]->ChngFillClr(BROWN);
			break;
		case FNo:
			pOut->PrintMessage("Selected Color: Black");
			FigList[i]->ChngFillClr(BLACK,false);
			break;
		case EMPTY:
			pOut->PrintMessage("Drawing color not changed!");
			break;
	
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
		}
	}

}
void ApplicationManager::ChangeBkColor(ActionType BkColor)
{
	switch(BkColor)
	{
		case BIndigo:
			pOut->PrintMessage("Selected Color: Indigo");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BBlue:
			pOut->PrintMessage("Selected Color: Blue");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BYellow:
			pOut->PrintMessage("Selected Color: Yellow");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BGreen:
			pOut->PrintMessage("Selected Color: Green");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BPink:
			pOut->PrintMessage("Selected Color: Pink");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BOrange:
			pOut->PrintMessage("Selected Color: Orange");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BRed:
			pOut->PrintMessage("Selected Color: Red");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BViolet:
			pOut->PrintMessage("Selected Color: Violet");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BBrown:
			pOut->PrintMessage("Selected Color: Brown");
			pOut->setcrntbkcolor(BkColor);
			break;
		case BBlack:
			pOut->PrintMessage("Selected Color: Black");
			pOut->setcrntbkcolor(BkColor);
			break;
		case EMPTY:
			pOut->PrintMessage("Drawing color not changed!");
			break;
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}

void ApplicationManager::ResizeSelected(ActionType SizeFactor )
{
	int c=0;
	for (int i = 0; i<FigCount; i++)
	{

		if(FigList[i]->IsSelected())
		{	
			CFigure *s = FigList[i]->CPY();
			s->setUdnoDraw(false);
			s->SetSelected(true);
			us.PushUstack(s);
			switch(SizeFactor)
			{
				case RQuarter:
					pOut->PrintMessage("Resizing");
					FigList[i]->Resize(0.25);
					break;
				case RHalf:
					FigList[i]->Resize(0.5);
					break;
				case RDouble:
					FigList[i]->Resize(2);
					break;
				case RQuad:
					FigList[i]->Resize(4);
					break;
				case EMPTY:
					pOut->PrintMessage("No Size was Selected");
					break;
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
}
}
void ApplicationManager::ChangeBorder(ActionType SizeFactor )
{
			switch(SizeFactor)
			{
				case WQuarter:
					pOut->setcrntwidth(SizeFactor);
					break;
				case WHalf:
					pOut->setcrntwidth(SizeFactor);
					break;
				case WDouble:
					pOut->setcrntwidth(SizeFactor);
					break;
				case WQuad:
					pOut->setcrntwidth(SizeFactor);
					break;
				case EMPTY:
					pOut->PrintMessage("No Size was Selected");
					break;
			}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();

}
void ApplicationManager::ChangeBorderSelected(ActionType SizeFactor )
{
	
	for (int i = 0; i<FigCount; i++)
	{

		if(FigList[i]->IsSelected())
		{	
			CFigure *s = FigList[i]->CPY();
			us.PushUstack(s);
			switch(SizeFactor)
			{
				case WQuarter:
					pOut->PrintMessage("Resizing");
					FigList[i]->ChngBorderWid(0.25);
					break;
				case WHalf:
					FigList[i]->ChngBorderWid(0.5);
					break;
				case WDouble:
					FigList[i]->ChngBorderWid(2);
					break;
				case WQuad:
					FigList[i]->ChngBorderWid(4);
					break;
				case EMPTY:
					pOut->PrintMessage("No Size was Selected");
					break;
	}

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
}
}
bool ApplicationManager::SeeSelected()
{
	for (int i = 0; i<FigCount; i++)
	{
		if(FigList[i]->IsSelected())
		 return true;
	}
	return false;
}


void ApplicationManager::CpyToClipboard()
{
	for(int j=0; j<ClipCount; j++)
	{
		delete Clipboard[j];
		Clipboard[j]=NULL;
	}
	ClipCount=0;
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->IsSelected()==true)
		{
			pOut->PrintMessage("copied to clipboard");
			Clipboard[ClipCount]=FigList[i]->CPY();
			ClipCount++;
			cout<<"Copied"<<endl;
		}
	}

	pOut->ClearStatusBar();
}
void ApplicationManager::PasteSelected(Point P)
{
	bool IsFirst=true;
	double slope=0;
	int dist=0;
	Point dp;
	bool allnotgood=false;
	bool allgood=true;
	//checking if clipboard is empty
	if( ClipCount == 0)
	{
		pOut->PrintMessage("Clipboard is empty! Click anywhere to continue.");
		int x,y;
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}
	//checking if number of figures exceed maximum
	if( ClipCount + FigCount > MaxFigCount)
	{
		pOut->PrintMessage("Error! Number of figures exceeds the maximum number. Click anywhere to continue. ");
		int x,y;
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}
	CFigure *N; int i;
	for(int i =0 ; i < ClipCount;i++)
	{
		N=Clipboard[i]->CPY();
		N->Move(P,IsFirst,dp,allgood);
		N->setPaste(true);
		if(allgood==false)
		{
			allnotgood=true;
		}
		AddFigure(N);//N=NULL;
		IsFirst=false;
	}
	IsFirst=true;
	if(allnotgood==true)
	{
		dropFig();
		pOut->PrintMessage("Point was invalid !!Choose another point");
	}
	if(allnotgood==false)
	{
		pOut->PrintMessage("Paste was succesful!!");
		for(int i=0;i<FigCount;i++)
		{
			if(FigList[i]->CheckPaste()==true)
			{
				FigList[i]->setID();
			FigList[i]->setPaste(false);
			}
		}
	}
	N=NULL;
}
void ApplicationManager::dropFig()
{
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->CheckPaste()==true)
		{
			
			for(int k=i;k<FigCount;k++)
			{
				FigList[k]=FigList[k+1];
			}
			FigCount--;
			i--;
		}
	}
}

void ApplicationManager::undo()
{
	CFigure*s = us.PopUstack();
	if (s != NULL)
	{
		for (int i = 0; i<FigCount; i++)
		{
			if ((s->getID()) == FigList[i]->getID())
			{
				/*else if(s->getUndoDraw()==false)
				{
				s->setUdnoDraw(true);
				FigList[i]=s;
				FigCount++;
				}*/
				if (s->getUndoDraw() != true)
				{
					cout << "buullshit" << endl;
					CFigure*temp;
					temp = FigList[i];
					FigList[i] = s;
					s = temp;
					s->setUdnoDraw(true);
					rs.PushRstack(s);
					return;
				}
			}
		}
		for (int i = 0; i<FigCount; i++)
		{
			if ((s->getID()) == FigList[i]->getID() && (s->getUndoDraw() == true))
			{
				s->setUdnoDraw(false);
				FigList[i] = NULL;
				rs.PushRstack(s);
				FigCount--;
				return;
			}
		}
	}

	if (s == NULL)
	{
		pOut->PrintMessage("No Action to be undone !!");
	}
	pOut->ClearDrawArea();
	UpdateInterface();
}
void ApplicationManager::redo()
{
	CFigure *s = rs.PopRstack();
	if (s != NULL)
	{

		for (int i = 0; i<FigCount; i++)
		{
			if (s->getID() == FigList[i]->getID() && s->getUndoDraw() == true)
			{
				cout << "HERE333" << endl;
				CFigure*temp;
				temp = FigList[i];
				FigList[i] = s;
				s = temp;
				s->setUdnoDraw(false);
				us.PushUstack(s);
				return;
			}
		}
		if (s->getUndoDraw() == false)
		{
			cout << "there" << endl;
			FigList[FigCount] = s;
			FigCount++;
			s->setUdnoDraw(true);
			us.PushUstack(s);
			return;
		}
	}
	if (s == NULL)
	{
		pOut->PrintMessage("No Action to be redone !!");
	}
	pOut->ClearDrawArea();
	UpdateInterface();
}