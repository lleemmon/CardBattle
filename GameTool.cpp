#include "GameTool.h"
#include"Player.h"

GameTool::GameTool() {

}

GameTool::~GameTool() {

}

int GameTool::getindex(string enemyname,int kind) {
	int row = 0;
	int col = 0;
	if (kind == 0 || kind == 2) {
		row = getchoose("Ҫ����[" + enemyname + "]����һ��:", 0, 9);
	}
	if (kind == 0 || kind == 1) {
		col = getchoose("Ҫ����[" + enemyname + "]����һ��:", 0, 9);
	}
	return row * 10 + col;
}

int GameTool::getchoose(string text,int left,int right) {
	int choice = -1;
	while (choice < left || choice > right) {
		cout << text;
		cin >> choice;
	}
	return choice;
}