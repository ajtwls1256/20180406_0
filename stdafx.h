#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "soundManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "iniDataManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "utils.h"
#include "txtData.h"
#include "database.h"

using namespace OCTA_UTIL;

//=======================================
// ## - 디파인문 - ## 18.01.12 ## 
//=======================================

#define WINNAME (LPSTR)(TEXT("Octa API"))
#define WINSTARTX 150
#define WINSTARTY 50
#define WINSIZEX 800
#define WINSIZEY 800
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND				randomFunction::getSingeton()
#define KEYMANAGER		keyManager::getSingeton()
#define IMAGEMANAGER	imageManager::getSingeton()
#define SOUNDMANAGER	soundManager::getSingeton()
#define TIMEMANAGER		timeManager::getSingeton()
#define EFFECTMANAGER	effectManager::getSingeton()
#define SCENEMANAGER	sceneManager::getSingeton()
#define KEYANIMANAGER	keyAniManager::getSingeton()
#define TXTDATA			txtData::getSingeton()
#define INIDATA			iniDataManager::getSingeton()
#define DATABASE		database::getSingeton()

//=======================================
// ## Macro ## 18.01.31 ## 
//=======================================

#define SAFE_DELETE(p) {if(p) { delete(p); (p) = NULL; }} 
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
extern BOOL _leftButtonDown;