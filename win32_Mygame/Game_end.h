//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĳ����� �̳���MyScene
//			�����趨����Ϸ��������ʾ�Ľ��� ͬʱ�趨�˶����û�����֮��Ľ�����ת�߼�
//			�����еķ������ᱻMydirector����

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

