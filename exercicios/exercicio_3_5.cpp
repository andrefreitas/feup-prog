// Exercice 3.5 a)
// Problem: Read a number and compose it in prime numbers
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <windows.h>
using namespace std;
bool scanFracc(int &numerator, int &denominator);
void reduceFracc(int &numerator, int &denominator);
void sumFracc(int &num1, int &denom1,int &num2, int &denom2); // Sum
void subFracc(int &num1, int &denom1,int &num2, int &denom2); // Subtraction
void prodFracc(int &num1, int &denom1,int &num2, int &denom2); // Division
void divideFracc(int &num1, int &denom1,int &num2, int &denom2); // Multiplication
int gcdEuclides(int num1,int num2);
void printFracc(int num,int denom);

void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main(){
	int num1,denom1,num2,denom2;
	int op=1;
	while(op!=6){
		// Clear the screen and print the menu
		gotoxy(0,0);
		system("CLS");
		// Clear the screen and print the menu
		cout << ":::::: Main Menu ::::::\n";
		cout << "1) Sum\t   2) Subtract\n";
		cout << "3) Product\t4) Division\n";
		cout << "5) Reduce\t6) EXIT\n";
		cout << ">>\t\t \t\t";
	    gotoxy(3,4);
		// Force the input an goto to the correct line
		while(!(cin >> op)){
			cin.clear();
			cin.ignore(1000,'\n');
			gotoxy(0,4);
			cout << ">>\t\t ";
			gotoxy(3,4);
		}
		
		if (op!=6){

		// Validates the input
		while (op<1 && op >5) {
			cout << "Wrong Option!\n";
			cin >> op;}
		while (!(scanFracc(num1,denom1) && scanFracc(num2,denom2)))
			cout << "Invalid Fraction(s)!\n";

		switch(op){
		case 1:sumFracc(num1,denom1,num2,denom2); break;
	    case 2:subFracc(num1,denom1,num2,denom2); break;
		case 3:prodFracc(num1,denom1,num2,denom2); break;
	    case 4:divideFracc(num1,denom1,num2,denom2); break;
		}
		
		cout << "ans: \n";
		printFracc(num1,denom1);
	    cout << endl;
		cin.ignore();
		cin.get();
		}
	}

    cin.get();
	return 0;
}

/************************************************
             AUXILIAR FUNCTIONS
*************************************************/

// Input: numerator and denominator
// Output: true or false
bool scanFracc(int &numerator, int &denominator){
	cout << "Numerator? ";
	cin >> numerator;
	cout << "Denominator? ";
	cin >> denominator;
	if (denominator==0){
		numerator=0;
		return false;
	}
	else return true;
}
int gcdEuclides(int num1,int num2){
	// num1 is the greatest
	if(num2>num1){
		int aux;
		aux=num1;
		num1=num2;
		num2=aux;}
	// Initialization
	int quotient, remainder;
	quotient=num1/num2;
	remainder=num1%num2;
	int num1Old;
	// Euclids algorithm: num1 = quotient(num1,num2) x num2 + remainder(num1,num2)
	while (remainder!=0){
		// gcd(num1,num2)=gcd(num2,remainder(num1,num2))
		num1Old=num1;
		num1=num2;
		num2=num1Old%num2;
		remainder=num1%num2;
		quotient=num1/num2;
	}
	return num2;
}

// Input: numerator and denominator
// Function: finds the gcd and reduce the fraction
void reduceFracc(int &numerator, int &denominator){
	int gcd=gcdEuclides(numerator,denominator);
	numerator/=gcd;
	denominator/=gcd;
}

// Input: 2 numerators and  2 denominators
// Function: compute the sum of the fractions and save the result in num1/num2
void sumFracc(int &num1, int &denom1,int &num2, int &denom2){
	if (denom1==denom2) num1+=num2;
	else{
		num1*=denom2;
		num2*=denom1;
		denom1*=denom2;
		num1+=num2;
	}
	reduceFracc(num1,denom1);
}

// Input: 2 numerators and  2 denominators
// Function: compute the subtraction of the fractions and save the result in num1/num2
void subFracc(int &num1, int &denom1,int &num2, int &denom2){
	if (denom1==denom2) num1-=num2;
	else{
		num1*=denom2;
		num2*=denom1;
		denom1*=denom2;
		num1-=num2;
	}
	if (num1!=0)
	reduceFracc(num1,denom1);
}

// Input: 2 numerators and  2 denominators
// Function: compute the product of the fractions and save the result in num1/num2
void prodFracc(int &num1, int &denom1,int &num2, int &denom2){
	num1*=num2;
	denom1*=denom2;
	reduceFracc(num1,denom1);
}

// Input: 2 numerators and  2 denominators
// Function: compute the division of the fractions and save the result in num1/num2
void divideFracc(int &num1, int &denom1,int &num2, int &denom2){
	num1*=denom2;
	denom1*=num2;
	reduceFracc(num1,denom1);
}
void printFracc(int num,int denom){
	cout << num << '\n' << "--" << '\n' << denom << endl;
}