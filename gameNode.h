#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

class gameNode
{
private:
	HDC _hdc;			//백버퍼 DC
	bool _managerInit;	//매니져들을 init할꺼냐

public:
	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(void);

	//백버퍼에 접근하기 위한 접근자
	image* getBackBuffer() { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

