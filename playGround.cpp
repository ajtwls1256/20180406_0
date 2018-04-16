#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);
	
	//¾ÀÃß°¡
	SCENEMANAGER->addScene("ÅÊÅ©¾À", new aStarScene);
	SCENEMANAGER->changeScene("ÅÊÅ©¾À");

	int test = 1;
	int test2 = 2;
	int test2_2 = 2.2;
	int a = asdf;

	return S_OK;
}

void playGround::release()
{
	gameNode::release();

}

void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
	
}

void playGround::render(void)
{
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================================
	
	SCENEMANAGER->render();
	
	//==================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
