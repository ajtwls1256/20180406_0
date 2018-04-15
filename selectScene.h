#pragma once
#include "gameNode.h"
#include "button.h"


class selectScene : public gameNode
{
private:
	button* _btnSceneChange;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	static void cbSceneChange();


	selectScene();
	~selectScene();
};

