#pragma once
#include"Player.h"

class Gamecenter
{
public:
	Player* player1;//进入场景中的玩家1
	Player* player2;//进入场景中的玩家2
	CardBag* systemcard;//系统牌库
	void battle();//双方进行对战
	Gamecenter();
	~Gamecenter();
};

