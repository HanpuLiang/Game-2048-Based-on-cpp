#include <iostream>
#include <cstdlib>
#include "Parameter.h"
using namespace std;

void Move(int(&MAP)[MAP_SIZE][MAP_SIZE], int direction, int position, int &score) {
	/*��ֱ�ƶ��ϲ�*/
	//��������
	void DeleteZero(int(&MAP)[MAP_SIZE][MAP_SIZE], int position);
	void Transpose(int(&MAP)[MAP_SIZE][MAP_SIZE]);

	//�����ˮƽ�����ϵĻ�, ��ת��
	if (direction == 1) {
		Transpose(MAP);
	}

	//�����ƶ����и���,���俿��һ��
	DeleteZero(MAP, position);

	for (int j = 0; j < MAP_SIZE; j++) {
		int start = abs(MAP_SIZE - 1 - position);
		int curPos = -start;
		//�ϲ�
		while (curPos-start < MAP_SIZE-1) {
			int cur = MAP[abs(curPos)][j];
			int next = abs(curPos + 1);
			if ((cur != 0) && (cur == MAP[next][j])) {
				MAP[next][j] = 0;
				MAP[abs(curPos)][j] *= 2;
				curPos += 2;
				score++;
			}
			else {
				curPos++;
			}
		}
	}

	//������ϲ������Ŀ�λ
	DeleteZero(MAP, position);

	//�����ˮƽ�����ϵĻ�, �����ת��һ��
	if (direction == 1) {
		Transpose(MAP);
	}
}

void DeleteZero(int(&MAP)[MAP_SIZE][MAP_SIZE], int position) {
	/*�ƶ���ͼ(��ֱ�ƶ�)�����еĿ�£, ��ɾ��0*/
	for (int j = 0; j < MAP_SIZE; j++) {
		for (int i = 0 - position; i < MAP_SIZE - 1 - position; i++) {
			if (MAP[abs(i)][j] == 0) {
				//�ҵ���i�����һ����Ϊ0�����꣬Ȼ��������ǰλ��
				for (int zeroPos = i + 1; zeroPos < MAP_SIZE - position; zeroPos++) {
					if (MAP[abs(zeroPos)][j] != 0) {
						MAP[abs(i)][j] = MAP[abs(zeroPos)][j];
						MAP[abs(zeroPos)][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void Transpose(int(&MAP)[MAP_SIZE][MAP_SIZE]) {
	/*�Ե�ͼ����ת��
	�е�0תΪ�е�0, �е�0תΪ�е�0*/
	void SwapElement(int &A, int &B);

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < i; j++) {
			SwapElement(MAP[i][j], MAP[j][i]);
		}
	}
}

void SwapElement(int &A, int &B) {
	/*��������Ԫ��*/
	int temp = A;
	A = B;
	B = temp;
}