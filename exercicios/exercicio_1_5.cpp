// -----------------------------------------------------------------------------------------------------------------------
// Exercice 1.5 
// Problem: Escreva um programa que leia dois tempos, expressos em horas, minutos e segundos e que determine a soma desses 
// tempos.
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
using namespace std;
// Auxiliar function to avoid repetiton of code
// Evaluates if is necessary to print and if is singular or plural
void printing(int val, char *name){
	if (val!=0) {
		cout << val << ' ';
		if (val > 1)  cout << strcat(name,"s, "); 
		else cout << strcat(name,", ");
	}
}

int main(){
	// Data structure *****
	struct time{
		int hr; // Hours
		int min; // Minutes
		int sec; // Seconds
	};
	time time1,time2,final;
	int days=0;

	// Input *************************************
	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> time1.hr >> time1.min >> time1.sec;
	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> time2.hr >> time2.min >> time2.sec;

	// Sum of times ******************************
    final.hr=time1.hr+time2.hr; // hours
	final.min=time1.min+time2.min; // minutes
	final.sec=time1.sec+time2.sec; // seconds

	// Compute the time correctly ****************
	if (final.sec>=60)
	{ final.min+=final.sec/60; // add the quotient
	  final.sec=final.sec % 60;} // equal the remainder
	if (final.min>=60)
	{ final.hr+=final.min/60;
	  final.min=final.min % 60;}
	if (final.hr>=24)
	{ days=final.hr/24;
	  final.hr=final.hr % 24;
	}

	// Output **********************************
	char st[15]; // for the printing function
	cout << "Soma dos tempos: ";
	strcpy(st,"dia");
	printing(days,st);
	strcpy(st,"hora");
	printing(final.hr,st);
	strcpy(st,"minuto");
	printing(final.min,st);
	// print the seconds. Didn't use the function 
	// because there isn't a comma on the end
	if (final.sec!=0) {
		cout << final.sec << ' ';
		if (final.sec > 1)  cout << "segundos"; 
		else cout << "segundo";
	}

	cout << '\n';
	system("pause");
}
