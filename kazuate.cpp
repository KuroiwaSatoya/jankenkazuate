#include <iostream>
#include <cstdlib>
#include <ctime>
#define DEBUG
using namespace std;

void KazuateChoice(int& playerNumber, int& enemyNumber) {

	cout << "�������Ă��鐔��1�`100�܂őI��ł������� > " << endl;
	cin >> playerNumber;

	while (playerNumber < 1 || playerNumber > 100) {
		cout << "1�`100�̐�������͂��Ă��������B\n ������x�I��ł��������B";
		cin >> playerNumber;
	}

}

bool KazuateJudge(int playerNumber, int enemyNumber) {

	if (playerNumber == enemyNumber) {
		cout << "�����I" << endl;
		return false;
	}
	else if (playerNumber > enemyNumber) {
		cout << "�����Ə������ł��B" << endl;
		return true;
	}
	else {
		cout << "�����Ƒ傫���ł��B" << endl;
	}
}

void StartKazuateGame() {

	int playerNumber = -1;
	int enemyNumber = -1;
	bool draw = true;

	srand((unsigned int)time(NULL));

	enemyNumber = rand() % 100 + 1;

#ifdef DEBUG
	cout << "DEBUG: ���̎�� " << enemyNumber << "�ł��B";
#endif

	while (draw) {
		KazuateChoice(playerNumber, enemyNumber);
		if ((playerNumber < 1 || playerNumber > 100)
			&& (enemyNumber < 1 || enemyNumber > 100)) {
			cout << "ERROR" << endl;
		}
		else
		{
			draw = KazuateJudge(playerNumber, enemyNumber);
		}
	}
}