//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ����Ҫ�����࣬����̳���MyScene
//			�ڸ����и�д���� update �� action ����������MyDirectory����ִ��
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

