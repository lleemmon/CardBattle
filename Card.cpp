#include "Player.h"
#include "Card.h"
#include"CardBag.h"

Card::Card(){

}

Card::~Card() {

}

void Card::Beat(Player& enemy,Player& player,CardBag& systemcard,int choice) {
	srand((unsigned)time(NULL));
	if (isattackcard) {
		if (!player.attack && isattackcard == 2) {
			return; 
		}
		player.MP -= player.mycard->cards[choice].cost;
		if (id == 25) {
			change_MP(player, 3, 0);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
		else if (id == 56) {
			skill_1_eyue(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
		else if (id == 58) {
			skill_2_guliuyue(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
		else if (id == 61) {
			skill_4_tianmanyueqian(enemy);
			player.losemycard(choice);
		}
		else if (id == 62) {
			skill_5_yuelonglunwei(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
		else if (id == 63) {
			skill_6_yuehunyanwo(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
		else if (israndcard) {
			randBeat(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			if (id != 60) {
				player.losemycard(choice);
			}
		}
		else if (isstablecard) {
			stableBeat(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
		else{
			RangeBeat(enemy);
			if (isattackcard == 2) {
				player.attack = false;
			}
			player.losemycard(choice);
		}
	}
	else {
		player.MP -= player.mycard->cards[choice].cost;
		if (id == 0) {
			change_MP(player, 2, 0);
			player.losemycard(choice);
		}
		else if (id == 21) {
			change_HP(player, 1, 0);
			player.losemycard(choice);
		}
		else if (id == 22) {
			change_HP(player, 1, 1);
			player.losemycard(choice);
		}
		else if (id == 23) {
			change_HP(player, 1, -1);
			player.losemycard(choice);
		}
		else if (id == 24) {
			change_MP(player, 0, 1);
			player.losemycard(choice);
		}
		else if (id == 26) {
			player.attack = true;
			player.losemycard(choice);
		}
		else if (id == 27) {
			player.getmycard(systemcard, 2);
			player.losemycard(choice);
		}
		else if (id == 28) {
			if (!enemy.mycard->cards.empty()) {
				int choice = 100 % enemy.mycard->cards.size();
				enemy.losemycard(choice);
			}
			player.losemycard(choice);
		}
		else if (id == 29) {
			if (!enemy.mycard->cards.empty()) {
				player.getmycard(*enemy.mycard, 1);
			}
			player.losemycard(choice);
		}
		else if (id == 31) {
			add_a_life(enemy, 1);
			player.losemycard(choice);
		}
		else if (id == 32) {
			add_a_life(player, -1);
			player.losemycard(choice);
		}
		else if (id == 33) {
			change_HP(player, 1, 0);
			add_a_life(player, -1);
			player.losemycard(choice);
		}
		else if (id == 34) {
			change_HP(player, 1, 0);
			add_a_life(player, 1);
			player.losemycard(choice);
		}
		else if (id == 42) {
			move_life(player);
			player.losemycard(choice);
		}
		else if (id == 43) {
			bedark(player);
			move_all_live(player);
			player.losemycard(choice);
		}
		else if (id == 44) {
			cleanruin(player);
			move_all_live(player);
			player.losemycard(choice);
		}
		else if (id == 45) {
			change_cost(player, 3, false,choice);
			player.losemycard(choice);
		}
		else if (id == 46) {
			change_cost(player, 1, true,choice);
			player.losemycard(choice);
		}
		else if (id == 47) {
			change_cost(player, 100, false,choice);
			player.losemycard(choice);
		}
		else if (id == 48) {
			player.getmycard(systemcard, 1);
			player.mycard->cards.back().cost -= 4;
			if (player.mycard->cards.back().cost < 0) {
				player.mycard->cards.back().cost = 0;
			}
			player.losemycard(choice);
		}
		else if (id == 49) {
			change_cost(enemy, -2, false);
			player.losemycard(choice);
		}
		else if (id == 50) {
			change_cost(enemy, -1, true);
			player.losemycard(choice);
		}
		else if (id == 51) {
			int choices = tool.getchoose("发动什么技能？[1][2]:", 1, 2);
			if (choices == 1) {
				change_cost(player, 5);
			}
			else {
				change_cost(enemy, 5);
			}
			player.losemycard(choice);
		}
		else if (id == 52) {
			change_MP(enemy, 0, -1);
			player.losemycard(choice);
		}
		else if (id == 53) {
			player.getmycard(systemcard, 3);
			player.losemycard(choice);
		}
		else if (id == 54) {
			attack_light(enemy);
			player.losemycard(choice);
		}
		else if (id == 55) {
			player.getmycard(systemcard, 4);
			player.losemycard(choice);
		}
		else if (id == 57) {
			int k = player.mycard->cards.size() - 1;
			player.mycard->cards.clear();
			player.getmycard(systemcard, k);
		}
		else if (id == 59) {
			player.losemycard(choice);
			skill_3_zhuhuanongyue(enemy);
		}
		else if (id == 64) {
			remove_life(player);
			player.losemycard(choice);
		}
		else if (id == 65) {
			remove_life_range(player);
			player.losemycard(choice);
		}
		else if (id == 66) {
			change_cost(player);
			player.losemycard(choice);
		}
	}
}

void Card::display(Player& player){
	cout << (Canuse(player) ? "[O]" : "[X]") << "[" << cost << "][" << (isattackcard == 2 ? "攻][" : "法][") << name << "]" << description << endl;
}

bool Card::Canuse(Player& player) {
	if ((isattackcard == 2)&& !player.attack) { 
		return false; 
	}
	if (cost > player.MP) {
		return false;
	}
	return true;
}

void Card::RangeBeat(Player& enemy) {
	if (ischoosecard) {
		int choice = tool.getchoose("发动什么技能？[1][2]:", 1, 2);
		int temp;
		if (needchooseline) {
			temp = tool.getindex(enemy.name, choice);
		}
		else {
			temp = tool.getindex(enemy.name, 0);
		}
		int row = temp / 10;
		int col = temp % 10;
		rangedamage(enemy, row, col,choice);
	}
	else {
		int temp = tool.getindex(enemy.name, 0);
		int row = temp / 10;
		int col = temp % 10;
		rangedamage(enemy, row, col, 1);
	}
}

void Card::randBeat(Player& enemy) {
	srand((unsigned)time(NULL));
	if (israndcard == 2) {
		randdamage_line(enemy);
	}
	else {
		if (randpriority == 4){
			randdamage_4(enemy);
		}
		else if (randpriority == 3) {
			randdamage_3(enemy);
		}
		else if (randpriority == 2) {
			randdamage_2(enemy);
		}
		else {
			randdamage_1(enemy);
		}
	}
}

void Card::stableBeat(Player &enemy) {
	for (int i = 0; i < attackrange; i++) {
		enemy.beattacked(dxy[i][0], dxy[i][1], isattackcard);
	}
}

void Card::rangedamage(Player& enemy,int row,int col,int flag) {
	if (flag == 1) {
		for (int i = 0; i < attackrange; i++) {
			enemy.beattacked(row + dxy[i][0], col + dxy[i][1], isattackcard);
		}
	}
	else {
		for (int i = 0; i < attackrange; i++) {
			enemy.beattacked(row + dxy2[i][0], col + dxy2[i][1], isattackcard);
		}
	}
}

void Card::randdamage_4(Player& enemy) {
	vector<int>live;
	for (int i = 0; i <= 99; i++) {
		if (enemy.places.place[i / 10][i % 10].has_heart) {
			live.push_back(i);
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < attackrange; i++) {
		if (!live.empty()) {
			int a = rand() % live.size();
			enemy.beattacked(live[a] / 10, live[a] % 10, isattackcard);
			live.erase(live.begin() + a);
		}
		else {
			return;
		}
	}
}

void Card::randdamage_3(Player& enemy) {
	vector<int>dark, light;
	for (int i = 0; i <= 99; i++){
		if ((enemy.places.place[i / 10][i % 10].state == 0)||(enemy.places.place[i / 10][i % 10].has_heart)) {
			dark.push_back(i);
		}
		else if (enemy.places.place[i / 10][i % 10].state == 1) {
			light.push_back(i);
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < attackrange; i++) {
		if (!dark.empty()) {
			int a = rand() % dark.size();
			enemy.beattacked(dark[a] / 10, dark[a] % 10, isattackcard);
			dark.erase(dark.begin() + a);
		}
		else if (!light.empty()) {
			int a = rand() % light.size();
			enemy.beattacked(light[a] / 10, light[a] % 10, isattackcard);
			light.erase(light.begin() + a);
		}
		else {
			return;
		}
	}
}

void Card::randdamage_2(Player& enemy) {
	vector<int>noruin;
	for (int i = 0; i <= 99; i++) {
		if (enemy.places.place[i / 10][i % 10].state != 2) {
			noruin.push_back(i);
		}
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < attackrange; i++) {
		if (noruin.empty()) {
			return;
		}
		int a = rand() % noruin.size();
		enemy.beattacked(noruin[a] / 10, noruin[a] % 10, isattackcard);
		noruin.erase(noruin.begin() + a);
	}
}

void Card::randdamage_1(Player& enemy) {
	vector<int>all;
	for (int i = 0; i <= 99; i++) {
		all.push_back(i);
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < attackrange; i++) {
		int a = rand() % all.size();
		enemy.beattacked(all[a] / 10, all[a] % 10, isattackcard);
		all.erase(all.begin() + a);
	}
}

void Card::randdamage_line(Player& enemy) {
	if (ischoosecard) {
		int choice = tool.getchoose("发动什么技能？[1][2]:", 1, 2);
		randdamage_line_1(enemy, choice);
	}
	else {
		randdamage_line_1(enemy, 1);
	}
}

void Card::randdamage_line_1(Player& enemy,int choice) {
	srand((unsigned)time(NULL));
	vector<int>all;
	for (int i = 0; i < 10; i++) {
		all.push_back(i);
	}
	if (choice == 1) {
		for (int i = 0; i < attackrange; i++) {
			int a = rand() % all.size();
			for (int j = 0; j < 10; j++) {
				enemy.beattacked(j, all[a],2);
			}
			all.erase(all.begin() + a);
		}
	}
	else {
		for (int i = 0; i < attackrange; i++) {
			int a = rand() % all.size();
			for (int j = 0; j < 10; j++) {
				enemy.beattacked(all[a], j,2);
			}
			all.erase(all.begin() + a);
		}
	}
}

void Card::change_MP(Player& player, int numbers,int maxnumber) {
	player.getMP(numbers, maxnumber);
}

void Card::change_HP(Player& player, int numbers,int maxnumber) {
	player.getHP(numbers, maxnumber);
}

void Card::add_a_life(Player& player,int numbers) {
	srand((unsigned)time(NULL));
	vector<int>nolive,live;
	for (int i = 0; i < 100; i++) {
		if (!(player.places.place[i / 10][i % 10].has_heart) && (player.places.place[i / 10][i % 10].state != 2)) {
			nolive.push_back(i);
		}
		if (player.places.place[i / 10][i % 10].has_heart) {
			live.push_back(i);
		}
	}
	if (numbers > 0) {
		for (int i = 0; i < numbers; i++) {
			int a = rand() % nolive.size();
			player.places.place[nolive[a] / 10][nolive[a] % 10].has_heart = true;
			player.places.livenumber++;
			nolive.erase(nolive.begin() + a);
		}
	}
	else {
		int a = rand() % live.size();
		player.places.place[nolive[a] / 10][nolive[a] % 10].has_heart = false;
		player.places.livenumber--;
	}
}

void Card::move_life(Player& player) {
	vector<int>danger_live;
	vector<int>dark;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		if (player.places.place[i / 10][i % 10].has_heart && (player.places.place[i / 10][i % 10].state == 1)) {
			danger_live.push_back(i);
		}
		if ((!player.places.place[i / 10][i % 10].has_heart)&& (player.places.place[i / 10][i % 10].state == 0)) {
			dark.push_back(i);
		}
	}
	if (danger_live.empty() || dark.empty()) {
		return;
	}
	int a = rand() % danger_live.size();
	player.places.place[danger_live[a] / 10][danger_live[a] % 10].has_heart = false;
	a = rand() % dark.size();
	player.places.place[dark[a] / 10][dark[a] % 10].has_heart = true;
}

void Card::bedark(Player& player) {
	for (int i = 0; i < 100; i++) {
		if (player.places.place[i / 10][i % 10].state == 1) {
			player.places.place[i / 10][i % 10].state = 0;
		}
	}
}

void Card::move_all_live(Player& player) {
	vector<int>noruin;
	int livecount = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		if (player.places.place[i / 10][i % 10].state != 2) {
			noruin.push_back(i);
		}
		if (player.places.place[i / 10][i % 10].has_heart) {
			player.places.place[i / 10][i % 10].has_heart = false;
			livecount++;
		}
	}
	for (int i = 0; i < livecount; i++) {
		int a = rand() % noruin.size();
		player.places.place[noruin[a] / 10][noruin[a] % 10].has_heart = true;
		noruin.erase(noruin.begin() + a);
	}
}

void Card::cleanruin(Player&player) {
	vector<int>ruin;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		if (player.places.place[i / 10][i % 10].state == 2) {
			ruin.push_back(i);
		}
	}
	int count = min(ruin.size(), player.MAX_HP * 2);
	for (int i = 0; i < count; i++) {
		int a = rand() % ruin.size();
		player.places.place[ruin[a] / 10][ruin[a] % 10].state = 0;
		ruin.erase(ruin.begin() + a);
	}
}

void Card::change_cost(Player& player, int numbers, bool flag,int offest) {
	srand((unsigned)time(NULL));
	if (player.mycard->cards.empty()) {
		return;
	}
	if (flag) {
		for (int i = 0; i < player.mycard->cards.size(); i++) {
			player.mycard->cards[i].cost -= numbers;
			if (player.mycard->cards[i].cost < 0) {
				player.mycard->cards[i].cost = 0;
			}
		}
	}
	else {
		vector<int>ver;
		for (int i = 0; i < player.mycard->cards.size(); i++) {
			if (i != offest) {
				ver.push_back(i);
			}
		}
		int a = rand() % ver.size();
		player.mycard->cards[ver[a]].cost -= numbers;
		if (player.mycard->cards[ver[a]].cost < 0) {
			player.mycard->cards[ver[a]].cost = 0;
		}
	}
}

void Card::change_cost(Player& player, int numbers, bool flag) {
	srand((unsigned)time(NULL));
	if (player.mycard->cards.empty()) {
		return;
	}
	if (flag) {
		for (int i = 0; i < player.mycard->cards.size(); i++) {
			player.mycard->cards[i].cost -= numbers;
			if (player.mycard->cards[i].cost < 0) {
				player.mycard->cards[i].cost = 0;
			}
		}
	}
	else {
		int a = rand() % player.mycard->cards.size();
		player.mycard->cards[a].cost -= numbers;
		if (player.mycard->cards[a].cost < 0) {
			player.mycard->cards[a].cost = 0;
		}
	}
}

void Card::change_cost(Player& player, int numbers) {
	if (player.mycard->cards.empty()) {
		return;
	}
	for (int i = 0; i < player.mycard->cards.size(); i++) {
		player.mycard->cards[i].cost = numbers;
	}
}

void Card::attack_light(Player& player){
	for (int i = 0; i < 100; i++) {
		if (player.places.place[i / 10][i % 10].state == 1) {
			player.beattacked(i / 10, i % 10, 2);
		}
	}
}

void Card::skill_1_eyue(Player& enemy) {
	vector<int>noruin;
	for (int i = 0; i <= 99; i++) {
		if (enemy.places.place[i / 10][i % 10].state != 2) {
			noruin.push_back(i);
		}
	}
	srand((unsigned)time(NULL));
	while (true) {
		if (!noruin.empty()) {
			int a = rand() % noruin.size();
			bool flag = enemy.places.place[noruin[a] / 10][noruin[a] % 10].has_heart;
			enemy.beattacked(noruin[a] / 10, noruin[a] % 10, isattackcard);
			if (flag) {
				return;
			}
			noruin.erase(noruin.begin() + a);
		}
		else {
			return;
		}
	}
}

void Card::skill_2_guliuyue(Player& player) {
	for (int i = 0; i < 100; i++) {
		if (player.places.place[i / 10][i % 10].state == 0) {
			player.places.place[i / 10][i % 10].state = 1;
		}
	}
}

void Card::skill_3_zhuhuanongyue(Player& player) {
	srand((unsigned)time(NULL));
	if (player.mycard->cards.empty()) {
		return;
	}
	int a = rand() % player.mycard->cards.size();
	const int k = player.mycard->cards[a].cost;
	player.losemycard(a);
	add_a_life(player,k);
}

void Card::skill_4_tianmanyueqian(Player& enemy) {
	srand((unsigned)time(NULL));
	vector<int>dark;
	for (int i = 0; i <= 99; i++) {
		if (enemy.places.place[i / 10][i % 10].state == 0) {
			dark.push_back(i);
		}
	}
	int k = 0;
	while (k < 2) {
		if (!dark.empty()) {
			int a = rand() % dark.size();
			enemy.beattacked(dark[a] / 10, dark[a] % 10, isattackcard);
			if (enemy.places.place[dark[a] / 10][dark[a] % 10].has_heart) {
				k++;
			}
			dark.erase(dark.begin() + a);
		}
		else {
			return;
		}
	}
}

void Card::skill_5_yuelonglunwei(Player& enemy) {
	srand((unsigned)time(NULL));
	vector<int>live;
	queue<pair<int,int>>q;
	int dx[8] = { -1,1,0,0,-1,-1,1,1 };
	int dy[8] = { 0,0,1,-1,-1,1,-1,1 };	
	for (int i = 0; i <= 99; i++) {
		if (enemy.places.place[i / 10][i % 10].has_heart) {
			live.push_back(i);
		}
	}
	if (live.empty()) {
		return;
	}
	int a = rand() % live.size();
	enemy.beattacked(live[a] / 10, live[a] % 10, isattackcard);
	for (int i = 0; i < 8; i++) {
		int tx = live[a] / 10 + dx[i], ty = live[a] % 10 + dy[i];
		if ((tx >= 0) && (tx <= 9) && (ty >= 0) && (ty <= 9) && enemy.places.place[tx][ty].has_heart) {
			q.push({ tx ,ty });
		}
	}
	while (!q.empty()) {
		int tx = q.front().first, ty = q.front().second;
		enemy.beattacked(tx, ty, isattackcard);
		q.pop();
		for (int i = 0; i < 8; i++) {
			if ((tx + dx[i] >= 0) && (tx + dx[i] <= 9) && (ty + dy[i] >= 0) && (ty + dy[i] <= 9) && enemy.places.place[tx + dx[i]][ty + dy[i]].has_heart) {
				q.push({ tx + dx[i] ,ty + dy[i] });
			}
		}
	}
}

void Card::skill_6_yuehunyanwo(Player& enemy) {
	srand((unsigned)time(NULL));
	int k = enemy.HP;
	int dx[5] = { 0,-1,-1,1,1 };
	int dy[5] = { 0,-1,1,-1,1 };
	vector<int>noruin;
	for (int i = 0; i < 100; i++) {
		if (enemy.places.place[i / 10][i % 10].state != 2) {
			noruin.push_back(i);
		}
	}
	for (int j = 0; j < k; j++) {
		int a = rand() % noruin.size();
		while (enemy.places.place[noruin[a] / 10][noruin[a] % 10].state == 2) {
			if (noruin.empty()) {
				return;
			}
			noruin.erase(noruin.begin() + a);
			a = rand() % noruin.size();
		}
		for (int s = 0; s < 5; s++) {
			enemy.beattacked(noruin[a] / 10 + dx[s], noruin[a] % 10 + dy[s], isattackcard);
		}
	}
}

void Card::remove_life(Player& player) {
	srand((unsigned)time(NULL));
	vector<int>lightlive;
	for (int i = 0; i < 100; i++) {
		if ((player.places.place[i / 10][i % 10].state == 1)&&(player.places.place[i / 10][i % 10].has_heart)) {
			lightlive.push_back(i);
		}
	}
	if (lightlive.empty()) {
		return;
	}
	int a = rand() % lightlive.size();
	player.places.place[lightlive[a] / 10][lightlive[a] % 10].has_heart = false;
	player.places.livenumber--;
}

void Card::remove_life_range(Player& player) {
	int row = tool.getchoose("要选择哪一行:", 0, 9);
	int col = tool.getchoose("要选择哪一列:", 0, 9);
	for (int i = 0; i < attackrange; i++) {
		int tx = row + dxy[i][0];
		int ty = col + dxy[i][1];
		if (tx>=0&&tx<=9&&ty>=0&&ty<=9&&player.places.place[tx][ty].has_heart) {
			player.places.place[tx][ty].has_heart = false;
			player.places.livenumber--;
		}
	}
}

void Card::change_cost(Player& player) {
	if (player.mycard->cards.empty()) {
		return;
	}
	for (int i = 0; i < player.mycard->cards.size(); i++) {
		player.mycard->cards[i].cost /= 2;
	}
}