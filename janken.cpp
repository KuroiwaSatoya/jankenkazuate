#include <iostream>
#include <cstdlib>
#include <ctime>
#define DEBUG
using namespace std;

void JankenChoice(int &playerHand, int &enemyHand) {

	const char* hands[] = { "グー", "チョキ", "パー" };

	srand((unsigned int)time(NULL));

	enemyHand = rand() % 3;

#ifdef DEBUG
	cout << "デバッグしています。: 私の手は " << hands[enemyHand] << "です。";
#endif

	cout << "手を選んでください(1: グー 2: チョキ 3: パー ) > " << endl;
	cin >> playerHand;

	while (playerHand < 1 || playerHand > 3) {
		cout << "1～3の数字を入力してください。\n もう一度選んでください(1: グー 2: チョキ 3: パー )";
		cin >> playerHand;
	}

	playerHand--;

}

bool JankenJudge(int playerHand, int enemyHand)	{

	const char* hands[] = { "グー", "チョキ", "パー" };

	cout << "あなたが選んだ手は" << hands[playerHand] << "です。" << endl;

	cout << "私が選んだ手は" << hands[enemyHand] << "です。" << endl;

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