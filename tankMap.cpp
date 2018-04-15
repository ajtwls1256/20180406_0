#include "stdafx.h"
#include "tankMap.h"


tankMap::tankMap()
{
}


tankMap::~tankMap()
{

}


HRESULT tankMap::init()	  
{
	//샘플타일 이미지 등록
	IMAGEMANAGER->addFrameImage("mapTiles", "maptiles.bmp", 0, 0, 640, 288, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));


	_pos[0] = 0;

	load();

	return S_OK;
}


void tankMap::release()	  
{

}


void tankMap::update()	  
{

}


void tankMap::render(void)
{
	IMAGEMANAGER->render("mapTiles", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("mapTiles")->getWidth(), 0);

	// 지형
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		IMAGEMANAGER->frameRender("mapTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}

	//오브젝트
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].obj == OBJ_NONE) continue;
		IMAGEMANAGER->frameRender("mapTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].objFrameX, _tiles[i].objFrameY);
	}

}



void tankMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("mapSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);

	//1번째 타일이 지금 어떤 속성인지 로드해오면서 부여한다
	//힌트 비트필드기 때문에 비트연산자 공부를 해보길 ㅊㅊ!

	//메모리 초기화 한번 해줘야함. **
	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].terrain == TR_WATER) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
	}


	CloseHandle(file);
}


