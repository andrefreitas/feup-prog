// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.1 b
// Problem: check if a string is an Hydroxide
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
bool isHydroxide(string compound);
int main(){
	string st;
	cout << "Compound? ";
	cin >> st;
	if (isHydroxide(st)) cout << "It is an Hydroxide!\n"; 
	else cout << "It isn't an Hydroxide...\n";
	cin.get();
	return 0;
} 
bool isHydroxide(string compound){
   int lim=compound.length();
   string control;
   string last="OH";
   control=compound.substr(lim-2,2);
   return !control.compare(last);
}