#include "enemy.h"
#include"config.h"
#include<assert.h>

ENEMY::ENEMY(){
	img=LoadGraph("data/texture/mob.png");
	assert(img>0);
	graphsize = 64;
	
	pos = { 0.0f,0.0f,0.0f };
	
	active = false;
}
ENEMY::~ENEMY(){
	DeleteGraph(img);
}
void ENEMY::Move(){
	if (active) {

pos.x += -5;
	if (pos.x < 0 - graphsize) {
		pos.x = SCREEN_WIDTH + graphsize;
		pos.y = GetRand(SCREEN_HEIGHT-graphsize);
	}
	}
}
void ENEMY::Draw(){
	if (active) {

	DrawRectGraph(pos.x,pos.y,
			0,0,
		graphsize,graphsize,img,true);
	}
}

void ENEMY::Instant(){
	active = true;
	pos.x = (float)(SCREEN_WIDTH + graphsize) + GetRand(SCREEN_WIDTH);
	pos.y = GetRand(SCREEN_HEIGHT - graphsize);

}
