#include <iostream>
#include "janken.h"
#include "kazuate.h"
using namespace std;

int main() {

	char playAgain = 'y';
	int gameChoice = -1;

	if (playAgain == 'y' || playAgain == 'Y') {

		while (true) {

			cout << "����񂯂�Q�[������肽���ꍇ��1�A�����ăQ�[��������ꍇ��2��I�����Ă��������B > "
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
			cout << "������x�v���C���܂����H(�͂�: y ������: n)" << endl;
			cin >> playAgain;
		}
	}
	else {
		cout << "�v���O�������I�����܂��B" << endl;
		return 0;
	}

}