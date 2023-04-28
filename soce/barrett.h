#pragma once
#include<DxLib.h>
class BARRETT {
public:
	BARRETT();
	~BARRETT();
	void Move();
	void Draw();
	void Instant(VECTOR _pos, VECTOR _vec={5,0,0});
	bool GetActive(){return active;}
	void SetActive(bool _active){active=_active;}
	VECTOR GetPos(){return pos;}
private:
	int img;
	VECTOR pos;
	bool active;
	VECTOR vec;
};