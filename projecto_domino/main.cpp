#include "allfives.h"
int main(){
	char op;

	resizeConsole();
	setWindow(WIDTH,HEIGHT,50,0);
	srand((unsigned)(time(NULL)));
	do{
	board domino(1);
    domino.run();
	cout<<"Deseja Jogar novamente?(s/n)";
	cin>>op;
	system("cls");
	}
	while('S'==(toupper(op)));
	return 0;
}