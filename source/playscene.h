#pragma once
#include"scenebase.h"
#include"objectmanager.h"
class PLAYSCENE :public SCENEBASE{
public:
	PLAYSCENE()		;
	 ~PLAYSCENE()	;
	void Update()	override;
	void Draw()		override;
	bool GetEndKey() { return endkey; }
private:
	bool endkey=false;
	OBJECTMANAGER* obj;
};