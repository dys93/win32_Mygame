//ѧ�ţ�1252957
//������������
//�ļ�����GameScene
//�ļ�������������Ϸ�ĳ����� ��һ������ 
//			��������򵥵ĳ����߼� ����ɾ�������߽�Ķ���
//			


#include "stdafx.h"
#include "MyScene.h"


MyScene::MyScene(void)
{
}


MyScene::~MyScene(void)
{
}
void MyScene::addSprite(MyShape *shape,int layer){

	list_of_object[layer].push_back(shape);
}
void MyScene::removeSpriteByTag(int tag){
	for(int i=0;i<4;i++)
	{
		for(auto j=list_of_object[i].size();j!=0;j--)
		{
			if(list_of_object[i][j]->gettag()==tag)
			{
				removeSprite(i,j);
			}
		}
	}
}

void MyScene::removeSprite(int i,int j)
{
	auto spr=list_of_object[i].begin();
	spr+=j;
	spr;
	auto *p=list_of_object[i][j];
	(list_of_object[i]).erase(spr);
	delete p;
}
//director������ײ������Ϣ
void MyScene::when_collision(MyShape *shape1,MyShape *shape2)
{

}
//���»���ÿһ֡ ����ͨ��director��keystatu��ð�����Ϣ
void MyScene::action()
{

}
void MyScene::update()
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
void MyScene::collision_detec()
{
	for(int j=0;j<list_of_object[1].size();j++)
	{
		for(int j1=0;j1<list_of_object[0].size();j1++)
		{
			if(MyShape::iscollision(*list_of_object[1][j],*list_of_object[0][j1])!=NULL)
			{
				when_collision(list_of_object[1][j],list_of_object[0][j1]);
			}
		}
	}
	for(int j=0;j<list_of_object[2].size();j++)
	{
		for(int j1=0;j1<list_of_object[0].size();j1++)
		{
			if(MyShape::iscollision(*list_of_object[2][j],*list_of_object[0][j1])!=NULL)
			{
				when_collision(list_of_object[2][j],list_of_object[0][j1]);
			}
		}
	}
	for(int j=0;j<list_of_object[3].size();j++)
	{
		for(int j1=0;j1<list_of_object[1].size();j1++)
		{
			if(MyShape::iscollision(*list_of_object[3][j],*list_of_object[1][j1])!=NULL)
			{
				when_collision(list_of_object[3][j],list_of_object[1][j1]);
			}
		}
	}
}
void MyScene::draw()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<list_of_object[i].size();j++)
		{
			list_of_object[i][j]->draw();
		}
	}
}

void MyScene::remove_out_ob()
{
	for(int i=0;i<4;i++)
	{
		for(int j=list_of_object[i].size()-1;j>=0;j--)
		{
			
			size z=MyDirector::getDirector()->getWinSize();
			size pos=list_of_object[i][j]->getcenter();
			if(z.x>pos.x&&pos.x>-30&&z.y>pos.y&&pos.y>-30&&list_of_object[i][j]->getlife()>0)
			{
				continue;
			}
			else 
			{
				
				this->removeSprite(i,j);
			}
		}
	}

}