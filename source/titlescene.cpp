#include "titlescene.h"

TITLESCENE::TITLESCENE(){
}
TITLESCENE::~TITLESCENE(){

}
void TITLESCENE::Update(){
}
void TITLESCENE::Draw(){
	DrawFormatString(10,10+GetFontSize()*1,GetColor(255,255,255),"Pを押してC++ STGスタート");
	DrawFormatString(10,10+GetFontSize()*2,GetColor(255,255,255),"Lを押して元STGスタート");
	DrawFormatString(10,10+GetFontSize()*4,GetColor(255,255,255),"ESCAPEを押してここに戻る");
	DrawFormatString(10,10+GetFontSize()*5,GetColor(255,255,255),"ESCAPE+LSHIFTを押して閉じる");
	
	//DrawBox(300,200,400,500,GetColor(25,255,190),true);

	DrawFormatString(400,300,GetColor(255,255,255),"ここはエントランス");
}
