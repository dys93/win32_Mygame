//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĵ����� ����һ������ ��д���Ĺ��캯�����趨��ʼ����
//			MyDirector���������ӽ����ĳ�����Ļ��Ʒ����Լ����·���
//			ͨ���Ը���Ĳ����ﵽ�����л���Ч��


#include "stdafx.h"
#include "MyDirector.h"
#include <iostream>
#include "selftimer.h"
#include "GameScene.h"
#include "initScene.h"
using namespace std;
MyDirector::MyDirector(void)
{
	initScene *a=new initScene();
	pushScene(a);
	srand(GetCurrentTime());
}


MyDirector::~MyDirector(void)
{

}


//����
MyDirector *MyDirector::getDirector(){
	static MyDirector instance;
	return &instance;
}

void MyDirector::setKeyStatu(string key,string statu)
{
	key_statu[key]=statu;
}
string MyDirector::getKeyStatu(string key){
	map<string , string> ::iterator iter;
	iter = key_statu.find(key);
	if(iter!=key_statu.end())
		return iter->second;
	return "";
}
void MyDirector::setHWND(HWND hWnd){
	this->hWnd=hWnd;
}

HWND MyDirector::getHWND()
{
	return this->hWnd;

}
//���ڵ���update ��ӵ���Scene->update()
void MyDirector::update(){
	HBRUSH hbrush=CreateSolidBrush(RGB(255,255,255));
	HDC hdc=GetDC(MyDirector::getDirector()->getHWND());
	SelectObject(MyDirector::getDirector()->hMemDC,hbrush);
	if(Queue_Scene.empty())
	{
		DeleteObject(hbrush);
		DeleteDC(hdc);
		return ;
	}
	else
	{
		MyDirector::getDirector()-> hMemDC = CreateCompatibleDC(hdc);
		MyDirector::getDirector()->hBitmap = CreateCompatibleBitmap(hdc,768*0.7, 1024*0.7);
		SelectObject(MyDirector::getDirector()->hMemDC, MyDirector::getDirector()->hBitmap);

		HBRUSH hbrush=CreateSolidBrush(RGB(255,255,255));
		RECT rect;
		rect.top=0;
		rect.left=0;
		rect.bottom=1024*0.7;
		rect.right=768*0.7;
		FillRect(MyDirector::getDirector()->hMemDC,&rect,hbrush);

		Queue_Scene.front()->action();
		Queue_Scene.front()->collision_detec();
		Queue_Scene.front()->update();
		Queue_Scene.front()->draw();

		BitBlt(hdc, 0, 0,756*0.7,1024*0.7,MyDirector::getDirector()->hMemDC, 0, 0, SRCCOPY);
		DeleteObject(hbrush);
		DeleteDC(hdc);
		DeleteDC(hMemDC);
	
		DeleteObject(hBitmap);
	}
}
//��ʼ�������б� �Լ�������

void MyDirector::setWinSize(size winSize){
	this->winSize=winSize;
}
size MyDirector::getWinSize(){
	return this->winSize;
}

void MyDirector::pushScene(MyScene* scene){
	Queue_Scene.push(scene);
}
void MyDirector::popScene(){
	Queue_Scene.pop();
}

void MyDirector::ConsolePrint(string out){
	static int time=0;
	if(time ==0)
	{
		time++;
	}
	AllocConsole();
	std::cout<<out;
	
	//FreeConsole();
}

MyScene* MyDirector::getScene()
{
	return (Queue_Scene.front());

}