#pragma once
#include"scenebase.h"
#include"playscene.h"
#include"titlescene.h"
#include<DxLib.h>
class SCENEMANAGER {
public:
	SCENEMANAGER();
	~SCENEMANAGER();
	void Update();
	void Draw();
private:
	void ChangeScenes();

	enum SCENENUMBER {
		noscene = -1,
		titlescene = 0,
		playscene,
		endscene,

	};

	bool ressetpushed;
	
	SCENENUMBER nowscene;
	SCENENUMBER oldscene;
	
	SCENEBASE* sceneobj;
	
};