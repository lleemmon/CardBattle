#pragma once
#include"stdafx.h"
#include"GameTool.h"

class Player;
class CardBag;
class Card
{
public:
	int id;//���Ʊ��
	int cost;//����ˮ������
	int number;//�����ƿ���Ӧ���е���Ŀ
	int dxy[40][2];//��Χ�Թ���������仯
	int dxy2[20][2];//dxy�ĵڶ�ѡ��
	int attackrange;//��Χ�Թ����Ĺ���������
	int randpriority;//�������ȼ� [3]����δ����δ���ݻٸ���[2]����δ���ݻٸ���[1]�����[0]�����
	int isattackcard;//�Ƿ�Ϊ������ 0���� 1������ 2������
	bool ischoosecard;//�Ƿ�Ϊ������
	bool isstablecard;//�Ƿ�Ϊ������Χ�̶�����
	bool needchooseline;//�Ƿ���Ҫ������������ѡ��
	int israndcard;//�Ƿ�Ϊ����� [0]���� [1]һ����� [2]�������
	string name;//��������
	string description;//������������
	GameTool tool;//��Ϸ����
	void Beat(Player&,Player&,CardBag&,int);//��������
	void display(Player&);//չʾ���Ƶ���Ϣ
	void RangeBeat(Player&);//��Χ����
	void randBeat(Player&);//�������
	void stableBeat(Player&);//�̶�����
	void rangedamage(Player&,int,int,int);//��Χ����-����
	void randdamage_4(Player&);//�������-����4
	void randdamage_3(Player&);//�������-����3
	void randdamage_2(Player&);//�������-����2
	void randdamage_1(Player&);//�������-����1
	void randdamage_line(Player&);//�������-����
	void randdamage_line_1(Player&,int);//�������-����-����
	void change_MP(Player&, int, int);//�ָ����MP ����2�����ħ��ֵ�ĸı�
	void change_HP(Player&, int, int);//�ظ����HP ����2���������ֵ�ĸı�
	void move_life(Player&);//ת�ư���λ��
	void remove_life(Player&);//�Ƴ�һ���������İ���
	void remove_life_range(Player&);//�Ƴ��Լ�3*3��Χ�İ���
	void add_a_life(Player&,int);//Ϊһ��������ӻ���ٰ���
	void bedark(Player&);//ʹ���б��������ӱ���������
	void cleanruin(Player&);//�ָ�N�����ݻٸ���
	void move_all_live(Player&);//ʹ���а����������
	void change_cost(Player&,int,bool,int);//����������Ϊfalse�������ı����true����ȫ���ı����,���ĸ����ڷ�ֹbug
	void change_cost(Player&, int, bool);//����������Ϊfalse�������ı����true����ȫ���ı����,����ר�ã�������ĸ�����
	void change_cost(Player&, int);//�������Ʊ��һ������
	void change_cost(Player&);//�������Ʒ��ü���
	void attack_light(Player&);//�ݻ����б�������λ
	void skill_1_eyue(Player&);//����������з���ѪΪֹ
	void skill_2_guliuyue(Player&);//ȫͼ����
	void skill_3_zhuhuanongyue(Player&);//�黪Ū��
	void skill_4_tianmanyueqian(Player&);//��������
	void skill_5_yuelonglunwei(Player&);//������β
	void skill_6_yuehunyanwo(Player&);//�»�����
	bool Canuse(Player&);//���ظ����Ƿ���Ա�ʹ��
	Card();
	~Card();
};

