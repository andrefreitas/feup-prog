// -----------------------------------------------------------------------------------------------------------------------
// Exercice 4.1 a
// Problem: check if a string is an Hydroxide
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
using namespace std;
bool isHydroxide(char compound[]);
int main(){
	char st[10];
	cout << "Compound? ";
	gets(st);
	if (isHydroxide(st)) cout << "It is an Hydroxide!\n"; 
	else cout << "It isn't an Hydroxide...\n";
	cin.get();
	return 0;
} 
bool isHydroxide(char compound[]){
   int lim=strlen(compound)-1;
   char last2[3];
   last2[0]=compound[lim-1];
   last2[1]=compound[lim];
   last2[2]='\0';
   return !strcmp(last2,"OH");
}