#include"laststg_item.h"
#include<DxLib.h>
#include<assert.h>
#include<math.h>
#include"laststg_common.h"
#include"laststg_switchControl.h"
#include"laststg_config.h"
#include"laststg_player.h"
#include"laststg_randquake.h"
#include"laststg_scenemanager.h"
static const int SPWANITME = 5;

namespace {

	enum ITEMTYPE {
		noitem = -1,
		heal = 0,//回復
		inv,//無敵
		a,

		maxitemtype
	};
	int itemcount[maxitemtype] = {0,0,0};

	struct ITEM {
		POS pos = {};
		int typeimg[maxitemtype] = {};//-1
		int mytype = -1;
		bool active=false;
		double size=20;
	};
	const int maxitem = 20;
	ITEM item[maxitem];
	int spawncount=0;


	bool keystop=false;
	int count = 0;

	int getse = -1;
}
void ItemInit() {
	getse = LoadSoundMem("data/sound/殴る蹴るなどの.mp3");
	assert(getse>0);
	itemcount[0] = 0;
	itemcount[1] = 0;
	itemcount[2] = 0;
	for (int i = 0; i < maxitem; i++) {
		item[i]={};
		item[i].mytype=noitem;

		for (int j = 0; j < maxitemtype; j++) {
		item[i].typeimg[j]=MakeScreen(20,20,TRUE);
		SetDrawScreen(item[i].typeimg[j]);
		int color=0;
		int no=187;
		if(j==0)color=GetColor(255,no,no);
		else if(j==1)color=GetColor(no,no,255);
		else if(j==2)color=GetColor(no,255,no);
		else color=GetColor(no,no,no);
		DrawCircle(8,8,8,color,true);
		assert(item[i].typeimg[j]>0);
		SetDrawScreen(DX_SCREEN_BACK);

		}
	}
	spawncount=0;
}
void ItemCreate(POS _pos, int _type) {
	for (int i = 0; i < maxitem; i++) {
		if (item[i].active)
			continue;
		item[i].mytype = _type;
		if (_type == -1) {
			item[i].mytype = GetRand(maxitemtype);
		}
		item[i].pos = _pos;
		item[i].active = true;
		return;
	}
}
void ItemUpdate() {
	count+=5;
	//移動
	for (int i = 0; i < maxitem; i++) {
		if (!item[i].active)
			continue;
		
		//プレイヤーに合わせた動き
		item[i].pos = PosAdd(item[i].pos,GetPlayerVX());

		//動き
		double lvx=cos(DX_PI/180*count)*GetRand(10)/10;
		double lvy=sin(DX_PI/180*count)*GetRand(20)/10;
		VECTOR p = RandQuakeMove();
		POS v = {lvx+p.x,lvy+p.y};
		item[i].pos = PosAdd(item[i].pos,v);

	//消す
		if (item[i].pos.x < 0||
			item[i].pos.y < 0||
			item[i].pos.x > SCREEN_WIDTH||
			item[i].pos.y > SCREEN_HEIGHT
			) {
			item[i].active=false;
		}

	}

	//生成
	if (spawncount++ >= SPWANITME) {
		POS p = {GetRand(SCREEN_WIDTH),GetRand(SCREEN_HEIGHT)};
		ItemCreate(p);

		spawncount=0;
	}
		POS p = { SCREEN_WIDTH / 1.5f,SCREEN_HEIGHT / 1.5f };
		bool key = CheckHitKey(KEY_INPUT_SPACE);
		if (key && !keystop) {
			ItemCreate(p);
			keystop = true;
		}
		else if (!key) {
			keystop = false;
		}
}
void ItemDraw() {
	for (int i = 0; i < maxitem; i++) {
	//DrawGraph(item[i].pos.x, item[i].pos.y, item[i].typeimg[item[0].mytype], true);
		if (!item[i].active)
			continue;
		if(RandQuakeGetActive())
		DrawGraph(item[i].pos.x,item[i].pos.y,item[i].typeimg[item[i].mytype],true);
		else
		DrawGraph(item[i].pos.x,item[i].pos.y,item[i].typeimg[item[i].mytype],true);
	}
}
void ItemDelete() {
	DeleteSoundMem(getse);
	for (int i = 0; i < maxitem; i++) {
		DeleteGraph(item[i].typeimg[i]);
		item[i].typeimg[i] = -1;
	}
}

bool ItemCollision(POS _pos,double _size) {
	for (int i = 0; i < maxitem; i++) {
		if (!item[i].active)
			continue;
		if (CircleCollision(_pos, _size, item[i].pos, item[i].size / 2)) {
			if (GetNowScene() != 3) {	// clearScene 以外
				item[i].active = false;
				itemcount[item[i].mytype]++;
			}
			PlaySoundMem(getse,DX_PLAYTYPE_BACK);
			return true;
		}
	}
	return false;
}

int ItemGetR(){
	return itemcount[0];
}
int ItemGetG(){
	return itemcount[2];
}
int ItemGetB(){
	return itemcount[1];
}
