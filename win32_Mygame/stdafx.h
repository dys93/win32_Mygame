// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


struct size{
	float x;
	float y;
	size():x(0),y(0){};
	size(float  x,float y):x(x),y(y){};
	size(double  x,double y):x(x),y(y){};
	size(int  x,int y):x(x),y(y){};
};

// TODO: 在此处引用程序需要的其他头文件
#include "MyDirector.h"
#include "MyShape.h"
#include "MyScene.h"
#include "selftimer.h"
