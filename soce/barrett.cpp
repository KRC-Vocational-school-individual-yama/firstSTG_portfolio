#include "barrett.h"
#include<assert.h>
#include"config.h"

BARRETT::BARRETT(){
	img = LoadGraph("data/texture/effect.png");
	assert(img > 0);

	pos.x = 0;
	pos.y = 300;
	pos.z = 0;
	active = false;
	vec = {0,0,0};
}

BARRETT::~BARRETT()
{
}

void BARRETT::Move() {
	if (active) {
		pos.x += vec.x;
		pos.y += vec.y;
		if (pos.x > SCREEN_WIDTH) {
			active = false;
		}
		if (pos.x < 0) {
			active = false;
		}
	}
}

void BARRETT::Draw(){
	if (active) {

	DrawRectGraph(pos.x,pos.y,
		0,0,
		64,64,img,true);
	}
}

void BARRETT::Instant(VECTOR _pos, VECTOR _vec){
	if (!active) {
	active = true;
	pos = _pos;
	vec = _vec;
	}
}
