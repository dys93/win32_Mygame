//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĳ����� �̳���MyScene
//			�����趨����Ϸ�ոտ�ʼ�Ľ��� ��ʾһЩ��Ϸ�Ļ�������˵�� �����˽�����Ϸ�������ת
//			�����еķ������ᱻMydirector����

#pragma once
#include "myscene.h"
#include "stdafx.h"
#include "enemy.h"
#include "MyDirector.h"
class initScene :
	public MyScene
{
	enemy * you;
	HBITMAP bg;
	selftimer at;
public:
	initScene(void);
	~initScene(void);
	void action();
	void when_collision(MyShape*,MyShape*);
	void update();
};

