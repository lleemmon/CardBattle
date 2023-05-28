#include "Place.h"
Place::Place() {
	state = 0;
	has_heart = false;
}

Place::~Place(){

}

char Place::showplacedata(){
	if (state == 0) {
		return 22;
	}
	else if (state == 1) {
		if (has_heart) {
			return '*';
		}
		else {
			return ' ';
		}
	}
	else {
		return 'X';
	}
}
