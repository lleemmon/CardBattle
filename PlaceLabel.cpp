#include "PlaceLabel.h"

PlaceLabel::PlaceLabel(){
	srand((unsigned)time(NULL));
	livenumber = 0;
	while (livenumber < 10) {
		int c = rand() % 100;
		if (place[c / 10][c % 10].has_heart == false) {
			place[c / 10][c % 10].has_heart = true;
			livenumber++;
		}
	}
}

void PlaceLabel::showplacesdata() {
	cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i;
		for (int j = 0; j < 10; j++) {
			cout << place[i][j].showplacedata() << " ";
		}
		cout << endl;
	}
}