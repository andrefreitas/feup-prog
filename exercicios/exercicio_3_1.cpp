// Exercice 3.1
// Problem: Compute the area of a triangle
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
#include <iostream>
#include <math.h>
using namespace std;
double distance(double x1, double y1, double x2, double y2);
double area(double x1, double y1, double x2, double y2,double x3, double y3);
int main(){
	// Input
	int x1,x2,x3,y1,y2,y3;
	cout << "1st Coordinate(x,y)? ";
	cin >> x1 >> y1;
	cout << "2st Coordinate(x,y)? ";
	cin >> x2 >> y2;
	cout << "3st Coordinate(x,y)? ";
	cin >> x3 >> y3;
	// Compute
	double triangarea=area(x1,y1,x2,y2,x3,y3);
	// Print
	cout << "The area of the triangle is: " << triangarea << endl;
	cin.get();
	system("pause");
}

double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow((double)x2-x1,2)+pow((double)y2-y1,2));
}
double area(double x1, double y1, double x2, double y2,double x3, double y3){
	double a=distance(x1,y1,x2,y2);
    double b=distance(x2,y2,x3,y3);
	double c=distance(x1,y1,x3,y3);
	double semip=(a+b+c)/2.0;
	return sqrt(semip*(semip-a)*(semip-b)*(semip-c));
}