//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的精灵类  该类继承自 enemy
//			该类用于绘制可以发射子弹的单位 包括玩家控制的单位
//			


#include "stdafx.h"
#include "bigenemy.h"
#include <math.h>
#include "selftimer.h"

#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

void bigenemy::update()
{
	if(gettag()!=0){
	if(at.after(600)&&at.repeat(enemyinfor.spacetime)&&at.before(5000))
	{
		this->setspeed(size(0,0));
		this->createsmallenemy();
	}
	if(at.when(5000))
	{
		this->setspeed(size(0,-100));
	}
	center.x+=getspeed().x/60;
	center.y+=getspeed().y/60;
	}

}
void bigenemy::createsmallenemy()
{

	float smallspeed=enemyinfor.speed;
	size sp;
	double a=getdegree();

	for(int i=0;i<enemyinfor.eachnum;i++)
	{

		if(smallkind==0){
		sp.x=smallspeed*cos((a+i*enemyinfor.eachdegree)/180*3.1415);
		sp.y=smallspeed*sin((a+i*enemyinfor.eachdegree)/180*3.1415);
		}
		else 
		{
			sp.x=you->center.x-center.x;
			sp.y=you->center.y-center.y;
			float l = sqrt(sp.x*sp.x+sp.y*sp.y);
			sp.x=sp.x/l*smallspeed;
			sp.y=sp.y/l*smallspeed;
		}
		enemy* temp=new enemy();
		temp->setspeed(sp);
		temp->setcenter(this->getcenter());
		temp->setlife(1);
		if(this->gettag()==0)
		{	
			temp->settag(3);
			sp.x=0;
			sp.y=-400;
			temp->setR(7);
			temp->setcolor(RGB(0,0,0));
			temp->setspeed(sp);	
		//	PlaySound(_T("shoot.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_NODEFAULT);
			
		}
		else 
		{
			temp->setR(8.5);
			temp->settag(2);
		}
		MyDirector::getDirector()->getScene()->addSprite((MyShape*)temp,temp->gettag());
	}
	setdegree(getdegree()+enemyinfor.routedegree);

}
void bigenemy::setyou(enemy* you)
{
	this->you=you;
}
bigenemy::bigenemy(void)
{
	
	smallkind=0;
}
bigenemy::~bigenemy(void)
{
}
void bigenemy::setenemyinfor(createinfor enemyinfor)
{
	this->enemyinfor=enemyinfor;
}

	