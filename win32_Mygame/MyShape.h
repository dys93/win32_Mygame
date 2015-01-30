//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ľ����� ��һ������
//			������Ա��̳� ����д���е�һЩ����
//			�����еķ������ᱻMydirector����
//			���ඨ���˵ײ�Ļ��ƺ���


#pragma once
#include "MyDirector.h"
#include <vector>


class MyShape
{
private:
	//0:Բ  1����  4��������
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

