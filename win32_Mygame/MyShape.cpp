//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的精灵类 是一个基类
//			该类可以被继承 并复写其中的一些方法
//			该类中的方法将会被Mydirector调用
//			该类定义了底层的绘制函数


#include "stdafx.h"
#include "MyShape.h"
#include "MyScene.h"
#include <algorithm>
MyShape::MyShape(void)
{
	kind = 0;
}


MyShape::~MyShape(void)
{
}
int MyShape::gettag()
{
	return tag;
}
void MyShape::settag(int tag)
{
	this->tag=tag;
}

MyShape* MyShape::create(int kind,size center,int R){
	MyShape *temp=new MyShape();
	temp->setkind(kind);
	temp->center=center;
	temp->r=R;
	return temp;

}
void MyShape::setkind(int kind)
{
	this->kind=kind;
}
int MyShape::getkind()
{
	return this->kind;
}
//if collision return the place else return null
size* MyShape::iscollision(MyShape shape1,MyShape shape2)
{
	//比较粗糙的碰撞检测
	bool flag=false;
	int x=shape2.center.x-shape1.center.x;
	int y=shape2.center.y-shape1.center.y;
	
	if((shape1.r+shape2.r)>sqrt(x*x+y*y))
	{
		size *m=new size(x/2+shape1.center.x,y/2+shape1.center.y);
		return m;
	}

	return NULL;
}
int MyShape::getselfmask()
{
	return this->selfmask;
}
void MyShape::setselfmask(int mask)
{
	this->selfmask=mask;
}
int MyShape::gettargetmask()
{
	return this->targetmask;
}
void MyShape::settargetmask(int mask)
{
	this->targetmask=mask;
}

void MyShape::changePosition(size c)
{
	this->center.x+=c.x;
	this->center.y+=c.y;
}

void MyShape::setdegree(int degree)
{
	this->degree=degree;
}
int MyShape::getdegree()
{
	return degree;
}
void MyShape::setcolor(COLOR16 c)
{
	this->c=c;
}
void MyShape::update()
{

}
COLOR16 MyShape::getcolor()
{
	return c;	
}

void MyShape::draw()
{
	HPEN pen=CreatePen(BS_SOLID,2,c);
	SelectObject(MyDirector::getDirector()->hMemDC,pen);
	if(kind==0)
	{
		Ellipse(MyDirector::getDirector()->hMemDC,center.x-r,center.y-r,center.x+r,center.y+r);
	}
	DeleteObject(pen);
}


void MyShape::setcenter(size center)
{
	this->center.x=center.x;
	this->center.y=center.y;

}
size MyShape::getcenter()
{
	return this->center;
}
void MyShape::setR(int r)
{
	this->r=r;
}
int MyShape::getR()
{
	return r;
}



void MyShape::setsmall_enemy_tag(int tag)
	{
		this->smallenemy_tag=tag;
	}
	int MyShape::getsmall_enemy_tag()
	{
		return this->smallenemy_tag;
	}
	void MyShape::setlife(int life)
	{
		this->life=life;
	}
	int MyShape::getlife()
	{
		return life;
	}
