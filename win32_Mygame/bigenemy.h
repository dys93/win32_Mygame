#pragma once

//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ľ�����  ����̳��� enemy
//			�������ڻ��ƿ��Է����ӵ��ĵ�λ ������ҿ��Ƶĵ�λ
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

