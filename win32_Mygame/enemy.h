//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ľ����� �̳���MyShape
//			���ඨ���˼򵥵Ĳ����趨 �Լ�������ƶ�
//			


#pragma once
#include "myshape.h"
class enemy :
	public MyShape
{
private :

	size speed;
public:

	void setspeed(size speed);
	size getspeed();
	virtual void update();
	enemy(void);
	~enemy(void);
};

