#include "stdafx.h"
#include "animationTest.h"


animationTest::animationTest()
{
}


animationTest::~animationTest()
{

}

HRESULT animationTest::init()
{
	_camel = IMAGEMANAGER->addFrameImage("³«Å¸", "camel.bmp", 300, 267, 4, 3, true, RGB(255, 0, 255));

	//µğÆúÆ®
	_ani1 = new animation;
	_ani1->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani1->setDefPlayFrame(true, true);
	_ani1->setFPS(1);

	//¹è¿­·Î Àç»ı
	int arrAni[] = {1, 3, 5, 7, 9, 2, 4, 6};
	_ani2 = new animation;
	_ani2->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani2->setPlayFrame(arrAni, 8, true);
	_ani2->setFPS(1);

	//±¸°£ ¾Ö´Ï¸ŞÀÌ¼ğ
	_ani3 = new animation;
	_ani3->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani3->setPlayFrame(1, 7, false, true);
	_ani3->setFPS(1);

	IMAGEMANAGER->addImage("Æø¹ß", "explosion.bmp", 832, 62, true, RGB(255, 0, 255));

	_effect = new effect;
	_effect->init(IMAGEMANAGER->findImage("Æø¹ß"), 32, 62, 1.0f, 0.3f);

	EFFECTMANAGER->addEffect("explosion", "explosion.bmp", 832, 62, 32, 62, 1.0f, 0.3f, 1000);

	_bossDieCount = 0;

	return S_OK;
}

void animationTest::release()
{

}

void animationTest::update() 
{
	if ( KEYMANAGER->isOnceKeyDown('A') ) _ani1->start();
	if ( KEYMANAGER->isOnceKeyDown('S') ) _ani2->start();
	if ( KEYMANAGER->isOnceKeyDown('D') ) _ani3->start();

	_ani1->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 30);
	_ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	if ( KEYMANAGER->isOnceKeyDown(VK_LBUTTON) ) _effect->startEffect(_ptMouse.x, _ptMouse.y);
	if ( KEYMANAGER->isStayKeyDown(VK_RBUTTON) ) EFFECTMANAGER->play("explosion", _ptMouse.x, _ptMouse.y);

	_effect->update();
	EFFECTMANAGER->update();


	_bossDieCount++;

	if ( _bossDieCount % 10 == 0 )
	{
		EFFECTMANAGER->play("explosion", RND->getFromIntTo(100, 200), RND->getFromIntTo(100, 200));

	}
}

void animationTest::render() 
{
	_camel->aniRender(getMemDC(), 100, 100, _ani1);

	_camel->aniRender(getMemDC(), 200, 100, _ani2);

	_camel->aniRender(getMemDC(), 300, 100, _ani3);

	_effect->render();
	EFFECTMANAGER->render();
}
