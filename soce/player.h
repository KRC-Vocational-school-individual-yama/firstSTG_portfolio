#pragma once
#include<DxLib.h>
class PLAYER {
public:
	PLAYER();
	~PLAYER();
	void Move();
	void Draw();
	VECTOR GetPos() { return pos; }
	int GetSize() { return size; }
	void SetActive(bool _active){active=_active;}
	bool GetActive(){return active;}

private:
	void CharaControl();

	VECTOR pos;//ｘｙのみ	position
	int size;//キャラ当たり判定サイズ
	int img;//画像ハンドル
	int graphSize;//１キャラの大きさ
	int anim;

	bool active;//敵に当たった時（仮

	VECTOR move;//移動量
};