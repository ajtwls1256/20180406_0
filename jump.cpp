#include "stdafx.h"
#include "jump.h"


jump::jump()
{
}


jump::~jump()
{

}

HRESULT jump::init()
{
	_isJumping = _jumpPower = _gravity = 0;

	return S_OK;
}

void jump::release()
{

}

void jump::update()	
{
	//점프 중이지 않으면 실행시키지 않는다
	if (!_isJumping) return;

	*_y -= _jumpPower;
	_jumpPower -= _gravity;

	if (_startY <= *_y)
	{
		_isJumping = false;
		*_y = _startY;
	}

}

void jump::render()	
{

}


void jump::jumping(float* x, float* y, float power, float gravity)
{
	//점프하고 있으면 건드리지 않는다
	if (_isJumping) return;

	_isJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;

	_gravity = gravity;
	_jumpPower = power;
}
