//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的时间控制类
//			该类用于指定游戏过程 
//			用于设定游戏开始后多少时间执行相应操作
//			用于设定一个场景中 循环操作的执行间隔

#include "stdafx.h"
#include "selftimer.h"


selftimer::selftimer(void)
{
	start_time=GetTickCount();
	when_time=GetTickCount();
	repeat_time=GetTickCount();
	sleep=false;
}


selftimer::~selftimer(void)
{
}
void selftimer::init()
{
	start_time=GetTickCount();
	sleep=false;
}
bool selftimer::when(int m)
{
	int new_time=GetTickCount();
	int b=when_time-start_time;
	if(when_time-start_time<m&&sleep==false)
	{
		when_time=new_time;
		if(when_time-start_time>m)
		{
			return true;
		}
	}
	when_time=new_time;
	return false;
}

bool selftimer::repeat(int m)
{
	int new_time=GetTickCount();
	if((repeat_time-start_time)%m>((new_time-start_time)%m))
	{
		repeat_time=new_time;
		return true;
	}
	repeat_time=new_time;
	return false;
}
bool selftimer::after(int m)
{
	int new_time=GetTickCount();
	if(((new_time-start_time)>m))
	{
		return true;
	}
	return false;
}
bool selftimer::run(){
	return false;
}
bool selftimer::wait()
{
	return false;
}
bool selftimer::before(int m)
{
	int new_time=GetTickCount();
	if(((new_time-start_time)<m))
	{
		return true;
	}
	return false;
}
DWORD selftimer::gettime()
{
	return	GetTickCount()-start_time;
}