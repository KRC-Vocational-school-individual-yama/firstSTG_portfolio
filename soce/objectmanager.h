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
	void PlayerInstantBarrett();//�e�̐���
	void EnemyInstantBarrett(VECTOR _pos);//�e�̐���
	void EnemyInstat();//�G�̐���
	void AllUpdate();//���ꂼ��̍s��
	void PlayerCollisionEnemy();//player enemy �����蔻��
	void PlayerCollisionEnemyBarrett();//player enemybarrett �����蔻��
	void EnemyCollisionBarrett();//enemy barrett �����蔻��
	bool SwitchControl(bool keyflag);//�X�C�b�`�ؑ�
	bool oneflag;
	bool keystop;


	static const int throwtime = 10;//�N�[���^�C��
	int throwcounter;
	static const int enetime = 30;//�N�[���^�C��
	int enecounter;
	PLAYER* player;
	const int enenum=25;//�G��
	ENEMY* ene;
	const int barnum = 15;//�����e��
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