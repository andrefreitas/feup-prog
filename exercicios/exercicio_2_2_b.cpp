// Exercice 2.3
// Problem: Lê três números e imprime por ordem decrescente
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
	// Input
	int a,b,c;
	cout << "a? b? c? ";
	cin >> a >> b >> c;
	// Evaluate
	int max,med,min;
	int troca;
	max=min=a;
	// Compute the Maximum
	if (b>a) max=b; 
	if (c>max) max=c;
	// Compute the Minimum
	if (b<a) min=b; 
    if (c<min) min=c;
	// Compute the medium
	if ((b!= max) && (b!=min)) med =b;
	else if((c!= max) && (c!=min)) med =c;
	else med=a;
	cout << max << '\n' << med << '\n' << min << '\n';
	system("pause");
	return 0;
}