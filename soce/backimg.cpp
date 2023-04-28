#include "backimg.h"
#include<assert.h>
#include"config.h"

BACKIMG::BACKIMG(){
	x		=0;
	speed	=5;
	img		=-1;
	
	img = LoadGraph("data/texture/blue_00038.jpg");
	assert(img>0);
}
BACKIMG::~BACKIMG(){
	if (img > 0) {
	 DeleteGraph(img);
	 img = -1;
	}

}
void BACKIMG::Move(){
	x += speed;
	if (x > SCREEN_WIDTH) {
		x = 0;
	}
}
void BACKIMG::Draw(){
	DrawExtendGraph(0+x,0,SCREEN_WIDTH + x,SCREEN_HEIGHT,img,false);
	DrawExtendGraph(-SCREEN_WIDTH + x, 0, 0 + x,SCREEN_HEIGHT,img,false);
}
