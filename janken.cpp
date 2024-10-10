#include <iostream>
#include <cstdlib>
#include <ctime>
#define DEBUG
using namespace std;

void JankenChoice(int &playerHand, int &enemyHand) {

	const char* hands[] = { "�O�[", "�`���L", "�p�[" };

	srand((unsigned int)time(NULL));

	enemyHand = rand() % 3;

#ifdef DEBUG
	cout << "�f�o�b�O���Ă��܂��B: ���̎�� " << hands[enemyHand] << "�ł��B";
#endif

	cout << "���I��ł�������(1: �O�[ 2: �`���L 3: �p�[ ) > " << endl;
	cin >> playerHand;

	while (playerHand < 1 || playerHand > 3) {
		cout << "1�`3�̐�������͂��Ă��������B\n ������x�I��ł�������(1: �O�[ 2: �`���L 3: �p�[ )";
		cin >> playerHand;
	}

	playerHand--;

}

bool JankenJudge(int playerHand, int enemyHand)	{

	const char* hands[] = { "�O�[", "�`���L", "�p�[" };

	cout << "���Ȃ����I�񂾎��" << hands[playerHand] << "�ł��B" << endl;

	cout << "�����I�񂾎��" << hands[enemyHand] << "�ł��B" << endl;

	if (playerHand == enemyHand) {
		cout << "�������Ȃ̂ł���1����܂��I" << endl;
		return true;
	}
	else if ((playerHand == 0 && enemyHand == 1) ||	
		(playerHand == 1 && enemyHand == 2) ||
		(playerHand == 2 && enemyHand == 0)) {
		cout << "���Ȃ��̏����ł��I" << endl;
		return false;
	}
	else {
		cout << "���̏����ł��I" << endl;
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