#include "CardBag.h"

CardBag::CardBag(bool ismainbag) {
	srand((unsigned)time(NULL));
	MAX_NUMBER = 10;
	vector<int>card_id;
	vector<int>temp;
	if (ismainbag) {
		cards.push_back(card[0]);
		for (int i = 1; i < CardNumber; i++) {
			for (int j = 0; j < card[i].number; j++) {
				card_id.push_back(i);
			}
		}
		MAX_NUMBER = card_id.size();
		for (int i = MAX_NUMBER; i > 0; i--) {
			int a = rand() % i;
			temp.push_back(card_id[a]);
			card_id.erase(card_id.begin() + a);
		}
		for (int i = MAX_NUMBER; i > 0; i--) {
			int a = rand() % i;
			cards.push_back(card[temp[a]]);
			temp.erase(temp.begin() + a);
		}
	}
}

CardBag::~CardBag() {
	
}

void CardBag::showcards(Player& player) {
	cout << "剩余牌数:" << cards.size() << endl;
	for (int i = 0;i<cards.size();i++) {
		cout << "id:" << i;
		cards[i].display(player);
	}
}

int CardBag::getcardchoose(Player& me) {
	int choice = -2;
	while (choice < -1 || choice >= cards.size()) {
		cout << "输入卡的id(-1退出选卡):";
		cin >> choice;
		if (choice == -1) {
			return -1;
		}
		else if (choice < 0 || choice >= cards.size()) {
			cout << "卡牌编号不存在，请重新选择" << endl;
		}
		else if (!cards[choice].Canuse(me)) {
			cout << "卡牌不可使用，请重新选择" << endl;
			choice = -2;
		}
		else {
			return choice;
		}
	}
}

void CardBag::getcard(CardBag& systemcard, int number) {
	for (int i = 0; i < number; i++) {
		cards.push_back(*(systemcard.cards.end() - 1));
		systemcard.losecard(-1);
	}
}

void CardBag::losecard(int option) {
	if (option == -1) {
		cards.pop_back();
	}
	else {
		cards.erase(cards.begin() + option);
	}
}

void CardBag::getlastcard(CardBag& systemcard) {
	cards.push_back(systemcard.cards[0]);
	systemcard.cards.erase(systemcard.cards.begin());
}

int CardBag::getcardnumber() {
	return cards.size();
}