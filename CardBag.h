#pragma once
#include "CardList.h"

class CardBag :
    public CardList
{
public:
    vector<Card>cards;
    int MAX_NUMBER;//允许的最大牌数
    void showcards(Player&);//展示自己所有的手牌
    void getcard(CardBag&, int);//获取K张牌
    void losecard(int);//失去一张牌
    void getlastcard(CardBag&);//分配后手的幸运币
    int getcardchoose(Player&);//获取想要使用的卡牌编号
    int getcardnumber();//获取剩余牌数
    CardBag(bool);
    ~CardBag();
};

