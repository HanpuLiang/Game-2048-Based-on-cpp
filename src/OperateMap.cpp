#include <ctime>
#include <iostream>
#include "Rand.h"
#include "OperateMove.h"
#include "Parameter.h"
using namespace std;

void Initlize(int(&MAP)[MAP_SIZE][MAP_SIZE]) {
	/*初始化地图MAP*/
	//设置背景色
	system("COLOR F0");
	//设置随机种子
	srand((int)time(0));
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			MAP[i][j] = 0;
		}
	}
}

void Generate(int(&MAP)[MAP_SIZE][MAP_SIZE]) {
	/*在地图中生成随机数*/
	//判断生成2还是4
	int randNum[2] = { 2, 4 };
	int chose24;
	if (Rand021() <= 0.5) chose24 = 2;
	else chose24 = 4;

	int noZeroMAP[MAP_SIZE*MAP_SIZE][2], noZeroNum = 0;

	//将不是0的格子保存下来, 从中选出一个生成
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
	/*输出地图*/
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
	/*根据指令移动地图*/
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
	/*判断游戏是否结束*/
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (MAP[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
