// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.3
// Problem: Compose the elements of a compound
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
void decompose(string comp);
int main(){
	// Input
	cout << "Compound? ";
	string comp;
	cin >> comp;
	// Evaluate
	decompose(comp);

	cin.get();
	return 0;

}
void decompose(string comp){
	for (int i=0; i<comp.length(); i++){
		if (!isdigit(comp[i])){
			// if is alphabetic
			if ((i+1)>=comp.length() || isdigit(comp[i+1]) || comp[i+1]==toupper(comp[i+1])) cout << comp[i] << endl;
			else if(comp[i+1]!=toupper(comp[i+1])) {cout << comp.substr(i,2) << endl; i++;}

		}

		
	}
}