#pragma once
#include"PlaceLabel.h"
#include"CardBag.h"
#include"GameTool.h"

class Player
{
public:
	int MAX_HP;//��ɫ�������ֵ
	int HP;//ʣ�������ֵ���������ֵ�̶�Ϊ5�㡣
	int MAX_MP;//��ǰ�غϵ������ֵ
	int MP;//ʣ��ķ���ֵ
	string name;//��ҵ�����
	bool attack;//ÿ�غϽ���һ�ι������ᣬtrue״̬�¿��Խ��й�����
	PlaceLabel places;//����ҵĵ���
	CardBag *mycard;//��ҵ��ƿ�
	GameTool tool;//������
	void action(Player&,CardBag&);//�ֵ���Ļغ���
	void show_player();//չʾ�Լ���ǰ��״��
	void show_enemy(Player&);//չʾ���˵�ǰ��״��
	void show_gamedata(Player&,CardBag&);//չʾ˫����ǰ��״��
	void beattacked(int,int,int);//������ʱ���н���,����3Ϊ�������� 1���� 2�ݻ�
	void updateMP();//���·���ֵ
	void showmycard();//չʾ�Լ��Ŀ���
	void usemycard();//ʹ���Լ��Ŀ���
	void winlose(Player&);//ʤ����ʧ�ܽ���
	void getmycard(CardBag&,int);//��ȡK����
	void losemycard(int);//��ʧһ����
	void preattack(CardBag&);//Ԥ������
	void normalattack(Player&);//��ͨ����
	void getMP(int,int);//���ܴ����Ļ�MPЧ��
	void getHP(int,int);//���ܴ����Ļ�HPЧ��
	void getlastcard(CardBag&);//���ֻ�õ���
	bool isalive();//����Ƿ��
	void roundover();//�غϽ������ݵ���
	Player(CardBag&,bool);
	~Player();
};

