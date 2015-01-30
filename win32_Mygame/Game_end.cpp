//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĳ����� �̳���MyScene
//			�����趨����Ϸ��������ʾ�Ľ��� ͬʱ�趨�˶����û�����֮��Ľ�����ת�߼�
//			�����еķ������ᱻMydirector����


#include "stdafx.h"
#include "Game_end.h"
#include "initScene.h"
#include "GameScene.h"
Game_end::Game_end(void)
{
	SCORE =0;
	MyDirector::getDirector()->setKeyStatu("LBUTTON","UP");
}
void Game_end::setScore(int Score)
{
	this->SCORE=Score;
}
void Game_end::action()
{
	static int maxScore=0;
	if(SCORE>maxScore)
		maxScore=SCORE;
	HBITMAP bg=(HBITMAP)LoadImage(NULL,  //Ӧ�ó���ʵ��   
		_T("gameback.bmp"),  //·��
    IMAGE_BITMAP,    
    768*0.537,        //�������0,��˲���ָ��bitmap�Ŀ�(λͼ������)  
    1024*0.545,        //�������0,��˲���ָ��bitmap�ĸ�(λͼ������)  
    LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE);
	
	SelectObject(MyDirector::getDirector()->hMemDC,bg);

  //  SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,0));
	DeleteObject(bg);


	SetTextColor(MyDirector::getDirector()->hMemDC,RGB(0,0,255));
	SetBkMode(MyDirector::getDirector()->hMemDC,TRANSPARENT);
	LOGFONT   logfont;       //�ı��������
	ZeroMemory(&logfont,   sizeof(LOGFONT));   
	logfont.lfCharSet   =   GB2312_CHARSET;   
	logfont.lfHeight   =   40;      //��������Ĵ�С
	HFONT   hFont   =   CreateFontIndirect(&logfont);   
	SelectObject(MyDirector::getDirector()->hMemDC, hFont); 

	TCHAR szBuffer[40];
	int a=swprintf_s(szBuffer,L"MAX_SCORE��%d",maxScore);
	LPCTSTR made;
	made=szBuffer;
	TextOut(MyDirector::getDirector()->hMemDC, 60, 70,made, a);
	DeleteObject(hFont);

	logfont.lfHeight   =   20;
	hFont   =   CreateFontIndirect(&logfont);  
	SelectObject(MyDirector::getDirector()->hMemDC, hFont); 
	a=swprintf_s(szBuffer,L"YOU_SCORE��%d",SCORE);
	made=szBuffer;
	TextOut(MyDirector::getDirector()->hMemDC, 140, 170,made, a);
	DeleteObject(hFont);

	RECT rect;
	rect.top=300;
	rect.left=170;
	rect.right=250;
	rect.bottom=330;
	HPEN pen=CreatePen(BS_SOLID,2,RGB(0,255,255));
	SelectObject(MyDirector::getDirector()->hMemDC,pen);
	Rectangle(MyDirector::getDirector()->hMemDC,rect.left,rect.top,rect.right,rect.bottom);

	a=swprintf_s(szBuffer,L"����",SCORE);
	made=szBuffer;
	TextOut(MyDirector::getDirector()->hMemDC,rect.left+20,rect.top+5,made,a);

	DeleteObject(hFont);
	DeleteObject(pen);
	static bool sta1=false;
	if(MyDirector::getDirector()->getKeyStatu("LBUTTON")=="DOWN")
	{
		POINT mouse;
		mouse.x=MyDirector::getDirector()->Mousex;
		mouse.y=MyDirector::getDirector()->Mousey;
		if(PtInRect(&rect,mouse))
		{
			sta1=true;
		}
	}
	if(MyDirector::getDirector()->getKeyStatu("LBUTTON")=="UP")
	{
		POINT mouse;
		mouse.x=MyDirector::getDirector()->Mousex;
		mouse.y=MyDirector::getDirector()->Mousey;
		if(PtInRect(&rect,mouse)&&sta1)
		{
			sta1=false;
			when_collision(NULL,NULL);
		}
		else 
			sta1=false;
	}

	RECT rect2;
	rect2.top=350;
	rect2.left=170;
	rect2.right=250;
	rect2.bottom=380;

	Rectangle(MyDirector::getDirector()->hMemDC,rect2.left,rect2.top,rect2.right,rect2.bottom);

	a=swprintf_s(szBuffer,L"����",SCORE);
	made=szBuffer;
	TextOut(MyDirector::getDirector()->hMemDC,rect2.left+20,rect2.top+5,made,a);

	static bool sta2=false;
	if(MyDirector::getDirector()->getKeyStatu("LBUTTON")=="DOWN")
	{
		POINT mouse;
		mouse.x=MyDirector::getDirector()->Mousex;
		mouse.y=MyDirector::getDirector()->Mousey;
		if(PtInRect(&rect2,mouse))
		{
			sta2=true;
		}
	}
	if(MyDirector::getDirector()->getKeyStatu("LBUTTON")=="UP")
	{
		POINT mouse;
		mouse.x=MyDirector::getDirector()->Mousex;
		mouse.y=MyDirector::getDirector()->Mousey;
		if(PtInRect(&rect2,mouse)&&sta2)
		{
			sta2=false;
			MyScene *p=MyDirector::getDirector()->getScene();
			MyDirector::getDirector()->popScene();
			MyDirector::getDirector()->pushScene(new GameScene());
			delete p;
		}
		else 
			sta2=false;
	}

	RECT rect3;
	rect3.top=400;
	rect3.left=170;
	rect3.right=250;
	rect3.bottom=430;

	Rectangle(MyDirector::getDirector()->hMemDC,rect3.left,rect3.top,rect3.right,rect3.bottom);

	a=swprintf_s(szBuffer,L"�˳�",SCORE);
	made=szBuffer;
	TextOut(MyDirector::getDirector()->hMemDC,rect3.left+20,rect3.top+5,made,a);

	static bool sta3=false;
	if(MyDirector::getDirector()->getKeyStatu("LBUTTON")=="DOWN")
	{
		POINT mouse;
		mouse.x=MyDirector::getDirector()->Mousex;
		mouse.y=MyDirector::getDirector()->Mousey;
		if(PtInRect(&rect3,mouse))
		{
			sta3=true;
		}
	}
	if(MyDirector::getDirector()->getKeyStatu("LBUTTON")=="UP")
	{
		POINT mouse;
		mouse.x=MyDirector::getDirector()->Mousex;
		mouse.y=MyDirector::getDirector()->Mousey;
		if(PtInRect(&rect3,mouse)&&sta3)
		{
			sta3=false;
			SendMessage( MyDirector::getDirector()->getHWND() ,WM_DESTROY,0,0);
		}
		else 
			sta3=false;
	}

}

void Game_end::when_collision(MyShape*,MyShape*)
{
	MyScene *p=MyDirector::getDirector()->getScene();
	MyDirector::getDirector()->popScene();
	MyDirector::getDirector()->pushScene(new initScene);
	delete p;
}
void Game_end::update()
{

}
Game_end::~Game_end(void)
{
}
