#include"scenemanager.h"
SCENEMANAGER::SCENEMANAGER() {
	nowscene = SCENENUMBER::titlescene;
	oldscene = SCENENUMBER::titlescene;
	ressetpushed=false;

	switch (nowscene) {
	case SCENENUMBER::titlescene:
	sceneobj = new TITLESCENE();
		break;
	case SCENENUMBER::playscene:
		sceneobj = new PLAYSCENE();
		break;
	case SCENENUMBER::endscene:
		sceneobj = nullptr;
		break;
	}
}
SCENEMANAGER::~SCENEMANAGER() {
	delete sceneobj;
}
void SCENEMANAGER::Update() {

	sceneobj->Update();


	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		nowscene = SCENENUMBER::titlescene;
	}if (CheckHitKey(KEY_INPUT_P)) {
		nowscene = SCENENUMBER::playscene;
	}
	//リセット
	bool resset = CheckHitKey(KEY_INPUT_R);
	if (resset&&!ressetpushed) {
		oldscene = SCENENUMBER::noscene;
	}
	ressetpushed = resset;

	//シーンの切替
	ChangeScenes();
	oldscene = nowscene;
}
void SCENEMANAGER::Draw() {
	sceneobj->Draw();
}

void SCENEMANAGER::ChangeScenes(){

	if (nowscene != oldscene) {
		if (sceneobj != nullptr)delete sceneobj;
	
		switch (nowscene) {
		case SCENENUMBER::titlescene:
			sceneobj = new TITLESCENE();
			break;
		case SCENENUMBER::playscene:
			sceneobj = new PLAYSCENE();
			break;
		case SCENENUMBER::endscene:
			sceneobj = nullptr;
			break;
		}
	}
}
