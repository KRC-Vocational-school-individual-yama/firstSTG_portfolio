#pragma once
#include<DxLib.h>
class PLAYER {
public:
	PLAYER();
	~PLAYER();
	void Move();
	void Draw();
	VECTOR GetPos() { return pos; }
	int GetSize() { return size; }
	void SetActive(bool _active){active=_active;}
	bool GetActive(){return active;}

private:
	void CharaControl();

	VECTOR pos;//�����̂�	position
	int size;//�L���������蔻��T�C�Y
	int img;//�摜�n���h��
	int graphSize;//�P�L�����̑傫��
	int anim;

	bool active;//�G�ɓ����������i��

	VECTOR move;//�ړ���
};