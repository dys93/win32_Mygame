//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ��ʱ�������
//			��������ָ����Ϸ���� 
//			�����趨��Ϸ��ʼ�����ʱ��ִ����Ӧ����
//			�����趨һ�������� ѭ��������ִ�м��

#pragma once

class selftimer
{
	bool sleep;
	DWORD start_time;
	DWORD when_time;
	DWORD repeat_time;
public:
	selftimer(void);
	~selftimer(void);
	DWORD gettime();
	void init();
	bool when(int m);
	bool repeat(int m);
	bool after(int m);
	bool before(int m);
	bool wait();
	bool run();
};

