//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ľ����� �̳���MyShape
//			���ඨ���˼򵥵Ĳ����趨 �Լ�������ƶ�
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