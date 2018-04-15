#pragma once
#include "gameNode.h"
#include "tile.h"
#include <vector>

//타일 사이즈
#define TILEWIDTH 32
#define TILEHEIGHT 32

//타일의 갯수
#define TILENUMX (WINSIZEX / TILEWIDTH)
#define TILENUMY (WINSIZEY / TILEHEIGHT)

class aStarTest : public gameNode
{
private:
	//전체 타일 담을 벡터
	vector<tile*>			_vTotalList;
	vector<tile*>::iterator _viTotalList;

	//갈 수 있는 타일을 담을 벡터
	vector<tile*>			_vOpenList;
	vector<tile*>::iterator _viOpenList;

	//최단 거리가 담겨있는 벡터
	vector<tile*>			_vCloseList;
	vector<tile*>::iterator _viCloseList;

	tile* _startTile;		//시작타일
	tile* _endTile;			//도착타일
	tile* _currentTile;		//현재타일

	bool _start;
	int _count;
	
public:
	aStarTest();
	~aStarTest();

	HRESULT init();
	void setTiles();
	vector<tile*> addOpenList(tile* currentTile);

	void pathFinder(tile* currentTile);

	void release();
	void update();
	void render();

};

