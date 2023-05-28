#pragma once
#include"stdafx.h"

class Place
{
public:
	int state;//0 - 2分别代表该格子为迷雾状态，照明状态，被摧毁状态
	bool has_heart;//true代表此格子有心，false代表此格子没有心
	char showplacedata();//用于返回该格子中的内容
	Place();
	~Place();
};

