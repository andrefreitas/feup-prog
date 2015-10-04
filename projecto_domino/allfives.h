// C++ Default Libraries
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "shortcolours.h"
#pragma comment(lib, "winmm.lib")
using namespace std;
#define WIDTH 1300
#define HEIGHT 700
// ----------------------------
//          Debug Prototypes
// ----------------------------
void debugBone();
void debugBoneyard();
void debugPlayer();
// ----------------------------
//          Useful Functions
// ----------------------------
void gotoxy(int x, int y);
bool exist(vector<int> vec,int value);
void setWindow(int width, int height, int x, int y);
void printline();
void print(string output,string align);
void inputInteger(int &varx);
int RoundMultiple5(int value);
void printColour(string colour);
void resizeConsole();
// ----------------------------
//          Bone Class
// ----------------------------

class bone{
private:
	int id;
	int head;
	int tail;
	int x;
	int y;
public:
	bone();
	bone(int head, int tail);
	// Set functions
	void setID(int num);
	void setValues(int head,int tail);
	void setCoord(int x, int y);
	// Get functions
	int getID();
	int getHead();
	int getTail();
	int getX();
	int getY();
	// Show function
	void showBone();
	// Useful functions
	int sum();
	bool isDouble();
};
// ----------------------------
//          Boneyard
// ----------------------------
class boneyard{
private:
	int id;
	vector<bone> bones;
public:
	boneyard();
	boneyard(int num);
	// Set functions
	void setID(int num);
	void setBones(vector<bone> bones);
	// Get functions
	int getID();
	vector<bone> getBones();
	int getSize();
	bone getBone(int order);
	// Game functions
	void generateBones();
	vector<bone> requestBone(vector<int> targets,int &valuefound, bool &bonefound);
	vector<bone> startPlayer();
	// Show function
	void showBoneyard();
};
// ----------------------------
//          Player Class
// ----------------------------
class player{
private:
	int id;
	string name;
	int score;
	vector<bone> bones;
	bool human;
public:
	player();
	player(string name,vector<bone> bones,int id);
	// Set functions
	void setID(int num);
	void setName(string playername);
	void setScore(int num);
	void setBones(vector<bone> vec);
	void setHuman(bool human);
	// Get functions
	int getID();
	string getName();
	int getScore();
	vector<bone> getBones();
	bool isHuman();
	int bonesSize();
    bone greatestPiece();
	int sumPieces();
	// Add functions
	void addBone(bone piece);
	void addScore(int num);
	// Play function
	bool canplay(vector<int> targets);
	bool play(vector<int> targets,bone &piece, int unsigned &pos, vector <bone> left, vector <bone> right, vector <bone> up, vector <bone> down, bone firstP,bool lockedDouble);
	void bot(vector<int> targets,bone &piece, int unsigned &valuefound, vector <bone> left, vector <bone> right, vector <bone> up, vector <bone> down, bone firstP,bool lockedDouble);
	int evaluatePoints(vector <bone> left, vector <bone> right, vector <bone> up, vector <bone> down,vector <int> targetBot,bone firstP,bool lockedDouble);
	// Show functions
	void showinfo();
	void showbones(vector<int> targets, vector<int>  &playableBones);
	void showAlternatives(bool checkLeft, bool checkRight, bool checkUp, bool checkDown);

};
// ----------------------------
//          Board Class
// ----------------------------
class board{
private:
	bone firstDoub;
	bone firstP;
	vector <bone> bonesUp;
	vector <bone> bonesDown;
	vector <bone> bonesLeft;
	vector <bone> bonesRight;
	vector <player> players;
	vector <int> targets;
	bool firstDouble;
	bool lockedDouble;
	bool lockedRight;
	bool lockedLeft;
	int id;
	boneyard game;
public:
	board();
	board(int id);
	// Set functions
	void setFirstDouble();
	void setlockedDouble();
	// Game functions
	int spaceNeeded(vector <bone> bones);
	void evaluateTargets(bone piece, int unsigned pos);
	void evaluatePoints(player &playeronplay);
	void evaluateWinner(vector <player> players, int lastPlayers);
	void startGame();
	void firstPiece();
	int haveWinner();
	void showBoard();
	int totalPlayers();
	void run();
	void printHeader();
	void requestBoneyard(bool &bonefound, int &valuefound, bone &piece, int i);
	void updateGame(bone &piece, int unsigned &pos,int i);
};