//学号：1252957
//姓名：丁宇笙
//文件名：GameScene
//文件描述：这是游戏的时间控制类
//			该类用于指定游戏过程 
//			用于设定游戏开始后多少时间执行相应操作
//			用于设定一个场景中 循环操作的执行间隔

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

