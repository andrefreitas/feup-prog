#include "allfives.h"
// ----------------------------
//        Constructors
// ----------------------------
player::player(){
	score=0;
}
player::player(string name,vector<bone> bones,int id){
	this->name=name;
	this->bones=bones;
	score=0;
	this->id=id;
}
// ----------------------------
//        Set functions
// ----------------------------
void player::setID(int num){
	id=num;
}
void player::setName(string playername){
	name=playername;
}
void player::setScore(int num){
	score=num;
}
void player::setBones(vector<bone> vec){
	bones=vec;
}
void player::setHuman(bool human){
	this->human=human;
}
// ----------------------------
//        Get functions
// ----------------------------
int player::getID(){
	return id;
}
string player::getName(){
	return name;
}
int player::getScore(){
	return score;
}
vector<bone> player::getBones(){
	return bones;
}
bool player::isHuman(){
	return human;
}
int player::bonesSize(){
	return bones.size();
}
int player::sumPieces(){
	int sum=0;
	for(int unsigned i=0; i<bones.size();i++){
		sum+=bones[i].sum();
	}
	return sum;
}
// ----------------------------
//        Add functions
// ----------------------------
void player::addBone(bone piece){
	bones.push_back(piece);
}
void player::addScore(int num){
	score+=num;
}
// *********************************************************
// Function: Get the greatest piece of the player. It is 
// useful for the function board::firstPiece(), that returns
// the greatest piece of all players of the board.
// Params: nothing
// Returns: object of type bone
// *********************************************************
bone player::greatestPiece(){
	bone b=bones[0];
	for(int unsigned i=1; i<bones.size();i++){
        // (1) Put the greatest double
		if(b.isDouble() && bones[i].isDouble()){
			if((b.sum())<(bones[i].sum()))
				b=bones[i];}
		// (2) The greatest bone isn't a double and the bone found is
		else if (bones[i].isDouble())
			b=bones[i];
		// (3) The greatest bone isn't a double and the sum of the found is greater
		else if((b.sum())<(bones[i].sum()))
			b=bones[i];	
	}
	return b;
}
// *********************************************************
// Function: print the player info
// Params: nothing
// Returns: true or false
// *********************************************************
void player::showinfo(){
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";printline();
	cout << " Nome do Jogador: " << getName() << " | Pontos: " << getScore() << " | Total de Pecas: " << bonesSize() << endl;
	printline();
}
// *********************************************************
// Function: print the player bones, filtering by targets
// Params: nothing
// Returns: true or false
// *********************************************************
void player::showbones(vector<int> targets, vector<int> &playableBones){
	for (int unsigned i=0; i<bones.size(); i++){
		// For each bone check if its playable
		// Limit of 8 bones by row
		if((i+1)%10==0) cout << "\n";
		if (exist(targets,bones[i].getHead()) || exist(targets,bones[i].getTail()) || targets.size()==0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BG);
			cout << i+1;
			playableBones.push_back(i+1);
		} else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BR);
			cout << "X";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FW | BNULL);
		bones[i].showBone();
		
	}
	cout<< endl;
}
void player::showAlternatives(bool checkLeft, bool checkRight, bool checkUp, bool checkDown){
	if (checkLeft)
		cout<<"1 - Esquerda\n";
	if(checkRight)
		cout<<"2 - Direita\n";
	if(checkUp)
		cout<<"3 - Cima\n";
	if(checkDown)
		cout<<"4 - Baixo\n";
}
// *********************************************************
// Function: this function check if the user can play
// Params: nothing
// Returns: true or false
// *********************************************************
bool player::canplay(vector<int> targets){
	// For each bone, check if the targets have the head or tail
	for (int unsigned j=0; j<bones.size(); j++){
		if (exist(targets,bones[j].getHead()) || exist(targets,bones[j].getTail()))
				return true;
	}
	return false;
} 
// *********************************************************
// Function: this function do the play a bone if the user
// can play. Return false if the user don't have bones to play
// Params: nothing
// Returns: true or false
// *********************************************************
bool player::play(vector<int> targets,bone &piece,int unsigned &pos, vector <bone> left, vector <bone> right, vector <bone> up, vector <bone> down,bone firstP,bool lockedDouble){
	vector<int> playableBones; // Index of playable bones
	if (!canplay(targets)) return false;
	else if (!human){
		// (WARNING) Not Human
		showinfo();
		bot(targets,piece,pos, left, right, up, down,firstP,lockedDouble);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FWI | BR);
	    cout << "\nO Robot jogou: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FW | BNULL);
		piece.showBone();
		cout<<endl;
		system("pause");
		return true;
	}
	else {
		
		int input;
		// (1) Show Player Info
		showinfo();
		// (2) Show Player Bones
		showbones(targets,playableBones);
		printline();
		// (3) Get the bone number and validate input
		do{ 
			printColour("green");
			cout << "Ordem do domino a jogar:";
			printColour("clear");
			cout << " ";
			inputInteger(input);
		} while (!exist(playableBones,input));
		// (4) Change parameter piece to be played
		piece=bones[input-1];
		// (5) if exist more than 1 possibility where to put the piece
		int unsigned op;
		int unsigned howMany=0;
		bool checkLeft=false;
		bool checkRight=false;
		bool checkUp=false;
		bool checkDown=false;
		bool verify=false;
		for(int unsigned i=0; i<targets.size(); i++){
			if(piece.getHead()==targets[i] || piece.getTail()==targets[i]){
				switch(i){
				case 0 : checkLeft=true; howMany++; break;
				case 1 : checkRight=true; howMany++; break;
				case 2 : checkUp=true; howMany++; break;
				default: checkDown=true; howMany++; break;
				}
			}
		}
		if(howMany>1){
			showAlternatives(checkLeft, checkRight, checkUp, checkDown);
			cout<<"Opcao: ";
			cin>>op;

			switch(op){
			case 1: if(checkLeft) verify=true; break;
			case 2: if(checkRight) verify=true; break;
			case 3: if(checkUp) verify=true; break;
			case 4: if(checkDown) verify=true; break;
			default: verify=false;
			}

			while(cin.fail() || !verify){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Introduza uma opcao valida: ";
				cin>>op;
				switch(op){
			case 1: if(checkLeft) verify=true; break;
			case 2: if(checkRight) verify=true; break;
			case 3: if(checkUp) verify=true; break;
			case 4: if(checkDown) verify=true; break;
			default: verify=false;
			}
			}
			cin.ignore(1000,'\n');
			pos=op-1;
		}
		else{
			
		 //(5) Change parameter valuefound
		for (int unsigned i=0; i< targets.size() ; i++) {
			if (bones[input-1].getHead() == targets[i] || bones[input-1].getTail()== targets[i])
				pos=i;
			}
		}
		// (6) Remove the bone from the player
		bones.erase(bones.begin()+input-1,bones.begin()+input);
		return true;
	}
}
// *********************************************************
// Function: artificial inteligence behaviour for robot
// Params: the targets, the piece and the valuefound
// Returns: true or false
// *********************************************************
void player::bot(vector<int> targets,bone &piece, int unsigned &pos, vector <bone> left, vector <bone> right, vector <bone> up, vector <bone> down,bone firstP,bool lockedDouble){
	bool foundDouble=false;
	int doubleIndex;
	int valuefound;
	vector<bone> bonestoplay; // To evaluate the bone that get the best score
	// **************************************************************************
	// (1) fecth the playable bones
	// **************************************************************************
	for (int unsigned i=0; i<bones.size() && !foundDouble; i++){
		for (int unsigned j=0; j<targets.size() && !foundDouble; j++){
			if (bones[i].getHead() == targets[j] || bones[i].getTail() == targets[j] ){
				bonestoplay.push_back(bones[i]);
				// (WARNING) If found a Double, it has the priority
				if (bones[i].isDouble()){
					foundDouble=true;
					doubleIndex=i;
					pos=j;
					piece=bones[i];
					valuefound=bones[i].getHead();
				}
			}
		}
	}

	// **************************************************************************
	// (2) Evaluate if a double has found
	// **************************************************************************
	if (foundDouble){
		bones.erase(bones.begin()+doubleIndex,bones.begin()+doubleIndex+1);
	}
	else {
	// **************************************************************************
	// (3) Evaluate if a multiple of 5 is found
	// **************************************************************************
		int sum=0;
		int id=0;
		bool foundGood=false;
		vector<int> goodBones; // Bones index that can get score
		vector<int> outsideGood; // Value of good bones
		for(int unsigned i=0; i<bonestoplay.size(); i++){
			piece=bonestoplay[i];
			bool checkLeft=false;
			bool checkRight=false;
			bool checkUp=false;
			bool checkDown=false;
			bool verify=false;
		for(int unsigned j=0; j<targets.size(); j++){
			if(piece.getHead()==targets[j] || piece.getTail()==targets[j]){
				switch(j){
				case 0 : checkLeft=true; break;
				case 1 : checkRight=true; break;
				case 2 : checkUp=true; break;
				default: checkDown=true; break;
				}
			}
		}
		if(checkLeft){
		vector<int> temp=targets;
		vector<bone> leftT=left;
		int value=temp[0];
		if(piece.getTail()!=value){ 
				int tail=piece.getTail();
				int head=piece.getHead();
				piece.setValues(tail,head);
		}
		temp[0]=piece.getHead();
		leftT.push_back(piece);
		if(sum<=evaluatePoints(leftT,right,up,down,temp,firstP, lockedDouble)){
			sum=evaluatePoints(leftT,right,up,down,temp,firstP, lockedDouble);
			id=i;
			pos=0;
		}
		}

		if(checkRight){
		vector<int> temp=targets;
		vector<bone> T=right;
	int value=temp[1];
		if(piece.getTail()!=value){ 
				int tail=piece.getTail();
				int head=piece.getHead();
				piece.setValues(tail,head);
		}
		temp[1]=piece.getHead();
		T.push_back(piece);
		if(sum<=evaluatePoints(left,T,up,down,temp,firstP, lockedDouble)){
			sum=evaluatePoints(left,T,up,down,temp,firstP, lockedDouble);
			id=i;
			pos=1;
		}
		}

		if(checkUp){
		vector<int> temp=targets;
		vector<bone> T=up;
		int value=temp[2];
		if(piece.getTail()!=value){ 
				int tail=piece.getTail();
				int head=piece.getHead();
				piece.setValues(tail,head);
		}
		temp[2]=piece.getHead();
		T.push_back(piece);
		if(sum<=evaluatePoints(left,right,T,down,temp,firstP, lockedDouble)){
			sum=evaluatePoints(left,right,T,down,temp,firstP, lockedDouble);
			id=i;
			pos=2;
		}
		}

		if(checkDown){
		vector<int> temp=targets;
		vector<bone> T=down;
		int value=temp[3];
		if(piece.getTail()!=value){ 
				int tail=piece.getTail();
				int head=piece.getHead();
				piece.setValues(tail,head);
		}
		temp[3]=piece.getHead();
		T.push_back(piece);
		if(sum<=evaluatePoints(left,right,up,T,temp,firstP, lockedDouble)){
			sum=evaluatePoints(left,right,up,T,temp,firstP, lockedDouble);
			id=i;
			pos=3;
		}
		}
	}	piece=bonestoplay[id];
		for(int unsigned i=0;i<bones.size();i++){
			if(piece.getID()==bones[i].getID()){
		bones.erase(bones.begin()+i,bones.begin()+i+1);
		break;
	}
		}
	}
}
		
	
int player::evaluatePoints(vector <bone> left, vector <bone> right, vector <bone> up, vector <bone> down,vector <int> targetBot, bone firstP,bool lockedDouble ){
	
	int sum=0;
	int l=left.size()-1;
	int r=right.size()-1;
	int u=up.size()-1;
	int d=down.size()-1;
	vector <int> sizes;

	sizes.push_back(l);
	sizes.push_back(r);
	sizes.push_back(u);
	sizes.push_back(d);
	
	//if there is only one piece or one side is free
	if(r==-1){
		if(l==-1) 
		sum=targetBot[0]+targetBot[1];
		else if (firstP.isDouble())
			sum=2*targetBot[1];
		else sum=targetBot[1];
	}
	else if(l==-1)
		 if (firstP.isDouble())
			sum=2*targetBot[0];
		else sum=targetBot[0];

	//if firstdouble is locked and no pieces in vertical
	if((u==-1 && d==-1) && lockedDouble){
		sum=2*targetBot[3];
	}
	
	for(int unsigned i=0; i<sizes.size(); i++){
		int size=sizes[i];

		if(i==0 && size>=0){
			if(left[size].isDouble())
				sum+=2*(targetBot[i]);
			else sum+=targetBot[i];
		}

		if (i==1 && size>=0){
			if(right[size].isDouble())
				sum+=2*(targetBot[i]);
			else sum+=targetBot[i];
		}
			if(i==2 && size>=0){
				if(up[size].isDouble())
					sum+=2*(targetBot[i]);
				else sum+=targetBot[i];
			}

			if(i==3 && size>=0){
				if(down[size].isDouble())
					sum+=2*(targetBot[i]);
				else sum+=targetBot[i];
			}
		}
			if(!(sum%5==0)) 
				sum=0;
	return sum;
}