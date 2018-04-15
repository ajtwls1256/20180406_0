#pragma once
#include "gameNode.h"
#include "tankMap.h"

enum TANKDIRECTION
{
	TANKDIRECTION_LEFT,
	TANKDIRECTION_UP,
	TANKDIRECTION_RIGHT,
	TANKDIRECTION_DOWN
};

class tank : public gameNode
{
private:
	tankMap* _tankMap;		//≈ ≈© ∏  ≈¨∂Ûæ≤~
	TANKDIRECTION _direction;

	//≈ ≈©ø°∞‘ « ø‰«— ∞ÕµÈ
	image* _image;
	RECT _rc;
	float _x, _y;
	float _speed;

public:
	tank();
	~tank();

	HRESULT init();
	void release();
	void update();
	void render();

	void tankMove();
	void setTankPosition();

	void setTankMapAddressLink(tankMap* tm) { _tankMap = tm; }
};

