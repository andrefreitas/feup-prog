#include "library.h"

IdentNum Book::numBooks = 0;

//constructors
Book::Book(){
}

Book::Book(string bookTitle, string bookAuthor, unsigned int bookQuantity)
{
	numBooks++;
	ID=numBooks;
	title=bookTitle;
	author=bookAuthor;
	numAvailable=bookQuantity;
}

//get methods
IdentNum Book::getID()const
{
	return ID;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

unsigned int Book::getNumAvailable() const
{
	return numAvailable;
}

//set methods
void Book::setID(IdentNum bookID)
{
	ID=bookID;
}

void Book::setTitle(string bookTitle)
{
	title=bookTitle;
}

void Book::setAuthor(string bookAuthor)
{
	author=bookAuthor;
}

void Book::setNumAvailable(unsigned int numBooks)
{
	numAvailable=numBooks;

}

void Book::setNumBooks(IdentNum num)
{
	numBooks=num;
}

void Book::addBooks(int bookQuantity)
{
	numAvailable+=bookQuantity;
}

void Book::loanBook()
{
	numAvailable--;
}

void Book::returnBook()
{
	numAvailable++;
}