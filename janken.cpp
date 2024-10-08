#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void JankenChoice(int &playerHand, int &enemyHand) {

	cout << "手を選んでください(1: グー 2: チョキ 3: パー ) > " << endl;
	cin >> playerHand;

	while (playerHand < 1 || playerHand > 3) {
		cout << "1～3の数字を入力してください。\n もう一度選んでください(1: グー 2: チョキ 3: パー )";
		cin >> playerHand;
	}

	playerHand--;

	srand((unsigned int)time(NULL));

	enemyHand = rand() % 3;

}

bool JankenJudge(int playerHand, int enemyHand)	{

	cout << "あなたが選んだ手は";
	switch (playerHand)
	{
	case 0:
		cout << "グーです。" << endl; break;
	case 1:
		cout << "チョキです。" << endl; break;
	case 2:
		cout << "パーです。" << endl; break;

	default:
		cout << "ERROR" << endl; break;
	}

	cout << "私が選んだ手は";
	switch (enemyHand)
	{
	case 0:
		cout << "グーです。" << endl; break;
	case 1:
		cout << "チョキです。" << endl; break;
	case 2:
		cout << "パーです。" << endl; break;

	default:
		cout << "ERROR" << endl; break;
	}

	if (playerHand == enemyHand) {
		cout << "あいこなのでもう1回やります！" << endl;
		return true;
	}
	else if ((playerHand == 0 && enemyHand == 1) ||	
		(playerHand == 1 && enemyHand == 2) ||
		(playerHand == 2 && enemyHand == 0)) {
		cout << "あなたの勝ちです！" << endl;
		return false;
	}
	else {
		cout << "私の勝ちです！" << endl;
		return false;
	}
}

void StartJankenGame() {

	int playerHand = -1;
	int enemyHand = -1;
	bool draw = true;
	
	while (draw) {
		JankenChoice(playerHand, enemyHand);
		if ((playerHand < 0 || playerHand > 2)
			&& (enemyHand < 0 || enemyHand > 2)) {
			cout << "ERROR" << endl;
		}
		else
		{
			draw = JankenJudge(playerHand, enemyHand);
		}
	}
}