// Exercice 1.4 
// Problem: Escreva um programa que leia os valores de a, b, c, d, e e f e determine a solução do sistema de equações correspondente. 
// Considere apenas situações em que a solução é possível e determinada. 
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
// If the determinant of the matrix is zero, it's impossible
bool possible(int a,int b,int d,int e){
	if (((a*e)-(b*d))==0) return false;
	else return true;
}
int main(){
	// Input
	int a,b,c,d,e,f;
	cout << "a ? :";
	cin >> a;
	cout << "b ? :";
	cin >> b;
	cout << "c ? :";
	cin >> c;
	cout << "d ? :";
	cin >> d;
	cout << "e ? :";
	cin >> e;
	cout << "f ? :";
	cin >> f;
	// Check if the system is possible
	if (possible(a,b,d,e)) 
	{	// Compute Solutions
		int x,y;
		x=(c*e-b*f)/(a*e-b*d);
		y=(a*f-c*d)/(a*e-b*d);
		// Print Solutions
		cout << "\nx = " << x;
		cout << "\ny= " << y;
	}
	else cout << "Impossible";
	cout << "\n";
	system("pause");

}
