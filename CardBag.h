#pragma once
#include "CardList.h"

class CardBag :
    public CardList
{
public:
    vector<Card>cards;
    int MAX_NUMBER;//������������
    void showcards(Player&);//չʾ�Լ����е�����
    void getcard(CardBag&, int);//��ȡK����
    void losecard(int);//ʧȥһ����
    void getlastcard(CardBag&);//������ֵ����˱�
    int getcardchoose(Player&);//��ȡ��Ҫʹ�õĿ��Ʊ��
    int getcardnumber();//��ȡʣ������
    CardBag(bool);
    ~CardBag();
};

