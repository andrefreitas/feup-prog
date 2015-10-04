// Exercice 4.2
// Problem: Checks if a string has a n sequence of a char
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <string>
using namespace std;
bool sequenceSearch(string s, int nc,char c);
int main(){
	// Input
	string s; int nc; char c;
	cout << "String? ";
	cin >> s;
	cout << "Char? ";
	cin >> c;
	cout << "Number of chars? ";
	cin >> nc;

	// Evaluate string
	if(sequenceSearch(s,nc,c)) cout << "The sequence exists!\n";
	else cout << "No sequence!\n";

	cin.get();
	return 0;
}
bool sequenceSearch(string s, int nc,char c){
	string control (nc,c);

	for (int i=0;(i+nc)<s.length();i++){
		if(!(control.compare(s.substr(i,nc)))) return 1;
		
	}
	return 0;
}