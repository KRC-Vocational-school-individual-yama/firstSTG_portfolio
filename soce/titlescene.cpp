#include "titlescene.h"

TITLESCENE::TITLESCENE(){
}
TITLESCENE::~TITLESCENE(){

}
void TITLESCENE::Update(){
}
void TITLESCENE::Draw(){
	DrawFormatString(10,10+GetFontSize()*1,GetColor(255,255,255),"P��������C++ STG�X�^�[�g");
	DrawFormatString(10,10+GetFontSize()*2,GetColor(255,255,255),"L�������Č�STG�X�^�[�g");
	DrawFormatString(10,10+GetFontSize()*4,GetColor(255,255,255),"ESCAPE�������Ă����ɖ߂�");
	DrawFormatString(10,10+GetFontSize()*5,GetColor(255,255,255),"ESCAPE+LSHIFT�������ĕ���");
	
	//DrawBox(300,200,400,500,GetColor(25,255,190),true);

	DrawFormatString(400,300,GetColor(255,255,255),"�����̓G���g�����X");
}
