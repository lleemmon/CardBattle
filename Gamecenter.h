#pragma once
#include"Player.h"

class Gamecenter
{
public:
	Player* player1;//���볡���е����1
	Player* player2;//���볡���е����2
	CardBag* systemcard;//ϵͳ�ƿ�
	void battle();//˫�����ж�ս
	Gamecenter();
	~Gamecenter();
};

