#include "allfives.h"
// *********************************************************
// Function: Sets the cursor position
// Params: int x, int y
// Returns: nothing
// *********************************************************
void gotoxy(int x, int y) {
	COORD coord; 
	coord.X = x; coord.Y = y; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}
// *********************************************************
// Function: Check if exists in a vector
// Params: vector<int> vec, int value
// Returns: true or false
// *********************************************************
bool exist(vector<int> vec,int value){
	for (int unsigned i=0; i<vec.size(); i++)
		if(value==vec[i]) return true;
	return false;
}
// *********************************************************
// Function: Define window size and position
// Params: int width, int height, int x, int y
// Returns: nothing
// *********************************************************
void setWindow(int width, int height, int x, int y){
	HWND hWnd = GetConsoleWindow();
	MoveWindow(hWnd,x,y,width,height,TRUE);
}
// *********************************************************
// Function: Print the line
// Params: nothing
// Returns: nothing
// *********************************************************
void printline(){
	int unsigned total=150;
	for (int unsigned i=0; i<total; i++){
		cout << "=";
	}
	cout << endl;
}
// *********************************************************
// Function: Print something on left, right or center
// Params: nothing
// Returns: nothing
// *********************************************************
void print(string output,string align){
	int total=150-output.length();
	if (align=="center"){
		total/=2;
        for(int i=0;i<total;i++)
			cout<<" ";
	}
	cout << output;
}
// *********************************************************
// Function: Force an input to be an integer
// Params: varx by reference
// Returns: nothing
// *********************************************************
void inputInteger(int &varx){
	string userInput;
	bool isnumber=true; 
	do{
		if (!isnumber){ 
			cout << "\n(ATENCAO!)Input invalido, introduza um inteiro: ";
			cin.clear();
			cin.ignore(1000,'\n');
		}
		isnumber=true; // Allways after cout
		cin >> userInput;
		// For each caracter, check if it is in the limits of integers, in ascii table
		for (int unsigned i=0; i<userInput.size();i++){
			if (((int) userInput[i]) < 48 || ((int) userInput[i])> 57){
				isnumber=false;
				break;
			}
		}
	}
	while(!isnumber);
	varx=atoi(userInput.c_str());
	cin.ignore(1000,'\n');
}

// *********************************************************
// Function: Find the nearest multiple of 5 
// Params: value
// Returns: integer
// *********************************************************
int RoundMultiple5(int valor){
	int Result;
	Result= 5 *((valor + 2) / 5);
	return Result;
}
// *********************************************************
// Function: Print Colours
// Params: colour name
// *********************************************************
void printColour(string colour){
	if (colour=="red"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BR);
	}
	if (colour=="green"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BG);
	}
	if (colour=="clear"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
	}
}
// *********************************************************
// Function: Resize the Console
// Params: No.
// *********************************************************
void resizeConsole()
{
    HANDLE hOut;
    COORD NewSBSize;
    SMALL_RECT DisplayArea = {0, 0, 0, 0};

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    NewSBSize.X = 150;
    NewSBSize.Y = 65;

    SetConsoleScreenBufferSize(hOut, NewSBSize);
    DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
    SetConsoleWindowInfo(hOut,TRUE, &DisplayArea);
}