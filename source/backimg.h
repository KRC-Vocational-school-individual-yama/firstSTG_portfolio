#pragma once
#include<DxLib.h>
class BACKIMG {
public:
	BACKIMG();
	~BACKIMG();
	void Move();
	void Draw();

private:
	int x;
	int speed;
	int img;
};