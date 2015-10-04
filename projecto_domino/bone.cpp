#include "allfives.h"
// ----------------------------
//        Constructors
// ----------------------------
bone::bone(){
}
bone::bone(int head, int tail){
	this->head=head;
	this->tail=tail;
}
// ----------------------------
//        Set functions
// ----------------------------
void bone::setID(int num){
	this->id=num;
}
void bone::setValues(int head,int tail){
	this->head=head;
	this->tail=tail;
}

void bone::setCoord(int x, int y){
this->x=x;
this->y=y;
}
// ----------------------------
//        Get functions
// ----------------------------
int bone::getID(){
	return id;
}
int bone::getHead(){
	return head;
}
int bone::getTail(){
	return tail;
}
bool bone::isDouble(){
	return getHead()==getTail();
}
int bone::getX(){
return x;
}
int bone::getY(){
return y;
}
// ----------------------------
//		 Show function
// ----------------------------
void bone::showBone(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BWI);
	cout << " " << getHead() << ":" << getTail() << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
	cout << " ";
}
// ----------------------------
//		 Sum of  the head and tail
// ----------------------------
int bone::sum(){
	int sum;
	sum=getHead()+ getTail();
	return sum;
}