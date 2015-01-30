//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的精灵类 是一个基类
//			该类可以被继承 并复写其中的一些方法
//			该类中的方法将会被Mydirector调用
//			该类定义了底层的绘制函数


#pragma once
#include "MyDirector.h"
#include <vector>


class MyShape
{
private:
	//0:圆  1：点  4：长方形
	int kind;
	COLOR16 c;
	int degree;
	int tag;
	int selfmask;
	int targetmask;
		 int life;
		 int smallenemy_tag;
public:
	size center;
	int r;
	void setcenter(size center);
	size getcenter();
	void setR(int r);
	int getR();
	void setkind(int kind);
	int getkind();
	void setselfmask(int mask);
	int getselfmask();
	void settargetmask(int mask);
	int gettargetmask();

	int gettag();
	void settag(int tag);

	static MyShape* create(int kind,size center,int R);
	//if collision return the place else return null
	static size* iscollision(MyShape a,MyShape b);

	void changePosition(size c);
	virtual void update();
	void setdegree(int degree);
	int getdegree();

	void setcolor(COLOR16 c);
	COLOR16 getcolor();


	void setsmall_enemy_tag(int tag);
	int getsmall_enemy_tag();
	void setlife(int life);
	int getlife();



	void draw();

	MyShape(void);
	~MyShape(void);
};

