// -----------------------------------------------------------------------------------------------------------------------
// Exercice 3.3 a
// Problem: Compute the SQRT
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
#define DEBUGMODE 0
double sqrt(int num, double delta,int maxi);
int main(){
	// Input
	int num,maxi;
	double delta;
	cout << "Number? ";
	cin >> num;
	cout << "Delta? ";
	cin >> delta;
	cout << "Maxi? ";
	cin >> maxi;
	// Compute
	double squareroot=sqrt(num,delta,maxi);
	// Output
	cout << "The square root is: " << squareroot << endl;
	system("pause");
	return 0;
}
double sqrt(int num, double delta,int maxi){
	// Computing the square root until max interations or difference < delta
	double rq,rqn=1,dif;
	dif = delta+1;
	if(DEBUGMODE){
		cout << setw(9) << "rq";
		cout << setw(9) <<"rqn";
		cout << setw(9) <<"rqn^2";
		cout << setw(15) <<"dif=n-rqn^2" << "\n\n";}
	for (int i=1;i<=maxi && dif >= delta; i++){
		rq=rqn;
		rqn= (rq + (double) num / rq) / 2.0;
		dif = abs(num - rqn*rqn);
		if(DEBUGMODE) cout << setw(9) << rq <<  setw(9) << rqn  << setw(9) << rqn*rqn  << setw(15) << num - rqn*rqn << endl;
	}
return rqn;
}