//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĳ����� �̳���MyScene
//			�����趨����Ϸ�ոտ�ʼ�Ľ��� ��ʾһЩ��Ϸ�Ļ�������˵�� �����˽�����Ϸ�������ת
//			�����еķ������ᱻMydirector����


#include "stdafx.h"
#include "initScene.h"
#include "GameScene.h"

initScene::initScene(void)
{
	you=new enemy();
	you->settag(0);
	you->setcolor(RGB(0,0,255));
	you->setcenter(size(712*0.3,1024*0.6*0.618));
	this->addSprite(you,0);
}


initScene::~initScene(void)
{


}


void initScene::action()
{
	bg=(HBITMAP)LoadImage(NULL,  //Ӧ�ó���ʵ��   
		_T("gameback.bmp"),  //·��
    IMAGE_BITMAP,    
    768*0.537,        //�������0,��˲���ָ��bitmap�Ŀ�(λͼ������)  
    1024*0.545,        //�������0,��˲���ָ��bitmap�ĸ�(λͼ������)  
    LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE);
	SelectObject(MyDirector::getDirector()->hMemDC,bg);
    SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,255));
	DeleteObject(bg);
	SetBkMode(MyDirector::getDirector()->hMemDC,TRANSPARENT);

	LOGFONT   logfont;       //�ı��������
		ZeroMemory(&logfont,   sizeof(LOGFONT));   
		logfont.lfCharSet   =   GB2312_CHARSET;   
		logfont.lfHeight   =   15;      //��������Ĵ�С
		logfont.lfWeight=3;
		HFONT   hFont   =   CreateFontIndirect(&logfont);   
		SelectObject(MyDirector::getDirector()->hMemDC, hFont);
		DeleteObject(hFont);
	TextOut(MyDirector::getDirector()->hMemDC, 110,30, TEXT("ʹ���������ҽ��п���"), 10);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 60, TEXT("��סshift�������ƶ�"),12);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 90, TEXT("X ʹ����������"),8);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 120, TEXT("Z �����ӵ�"),6);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 150, TEXT("��ܺ�ɫ�ĵ���"),7);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 180, TEXT("��ֻ�������� ��ÿ��������5��"),15);
	
	TextOut(MyDirector::getDirector()->hMemDC, 40, 220, TEXT("�ƶ�����-> --------------------- <-��ʼ��Ϸ"),35);

}
void initScene::when_collision(MyShape* shape1,MyShape* shape2)
{
	MyScene *m=MyDirector::getDirector()->getScene();
	MyDirector::getDirector()->popScene();
	MyDirector::getDirector()->pushScene(new GameScene);
	delete m;
}
void initScene::update()
{
	int speed=5;
	string statu=MyDirector::getDirector()->getKeyStatu("SHIFT");
	size cent=you->getcenter();
	if(statu=="DOWN")
	{
		speed/=2;
	}
	statu=MyDirector::getDirector()->getKeyStatu("UP");
	if(statu=="DOWN")
	{
		cent.y-=speed;
		if(cent.y<0)
			cent.y=0;
		if(cent.y<220){
			when_collision(NULL,NULL);
		}
	}
	statu=MyDirector::getDirector()->getKeyStatu("DOWN");
	if(statu=="DOWN")
	{
		cent.y+=speed;
		if(cent.y>1024*0.54)
			cent.y=1024*0.54;
	}
	statu=MyDirector::getDirector()->getKeyStatu("LEFT");
	if(statu=="DOWN")
	{
		cent.x-=speed;
		if(cent.x<0)
			cent.x=0;
	}
	statu=MyDirector::getDirector()->getKeyStatu("RIGHT");
	if(statu=="DOWN")
	{
		cent.x+=speed;
		if(cent.x>768*0.54)
			cent.x=768*0.54;
	}
	statu=MyDirector::getDirector()->getKeyStatu("X");
	if(statu=="DOWN")
	{
		this->list_of_object[1].clear();
	}
	you->setcenter(cent);
}
