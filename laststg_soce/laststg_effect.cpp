#include"laststg_effect.h"
#include<DxLib.h>
#include<math.h>
#include"laststg_common.h"
#include"laststg_config.h"
#include"laststg_player.h"
static const float PI = 3.1415653;
static const int ALPHANUMRADIUS = 40;

namespace {
	struct GLOW {
		int alphanum=0;
		int radius=0;
		int color=0;
	POS pos = {};
	VEC vec = {};
	};
	const int glownum = 20;
	struct EFFE {
		GLOW glows[glownum] = {};
		bool active = false;
	};
	const int maxeffe = 5;
	EFFE effe[maxeffe] = {};


	bool keystop = false;
}

void EffectInit() {
	for (int j = 0; j < maxeffe; j++) {
		effe[j].active = false;
		for (int i = 0; i < glownum; i++) {
			effe[j].glows[i].pos = {};
			effe[j].glows[i].vec = {};
			effe[j].glows[i].alphanum = 0;
			effe[j].glows[i].radius = 0;
			effe[j].glows[i].color = 0;
		}
	}

}
void EffectCreate(POS _pos) {
	for (int j = 0; j < maxeffe; j++) {
		if (effe[j].active)continue;
		effe[j].active = true;
		for (int i = 0; i < glownum; i++) {
			effe[j].glows[i].pos = _pos;
			effe[j].glows[i].alphanum = 255;
			effe[j].glows[i].radius = GetRand(3) + 2;
			effe[j].glows[i].color = GetColor(GetRand(255), GetRand(80), GetRand(100));
			int angle = PI / 180 * (i * 360 / glownum);
			effe[j].glows[i].vec.vx = cos(angle) * GetRand(7);
			effe[j].glows[i].vec.vy = sin(angle) * GetRand(7);
		}
			return;
	}
}
void EffectUpdate() {
	//行動
	for (int j = 0; j < maxeffe; j++) {
		for (int i = 0; i < glownum; i++) {

			//playerに合わせた動き
			effe[j].glows[i].pos = PosAdd(effe[j].glows[i].pos, GetPlayerVX());

			effe[j].glows[i].pos.x += effe[j].glows[i].vec.vx;
			effe[j].glows[i].pos.y += effe[j].glows[i].vec.vy;
			effe[j].glows[i].alphanum += -(255 / ALPHANUMRADIUS);
			if (effe[j].glows[i].alphanum <= 0) {
				effe[j].glows[i].alphanum = 0;
				effe[j].active = false;
			}
		}
	}
	
	//debug用生成
	POS p={SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
	bool key=CheckHitKey(KEY_INPUT_3);
	if (key&&!keystop) {
		
		EffectCreate(p);
		keystop=true;
	}
	else {
		keystop=false;
	}
}
void EffectDraw() {
	for (int j = 0; j < maxeffe; j++) {
		if (effe[j].active) {
			for (int i = 0; i < glownum; i++) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA,effe[j].glows[i].alphanum);
				DrawCircle(effe[j].glows[i].pos.x, effe[j].glows[i].pos.y, effe[j].glows[i].radius, effe[j].glows[i].color, true);
			}
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}
void EffectDelete() {

}