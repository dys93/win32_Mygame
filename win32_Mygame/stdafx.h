// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
// C ����ʱͷ�ļ�
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

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "MyDirector.h"
#include "MyShape.h"
#include "MyScene.h"
#include "selftimer.h"
