#include "allfives.h"
// ----------------------------
//        Constructors
// ----------------------------
boneyard::boneyard(){
	generateBones();
}
boneyard::boneyard(int num){
	id=num;
	generateBones();
}
// ----------------------------
//		 Generate Bones
// ----------------------------
void boneyard::generateBones(){
	int counter=1;
	for (int unsigned i=0; i<=6;i++)
		for (int unsigned j=i;j<=6; j++){
			bone temp(i,j);
			temp.setID(counter++);
			bones.push_back(temp);
		}
}
// ----------------------------
//		 Set Functions
// ----------------------------
void boneyard::setID(int num){
	id=num;
}
void boneyard::setBones(vector<bone> bones){
	this->bones=bones;
}
// ----------------------------
//		 Get Functions
// ----------------------------
int boneyard::getID(){
	return id;
}
vector<bone> boneyard::getBones(){
	return bones;
}
int boneyard::getSize(){
	return bones.size();
}
bone boneyard::getBone(int order){
	return bones[order-1];
}
// *********************************************************
// Function: when the user can't play, he need to request
// bones from the boneyard.
// Params: targets and the valuefound
// Returns: vector of bones collected in the boneyard
// *********************************************************
vector<bone> boneyard::requestBone(vector<int> targets,int &valuefound, bool &bonefound){
	vector<bone> retrieved;
	bonefound=false;
	int randBone;
	// (1) While we don't found a bone to play
	while(!bonefound && bones.size()>0){
		// (2) Generate a Random Bone
		randBone=rand() % bones.size();
		// (3) Attribue to a temporary bone, to me more easily handled
		bone boneGenerated=bones[randBone];
		// (4) Remove bone
	    bones.erase(bones.begin()+randBone,bones.begin()+randBone+1);
		retrieved.push_back(boneGenerated);
		// (5) For each target
		for(int unsigned j=0; j<targets.size(); j++){
			// (4) Check if the bone is playable
			if (boneGenerated.getHead()==targets[j] || boneGenerated.getTail()==targets[j]){
				bonefound=true;
				break;
			}
		}
		// (6) If the boneyard is empty and nothing has found, the user can't play
		if (bones.size()==0) break;
	}
	return retrieved;
}
// *********************************************************
// Function: generate 7 random bones for the player
// Params: nothing
// Returns: a 7 vector of bones
// *********************************************************
vector<bone> boneyard::startPlayer(){
	int index;
	bone temp;
	vector<bone> playerbones;
	// Randomly get the 7 bones
	for (int i=0;i<7;i++){
		index=rand() % this->getSize();
		temp=this->bones[index];
		playerbones.push_back(temp);
		// Remove the bone
		this->bones.erase(bones.begin()+index,bones.begin()+index+1);
	}
	return playerbones;
}
// ----------------------------
//		Show Function
// ----------------------------
void boneyard::showBoneyard(){
	for (int i=1; i<=this->getSize(); i++){
		bone temp=this->getBone(i);
		temp.showBone();
		cout << " ";
		if ((i%5)==0) cout << endl;
	}
}