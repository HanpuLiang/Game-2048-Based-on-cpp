#include <iostream>
#include <Windows.h>
#include "OperateMap.h"
#include "Parameter.h"
using namespace std;

int MAP[MAP_SIZE][MAP_SIZE];


int main() {
    //初始化地图
    Initlize(MAP);
    bool isFull = false;
	int score = 0;
    while (!isFull) {
		//刷新窗口
		system("cls");
        //生成数字
        Generate(MAP);
        //显示地图
		ShowMap(MAP, score);
        //输入指令
        char command;
        cin >> command;
        //移动地图
        MoveMap(MAP, command, score);
        //是否结束？
        isFull = IsOver(MAP);
    }
	cout << "GAME OVER" << endl;
	system("pause");
    return 0;
}
