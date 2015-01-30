//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的场景类 继承自MyScene
//			该类设定了游戏刚刚开始的界面 显示一些游戏的基本操作说明 定义了进入游戏界面的跳转
//			该类中的方法将会被Mydirector调用


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
	bg=(HBITMAP)LoadImage(NULL,  //应用程序实例   
		_T("gameback.bmp"),  //路径
    IMAGE_BITMAP,    
    768*0.537,        //如果不置0,则此参数指定bitmap的宽(位图被拉伸)  
    1024*0.545,        //如果不置0,则此参数指定bitmap的高(位图被拉伸)  
    LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE);
	SelectObject(MyDirector::getDirector()->hMemDC,bg);
    SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,255));
	DeleteObject(bg);
	SetBkMode(MyDirector::getDirector()->hMemDC,TRANSPARENT);

	LOGFONT   logfont;       //改变输出字体
		ZeroMemory(&logfont,   sizeof(LOGFONT));   
		logfont.lfCharSet   =   GB2312_CHARSET;   
		logfont.lfHeight   =   15;      //设置字体的大小
		logfont.lfWeight=3;
		HFONT   hFont   =   CreateFontIndirect(&logfont);   
		SelectObject(MyDirector::getDirector()->hMemDC, hFont);
		DeleteObject(hFont);
	TextOut(MyDirector::getDirector()->hMemDC, 110,30, TEXT("使用上下左右进行控制"), 10);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 60, TEXT("按住shift键慢速移动"),12);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 90, TEXT("X 使用清屏技能"),8);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 120, TEXT("Z 发射子弹"),6);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 150, TEXT("躲避红色的敌人"),7);
	TextOut(MyDirector::getDirector()->hMemDC, 110, 180, TEXT("你只有三条命 而每个敌人有5条"),15);
	
	TextOut(MyDirector::getDirector()->hMemDC, 40, 220, TEXT("移动到此-> --------------------- <-开始游戏"),35);

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
