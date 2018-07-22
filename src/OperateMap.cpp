#include <ctime>
#include <iostream>
#include "Rand.h"
#include "OperateMove.h"
#include "Parameter.h"
using namespace std;

void Initlize(int(&MAP)[MAP_SIZE][MAP_SIZE]) {
	/*��ʼ����ͼMAP*/
	//���ñ���ɫ
	system("COLOR F0");
	//�����������
	srand((int)time(0));
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			MAP[i][j] = 0;
		}
	}
}

void Generate(int(&MAP)[MAP_SIZE][MAP_SIZE]) {
	/*�ڵ�ͼ�����������*/
	//�ж�����2����4
	int randNum[2] = { 2, 4 };
	int chose24;
	if (Rand021() <= 0.5) chose24 = 2;
	else chose24 = 4;

	int noZeroMAP[MAP_SIZE*MAP_SIZE][2], noZeroNum = 0;

	//������0�ĸ��ӱ�������, ����ѡ��һ������
	for (int i = 0; i < MAP_SIZE; i++) {
		for(int j = 0; j < MAP_SIZE; j++) {
			if (MAP[i][j] == 0) {
				noZeroMAP[noZeroNum][0] = i;
				noZeroMAP[noZeroNum][1] = j;
				noZeroNum++;
			}
		}
	}
	if (noZeroNum != 0) {
		int generatePos = RandA2B(0, noZeroNum - 1);
		int x = noZeroMAP[generatePos][0];
		int y = noZeroMAP[generatePos][1];
		MAP[x][y] = chose24;
	}
}

void ShowMap(int(&MAP)[MAP_SIZE][MAP_SIZE], int score) {
	/*�����ͼ*/
	cout << "Now Your Game Map is: " << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (MAP[i][j] == 0) cout << "	" << "-";
			else cout << "	" << MAP[i][j];
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "Now Your Score is: " << score << endl;
	cout << "Plase Move Map(up:w down:s left:a right:d): ";
}

void MoveMap(int(&MAP)[MAP_SIZE][MAP_SIZE], const char command, int &score) {
	/*����ָ���ƶ���ͼ*/
	switch (command) {
	case 'w':
		Move(MAP, 0, 0, score);
		break;
	case 's':
		Move(MAP, 0, MAP_SIZE - 1, score);
		break;
	case 'a':
		Move(MAP, 1, 0, score);
		break;
	default:
		Move(MAP, 1, MAP_SIZE - 1, score);
	}
}

bool IsOver(int(&MAP)[MAP_SIZE][MAP_SIZE]) {
	/*�ж���Ϸ�Ƿ����*/
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (MAP[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
