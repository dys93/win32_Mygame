//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的场景类 继承自MyScene
//			该类设定了游戏结束后显示的界面 同时设定了对于用户操作之后的界面跳转逻辑
//			该类中的方法将会被Mydirector调用

#pragma once
#include "myscene.h"
class Game_end :
	public MyScene
{
private: int SCORE;
public:
	void action();
	void when_collision(MyShape*,MyShape*);
	void update();
	void setScore(int Score);
	Game_end(void);
	~Game_end(void);
};

