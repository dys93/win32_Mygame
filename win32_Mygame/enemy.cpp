//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的精灵类 继承自MyShape
//			该类定义了简单的参数设定 以及精灵的移动
//			


#include "stdafx.h"
#include "enemy.h"
#include <iostream>

enemy::enemy(void)
{
	speed.x=0;
	speed.y=0;
	center.x=100;
	center.y=100;
	settag(0);
	setR(10);
	setcolor(RGB(255,0,0));
}


enemy::~enemy(void)
{
}
void enemy::update()
{
	center.x+=getspeed().x/80;
	center.y+=getspeed().y/80;
}
void enemy::setspeed(size speed)
{
	this->speed.x = speed.x;
	this->speed.y = speed.y;
}
size enemy::getspeed()
{
	return speed;
}