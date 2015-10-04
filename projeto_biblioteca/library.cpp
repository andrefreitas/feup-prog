#include "library.h"
/********************************************************************
Constructors/Destructor
********************************************************************/
Library::Library(string fileUsers, string fileBooks)
{ 
	ifstream infile;
	filenameUsers=fileUsers;
	filenameBooks=fileBooks;

	// Check if books files exists
	infile.open(filenameBooks.c_str());
	if (infile.fail())
	{
		ofstream outfile;
		outfile.open(filenameBooks.c_str());
		outfile.close();
	} 
	else {infile.close(); loadBooks();}

	// Check if users files exists
	infile.open(filenameUsers.c_str());
	if (infile.fail())
	{
		ofstream outfile;
		outfile.open(filenameUsers.c_str());
		outfile.close();
	}
	else {infile.close(); loadUsers();}

}

Library::Library(){ 
}

//Each time the program finishes, books and users are saved automatically
Library::~Library(){
saveUsers();
saveBooks();
}

/********************************************************************
Get functions
********************************************************************/
User Library::getUserByID(IdentNum uID) const
{
	User user;
	if(users.size()!=0 && (uID>0 && uID<=users.size()))
	{
		uID--;
		return users[uID];
	}
	else return user;
}

Book Library::getBookByID(IdentNum bookID) const
{	
	Book book;
	book.setNumAvailable(0);

	if(books.size()!=0 && (bookID>0 && (bookID<=books.size()))){
	bookID--;
	return books[bookID];
	}
	else return book;
}

//EXTRAS
IdentNum Library::getNumUsers() const{
	return users.size();
}

IdentNum Library::getNumBooks() const{
	return books.size();
}

/********************************************************************
Loading functions
********************************************************************/
void Library:: loadUsers()
{	
	ifstream input;
	IdentNum userID, numUsers=0;
	string Username;
	User u;
	bool active;

	input.open(filenameUsers.c_str());
	// get the number of users
	input.ignore(1000,':'); //ignore the string before the number
	input>>numUsers;
	u.setNumUsers(numUsers);
	// main loop to get id, name, status and requested books
	while(!input.eof())	// while not at end of the file
	{
		input.ignore(100, ':');
		input>>userID;
		input.ignore(1000,'\n'); //ignore to change line 
		getline(input,Username);
		input.ignore(1000, ':');
		input>>active;

		u.setID(userID);
		u.setName(Username);
		u.setActive(active);

		// Get requested  books
		string booklist;
		vector<IdentNum> bookvector;

		input.ignore(1000, ':');
		// Algorithm: the spaces between numbers are the reference to get the integers.
		// While exists spaces add to the bookvector the numbers and erase them from the string
		getline(input, booklist);
		booklist.erase(0,1); //erase the space before the first number
		booklist.push_back(' ');// insert a space in the end of the string
		int whereis;
		while (booklist.find(" ")!=-1){
			whereis=booklist.find(" ");
			bookvector.push_back(atoi(booklist.substr(0,whereis+1).c_str()));
			booklist.erase(0,whereis+1);
		}
		if(bookvector[0]==0)
		bookvector.clear();
		u.setRequestedBooks(bookvector);
		addUser(u);
	}
	//close the file
	input.close();
}

void Library::loadBooks()
{
	ifstream input;
	IdentNum bookID, numBooks=0;
	string bookTitle, bookAuthor;
	unsigned int bookNumAvailable;
	Book b;

	
	input.open(filenameBooks.c_str());

	input.ignore(1000,':'); //ignore the string before the number
	input>>numBooks;
	b.setNumBooks(numBooks);

	while(!input.eof())	//while not at the end of the file
	{
		input.ignore(1000, ':');
		input>>bookID; 
		input.ignore(1000,'\n'); //to change line
		getline(input,bookTitle);
		getline(input,bookAuthor);
		input.ignore(1000, ':');
		input>>bookNumAvailable;
		b.setID(bookID);
		b.setTitle(bookTitle);
		b.setAuthor(bookAuthor);
		b.setNumAvailable(bookNumAvailable);
		addBook(b);
	}
	//close the file
	input.close();
}

/********************************************************************
Saving functions
********************************************************************/
void Library::saveBooks()
{
	ofstream outfile;
	string nameTemp="tempbooks.txt";

	//temporary file
	outfile.open(nameTemp.c_str());
	
	//writes in the file while the size of the vector books is not reached
	outfile<<"*Número total de livros*: "<<books.size();
	for (unsigned int i=0; i<books.size();i++)
	{
		Book b=books[i];
		outfile <<endl<<endl
			<<"ID: "<<b.getID()<<endl
			<<b.getTitle()<<endl
			<<b.getAuthor()<<endl
			<<"Quantidade: "<<b.getNumAvailable();
	}
	//close the file
	outfile.close();

	//if everything's alright
	if(outfile.good())
	{
		remove(filenameBooks.c_str());
		rename(nameTemp.c_str(),filenameBooks.c_str());
	} 
}

void Library::saveUsers()
{
	
	ofstream outfile;
	string nameTemp="tempusers.txt";

	//temporary file
	outfile.open(nameTemp.c_str());
	//writes in the file while the size of the vector users is not reached
	outfile<<"*Número total de utilizadores*: "<<users.size();
	for (unsigned int i=0; i<users.size();i++)
	{
		User u=users[i];
		vector<IdentNum> booksRequested=u.getRequestedBooks();

		outfile <<endl<<endl
			<<"ID: "<<u.getID()<<endl
			<<u.getName()<<endl
			<<"Activo: "<<u.isActive()<<endl
			<<"Livros em posse(ID):";

		if(u.hasBooksRequested())
		{
			for(unsigned int i=0; i<u.getRequestedBooks().size(); i++)
			{
				outfile<<' '<<booksRequested[i];
			}
		}
		else outfile<<' '<<0; 
	}
	//close the file
	outfile.close();

	//if everything's alright
	if(outfile.good())
	{
		remove(filenameUsers.c_str());
		rename(nameTemp.c_str(),filenameUsers.c_str());
	} 
}

/********************************************************************
Loan/return
********************************************************************/
void Library::loanBook(IdentNum uID, IdentNum bID) 
{
	User user;
	Book b;

	//search the book(by ID) in the booklibrary(vector-books) and dec the number available
	b=getBookByID(bID);
	b.loanBook();
	replaceBook(b);
	//search the user(by ID) in the userlibrary(vector-users) and associate him to the book
	user=getUserByID(uID);
	user.borrowBook(bID);
	replaceUser(user);
}

void Library::returnBook(IdentNum uID, IdentNum bID)
{
	User user;
	Book b;

	//search the book(by ID) in the booklibrary(vector-books) and inc the number available
	b = getBookByID(bID);
	b.returnBook();
	replaceBook(b);
	//search the user(by ID) in the userlibrary(vector-users) and remove the book associated
	user = getUserByID(uID);
	user.returnBook(bID);
	replaceUser(user);
}

/********************************************************************
Add functions
********************************************************************/
void Library::addBook(Book bookLib)
{
	books.push_back(bookLib);
}

void Library::addUser(User userLib)
{	
	users.push_back(userLib);
}

/********************************************************************
Showing functions
********************************************************************/
void Library::showBooks() const
{	
	unsigned int IDField=9, AuthorTitleField=3*9,QDfield=10;  //fields
	if(books.size()==0)
		cout<<"### Livros ###"<<endl
			<<" -------------------------------------------------------------------------"<<endl
			<<setw(IDField)<<left<<"|"
			<<setw(39)<<right<<"Nenhum Livro registado!"
			<<setw(27)<<right<<'|'<<endl;
	else{
		//header
		cout<<"### Livros ###"<<endl
			<<" -------------------------------------------------------------------------"<<endl
			<<setw(IDField)<<left<<"|ID"
			<<setw(AuthorTitleField)<<left<<"|Titulo"
			<<setw(AuthorTitleField)<<left<<"|Autor"
			<<"|QTD. Disp.|"<<endl
			<<" -------------------------------------------------------------------------"<<endl;
		//run the vector books and shows all the books associated to the vector; using 'setw' to align
		for (unsigned int i=0; i<books.size();i++)
		{
			cout<<"|"<<setw(IDField-1)<<left<<books[i].getID()
				<<"|"<<setw(AuthorTitleField-1)<<left<<books[i].getTitle()
				<<"|"<<setw(AuthorTitleField-1)<<left<<books[i].getAuthor()
				<<"|"<<setw(QDfield)<<left<<books[i].getNumAvailable()
				<<"|"<<endl;
		}}
	//footer
	cout<<" -------------------------------------------------------------------------"<<endl;
}

void Library::showUsers() const
{
	unsigned int IDfield=9, Namefield=27,Activefield=18;
	if(users.size()==0)
		cout<<"### Utilizadores ###"<<endl
		<<" -----------------------------------------------------"<<endl
		<<"|"<<setw(40)<<right<<"Nenhum utilizador registado!"<<setw(14)<<right<<"|"<<endl;
	else
	{
		//header
		cout<<"### Utilizadores ###"<<endl
			<<" -----------------------------------------------------"<<endl
			<<setw(IDfield)<<left<<"|ID"
			<<setw(Namefield)<<left<<"|Nome"
			<<setw(Activefield)<<left<<"|Activo"
			<<'|'<<endl
			<<" -----------------------------------------------------"<<endl;
		//shows all the users associated to the vector ; using 'setw' to align
		for (unsigned int i=0; i<users.size();i++)
		{
			cout<<"|"<<setw(IDfield-1)<<left<<users[i].getID()
				<<"|"<<setw(Namefield-1)<<users[i].getName()
				<<"|"<<setw(Activefield-1)<<left<<users[i].showStatus()
				<<setw(1)<<right<<"|"<<endl;
		}
	}
	//footer
	cout<<" -----------------------------------------------------"<<endl;
}

void Library::showAvailableBooks(User user) const
{
	unsigned int bookQD;
	unsigned int IDField=9, AuthorTitleField=27, QDfield=10;  // fields
	bool check=false;
	
		//header
		cout<<endl<<"### Livros ###"<<endl
			<<" -------------------------------------------------------------------------"<<endl
			<<setw(IDField)<<left<<"|ID"
			<<setw(AuthorTitleField)<<left<<"|Titulo"
			<<setw(AuthorTitleField)<<left<<"|Autor"
			<<"|QTD. Disp.|"<<endl
			<<" -------------------------------------------------------------------------"<<endl;

		//shows the books that are available to request
		for (unsigned int i=0;i<books.size();i++)
		{	
			bookQD=books[i].getNumAvailable();

			if ((bookQD!=0) && !(user.havethebook(i+1))){
			cout<<"|"<<setw(IDField-1)<<left<<books[i].getID()
				<<"|"<<setw(AuthorTitleField-1)<<left<<books[i].getTitle()
				<<"|"<<setw(AuthorTitleField-1)<<left<<books[i].getAuthor()
				<<"|"<<setw(QDfield)<<left<<books[i].getNumAvailable()
				<<"|"<<endl;
			check=true;
			}
		}
		//if not available
		if(!check){
			cout<<"|"<<setw(50)<<right<<"Nenhum Livro disponivel!"
				<<setw(24)<<right<<"|"<<endl;
		}
	//footer
	cout <<" -------------------------------------------------------------------------"<<endl;
}

void Library::showUserBooks(IdentNum uID) const
{
	//EXTRA function: Shows all the books requested by the user
	User user;
	IdentNum ID;
	unsigned int i=0;
	vector <IdentNum> requestedBooks;
	unsigned int IDField=9, TitleField=27, AuthorField=18;  // fields

	user=getUserByID(uID);
	requestedBooks=user.getRequestedBooks();
	//header
	cout	<<endl<<"### Livros ###"<<endl
			<<" -----------------------------------------------------"<<endl
			<<setw(IDField)<<left<<"|ID"
			<<setw(TitleField)<<left<<"|Titulo"
			<<setw(AuthorField)<<left<<"|Autor"
			<<"|"<<endl
			<<" -----------------------------------------------------"<<endl;

		while(i<requestedBooks.size())
		{
			ID = requestedBooks[i];
			ID--;
			cout<<"|"<<setw(IDField-1)<<left<<books[ID].getID()
				<<"|"<<setw(TitleField-1)<<left<<books[ID].getTitle()
				<<"|"<<setw(AuthorField-1)<<left<<books[ID].getAuthor()
				<<"|"<<endl;
			i++;
		}
	//footer
	cout  <<" -----------------------------------------------------"<<endl;
}

void Library::showActiveUsers() const
{
	//EXTRA function
	User user;
	bool active;
	unsigned int IDfield=9, Namefield=27,Activefield=18;
	if(activeUsers())
		{
			//header
		cout<<"### Utilizadores ###"<<endl
			<<" -----------------------------------------------------"<<endl
			<<setw(IDfield)<<left<<"|ID"
			<<setw(Namefield)<<left<<"|Nome"
			<<setw(Activefield)<<left<<"|Activo"
			<<'|'<<endl
			<<" -----------------------------------------------------"<<endl;
		//run the vector users and shows all the active users; using 'setw' to align
		for (unsigned int i=0; i<users.size();i++)
		{ 
			user=users[i];
			active=user.isActive();

			if(active)
				cout<<"|"<<setw(IDfield-1)<<left<<users[i].getID()
				<<"|"<<setw(Namefield-1)<<users[i].getName()
				<<"|"<<setw(Activefield-1)<<left<<users[i].showStatus()
				<<setw(1)<<right<<"|"<<endl;
		}
	}
	else {
		cout<<"### Utilizadores ###"<<endl
		<<" -----------------------------------------------------"<<endl
		<<"|"<<setw(40)<<right<<"Nenhum utilizador activo!"<<setw(14)<<right<<"|"<<endl;}

	//footer
	cout<<" -----------------------------------------------------"<<endl;
}

/********************************************************************
Shearching functions
********************************************************************/
void Library::showBooks(string str) const
{
	string bookName;
	bool counter=true;
	unsigned int IDField=9, AuthorTitleField=3*9,QDfield=10;

		//header
		cout<<" -------------------------------------------------------------------------"<<endl
			<<setw(IDField)<<left<<"|ID"
			<<setw(AuthorTitleField)<<left<<"|Titulo"
			<<setw(AuthorTitleField)<<left<<"|Autor"
			<<"|QTD. Disp.|"<<endl
			<<" -------------------------------------------------------------------------"<<endl;

		//Compare the name of each book with the string written by the user 
		for (unsigned int i=0;i<books.size();i++)
		{
			bookName=books[i].getTitle();
			strToUpper(bookName);
			strToUpper(str);

			if (bookName.find(str)!=string::npos)
			{
				cout<<"|"<<setw(IDField-1)<<left<<books[i].getID()
				<<"|"<<setw(AuthorTitleField-1)<<left<<books[i].getTitle()
				<<"|"<<setw(AuthorTitleField-1)<<left<<books[i].getAuthor()
				<<"|"<<setw(QDfield)<<left<<books[i].getNumAvailable()
				<<"|"<<endl;
				counter=false;
			}
		}
		if(counter) 
			cout<<"|\t\t\tNenhum livro encontrado!\t\t\t  |"<<endl;
	//footer
	cout<<" -------------------------------------------------------------------------"<<endl;
}

void Library::showUsers(string str) const
{
	string username;
	bool counter=true;
	unsigned int IDfield=9, Namefield=27,Activefield=18;

		cout<<"### Utilizadores ###"<<endl
			<<" -----------------------------------------------------"<<endl
			<<setw(IDfield)<<left<<"|ID"
			<<setw(Namefield)<<left<<"|Nome"
			<<setw(Activefield)<<left<<"|Activo"
			<<'|'<<endl
			<<" -----------------------------------------------------"<<endl;
		//show all users
		for (unsigned int i=0;i<users.size();i++)
		{
			username=users[i].getName();
			strToUpper(username);
			strToUpper(str);

			if (username.find(str)!=string::npos)

			{
				cout<<"|"<<setw(IDfield-1)<<left<<users[i].getID()
					<<"|"<<setw(Namefield-1)<<users[i].getName()
					<<"|"<<setw(Activefield-1)<<left<<users[i].showStatus()
					<<setw(1)<<right<<"|"<<endl;
				counter=false;
			}
		}
		if(counter) 
			cout<<":\t   Nenhum utilizador encontrado!\t      :"<<endl;
		//footer
		cout <<" -----------------------------------------------------"<<endl;
}

/********************************************************************
EXTRAS
********************************************************************/
// converts a string to a UPPERCASE string
void strToUpper(string &str)
{
	for (size_t i=0; i<str.length(); i++)
		str[i] = toupper(str[i]);
}

// updates the user in the users vector
void Library::replaceUser(User user)
{
	IdentNum userID;
	userID=user.getID();
	userID--;
	users[userID]=user;
}

// updates the book in the books vector
void Library::replaceBook(Book book)
{
	IdentNum bookID;
	bookID=book.getID();
	bookID--;
	books[bookID]=book;
}

// count the number of active users. Returns TRUE if there is at least one active user
bool Library::activeUsers() const
{ 
	bool counter=0;
	unsigned int i;
	
	for(i=0; i<users.size();i++)
	{
		if(users[i].isActive())
			counter++;
	}
	return counter;
}

// returns true if there are available books to request from the user
bool Library::AvailableBooks(User user) const
{
	bool check=false;
	IdentNum bookQD;

	for (unsigned int i=0;i<books.size();i++)
		{	
			bookQD=books[i].getNumAvailable();

			if ((bookQD!=0) && !(user.havethebook(i+1))){
				check=true;
			}
		}
	return check;
}
