#include "Player.h"
Player::Player(CardBag& systemcard,bool islast) {
	mycard = new CardBag(false);
	MAX_HP = 5;
	HP = 5;
	MAX_MP = 0;
	MP = 0;
	attack = false;
	string temp_name;
	do {
		cout << "请给你的角色起个名吧(名字长度不能超过8):" ;
		cin >> temp_name;
	}while(temp_name.size() > 8);
	name = temp_name;
	cout << "命名成功:" << name << endl;
	if (islast) {
		getlastcard(systemcard);
		getmycard(systemcard, 4);
	}
	else {
		getmycard(systemcard, 3);
	}
	SC;
}

Player::~Player() {

}

void Player::action(Player &enemy,CardBag& systemcard) {
	if (!isalive()) {
		return;
	}
	preattack(systemcard);
	while (true) {
		show_gamedata(enemy, systemcard);
		int choice = tool.getchoose("[0]结束回合\n[1]普通攻击\n[2]使用卡牌\n输入你想执行的编号:", 0, 2);
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			normalattack(enemy);
		}
		else {
			mycard->showcards(*this);
			int choice = mycard->getcardchoose(*this);
			if (choice != -1) {
				mycard->cards[choice].Beat(enemy, *this,systemcard, choice);
			}
		}
		SC;
	}
	roundover();
	SC;
}

bool Player::isalive() {
	return HP > 0;
}

void Player::show_player() {
	cout << "[" << name << "]" << "HP:" << HP << "/" << MAX_HP << " MP:" << MP << "/" << MAX_MP << " 进攻:" << (attack ? "[O]" : "[X]") <<
		" 剩余爱心:" << places.livenumber << endl;
	places.showplacesdata();
}

void Player::show_enemy(Player& enemy) {
	enemy.show_player();
}

void Player::show_gamedata(Player& enemy,CardBag& systemcard) {
	cout << "系统剩余牌数:" << systemcard.getcardnumber() << endl;
	show_player();
	show_enemy(enemy);
	cout << "轮到[" << name << "]了!" << endl;
}

void Player::beattacked(int i, int j,int kind) {
	if (i < 0 || i > 9 || j < 0 || j > 9) {
		return;
	}
	if (kind == 1) {
		if (places.place[i][j].state == 0) {
			places.place[i][j].state = 1;
		}
	}
	else if (kind == 2) {
		places.place[i][j].state = 2;
		if (places.place[i][j].has_heart) {
			places.place[i][j].has_heart = false;
			HP--;
			cout << "[" << name << "]受到1点伤害" << endl;
			places.livenumber--;
			SLEEP;
		}
	}
}

void Player::updateMP(){
	if (MAX_MP < 10) {
		MAX_MP++;
	}
	MP = MAX_MP;
}

void Player::showmycard() {
	mycard->showcards(*this);
}

void Player::usemycard() {
	showmycard();
	mycard->getcardchoose(*this);
}

void Player::winlose(Player& enemy) {
	cout << "------对战结果------" << endl;
	cout << "[" << name << "]" << "胜利!" << endl;
	cout << "[" << enemy.name << "]" << "失败!" << endl;
}

void Player::getmycard(CardBag& systemcard,int number) {
	mycard->getcard(systemcard,number);
};

void Player::losemycard(int option) {
	mycard->losecard(option);
}

void Player::preattack(CardBag& systemcard) {
	updateMP();
	attack = true;
	getmycard(systemcard, 1);
}

void Player::normalattack(Player& enemy) {
	if (!attack) {
		cout << "本回合不能再攻击了!" << endl;
		return;
	}
	int temp = tool.getindex(enemy.name, 0);
	enemy.beattacked(temp / 10, temp % 10, 2);
	attack = false;
}

void Player::getMP(int number, int maxnumber) {
	if (MAX_MP + maxnumber > 10){
		MAX_MP = 10;
	}
	else {
		MAX_MP += maxnumber;
	}
	MP += number;
}

void Player::getHP(int number,int maxnumber) {
	MAX_HP += maxnumber;
	if (HP + number <= MAX_HP) {
		HP += number;
	}
	else {
		HP = MAX_HP;
	}
}

void Player::getlastcard(CardBag& systemcard) {
	systemcard.getlastcard(systemcard);
}

void Player::roundover() {
	MP = 0;
	attack = false;
}