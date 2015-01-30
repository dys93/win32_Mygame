//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的精灵类 继承自MyShape
//			该类定义了简单的参数设定 以及精灵的移动
//			


#pragma once
#include "myshape.h"
class enemy :
	public MyShape
{
private :

	size speed;
public:

	void setspeed(size speed);
	size getspeed();
	virtual void update();
	enemy(void);
	~enemy(void);
};

