// Exercice 1.1 
// Problem: Escreva um programa que leia do teclado uma letra e mostre o respectivo código ASCII. 
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
using namespace std;
int main(){
char letter;
cout << "Introduza uma letra: ";
cin >> letter;
cout << "Caracter em ASCII: " << int(letter) << "\n\n";
system("pause");
}