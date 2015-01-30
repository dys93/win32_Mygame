//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的场景类 是一个基类 
//			该类包含简单的场景逻辑 比如删除超出边界的对象
//			


#pragma once
#include "stdafx.h"
#include <vector>
#include "MyShape.h"
#include "MyDirector.h"

using namespace std;

class MyScene
{
public:
	vector<MyShape*> list_of_object[4];

	void addSprite(MyShape*,int);
	void removeSpriteByTag(int tag);
	void removeSprite(int i,int j);
	//director发现碰撞发送消息
	virtual void when_collision(MyShape*,MyShape*);
	//重新绘制每一帧 可以通过director的keystatu获得按键消息
	virtual void update();
	virtual void action();
	void draw();
	MyScene(void);
	~MyScene(void);
	void collision_detec();
	void remove_out_ob();
};

