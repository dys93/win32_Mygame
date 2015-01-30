//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĳ����� ��һ������ 
//			��������򵥵ĳ����߼� ����ɾ�������߽�Ķ���
//			


#pragma once
#include "stdafx.h"
#include <vector>
#include "MyShape.h"
#include "MyDirector.h"

using namespace std;

class MyScene
{
public:
	vector<MyShape*> list_of_object[4];

	void addSprite(MyShape*,int);
	void removeSpriteByTag(int tag);
	void removeSprite(int i,int j);
	//director������ײ������Ϣ
	virtual void when_collision(MyShape*,MyShape*);
	//���»���ÿһ֡ ����ͨ��director��keystatu��ð�����Ϣ
	virtual void update();
	virtual void action();
	void draw();
	MyScene(void);
	~MyScene(void);
	void collision_detec();
	void remove_out_ob();
};

