#pragma once
#include"PlaceLabel.h"
#include"CardBag.h"
#include"GameTool.h"

class Player
{
public:
	int MAX_HP;//角色最大生命值
	int HP;//剩余的生命值，最大生命值固定为5点。
	int MAX_MP;//当前回合的最大法力值
	int MP;//剩余的法力值
	string name;//玩家的名字
	bool attack;//每回合仅有一次攻击机会，true状态下可以进行攻击。
	PlaceLabel places;//该玩家的地盘
	CardBag *mycard;//玩家的牌库
	GameTool tool;//工具类
	void action(Player&,CardBag&);//轮到你的回合了
	void show_player();//展示自己当前的状况
	void show_enemy(Player&);//展示敌人当前的状况
	void show_gamedata(Player&,CardBag&);//展示双方当前的状况
	void beattacked(int,int,int);//被攻击时进行结算,参数3为攻击类型 1照亮 2摧毁
	void updateMP();//更新法力值
	void showmycard();//展示自己的卡牌
	void usemycard();//使用自己的卡牌
	void winlose(Player&);//胜利和失败界面
	void getmycard(CardBag&,int);//获取K张牌
	void losemycard(int);//丢失一张牌
	void preattack(CardBag&);//预备攻击
	void normalattack(Player&);//普通攻击
	void getMP(int,int);//技能带来的回MP效果
	void getHP(int,int);//技能带来的回HP效果
	void getlastcard(CardBag&);//后手获得的牌
	bool isalive();//玩家是否存活？
	void roundover();//回合结束数据调整
	Player(CardBag&,bool);
	~Player();
};

