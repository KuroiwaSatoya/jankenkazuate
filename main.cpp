#include <iostream>
#include "janken.h"
#include "kazuate.h"
using namespace std;

int main() {

	char playAgain = 'y';
	int gameChoice = -1;

	if (playAgain == 'y' || playAgain == 'Y') {

		while (true) {

			cout << "じゃんけんゲームがやりたい場合は1、数当てゲームをする場合は2を選択してください。 > "
				<< endl;
			cin >> gameChoice;

			switch (gameChoice) {
			case 1:
				StartJankenGame(); break;
			case 2:
				StartKazuateGame(); break;
			default:
				cout << "ERROR" << endl; break;
			}
			cout << "もう一度プレイしますか？(はい: y いいえ: n)" << endl;
			cin >> playAgain;
		}
	}
	else {
		cout << "プログラムを終了します。" << endl;
		return 0;
	}

}