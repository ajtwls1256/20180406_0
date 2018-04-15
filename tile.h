#pragma once
#include "gameNode.h"

class tile : public gameNode
{
private:
	int _idX;		//인덱스 X,Y
	int _idY;

	POINT _center;	// 타일 중점
	RECT _rc;		// 타일 렉트

	// F = G + H
	// F == Total Cost 총 경로 비용
	// G == 시작점으로부터 현재 노드까지 경로비용
	// H == 현재 노드로부터 도착점까지의 경로비용

	float _totalCost;		//F
	float _costFromStart;	//G
	float _costToGoal;		//H

	bool _isOpen;			//갈 수 있는 길이냐

	tile* _parentNode;		//상위 타일(현재 타일)

	COLORREF	_color;
	HBRUSH		_brush;
	HPEN		_pen;

	string _attribute;		//타일 속성

public:
	tile();
	~tile();

	HRESULT init(int idX, int idY);
	void release();
	void update();
	void render();

	int getIdX() { return _idX; }
	int getIdY() { return _idY; }

	void setColor(COLORREF color)
	{
		DeleteObject(_brush);
		_color = color;
		_brush = CreateSolidBrush(_color);
	}

	//============= 접근자 & 설정자 =====================
	RECT getRect() { return _rc; }

	void setCenter(POINT center) { _center = center; }
	POINT getCenter() { return _center; }

	void setAttribute(string str) { _attribute = str; }
	string getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }

	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(tile* t) { _parentNode = t; }
	tile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

};

