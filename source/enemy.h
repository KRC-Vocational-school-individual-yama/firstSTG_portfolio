#pragma once
#include<DxLib.h>
class ENEMY {
public:
	ENEMY();
	~ENEMY();
	void Move();
	void Draw();
	void Instant();
	VECTOR GetPos() { return pos; }
	//int GetSize() { return size; }
	bool GetActive() { return active; }
	void SetActive(bool _active){active=_active;}
private:
	VECTOR pos;
	int img;
	int graphsize;
	bool active;
};