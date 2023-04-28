#include "playscene.h"

PLAYSCENE::PLAYSCENE(){
	obj = new OBJECTMANAGER();
}
PLAYSCENE::~PLAYSCENE(){
	delete obj;
}
void PLAYSCENE::Update(){
	obj->Update();
}
void PLAYSCENE::Draw(){
	obj->Draw();
}
