

#include "Parameter.h"

void Move(int(&MAP)[MAP_SIZE][MAP_SIZE], int direction, int position, int &score);
void DeleteZero(int(&MAP)[MAP_SIZE][MAP_SIZE], int position);
void Transpose(int(&MAP)[MAP_SIZE][MAP_SIZE]);
void SwapElement(int &A, int &B);
