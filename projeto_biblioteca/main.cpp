#include <iostream>
#include <conio.h>
#include "library.h"

using namespace std;

int main ()
{
	Library library("users.txt","books.txt");

	int op = 0;
	char cfg;

	do
	{
		//show menu

		cout << "**** Seja bem vindo a biblioteca PROGRAMACAO TP1 ****\n";
		cout << "#### Area de Administracao ####\n\n";
		cout << "1 - Registar Utilizador\n";
		cout << "2 - Adicionar livro\n";
		cout << "3 - Listar todos os utilizadores\n";
		cout << "4 - Listar todos os livros\n";
		cout << "5 - Pesquisar por utilizador\n";
		cout << "6 - Pesquisar por livro\n";
		cout << "7 - Mudar estado de um utilizador\n";
		cout << "\n#### Area de Utlizador ####\n\n";
		cout << "8 - Requisitar Livro\n";
		cout << "9 - Devolver Livro\n";

		cout<< "\n0 - Sair\n";
		cout<< "\nOpcao: ";
		// read user option
		cin >> op;
		cin.ignore(1000,'\n');
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			op=-1;
		}
		// if option is valid, ask for sure
		if(op>=0 && op<10){
			cout<<"Tem a certeza que deseja efectuar esta operacao?(Y/N)";
			cin>>cfg;
			cin.ignore(1000,'\n');
			if((toupper(cfg))!='Y')
			op=-1;
		}
		// Option to exit
		switch(op) {
		case 0:
			{
				system("cls");
				cout<<"A gravar... Nao encerre a aplicacao!"<<endl<<endl;
				clock_t start_time;
				start_time = clock();
				while((clock() - start_time) < 3 * CLOCKS_PER_SEC){
				} //delay time (3sec)

				cout<<"Gravacao concluida com exito!"
					<<endl<<endl
					<<"Ate a proxima!"
					<<endl<<endl
					<<"Prima qualquer tecla para sair...";
					_getch();
			}
			break;
		// Add users
		case 1:
			{

				string username;
				char opl;

				do
				{	
					system("cls");
					cout<<"Introduza o nome: ";
					getline(cin, username);
					
					while(username.length()>25){
						cout<<"\nErro! Nome de utilizador demasiado grande!\n\nInsira um nome ate 25 caracteres: ";
						getline(cin,username);
					}

					User u(username);
					library.addUser(u);
					cout<<endl<<"Utilizador "<<u.getName()<<" adicionado com sucesso com o ID: "<<u.getID()<<endl<<endl;
					cout<<"Deseja adicionar mais utilizadores?(Y/N)";
					cin>>opl;
					cin.ignore(1000,'\n');

				}
				while('Y'==(toupper(opl)));
			}
			library.saveUsers();
			break;
        // Add books
		case 2:
			{

				string title, author;
				char opl;
				int num;

				do{
					system("cls");
					cout<<"Introduza o titulo: ";
					getline(cin, title);
					
					while(title.length()>25){
						cout<<"\nErro! Nome do livro demasiado grande!\n\nInsira um nome ate 25 caracteres: ";
						getline(cin,title);
					}
					cout<<"\nIntroduza o autor: ";
					getline(cin,author);
					
					while(author.length()>17){
						cout<<"\nErro! Autor do livro demasiado grande!\n\nInsira um nome ate 16 caracteres: ";
						getline(cin,author);
					}
					cout<<"\nIntroduza a quantidade disponivel: ";
					cin>>num;
					
					while((num<0 || num>999999999) || cin.fail()){	// '999999999' is the last number that user can insert 
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Erro! Quantidade demasiado grande/quantidade invalida!\nIntroduza uma quantidade valida: "; 
						cin>>num;
					}

					cin.ignore(1000,'\n');
					Book b(title, author, num);
					library.addBook(b);
					cout<<endl<<"Livro "<<b.getTitle()<<" adicionado com sucesso com o ID: "<<b.getID()<<endl<<endl;
					cout<<"Deseja adicionar mais livros?(Y/N)";
					cin>>opl;
					cin.ignore(1000,'\n');
				}
				while('Y'==(toupper(opl)));
			}
			library.saveBooks();
			break;
	    // List users
		case 3:
			{
				system("cls");
				library.showUsers();
			}
			break;
        // List books
		case 4:
			{
				system("cls");
				library.showBooks();
			}
			break;
        // Search users
		case 5:
			{
				char opl;
				string str;

				do
				{
					system("cls");
					if(library.getNumUsers()==0){
						library.showUsers(); break;
					}
					cout<<"Escreva os termos pelos quais deseja pesquisar: ";
					getline(cin, str);
					library.showUsers(str);
					cout<<"Deseja pesquisar de novamente?(Y/N)";
					cin>>opl;
					cin.ignore(1000,'\n');
				}
				while('Y'==toupper(opl));
			}
			break;
        // Search books
		case 6:
			{
				char opl;
				string str;

				do
				{
					system("cls");
					if(library.getNumBooks()==0){
						library.showBooks();
						break;
					}
					cout<<"Escreva os termos pelos quais deseja pesquisar: ";
					getline(cin, str);
					library.showBooks(str);
					cout<<"Deseja pesquisar de novamente?(Y/N)";
					cin>>opl;
					cin.ignore(1000,'\n');
				}
				while('Y'==toupper(opl));
			}break;
        // Change users status
		case 7:
			{	
				User user;
				int userID;
				unsigned int active=0;
				bool check;
				char op;

				do
				{
					system("cls");
					library.showUsers();
					if(library.getNumUsers()==0)
						break;
					cout<<"Qual o utilizador do qual deseja actualizar o estado?: ";
					cin>>userID;
					user=library.getUserByID(userID);

					while (user.getID() ==0 || cin.fail()) {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<endl<<"Erro! Utilizador invalido! Introduza um utilizador valido: ";
						cin>>userID;
						user=library.getUserByID(userID);
					}
					cin.ignore(1000,'\n');

					do
					{
						cout <<"1 - Activo\n"
							<<"2 - Inactivo\n\n"
							<<"Opcao: ";
						cin>>active;
						if((!(active==1 || active==2)) || cin.fail()){
							cin.clear();
							cin.ignore(1000,'\n');
							cout<<"Opcao invalida! Escolha das seguintes opcoes: "<<endl;
							check = false;
						}
						else check=true;

					}
					while(check==false);

					cin.ignore(1000,'\n');
					
					if(user.hasBooksRequested() && active==2)
						cout<<"\nErro! utilizador tem livros em sua posse. Devolva primeiramente os livros.\n\n"; 
					else if(user.isActive())
							if(active==1)
							cout<<"O estado do utilizador "<<user.getName()<<" ja se encontra activo!\n\n";
						else {
							user.setActive(false); 
							library.replaceUser(user);
							cout<<"O estado do utilizador "<<user.getName()<<" foi actualizado para inactivo!\n\n";}
					else if(active==2)
						cout<<"O estado do utilizador "<<user.getName()<<" ja se encontra inactivo!\n\n";
					else {
						user.setActive(true);
						library.replaceUser(user);
						cout<<"O estado do utilizador "<<user.getName()<<" foi actualizado para activo!\n\n";}
					
					cout<<"Deseja actualizar outros estados?(Y/N)";
					cin>>op;
					cin.ignore(1000,'\n');
				}while('Y'==toupper(op));
			}
			library.saveUsers();
			break;
	    // Request books
		case 8:
			{
				char op;
				IdentNum userID,bookID;
				User user;
				unsigned int numAvailable;

				do
				{ 
					system("cls");
					library.showActiveUsers();
					if(!library.activeUsers())
						break;
					cout<<"Qual o utilizador que vai efectuar a requisicao?: ";
					cin>>userID;

					user=library.getUserByID(userID);
					while(!user.isActive() || user.getID()==0 || cin.fail()){
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"Utilizador invalido! Escolha um utilizador valido: ";
						cin>>userID;
						user=library.getUserByID(userID);
					}
					cin.ignore(1000,'\n');
					library.showAvailableBooks(user);
					if(!library.AvailableBooks(user)){
						break;
					}
					cout<<"Qual o livro que o utilizador deseja requisitar?: ";
					cin>>bookID;
					numAvailable=library.getBookByID(bookID).getNumAvailable();

					while(user.havethebook(bookID) || (numAvailable==0)){
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"ID invalido! Escolha um livro valido: ";
						cin>>bookID;
						numAvailable=library.getBookByID(bookID).getNumAvailable();
					}
					cin.ignore(1000,'\n');
					library.loanBook(userID, bookID);
					cout<<endl<<"Requisicao efectuada com sucesso!\n\n";
					cout<<"Deseja requisitar outros livros?(Y/N)";
					cin>>op;
					cin.ignore(1000,'\n');
				}
				while('Y'==toupper(op));
			}
			library.saveUsers();
			library.saveBooks();
			break;
        // Return  books
		case 9:
			{
				char op;
				IdentNum userID,bookID;
				User user;

				do
				{	
					system("cls");
					library.showActiveUsers();
					if(!library.activeUsers())
						break;
					
					cout<<"Qual o utilizador que vai devolver o livro?: ";
					cin>>userID;
					user=library.getUserByID(userID);
					if (user.hasBooksRequested())
					{	cin.ignore(100,'\n');
						library.showUserBooks(userID);
						cout<<"Qual o livro que quer devolver?: ";
						cin>>bookID;
						while (!user.havethebook(bookID) || cin.fail()){
							cin.clear();
							cin.ignore(1000,'\n');
							cout<<"Erro! Introduza um livro valido!: ";
							cin>>bookID;
						}
						cin.ignore(1000,'\n');
						library.returnBook(userID, bookID);
						cout<<"\nDevolucao efectuada com sucesso!";
					}
					else {
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"\nERRO! Esse utilizador nao tem nenhum livro a devolver";
					}
					cout<<"\n\nDeseja devolver outros livros?(Y/N)";
					cin>>op;
					cin.ignore(1000,'\n');
				}
				while('Y'==toupper(op));
			}
			library.saveUsers();
			library.saveBooks();
			break;
		}
		if(op>0 && op<=9)
		{
			cout<<"\nPrima qualquer tecla para voltar ao menu...";
			_getch();
		}
		system("cls");
	}while (op != 0);
}
