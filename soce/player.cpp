#include "player.h"
#include"config.h"
#include<assert.h>

PLAYER::PLAYER(){
	size = 5;
	graphSize = 64;
	img = LoadGraph("data/texture/aoi.png");
	assert(img>0);
	anim=0;

	move = {5,5,0.0f};
	pos = { 0.0f,SCREEN_HEIGHT/2.0f,0.0f };
	active = true;

}
PLAYER::~PLAYER(){
	DeleteGraph(img);
}
void PLAYER::Move(){

	if (active) {
	CharaControl();
	}
	else {
		anim = 4;
	}
}
void PLAYER::Draw(){
	

	DrawRectGraph(pos.x,pos.y,
		graphSize*0,graphSize*anim,//âÊëúêÑà⁄	animetion
		graphSize,graphSize,img,true);
}

void PLAYER::CharaControl(){
	bool up		=CheckHitKey(KEY_INPUT_W);
	bool down	=CheckHitKey(KEY_INPUT_S);
	bool left	=CheckHitKey(KEY_INPUT_A);
	bool right	=CheckHitKey(KEY_INPUT_D);

	if (up) {
		pos.y += -move.y;
		if (pos.y < 0) {
			pos.y = 0;
		}
	}
	if (down) {
		pos.y += move.y;
		if (pos.y > SCREEN_HEIGHT - graphSize) {
			pos.y = SCREEN_HEIGHT - graphSize;
		}
	}
	if (left) {
		pos.x += -move.x;
		if (pos.x < 0) {
			pos.x = 0;
		}
	}
	if (right) {
		pos.x += move.x;
		if (pos.x > SCREEN_WIDTH - graphSize) {
			pos.x = SCREEN_WIDTH - graphSize;
		}
	}
}
