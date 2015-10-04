// Exercice 3.6
// Problem: Years calendar
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <iomanip>
using namespace std;
bool leapyear(int year);
int dayofMonthYear(int month,int year);
int monthcode(int month);
int dayofWeek(int year,int month, int day);
void printDayWeek(int daynum);
void printCalendar(int month,int year);
void printMonth(int month);
int main(){
	int year;
	int month;
	int day;

	// Input
	cout << "Year? ";
	cin >> year;
	cout << "Month? ";
	cin >> month;
	cout << "Day of the Month? ";
	cin >> day;

	// Leap year?
	if (leapyear(year)) cout << "Leap year!\n";
	else cout << "Normal year!\n";
	// Days of the month?
	cout << "Days of the month: ";
	cout << dayofMonthYear(month,year);
	// Day of the week?
	int daynum=dayofWeek(year,month,day);
	cout << "\nDay of the week: ";
	printDayWeek(daynum);
	// Print calendar
	cout << "\n\nCalendar:\n";
	printCalendar(month,year);

	system("pause");
	return 0;
}
//*************************************
//           AUX FUNCTIONS
// ***********************************

// Arguments: An integer year
// Function: Evaluate if the year is leap
// Return: True if leap and false if not
bool leapyear(int year){
	if ((year%4==0 && year%100!=0) || (year%400==0 && year%100==0)) return 1;
	else return 0;
}

// Arguments: An integer moth and year
// Function: Evaluate the number of the year
// Return: The month number of days
int dayofMonthYear(int month,int year){
	switch (month){
	case 1: return 31;
	case 2: if(leapyear(year)) return 29; else return 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
    case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;
	default: cout << "Invalid Month!\n";}
}

// Arguments: An integer year
// Function: Evaluate the number of the year
// Return: The month code to the Sohael Babwani formula
int monthcode(int month,int year){

	switch (month){
	case 1: if(leapyear(year)) return 6; else return 0;
	case 2: if(leapyear(year)) return 2; else return 3;
	case 3: return 3;
	case 4: return 6;
	case 5: return 1;
	case 6: return 4;
    case 7: return 6;
	case 8: return 2;
	case 9: return 5;
	case 10: return 0;
	case 11: return 3;
	case 12: return 5;
	default: cout << "Invalid Month!\n";}

}
// Arguments: An integer day of the month and a month
// Function: Evaluate the number of the year
// Return: The day of the week
int dayofWeek(int year,int month, int day){
	// day of the month: day
	// month number: month
	// year: year
	/* month first two digits */ int s=year/100;
	/* month last two digits */ int a=year%100;
	/* month code */ int c=monthcode(month,year);

	int ds=( (5*a)/4 + c + day - 2 * (s%4) + 7) % 7;
	if (ds==1) return ds+6;
	else  return (6+ds)%7;
}

void printDayWeek(int daynum){
	switch (daynum){
	case 1: cout << "Monday\n"; break;
	case 2: cout << "Tuesday\n"; break;
	case 3: cout << "Wednesday\n"; break;
	case 4: cout << "Thursday\n"; break;
	case 5: cout << "Friday\n"; break;
	case 6: cout << "Saturday\n"; break;
	case 7: cout << "Sunday\n"; break;
	default : cout <<"Invalid day!\n";
	}
}

void printMonth(int month){
	switch (month){
	case 1: cout << "January"; break;
	case 2: cout << "February"; break;
	case 3: cout << "March"; break;
	case 4: cout << "April"; break;
	case 5: cout << "May"; break;
	case 6: cout << "June"; break;
	case 7: cout << "July"; break;
	case 8: cout << "August"; break;
	case 9: cout << "September"; break;
	case 10: cout << "October"; break;
	case 11: cout << "November"; break;
	case 12: cout << "December"; break;
	default : cout <<"Invalid month!\n";
	}
}

void printCalendar(int month,int year){
	printMonth(month);
	cout << " / " << year << endl;
	int monthdays=dayofMonthYear(month,year);
	int daycounter=1;
	int daynum;
	// Main Calendar
	cout << "Mon Tue Wed Thu Fri Sat Sun\n";
	do{
		for (int i=1;i<=7;i++){
            daynum=dayofWeek(year,month,daycounter);
			 if (i==daynum) {cout << setw(3) << daycounter << ' ';
			 daycounter++;}
			 else cout << "    ";
			
		}
		cout << endl;
	}
	while(daycounter<monthdays);
	

}