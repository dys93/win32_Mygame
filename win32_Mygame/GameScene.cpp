//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的主要场景类，该类继承自MyScene
//			在该类中复写方法 update 及 action 交给导演类MyDirectory进行执行
//			


#include "stdafx.h"
#include "GameScene.h"
#include "bigenemy.h"
#include "Game_end.h"


MCIDEVICEID  dev[20];
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;

GameScene::GameScene(void)
{
	you=new bigenemy();
	you->settag(0);
	you->setcolor(RGB(0,0,255));
	you->setcenter(size(712*0.3,1024*0.6*0.618));
	createinfor aenemy(500,1,0,0,0);
	you->setenemyinfor(aenemy);
	you->setlife(3);
	this->addSprite(you,0);
	bomb=3;
	//PlaySound(_T("bgmusic.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_NODEFAULT|SND_LOOP);
	mciOpen.lpstrElementName=L"bgmusic.wav";
	if(mciSendCommand(NULL,MCI_OPEN, MCI_OPEN_ELEMENT ,(DWORD)&mciOpen)==0)
		dev[0]=mciOpen.wDeviceID;
	else
		mciOpen.wDeviceID=dev[0];

		mciPlay.dwFrom = 0;
	mciSendCommand(mciOpen.wDeviceID,MCI_PLAY,MCI_NOTIFY | MCI_FROM,(DWORD)&mciPlay);

	mciOpen.lpstrElementName=L"bomb.wav";
			

	if((mciSendCommand(NULL,MCI_OPEN, MCI_OPEN_ELEMENT ,(DWORD)&mciOpen))==0)
		dev[1]=mciOpen.wDeviceID;

	mciOpen.lpstrElementName=L"shoot4.wav";
			
	if((mciSendCommand(NULL,MCI_OPEN, MCI_OPEN_ELEMENT ,(DWORD)&mciOpen))==0)
		dev[2]=mciOpen.wDeviceID;

	mciOpen.lpstrElementName=L"gameover.wav";
			
	if((mciSendCommand(NULL,MCI_OPEN, MCI_OPEN_ELEMENT ,(DWORD)&mciOpen))==0)
		dev[3]=mciOpen.wDeviceID;

}
void GameScene::action()
{
	//background

	
	float size1=0.7;
	size winSize(712*size1,1024*size1);
	RECT rect;
	rect.top=0;
	rect.left=0;
	rect.bottom=30;
	rect.right=100;
	bg=(HBITMAP)LoadImage(NULL,  //应用程序实例   
		_T("gameback.bmp"),  //路径
    IMAGE_BITMAP,    
    768*0.537,        //如果不置0,则此参数指定bitmap的宽(位图被拉伸)  
	1024*0.545,       //如果不置0,则此参数指定bitmap的高(位图被拉伸)  
    LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE);

	SelectObject(MyDirector::getDirector()->hMemDC,bg);
    SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,0));
	DeleteObject(bg);

	//message before game
	if(at.before(3000))
	{
		int time=3;
		if(at.after(1000))
			time--;
		if(at.after(2000))
			time--;
		if(	at.after(3000))
			time--;
		SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,255));
		SetBkMode(MyDirector::getDirector()->hMemDC,TRANSPARENT);
		LOGFONT   logfont;       //改变输出字体
		ZeroMemory(&logfont,   sizeof(LOGFONT));   
		logfont.lfCharSet   =   GB2312_CHARSET;   
		logfont.lfHeight   =   50;      //设置字体的大小
		HFONT   hFont   =   CreateFontIndirect(&logfont);   
		SelectObject(MyDirector::getDirector()->hMemDC, hFont); 
		

		TCHAR szBuffer[40];
		int a=swprintf_s(szBuffer,L"%d",time);
		LPCTSTR made;
		made=szBuffer;
		TextOut(MyDirector::getDirector()->hMemDC, 199, 50,made, a);
		DeleteObject(hFont);
	}
	//message in game
	int m=3000;
	if(at.after(3000))
	{
		int z=(at.gettime()-3000)/50;
		if(z<1500)m-=z;
		else m=1500;
		SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,255));
		SetBkMode(MyDirector::getDirector()->hMemDC,TRANSPARENT);
		LOGFONT   logfont;       //改变输出字体
		ZeroMemory(&logfont,   sizeof(LOGFONT));   
		logfont.lfCharSet   =   GB2312_CHARSET;   
		logfont.lfHeight   =   15;      //设置字体的大小
		HFONT   hFont   =   CreateFontIndirect(&logfont);   
		SelectObject(MyDirector::getDirector()->hMemDC, hFont); 
		
		TCHAR szBuffer[40];
		int a=swprintf_s(szBuffer,L"bomb：%d",bomb);
		LPCTSTR made;
		made=szBuffer;
		TextOut(MyDirector::getDirector()->hMemDC, 30, 30,made, a);

		
		a=swprintf_s(szBuffer,L"SCORE：%d",at.gettime()-3000);
		made=szBuffer;
		TextOut(MyDirector::getDirector()->hMemDC, 300, 30,made, a);

		a=swprintf_s(szBuffer,L"NEXT：%d",m);
		made=szBuffer;
		TextOut(MyDirector::getDirector()->hMemDC, 160, 30,made, a);

		SetTextColor(MyDirector::getDirector()->hMemDC,RGB(255,0,0));

		if(you->getlife()==3)
		a=swprintf_s(szBuffer,L"❤❤❤");
		if(you->getlife()==2)
		a=swprintf_s(szBuffer,L"❤❤");
		if(you->getlife()==1)
		a=swprintf_s(szBuffer,L"❤");
		
		made=szBuffer;
		TextOut(MyDirector::getDirector()->hMemDC, 30, 500,made, a);
		
		DeleteObject(hFont);
	}
	//create enemy
	if(at.repeat(m)){
		
		bigenemy *b_enemy=new bigenemy;
		b_enemy->setdegree(0);
		size pos;
		pos.x= rand()% (int)winSize.x;
		pos.y=0;
		b_enemy->setcenter(pos);
		b_enemy->settag(1);
		pos.x=0;
		pos.y=100;
		b_enemy->setspeed(pos);
		b_enemy->setlife(5);
		int random=rand()%100;
		//>90 12连发
		// 80~90 自击狙
		if(random<90&&random>=80)
		{
			b_enemy->setyou(you);
			createinfor aenemy(300,1,0,0,300);
			b_enemy->setenemyinfor(aenemy);
			b_enemy->smallkind=1;
		}
		//60~80 1发扫射
		if(random<80&&random>=60)
		{
			createinfor aenemy(400,1,15,20,200);
			b_enemy->setenemyinfor(aenemy);
			
		}
		//40~60 2发扫射
		if(random<60&&random>=40)
		{
			createinfor aenemy(350,2,180,20,200);
			b_enemy->setenemyinfor(aenemy);
		}
		//20~40 3发扫射
		if(random<40&&random>=20)
		{
			createinfor aenemy(300,3,120,30,300);
			b_enemy->setenemyinfor(aenemy);
		}
		//0~20 4发扫射
		if(random<20)
		{
			createinfor aenemy(300,4,15,30,300);
			b_enemy->setenemyinfor(aenemy);
		}
		//0~20 4发扫射
		if(random<10)
		{
			createinfor aenemy(130,36,10,3,500);
			b_enemy->setenemyinfor(aenemy);
		}
		if(random<5)
		{
			createinfor aenemy(300,6,60,13,200);
			b_enemy->setenemyinfor(aenemy);
		}
		if(random==1)
		{
			createinfor aenemy(200,18,20,3,200);
			b_enemy->setenemyinfor(aenemy);
		}
		this->addSprite(b_enemy,1);
	}




	//you
	int speed=4;
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
	static bool flag=true;
	if(statu=="UP")
	{
		 flag=true;

	}
	if(statu=="DOWN"&&flag==true)
	{
		flag=false;
		if(bomb>0)
		{
		//	PlaySound(_T("bomb.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_NODEFAULT|SND_NOSTOP);
			mciOpen.lpstrElementName=L"bomb.wav";
			int a=0;
			if((a=mciSendCommand(NULL,MCI_OPEN, MCI_OPEN_ELEMENT ,(DWORD)&mciOpen))==0)
				dev[1]=mciOpen.wDeviceID;
			else
				mciOpen.wDeviceID=dev[1];
			mciPlay.dwFrom = 0;
			mciSendCommand(mciOpen.wDeviceID,MCI_PLAY,MCI_NOTIFY | MCI_FROM,(DWORD)&mciPlay);

			bomb--;
			this->list_of_object[1].clear();
			this->list_of_object[2].clear();
		}
	}
	statu=MyDirector::getDirector()->getKeyStatu("Z");
	static bool isshoot=true;
	static selftimer *z=new selftimer;
	if(statu=="UP")
	{
	}
	if(statu=="DOWN")
	{
		if(isshoot==true)
		{
			((bigenemy*)you)->createsmallenemy();
			isshoot=false;
			delete z;
			z=new selftimer;

			mciOpen.wDeviceID=dev[2];
			mciPlay.dwFrom = 0;
			mciSendCommand(mciOpen.wDeviceID,MCI_PLAY,MCI_NOTIFY | MCI_FROM,(DWORD)&mciPlay);

		}
	}
	if(z->after(120))
		{
			isshoot=true;
		}
	you->setcenter(cent);
}

GameScene::~GameScene(void)
{
}
void GameScene::when_collision(MyShape* shape1,MyShape* shape2)
{
	if(shape1->getlife()>0&&shape2->getlife()>0)
	{
		shape1->setlife(shape1->getlife()-1);
		shape2->setlife(shape2->getlife()-1);
	}
	if(you->getlife()==0)
	{
		gamelost();
	}
}
void GameScene::gamelost()
{
	MyScene *p=MyDirector::getDirector()->getScene();
		MyDirector::getDirector()->popScene();
		Game_end *end=new Game_end();
		end->setScore(at.gettime()-3000);
		MyDirector::getDirector()->pushScene(end);
		delete p;
	//	PlaySound(NULL,NULL,SND_ASYNC|SND_FILENAME);//SND_NOSTOP 
		mciSendCommand (dev[0], MCI_CLOSE, NULL, NULL);
		mciOpen.wDeviceID=dev[3];
		mciPlay.dwFrom = 0;
		mciSendCommand(mciOpen.wDeviceID,MCI_PLAY,MCI_NOTIFY | MCI_FROM,(DWORD)&mciPlay);

}
void GameScene::update()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<list_of_object[i].size();j++)
		{
			list_of_object[i][j]->update();
		}
	}
	
	this->remove_out_ob();
}