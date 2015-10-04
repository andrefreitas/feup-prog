// Exercice 4.5
// Problem: Manipulate fractions with structs
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <windows.h>
using namespace std;
struct fraction{
	int numerator;
	int denominator;
};
bool scanFracc(fraction &frac);
fraction reduceFracc(fraction frac);
fraction sumFracc(fraction frac1,fraction frac2); // Sum
fraction subFracc(fraction frac1,fraction frac2); // Subtraction
fraction prodFracc(fraction frac1,fraction frac2); // Division
fraction divideFracc(fraction frac1,fraction frac2);// Multiplication
int gcdEuclides(int num1,int num2);
void printFracc(fraction frac);



void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main(){
	fraction f1,f2;
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
		if (op==5) 
			while (!scanFracc(f1))
			cout << "Invalid Fraction!\n";
		else 
		while (!(scanFracc(f1) && scanFracc(f2)))
			cout << "Invalid Fraction(s)!\n";

		switch(op){
		case 1:f1=sumFracc(f1,f2); break;
	    case 2:f1=subFracc(f1,f2); break;
		case 3:f1=prodFracc(f1,f2); break;
	    case 4:f1=divideFracc(f1,f2); break;
		case 5:f1=reduceFracc(f1); break;
		}
		
		cout << "ans: \n";
		printFracc(f1);
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
bool scanFracc(fraction &frac){
	cout << "Numerator? ";
	cin >> frac.numerator;
	cout << "Denominator? ";
	cin >> frac.denominator;
	if (frac.denominator==0){
		frac.numerator=0;
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
fraction reduceFracc(fraction frac){
	int gcd=gcdEuclides(frac.numerator,frac.denominator);
	frac.numerator/=gcd;
	frac.denominator/=gcd;
	return frac;
}

// Input: 2 numerators and  2 denominators
// Function: compute the sum of the fractions and save the result in num1/num2
fraction sumFracc(fraction frac1,fraction frac2){
	if (frac1.denominator==frac2.denominator) frac1.numerator+=frac2.numerator;
	else{
		frac1.numerator*=frac2.denominator;
		frac2.numerator*=frac1.denominator;
		frac1.denominator*=frac2.denominator;
		frac1.numerator+=frac2.numerator;
	}
	return reduceFracc(frac1);
}

// Input: 2 numerators and  2 denominators
// Function: compute the subtraction of the fractions and save the result in num1/num2
fraction subFracc(fraction frac1,fraction frac2){
	if (frac1.denominator==frac2.denominator) frac1.numerator-=frac2.numerator;
	else{
		frac1.numerator*=frac2.denominator;
		frac2.numerator*=frac1.denominator;
		frac1.denominator*=frac2.denominator;
		frac1.numerator-=frac2.numerator;
	}
	return reduceFracc(frac1);
}

// Input: 2 numerators and  2 denominators
// Function: compute the product of the fractions and save the result in num1/num2
fraction prodFracc(fraction frac1,fraction frac2){
	frac1.numerator*=frac2.numerator;
	frac1.denominator*=frac2.denominator;
	return reduceFracc(frac1);
}

// Input: 2 numerators and  2 denominators
// Function: compute the division of the fractions and save the result in num1/num2
fraction divideFracc(fraction frac1,fraction frac2){
	frac1.numerator*=frac2.denominator;;
	frac1.denominator*=frac2.numerator;
	return reduceFracc(frac1);
}
void printFracc(fraction frac){
	cout << frac.numerator << '\n' << "--" << '\n' << frac.denominator << endl;
}