#pragma once
#include "gameNode.h"

class jump : public gameNode
{
private:
	float _jumpPower;
	float _gravity;

	//점프할때 좌표 
	float* _x;
	float* _y;

	float _startX, _startY;

	bool _isJumping;

public:
	jump();
	~jump();

	HRESULT init();
	void release();
	void update();
	void render();

	void jumping(float* x, float* y, float power, float gravity);

	bool getIsJumping() { return _isJumping; }
};

