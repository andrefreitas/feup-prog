// Exercice 2.14
// Problem: Compute the square root
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <iomanip>
#include <math.h>
#define DEBUGMODE 1
using namespace std;
int main(){
	int num,nMaxIter; float delta; // Input
	
	cout << "This program compute the square root of a number.\nNumber? ";
	cin >> num;
	cout << "Delta? ";
	cin >> delta;
	cout << "Max of iterations? ";
	cin >> nMaxIter;

	// Computing the square root until max interations or difference < delta
	double rq,rqn=1,dif;
	dif = delta+1;
	if(DEBUGMODE){
		cout << setw(9) << "rq";
		cout << setw(9) <<"rqn";
		cout << setw(9) <<"rqn^2";
		cout << setw(15) <<"dif=n-rqn^2" << "\n\n";}
	for (int i=1;i<=nMaxIter && dif >= delta; i++){
		rq=rqn;
		rqn= (rq + (double) num / rq) / 2.0;
		dif = abs(num - rqn*rqn);
		if(DEBUGMODE) cout << setw(9) << rq <<  setw(9) << rqn  << setw(9) << rqn*rqn  << setw(15) << num - rqn*rqn << endl;
	}

	// Result = rqn
	cout << "\nThe Square root is: " << rqn << endl;
	cin.get();
	system("pause");
	
}