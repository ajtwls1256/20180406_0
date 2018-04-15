#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;

	//프레임 번호를 따로 두는 이유는 조금있다 (투 비 컨띠뉴)
	int _currentFrameX;
	int _currentFrameY;

	int _count;				//카운트
	int _fireCount;			//발사 카운트
	int _rndFireCount;		//랜덤하게 발사하기 위한 카운트

public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }
};

