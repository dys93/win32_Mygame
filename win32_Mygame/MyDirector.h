//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĵ����� ����һ������ ��д���Ĺ��캯�����趨��ʼ����
//			MyDirector���������ӽ����ĳ�����Ļ��Ʒ����Լ����·���
//			ͨ���Ը���Ĳ����ﵽ�����л���Ч��


#pragma once
#include <vector>
#include "MyShape.h"
#include "MyScene.h"
#include <map>
#include <string>
#include <queue>
#include <conio.h>
#include "selftimer.h"
using namespace std;
class MyDirector
{
private:
	HWND hWnd;
	//Ҫ���л��Ƶĵ�λ
	queue<MyScene*> Queue_Scene;
	size winSize;
	map <string,string> key_statu;
	MyDirector(void);
public:
	int Mousex,Mousey;
	HDC hMemDC;
	HBITMAP hBitmap;
	//����
	void setKeyStatu(string key,string statu);
	string getKeyStatu(string key);
	static MyDirector *getDirector();
	//���ڵ���update ��ӵ���Scene->update();
	void update();
	//��ʼ�������б� �Լ�������
	void setHWND(HWND hWnd);
	HWND getHWND();
	void setWinSize(size winSize);
	size getWinSize();

	void pushScene(MyScene*);
	void popScene();
	MyScene* getScene();
	void ConsolePrint(string out);

	~MyDirector(void);
};

