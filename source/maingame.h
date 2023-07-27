#pragma once
#include"scenemanager.h"
class MAINGAME {
public:
	MAINGAME();
	~MAINGAME();
	void Init() {}
	void Update();
	void Draw();
private:
	SCENEMANAGER* obj;
};