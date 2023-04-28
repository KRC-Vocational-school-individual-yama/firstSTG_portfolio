#pragma once
class SCENEBASE {
public:
	SCENEBASE() {}
	 virtual ~SCENEBASE()	=0{}
	 virtual void Update()	=0{}
	 virtual void Draw()	=0{}
private:
};