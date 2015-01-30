//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的场景类 继承自MyScene
//			该类设定了游戏刚刚开始的界面 显示一些游戏的基本操作说明 定义了进入游戏界面的跳转
//			该类中的方法将会被Mydirector调用

#pragma once
#include "myscene.h"
#include "stdafx.h"
#include "enemy.h"
#include "MyDirector.h"
class initScene :
	public MyScene
{
	enemy * you;
	HBITMAP bg;
	selftimer at;
public:
	initScene(void);
	~initScene(void);
	void action();
	void when_collision(MyShape*,MyShape*);
	void update();
};

