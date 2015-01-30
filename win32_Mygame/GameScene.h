//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的主要场景类，该类继承自MyScene
//			在该类中复写方法 update 及 action 交给导演类MyDirectory进行执行
//			


#pragma once
#include "MyScene.h"
#include "bigenemy.h"
class GameScene:public MyScene
{
private:
	bigenemy * you;
	HBITMAP bg;
	selftimer at;
	int bomb;

public:
	void gamelost();
	void action();
	GameScene(void);
	~GameScene(void);
	void when_collision(MyShape*,MyShape*);
	void update();
};

