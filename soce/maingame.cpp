#include"maingame.h"

MAINGAME::MAINGAME(){
	obj = new SCENEMANAGER();
}
MAINGAME::~MAINGAME(){
	delete obj;
}
void MAINGAME::Update(){
	obj->Update();
}
void MAINGAME::Draw(){
	obj->Draw();
}
