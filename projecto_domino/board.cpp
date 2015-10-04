#include "allfives.h"
// ----------------------------
//        Constructors
// ----------------------------
board::board(){
}
board::board(int id){
	this->id=id;
	startGame();
}
// ----------------------------
//        Set functions
// ----------------------------
void board::setFirstDouble(){
	firstDouble=true;
}
void board::setlockedDouble(){
	lockedDouble=true;
}

// *********************************************************
// Function: Update the targets vector
// Params: The bone that the player played
// Returns: nothing
// *********************************************************
void board::evaluateTargets(bone piece, int unsigned pos){
	if(targets.size()==0){
		targets.push_back(piece.getHead());
		targets.push_back(piece.getTail());
		if(piece.isDouble()){
			setFirstDouble();
			firstDoub=piece;
		}
	}
	else{
		if(!firstDouble && piece.isDouble()){
			setFirstDouble();
			firstDoub=piece;
		}
		targets[pos]=piece.getHead();
		}

	if((lockedLeft &&lockedRight) & !lockedDouble){
		setlockedDouble();
		targets.push_back(firstDoub.getHead());
		targets.push_back(firstDoub.getHead());
	}
}
// *********************************************************
// Function: Asks how many players and collect the data
// Params: nothing
// Returns: nothing
// *********************************************************
void board::startGame(){
	string name;
	int num;
	//Initializing variables
	lockedDouble=false;
	firstDouble=false;
	lockedRight=false;
	lockedLeft=false;

	// ########### Print header ########### 
	printColour("green");
	printline();
	printColour("clear");
	cout << endl;
	print("JOGO DOMINOS ALL FIVES","center");
	cout << endl;
	print("ESCOLHA QUANTOS JOGADORES PRETENDEM JOGAR","center");
	cout << endl;
	cout << endl;
	printColour("green");
	printline();
	printColour("clear");
	// ########### Play Sound ########### 
	PlaySoundA("intro.wav", NULL, SND_NODEFAULT |SND_NOWAIT | SND_ASYNC | SND_NOSTOP);
	// (1) How many players?
	do{
		cout << endl;
		print("Numero de Jogadores: ","center");
		inputInteger(num);// Extreme validation :D
	} while(num < 2 || num > 4);
	// (2) Get player data
	for (int i=0;i<num;i++){
		cout << endl;
		printline();
		cout << "Dados para o jogador numero " << i+1 << endl;
		printline();
		// (a) Name
		cout<<"[Nome]: ";
		getline(cin, name);
		// (b) Put 7 bones on the player
		player p(name, game.startPlayer(),i);
		// (c) Human bool
		string ans;
		cout << "[Humano]:(s/n) ";
		cin >> ans;
		cin.ignore(1000,'\n');
		if (ans[0]=='s' || ans[0]=='S') p.setHuman(true);
		else p.setHuman(false);
		// (d) Load the player
		players.push_back(p);
	}
	// (3) play the first piece
	firstPiece();
	// ########### Game is about to start... ########### 
	system("cls");
	cout << "\nO jogo vai comecar...\n";
	Sleep(1000);
	// ########### Stop sound ########### 
	PlaySoundA(0,0,0);
	gotoxy(60,20);
	cout<<"O jogador "<<players[totalPlayers()-1].getName()<<" jogou a primeira peca!\n";
	cin.get();
	gotoxy(0,0);
}
// *********************************************************
// Function: When the game starts, the greatest piece is 
// on the board, so this functions "put" this bone on the board
// Params: nothing
// Returns: nothing
// *********************************************************
void board::firstPiece(){
	// (1) First get the greatest piece of the players
	bone b=players[0].greatestPiece();
	for(int unsigned i=1; i<players.size(); i++){
		// (a) If the greatest is double
		if(b.isDouble())
		{	// (i) If the player has a greater
			if((players[i].greatestPiece().isDouble()))
				if((b.sum())<(players[i].greatestPiece().sum()))
					b=players[i].greatestPiece();
		}
		// (b) If the greatest isn't double and the player has one
		else if (players[i].greatestPiece().isDouble())
			b=players[i].greatestPiece();
		// (b) If the sum of head and bone is greater
		else if((b.sum())<(players[i].greatestPiece().sum()))
			b=players[i].greatestPiece();
	}
	// (2) Place the bone as first piece
	firstP=b;
	// (3) Update the targets
	evaluateTargets(b, 0);
	// (4) Remove the bone from the player, by the Bone ID
	int num=0;
	player player;
	for (int unsigned i=0; i<players.size(); i++){
		vector <bone> temp;
		temp=players[i].getBones();
		for(int unsigned c=0; c<temp.size();c++){	
			if(temp[c].getID()==b.getID()){
				temp.erase(temp.begin()+c,temp.begin()+c+1);
				players[i].setBones(temp);
				num=i;
			}
		}
	}  
	// (5) Evaluate the points & Put the player that played the first piece, on the end of the players
	evaluatePoints(players[num]);
	player=players[num];
	players.erase(players.begin()+num,players.begin()+num+1);
	players.push_back(player);
}
// *********************************************************
// Function: Update the player points
// Params: receive by reference the player that is playing
// Returns: nothing
// *********************************************************
void board::evaluatePoints(player &playeronplay){
	int sum=0;
	int l=bonesLeft.size()-1;
	int r=bonesRight.size()-1;
	int u=bonesUp.size()-1;
	int d=bonesDown.size()-1;
	vector <int> sizes;

	sizes.push_back(l);
	sizes.push_back(r);
	sizes.push_back(u);
	sizes.push_back(d);
	
	//if there is only one piece or one side is free
	if(r==-1){
		if(l==-1) 
		sum=targets[0]+targets[1];
		else if (firstP.isDouble())
			sum=2*targets[1];
		else sum=targets[1];
	}
	else if(l==-1)
		 if (firstP.isDouble())
			sum=2*targets[0];
		else sum=targets[0];

	//if firstdouble is locked and no pieces in vertical
	if((u==-1 && d==-1) && lockedDouble){
		sum=2*targets[3];
	}
	
	for(int unsigned i=0; i<sizes.size(); i++){
		int size=sizes[i];

		if(i==0 && size>=0){
			if(bonesLeft[size].isDouble())
				sum+=2*(targets[i]);
			else sum+=targets[i];
		}

		if (i==1 && size>=0){
			if(bonesRight[size].isDouble())
				sum+=2*(targets[i]);
			else sum+=targets[i];
		}
			if(i==2 && size>=0){
				if(bonesUp[size].isDouble())
					sum+=2*(targets[i]);
				else sum+=targets[i];
			}

			if(i==3 && size>=0){
				if(bonesDown[size].isDouble())
					sum+=2*(targets[i]);
				else sum+=targets[i];
			}
		}
			if(sum%5==0){ 
				playeronplay.addScore(sum);
			}
	//If we have a winner 
	if(haveWinner()){
		int sumWinner=0;
		int winner;
		winner=haveWinner()-1;
		for(int unsigned j=0; j<players.size();j++){
			if(j!=winner)
				sumWinner+=players[j].sumPieces();
		}
		sumWinner=RoundMultiple5(sumWinner);
		playeronplay.addScore(sumWinner);
	}
}

void board::evaluateWinner(vector <player> players, int lastPlayer){
	int pos=lastPlayer;
	int score=players[lastPlayer].getScore();
	
	for(int unsigned i=0; i<players.size(); i++){
		if(score<players[i].getScore()){
			pos=i;
			score=players[i].getScore();
		}
	}
	printline(); cout << endl;
	print("PARABENS ","center"); cout << players[pos].getName() << " !!\n";
	print("TOTAL DE PONTOS: ","center"); cout << score << "\n\n";
    printline(); cout << endl<<endl;
	cout<<"Outras pontuacoes:\n\n";
	for(int unsigned i=0; i<players.size();i++){
	if(i!=pos)
		cout<<"Jogador "<<players[i].getName()<<": "<<players[i].getScore()<<endl<<endl;
	}

}
// *********************************************************
// Function: Check if the game have a Winner
// Params: nothing
// Returns: 0 if no one, the player id if someone won the game
// *********************************************************
int board::haveWinner(){	 
	int winner=0;
	// (1) Find the player that has 0 bones
	for(int unsigned i=0; i<players.size(); i++){
		if(players[i].bonesSize()==0)
			winner=i+1;
	}
	return winner;
 }

int board::totalPlayers(){
	return players.size();
}

int board::spaceNeeded(vector <bone> bones){
	int size=0;
	for(int unsigned i=0; i<bones.size(); i++){
			if(bones[i].isDouble())
				size++;
			else size+=3;
	}
	return size;
}
// *********************************************************
// Function: Show the board of bones
// Params: nothing
// Returns: nothing
// *********************************************************
void board::showBoard(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BG);
	printline();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
	cout << endl;
	int x=70;
	int y=30;
	firstP.setCoord(x,y);
	gotoxy(x,y);
		if(firstP.isDouble()){
			cout<<'o';
			gotoxy(x,y-1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
			cout<<firstP.getHead();
			gotoxy(x,y+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
			cout<<firstP.getTail();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
		}
		else{ 
			for(int i=0;i<3;i++){
			gotoxy(x,y);
			if(i==0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<firstP.getHead();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
			}
			if(i==1)
				cout<<'|';
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<firstP.getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
			}
		x++;
		}
			x=firstP.getX();
		}
	x=x-spaceNeeded(bonesLeft);
	for(int i=bonesLeft.size()-1; i>-1; i--){
		if(bonesLeft[i].getID()==firstDoub.getID())
			firstDoub.setCoord(x,y);
			for(int j=0; j<3;j++){
			gotoxy(x,y);
			if(bonesLeft[i].isDouble()){
				cout<<'o';
				gotoxy(x,y-1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<bonesLeft[i].getHead();
				gotoxy(x,y+1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<bonesLeft[i].getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
				j=3;
			}
			else{
			if(j==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
					cout<<bonesLeft[i].getHead();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
			}

			if(j==1)
				 cout<<'|';

			if(j==2){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<bonesLeft[i].getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
			}
		}
			x++;
	}
}	
	if(!firstP.isDouble())
	x+=3;
	else x+=1;
	
	for(int unsigned i=0;i<bonesRight.size(); i++){
		if(bonesRight[i].getID()==firstDoub.getID())
			firstDoub.setCoord(x,y);
			for(int j=0; j<3;j++){
			gotoxy(x,y);
			if(bonesRight[i].isDouble()){
				cout<<'o';
				gotoxy(x,y-1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<bonesRight[i].getHead();
				gotoxy(x,y+1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<bonesRight[i].getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
				j=3;
			}
			else{
			if(j==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
					cout<<bonesRight[i].getTail();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
			}

			if(j==1)
				 cout<<'|';

			if(j==2){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<bonesRight[i].getHead();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
			}
		}
			x++;
	}
	}
	y=firstP.getY();
	y-=(1+spaceNeeded(bonesUp));
	if(firstP.getID()==firstDoub.getID())
		x=firstP.getX();
	else x=firstDoub.getX();

		for(int i=bonesUp.size()-1;i>-1; i--){
			for(int j=0; j<3;j++){
			gotoxy(x,y);
			if(bonesUp[i].isDouble()){
				cout<<'|';
				gotoxy(x-1,y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<bonesUp[i].getHead();
				gotoxy(x+1,y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<bonesUp[i].getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
				j=3;
			}
			else{
			if(j==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
					cout<<bonesUp[i].getHead();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
			}

			if(j==1)
				 cout<<'o';

			if(j==2){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<bonesUp[i].getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
			}
		}
			y++;
	}
	}
		y=firstP.getY()+2;
		for(int unsigned i=0;i<bonesDown.size(); i++){
			for(int j=0; j<3;j++){
			gotoxy(x,y);
			if(bonesDown[i].isDouble()){
				cout<<'|';
				gotoxy(x-1,y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<bonesDown[i].getHead();
				gotoxy(x+1,y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
				cout<<bonesDown[i].getTail();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
				j=3;
			}
			else{
			if(j==0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FR| BNULL);
					cout<<bonesDown[i].getTail();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
			}

			if(j==1)
				 cout<<'o';

			if(j==2){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG| BNULL);
				cout<<bonesDown[i].getHead();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW| BNULL);
			}
		}
			y++;
	}
	}
}
// *********************************************************
// Function: Show the board of bones
// Params: nothing
// Returns: nothing
// *********************************************************
void board::printHeader(){
	int play=1+bonesLeft.size()+bonesRight.size()+bonesUp.size()+bonesDown.size();
	system("cls");
	printColour("green");
	printline();
	printColour("clear");
	cout << endl;
	print("VAMOS JOGAR!!!","center");
	cout << endl;
	print("Pecas no monte: ","center"); cout << game.getSize() << endl ;
	print("Jogada numero: " ,"center"); cout << (play) << "\n\n";
	
}
// *********************************************************
// Function: Request boneyard bones
// *********************************************************
void board::requestBoneyard(bool &bonefound, int &valuefound, bone &piece, int i){
	// (WARNING) If the player couldn't play, he need to request bones
	// -------------------------------------------------------------
	// ########### Audio Warning ########### 
	PlaySoundA("error.wav", NULL, SND_FILENAME|SND_ASYNC);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BR);
	cout << "\nA pedir Dominos ao monte...\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
	Sleep(1000);
	// (a) Get the bone(s) from the boneyard
	vector<bone> retrieved;
	retrieved=game.requestBone(targets,valuefound,bonefound);
	// IF is necessary becayse the retrieved may update
	if(bonefound){
		// (b) Add the pieces to player
		for (int unsigned j=0; j<retrieved.size(); j++)
		players[i].addBone(retrieved[j]);
		// (c) Play Again
		printHeader();
		showBoard();
	}
	
}
// *********************************************************
// Function: Update game, like targets and board
// *********************************************************
void board::updateGame(bone &piece, int unsigned &pos, int i){
	int valuefound=targets[pos];
	// (1) The Tail allways is inside the table eg. | Head | Tail |
			if(piece.getTail()!=valuefound){ 
				int tail=piece.getTail();
				int head=piece.getHead();
				piece.setValues(tail,head);
			}
			// (2) Update valuefound if necessary
			if(!exist(targets, valuefound)){
				for (int unsigned l=0; l<targets.size() ; l++){
					if (targets[l]==piece.getHead()) valuefound=targets[l];
					if (targets[l]==piece.getTail()) valuefound=targets[l];
				}
			}
			// (3) BEGIN Evaluate double pieces
			if(firstP.isDouble()){
				if(pos==0)
					lockedLeft=true;

				else if (pos==1)
					lockedRight=true;
			}

			else if(piece.isDouble() && !(firstDouble))
				if(pos==0)
					lockedRight=true;
				else
					lockedLeft=true;

			if(firstDouble &&(!lockedDouble))
				if(pos==0 && lockedRight)
					lockedLeft=true;
				else if (pos==1 && lockedLeft)
					lockedRight=true;
			// (4) Add the bone to the board
			if(pos==0)
				bonesLeft.push_back(piece);
			else if(pos==1)
				bonesRight.push_back(piece);
			else if(pos==2) 
				bonesUp.push_back(piece);
			else bonesDown.push_back(piece);
		    // (5) Update targets
			evaluateTargets(piece, pos);
			// (6) player points
			evaluatePoints(players[i]);
}
// *********************************************************
// Function: Run the game
// *********************************************************
void board::run(){
	int unsigned i=0; // players index
	int unsigned counter=1; // game counter
	int unsigned lastplayer=0; // last player index
	bool bonefound; // if the player could play
	bone piece; // bone played
	int valuefound; // value in game
	int unsigned pos; // board position
	// Main loop of the game
	for (i=0; !haveWinner(); i++, counter++){
		printHeader();
		showBoard();
        bonefound=true;
	    // (1) The player plays
		if (!players[i].play(targets,piece,pos,bonesLeft,bonesRight,bonesUp,bonesDown,firstP,lockedDouble)){
			if(game.getSize()>0){
				requestBoneyard(bonefound,valuefound,piece,i);
				if(bonefound)
					// (c) Play Again
					players[i].play(targets,piece,pos,bonesLeft,bonesRight,bonesUp,bonesDown,firstP,lockedDouble);
			}
			else bonefound=false;
		}
		// (2) If the player could play Update Game

		if(bonefound) updateGame(piece,pos,i);
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BR);
			cout<<endl<<"Jogador "<<players[i].getName()<<" Nao pode jogar :( a passar para o proximo jogador\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FW | BNULL);
			system("pause");
		}
		// (3) Update last player
		lastplayer=i;
		// ########### Bone play Sound ########### 
		PlaySoundA("hit.wav", NULL, SND_FILENAME|SND_ASYNC);
		if(i+1==totalPlayers()) i=-1; // Reset player index
	}
	// -------------------------------------------------------------
	// (5) Someone won the game!
	// -------------------------------------------------------------
	system("cls");
	//Updates the points of the winner
	evaluatePoints(players[lastplayer]);
	 evaluateWinner(players,lastplayer);
	// ########### Congratulations Sound ########### 
	PlaySoundA("parabens.wav", NULL, SND_FILENAME|SND_ASYNC);
	cin.get();
}