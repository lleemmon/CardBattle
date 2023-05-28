#pragma once
#include"stdafx.h"
#include"GameTool.h"

class Player;
class CardBag;
class Card
{
public:
	int id;//卡牌编号
	int cost;//法力水晶消耗
	int number;//在总牌库中应该有的数目
	int dxy[40][2];//范围性攻击的坐标变化
	int dxy2[20][2];//dxy的第二选择
	int attackrange;//范围性攻击的攻击格子数
	int randpriority;//攻击优先级 [3]优先未照明未被摧毁格子[2]优先未被摧毁格子[1]纯随机[0]非随机
	int isattackcard;//是否为攻击牌 0不是 1照明牌 2攻击牌
	bool ischoosecard;//是否为抉择牌
	bool isstablecard;//是否为攻击范围固定的牌
	bool needchooseline;//是否需要跳过部分行列选择
	int israndcard;//是否为随机牌 [0]不是 [1]一般随机 [2]行列随机
	string name;//卡牌名称
	string description;//卡牌作用描述
	GameTool tool;//游戏工具
	void Beat(Player&,Player&,CardBag&,int);//卡牌作用
	void display(Player&);//展示卡牌的信息
	void RangeBeat(Player&);//范围攻击
	void randBeat(Player&);//随机攻击
	void stableBeat(Player&);//固定攻击
	void rangedamage(Player&,int,int,int);//范围攻击-附件
	void randdamage_4(Player&);//随机攻击-附件4
	void randdamage_3(Player&);//随机攻击-附件3
	void randdamage_2(Player&);//随机攻击-附件2
	void randdamage_1(Player&);//随机攻击-附件1
	void randdamage_line(Player&);//随机攻击-线型
	void randdamage_line_1(Player&,int);//随机攻击-线性-附件
	void change_MP(Player&, int, int);//恢复玩家MP 参数2是最大魔法值的改变
	void change_HP(Player&, int, int);//回复玩家HP 参数2是最大生命值的改变
	void move_life(Player&);//转移爱心位置
	void remove_life(Player&);//移除一个被照亮的爱心
	void remove_life_range(Player&);//移除自己3*3范围的爱心
	void add_a_life(Player&,int);//为一个玩家增加或减少爱心
	void bedark(Player&);//使所有被照亮格子变成迷雾格子
	void cleanruin(Player&);//恢复N个被摧毁格子
	void move_all_live(Player&);//使所有爱心随机打乱
	void change_cost(Player&,int,bool,int);//第三个参数为false代表单个改变费用true代表全部改变费用,第四个用于防止bug
	void change_cost(Player&, int, bool);//第三个参数为false代表单个改变费用true代表全部改变费用,敌人专用，无需第四个参数
	void change_cost(Player&, int);//将所有牌变成一个费用
	void change_cost(Player&);//将所有牌费用减半
	void attack_light(Player&);//摧毁所有被照明单位
	void skill_1_eyue(Player&);//随机攻击到敌方扣血为止
	void skill_2_guliuyue(Player&);//全图照明
	void skill_3_zhuhuanongyue(Player&);//珠华弄月
	void skill_4_tianmanyueqian(Player&);//天满月纤
	void skill_5_yuelonglunwei(Player&);//月龙轮尾
	void skill_6_yuehunyanwo(Player&);//月魂炎涡
	bool Canuse(Player&);//返回该牌是否可以被使用
	Card();
	~Card();
};

