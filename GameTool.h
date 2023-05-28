#pragma once
#include"stdafx.h"

class Player;
class GameTool
{
public:
	int getindex(string,int);//获取玩家选择的行号和列号 0取一个点 1取一列 2取一行
	int getchoose(string,int,int);//获取选择的编号参数分别为文本 左边界闭 右边界闭
	GameTool();
	~GameTool();
};

