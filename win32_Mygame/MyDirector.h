//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的导演类 他是一个单例 改写他的构造函数以设定开始场景
//			MyDirector将会调用添加进来的场景类的绘制方法以及更新方法
//			通过对该类的操作达到场景切换的效果


#pragma once
#include <vector>
#include "MyShape.h"
#include "MyScene.h"
#include <map>
#include <string>
#include <queue>
#include <conio.h>
#include "selftimer.h"
using namespace std;
class MyDirector
{
private:
	HWND hWnd;
	//要进行绘制的单位
	queue<MyScene*> Queue_Scene;
	size winSize;
	map <string,string> key_statu;
	MyDirector(void);
public:
	int Mousex,Mousey;
	HDC hMemDC;
	HBITMAP hBitmap;
	//单例
	void setKeyStatu(string key,string statu);
	string getKeyStatu(string key);
	static MyDirector *getDirector();
	//定期调用update 间接调用Scene->update();
	void update();
	//初始化参数列表 以及参数绑定
	void setHWND(HWND hWnd);
	HWND getHWND();
	void setWinSize(size winSize);
	size getWinSize();

	void pushScene(MyScene*);
	void popScene();
	MyScene* getScene();
	void ConsolePrint(string out);

	~MyDirector(void);
};

