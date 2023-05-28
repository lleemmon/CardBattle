#include "Gamecenter.h"

Gamecenter::Gamecenter() {
	systemcard = new CardBag(true);
    player1 = new Player(*systemcard, false);
    player2 = new Player(*systemcard, true);
}

Gamecenter::~Gamecenter() {

}

void Gamecenter::battle(){
    while (player1->isalive() && player2->isalive()) {
        player1->action(*player2, *systemcard);
        player2->action(*player1, *systemcard);
    }
    if (player1->isalive()) {
        player1->winlose(*player2);
    }
    else {
        player2->winlose(*player1);
    }
}
