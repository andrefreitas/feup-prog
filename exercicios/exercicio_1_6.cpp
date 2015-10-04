// -----------------------------------------------------------------------------------------------------------------------
// Exercice 1.6 
// Problem: Escreva um programa que leia as coordenadas dos vértices de um triângulo e calcule a sua área.
// Author: André Freitas 
// Email: p.andrefreitas@gmail.com
// -----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
using namespace std;
int main(){
		// Coordinate structure
	// Coordinate structure
	struct coordinate{
		int x;
		int y;
	};
	coordinate p1,p2,p3;
	// Read coordinates
	cout << "Ponto1 x e y? ";
	cin >> p1.x >> p1.y;
	cout << "Ponto2 x e y? ";
	cin >> p2.x >> p2.y;
	cout << "Ponto3 x e y? ";
	cin >> p3.x >> p3.y;
	// Compute a, b and c
	float a,b,c;
	a=sqrt(pow((float) (p2.x-p1.x),2) + pow((float) (p2.y-p1.y),2));
	b=sqrt(pow((float) (p2.x-p3.x),2) + pow((float) (p2.y-p3.y),2));
	c=sqrt(pow((float) (p1.x-p3.x),2) + pow((float) (p1.y-p3.y),2));
	//cout << "a: " << a;
	//cout << " b: " <<  b;
	//cout << " c: " << c;
	// Compute the semi-perimeter
	float s;
	s=(a+b+c)/2;
	//cout << "\ns: " << s;
	// Compute the area
	float area;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	// Print the area
	cout << "\nA area e " << area << '\n';
	system("pause");

}