#pragma once
#include"player.h"
#include"enemy.h"
#include"barrett.h"
#include"backimg.h"
#include<DxLib.h>
class OBJECTMANAGER {
public:
	OBJECTMANAGER();
	~OBJECTMANAGER();
	void Init() {}
	void Update();
	void Draw();
private:
	void PlayerInstantBarrett();//弾の生成
	void EnemyInstantBarrett(VECTOR _pos);//弾の生成
	void EnemyInstat();//敵の生成
	void AllUpdate();//それぞれの行動
	void PlayerCollisionEnemy();//player enemy 当たり判定
	void PlayerCollisionEnemyBarrett();//player enemybarrett 当たり判定
	void EnemyCollisionBarrett();//enemy barrett 当たり判定
	bool SwitchControl(bool keyflag);//スイッチ切替
	bool oneflag;
	bool keystop;


	static const int throwtime = 10;//クールタイム
	int throwcounter;
	static const int enetime = 30;//クールタイム
	int enecounter;
	PLAYER* player;
	const int enenum=25;//敵数
	ENEMY* ene;
	const int barnum = 15;//自分弾数
	BARRETT* barrett;
	const int enebarnum = 50;
	BARRETT* enebarrett;

	BACKIMG* backimg;

	struct COLLIDER {
		VECTOR pos;
		int size;
	};

	bool Collision(COLLIDER mob1,COLLIDER mob2);
};