#pragma once
#include"scenebase.h"
#include<DxLib.h>
class TITLESCENE:public SCENEBASE{
public:
	TITLESCENE()	;
	~TITLESCENE()	override;
	void Update()	override;
	void Draw()		override;
private:
};