#include "objectmanager.h"
OBJECTMANAGER::OBJECTMANAGER(){
	throwcounter=0;
	enecounter = 0;
	oneflag=false;
	keystop=false;

	player = new PLAYER();
	barrett = new BARRETT[barnum];
	ene = new ENEMY[enenum];
	enebarrett =new BARRETT[enebarnum];
	backimg = new BACKIMG();
}
OBJECTMANAGER::~OBJECTMANAGER(){
	delete player;
	delete[] barrett;
	delete[] ene;
	delete[] enebarrett;
	delete backimg;
}
void OBJECTMANAGER::Update(){
	//それぞれの行動
	AllUpdate();

	//デバッグ用
	bool debugkey = CheckHitKey(KEY_INPUT_1);
	SwitchControl(debugkey);

	//player enemy 当たり判定
	PlayerCollisionEnemy();
	//player enemybarrett 当たり判定
	PlayerCollisionEnemyBarrett();
	
	//enemy barrett 当たり判定
	EnemyCollisionBarrett();
	
	//敵の生成
	EnemyInstat();

	//弾の生成
	if (player->GetActive()) {//プレイヤーが生きてるときだけ
	PlayerInstantBarrett();
	}

	//敵の弾生成
	for (int i = 0; i < enenum; i++) {
		if (!(ene[i].GetActive()))continue;
		if (ene[i].GetPos().x==500) {
			EnemyInstantBarrett(ene[i].GetPos());
		}
	}
}
void OBJECTMANAGER::Draw(){
	if (!oneflag) {
	backimg->Draw();
	}
	player->Draw(); 
	for (int i = 0; i < barnum; i++) {
		barrett[i].Draw();
	}
	for (int i = 0; i < enenum; i++) {
		ene[i].Draw();
	}
	for (int i = 0; i < enebarnum; i++) {
		enebarrett[i].Draw();
	}
}
void OBJECTMANAGER::PlayerInstantBarrett(){
	bool insflag = CheckHitKey(KEY_INPUT_SPACE) == 1 && throwcounter > throwtime;
	if (insflag) {
		for (int i = 0; i < barnum; i++) {
			if (barrett[i].GetActive())continue;
			barrett[i].Instant(player->GetPos());
			break;
		}
		throwcounter = 0;
	}
	throwcounter++;
}
void OBJECTMANAGER::EnemyInstantBarrett(VECTOR _pos){
	for (int j = 0; j < enebarnum; j++) {
		if (enebarrett[j].GetActive())continue;
		VECTOR v = { -20,0,0 };
		enebarrett[j].Instant(_pos, v);
		break;
	}
}
void OBJECTMANAGER::EnemyInstat(){
	if (enecounter > enetime) {
		for (int i = 0; i < enenum; i++) {
			if (ene[i].GetActive())continue;
			ene[i].Instant();
		}
	}
	enecounter++;
}
void OBJECTMANAGER::AllUpdate(){
	player->Move();
	backimg->Move();
	for (int i = 0; i < enenum; i++) {
		ene[i].Move();
	}
	for (int i = 0; i < barnum; i++) {
		barrett[i].Move();
	}
	for (int i = 0; i < enebarnum; i++) {
		enebarrett[i].Move();
	}
}
void OBJECTMANAGER::PlayerCollisionEnemy(){
	for (int i = 0; i < enenum; i++) {
		if (!(ene[i].GetActive()))continue;
		COLLIDER _player;
		_player.pos = player->GetPos();
		_player.size = player->GetSize();
		COLLIDER _ene;
		_ene.pos = ene[i].GetPos();
		_ene.size = 5;
		DrawCircle(_ene.pos.x, _ene.pos.y, _ene.size, GetColor(255, 25, 190), false);
		DrawCircle(_player.pos.x, _player.pos.y, _player.size, GetColor(255, 25, 190), false);
		if (Collision(_player, _ene)&&!oneflag) {
			player->SetActive(false);
		}
	}
}
void OBJECTMANAGER::PlayerCollisionEnemyBarrett(){
	for (int i = 0; i < enebarnum; i++) {
		if (!(enebarrett[i].GetActive()))continue;
		COLLIDER _player;
		_player.pos = player->GetPos();
		_player.size = player->GetSize();
		COLLIDER _ene;
		_ene.pos = enebarrett[i].GetPos();
		_ene.size = 5;
		DrawCircle(_ene.pos.x, _ene.pos.y, _ene.size, GetColor(255, 25, 190), false);
		DrawCircle(_player.pos.x, _player.pos.y, _player.size, GetColor(255, 25, 190), false);
		if (Collision(_player, _ene) && !oneflag) {
			player->SetActive(false);
		}
	}
}
void OBJECTMANAGER::EnemyCollisionBarrett(){
	for (int j = 0; j < barnum; j++) {
		if (!(barrett[j].GetActive())) continue;
		for (int i = 0; i < enenum; i++) {
			if (!(ene[i].GetActive()))continue;
			COLLIDER _barrett;
			_barrett.pos = barrett[j].GetPos();
			_barrett.size = 5;
			COLLIDER _ene;
			_ene.pos = ene[i].GetPos();
			_ene.size = 5;
			DrawCircle(_ene.pos.x, _ene.pos.y, _ene.size, GetColor(255, 255, 255), false);
			DrawCircle(_barrett.pos.x, _barrett.pos.y, _barrett.size, GetColor(255, 255, 255), false);
			if (Collision(_barrett, _ene)) {
				barrett[j].SetActive(false);
				ene[i].SetActive(false);
			}
		}
	}
}
bool OBJECTMANAGER::SwitchControl(bool keyflag){
		if (keyflag && !keystop) {
			if (oneflag) {
				oneflag = false;
			}
			else if (!oneflag) {
				oneflag = true;
			}
			keystop = true;
		}
		else if (!keyflag)keystop = false;

		return oneflag;
	
}
bool OBJECTMANAGER::Collision(COLLIDER mob1, COLLIDER mob2) {
	float x = mob1.pos.x - mob2.pos.x;
	float y = mob1.pos.y - mob2.pos.y;
	float r = (float)mob1.size+ (float)mob2.size;
	bool flag = x * x + y * y < r* r;

	return flag;
}
