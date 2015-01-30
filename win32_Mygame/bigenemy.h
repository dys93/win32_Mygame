#pragma once

//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的精灵类  该类继承自 enemy
//			该类用于绘制可以发射子弹的单位 包括玩家控制的单位
//			
#include "enemy.h"
#include "stdafx.h"
struct createinfor
{
	float speed;
	int eachnum;
	int eachdegree;
	int routedegree;
	int spacetime;
	
	createinfor():speed(400.0),eachnum(12),eachdegree(30),routedegree(0)	,spacetime(500){}
	createinfor(float speed,int eachnum,int eachdegree,int routedegree,int spacetime)
	{
		this->speed=speed;
		this->eachdegree=eachdegree;
		this->eachnum=eachnum;
		this->routedegree=routedegree;
		this->spacetime=spacetime;

	}
};
class bigenemy:public enemy
{
private: selftimer at;
		 createinfor enemyinfor;
		 enemy *you;
		
public:
	
	int smallkind;
	void setyou(enemy* you);
	void createsmallenemy();
	void update();
	bigenemy(void);
	~bigenemy(void);
	void setenemyinfor(createinfor enemyinfor);
};

