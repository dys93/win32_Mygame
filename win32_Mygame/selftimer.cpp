//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ��ʱ�������
//			��������ָ����Ϸ���� 
//			�����趨��Ϸ��ʼ�����ʱ��ִ����Ӧ����
//			�����趨һ�������� ѭ��������ִ�м��

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