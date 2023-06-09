#include "CardList.h"

int _cost[MAX_CARD] = { 0,9,8,8,8,7,7,7,7,5,6,4,4,4,4,3,3,2,2,1,1,5,6,4,2,0,1,3,2,4,4,3,3,7,3,2,4,5,6,8,9,4,1,3,3,2,3,4,4,1,3,5,2,5,3,7,6,2,15,10,2,9,7,7,3,4,7 };
int _number[MAX_CARD] = { 1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,2,2,3,3,4,3,3,3,3,3,3,3,2,3,3,3,2,2,1,1,3,3,3,3,3,3,3,3,3,3,2,3,2,3,2,2,3,1,1,3,1,2,2,3,3,2 };
int _attackrange[MAX_CARD] = { 0,37,2,17,20,15,16,17,12,10,13,9,9,9,1,7,9,5,5,3,4,0,0,0,0,0,0,2,1,1,1,1,1,1,1,5,9,13,16,21,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,3,0,0,0,0,9,0};
int _priority[MAX_CARD] = { 0,0,1,0,0,0,0,0,3,2,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0 };
int _israndcard[MAX_CARD] = { 0,0,2,0,0,0,0,0,1,1,0,0,0,0,2,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 };
int _dxy[MAX_CARD][40][2] = { {{0,0}},
{{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7},{0,-8},{0,-9},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0},{-8,0},{-9,0}},
{{0,0}},
{{0,0},{-1,-1},{-2,-2},{-1,0},{-2,0},{-1,1},{-2,2},{0,1},{0,2},{1,1},{2,2},{1,0},{2,0},{1,-1},{2,-2},{0,-1},{0,-2}},
{{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},{0,9},{1,8},{2,7},{3,6},{4,5},{5,4},{6,3},{7,2},{8,1},{9,0}},
{{-2,1},{-1,1},{0,1},{1,1},{2,1},{-2,0},{-1,0},{0,0},{1,0},{2,0},{-2,-1},{-1,-1},{0,-1},{1,-1},{2,-1}},
{{-2,2},{-1,2},{0,2},{1,2},{2,2},{-2,1},{2,1},{-2,0},{2,0},{-2,-1},{2,-1},{-2,-2},{-1,-2},{0,-2},{1,-2},{2,-2}},
{{0,1},{0,2},{0,3},{0,-1},{0,-2},{0,-3},{-3,0},{-2,0},{-1,0},{1,0},{2,0},{3,0},{-1,1},{1,1},{-1,-1},{1,-1},{0,0}},
{{0,0}},
{{0,0}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1},{-2,0},{2,0},{0,2},{0,-2}},
{{0,0},{1,0},{2,0},{3,0},{4,0},{-1,0},{-2,0},{-3,0},{-4,0}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1}},
{{-2,0},{-1,0},{0,0},{1,0},{2,0},{0,1},{0,2},{0,-1},{0,-2}},
{{0,0}},
{{-3,0},{-2,0},{-1,0},{0,0},{1,0},{2,0},{3,0}},
{{0,0}},
{{-1,0},{1,0},{0,1},{0,-1},{0,0}},
{{-2,0},{-1,0},{0,0},{1,0},{2,0}},
{{-1,0},{0,0},{1,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{ {-1,0},{1,0},{0,1},{0,-1},{0,0}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1},{-2,0},{2,0},{0,2},{0,-2}},
{{-2,2},{-1,2},{0,2},{1,2},{2,2},{-2,1},{2,1},{-2,0},{2,0},{-2,-1},{2,-1},{-2,-2},{-1,-2},{0,-2},{1,-2},{2,-2}},
{{-1,2},{0,2},{1,2},{-2,1},{-1,1},{0,1},{1,1},{2,1},{-2,0},{-1,0},{0,0},{1,0},{2,0},{-2,-1},{-1,-1},{0,-1},{1,-1},{2,-1},{-1,-2},{0,-2},{1,-2}},
{{-2,2},{-1,2},{0,2},{1,2},{2,2},{-2,1},{-1,1},{0,1},{1,1},{2,1},{-2,0},{-1,0},{0,0},{1,0},{2,0},{-2,-1},{-1,-1},{0,-1},{1,-1},{2,-1},{-2,-2},{-1,-2},{0,-2},{1,-2},{2,-2}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1}},
{{0,0}}
};
int _dxy2[MAX_CARD][20][2] = { {{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{-1,2},{0,2},{1,2},{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1},{-1,-2},{0,-2},{1,-2}},
{{0,0}},
{{-1,1},{-2,2},{-3,3},{1,-1},{2,-2},{3,-3},{1,1},{2,2},{3,3},{-1,-1},{-2,-2},{-3,-3},{1,0},{-1,0},{0,1},{0,-1},{0,0}},
{{0,0}},
{{0,0}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1},{-2,-2},{2,2},{-2,2},{2,-2}},
{{0,0},{0,1},{0,2},{0,3},{0,4},{0,-1},{0,-2},{0,-3},{0,-4}},
{{0,0}},
{{-2,2},{-1,1},{0,0},{1,-1},{2,-2},{2,2},{1,1},{-1,-1},{-2,-2}},
{{0,0}},
{{0,3},{0,2},{0,1},{0,0},{0,-1},{0,-2},{0,-3}},
{{0,0}},
{{-1,1},{1,1},{-1,-1},{1,-1},{0,0}},
{{0,2},{0,1},{0,0},{0,-1},{0,-2}},
{{0,1},{0,0},{0,-1}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{-1,1},{1,1},{-1,-1},{1,-1},{0,0}},
{{0,0}},
{{-1,1},{0,1},{1,1},{-1,0},{0,0},{1,0},{-1,-1},{0,-1},{1,-1},{-2,-2},{2,2},{-2,2},{2,-2}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}},
{{0,0}}
};
int _isattackcard[MAX_CARD] = { 0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,2,0,0,0,0,2,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0,2,1,2,2,0,
0,0 };
bool _ischoosecard[MAX_CARD] = { false,false,true,false,false,true,false,true,false,false,true,true,false,true,true,true,false,true,true,true,false,false,false,false,
false,false,false,false,false,false,false,false,false,false,false,true,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,
true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
bool _isstablecard[MAX_CARD] = { true,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,
true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false
,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
bool _needchooseline[MAX_CARD] = { false,false,true,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,
false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,
false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
string _name[MAX_CARD] = { "月光","纵横" ,"复式激光" ,"辐射","叉型轰炸","地毯式轰炸","火焰包围圈","指向性辐射","高精度轰炸","精准轰炸","高级手雷","激光",
"手雷","十字斩","不稳定激光","零式切割","无差别轰炸","十字火焰","一闪","斩击","小型轰炸","复苏","强化","急救","增幅","防守契约","进攻契约","眼疾手快","弃牌术",
"隔空取物","攻心","诅咒","绿色守护","圣疗","危险手术","小油灯","油灯","高亮油灯","远景灯","驱散","圣光","敏锐嗅觉","保护","狂夜行动","紧急修复","伏击","皎月",
"虫洞","不稳定虫洞","阻碍","红月","制衡","虚弱","锦囊","销蚀","卡牌风暴","厌无忌-厄月","无间","月弦-孤留月","珠华弄月","新月","凶变-天满月纤","月龙轮尾","月魂炎涡",
"久式第零加护","虚空第四加护","精灵回廊"};
string _description[MAX_CARD] = { "法力+2","摧毁:1行1列" ,"抉择摧毁:[1]随机2列 [2]随机2行" ,"摧毁:长度为5的十和叉","摧毁:两条对角线" ,
"抉择摧毁:[1]5*3 [2]3*5","摧毁:5*5-3*3" ,"抉择摧毁:[1]3*3+上下左右2格 [2]3*3+斜方向2格","摧毁:随机12个未被摧毁的格子(迷雾优先)" ,
"摧毁:随机10个未被摧毁的格子","抉择摧毁:[1]3*3+上下左右1格 [2]3*3+斜对角1格","抉择摧毁:[1]9*1 [2]1*9","摧毁:3*3","抉择摧毁:[1]长度为5的十 [2]长度为5的叉",
"抉择摧毁:[1]随机1列 [2]随机1行","抉择摧毁:[1]7*1 [2]1*7","摧毁:随机9个格子","抉择摧毁:[1]长度为3的十 [2]长度为3的叉","抉择摧毁:[1]5*1 [2]1*5",
"抉择摧毁:[1]3*1 [2]1*3","摧毁:随机4个格子","HP+1","HP+1,最大HP+1","HP+1，最大HP-1","最大MP+1","消耗进攻权+3MP","获得进攻权","抽2张牌","随机弃对手1张牌",
"随机抽对手1张牌","摧毁对手1个心","对手心+1","心-1","HP+1，心-1","HP+1，心+1","抉择照亮:[1]长度为3的十[2]长度为3的叉","照亮:3*3",
"抉择照亮:[1]3*3+上下左右1格 [2]3*3+斜对角1格","照亮:5*5-3*3","照亮:5*5-4角落","照亮:5*5","照亮对手1个心","转移1个被照明的心到迷雾"
,"所有照明格子变为迷雾，打乱所有心","修复2*最大生命值个被摧毁格子，打乱所有心","随机将一张手牌-3费","所有手牌-1费","随机将1个手牌变为0费",
"抽一张牌，该牌的费用-4","随机给对手1张牌+2费","对手所有手牌+1费","抉择[1]我方所有手牌变为5费[2]敌方所有手牌变为5费","敌方最大MP-1","抽3张牌",
"摧毁:所有照明格子","抽4张牌","[连锁]摧毁非损坏格子[结束]摧毁1个心","弃掉所有手牌，抽取等额的牌","照明:10*10",
"随机我方弃1张牌,对方爱心+被弃牌Cost","摧毁:随机3个未被摧毁的格子,使用后该牌不会消失","[连锁]照亮迷雾格子[结束]照亮两个爱心",
"[连锁]摧毁1个心[结束]周围8格没有心","摧毁:随机敌方当前血量次数的长度为3的叉，中心点优先选取非摧毁格子","移除1个被照明的爱心","移除3*3范围内的所有爱心",
"所有手牌费用减半"};

CardList::CardList(){
	CardNumber = 67;
	for (int i = 0; i < CardNumber; i++) {
		card[i].cost = _cost[i];
		card[i].number = _number[i];
		card[i].isattackcard = _isattackcard[i];
		card[i].ischoosecard = _ischoosecard[i];
		card[i].name = _name[i];
		card[i].description = _description[i];
		card[i].id = i;
		card[i].attackrange = _attackrange[i];
		card[i].randpriority = _priority[i];
		card[i].israndcard = _israndcard[i];
		card[i].isstablecard = _isstablecard[i];
		card[i].needchooseline = _needchooseline[i];
		for (int j = 0; j < card[i].attackrange; j++) {
			card[i].dxy[j][0] = _dxy[i][j][0];
			card[i].dxy[j][1] = _dxy[i][j][1];
			if (card[i].ischoosecard) {
				card[i].dxy2[j][0] = _dxy2[i][j][0];
				card[i].dxy2[j][1] = _dxy2[i][j][1];
			}
		}
	}
}

CardList::~CardList(){

}