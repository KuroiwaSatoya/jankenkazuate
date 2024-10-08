#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void KazuateChoice(int& playerNumber, int& enemyNumber) {

	cout << "推測している数を1～100まで選んでください > " << endl;
	cin >> playerNumber;

	while (playerNumber < 1 || playerNumber > 100) {
		cout << "1～100の数字を入力してください。\n もう一度選んでください。";
		cin >> playerNumber;
	}

	srand((unsigned int)time(NULL));

	enemyNumber = rand() % 100 + 1;

}

bool KazuateJudge(int playerNumber, int enemyNumber) {

	if (playerNumber == enemyNumber) {
		cout << "正解！" << endl;
		return false;
	}
	else if (playerNumber > enemyNumber) {
		cout << "もっと小さいです。" << endl;
		return true;
	}
	else {
		cout << "もっと大きいです。" << endl;
	}
}

void StartKazuateGame() {

	int playerNumber = -1;
	int enemyNumber = -1;
	bool draw = true;

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