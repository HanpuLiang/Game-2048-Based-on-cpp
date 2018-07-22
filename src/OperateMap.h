
#include "Parameter.h"

void Initlize(int(&MAP)[MAP_SIZE][MAP_SIZE]);
void Generate(int(&MAP)[MAP_SIZE][MAP_SIZE]);
void ShowMap(int(&MAP)[MAP_SIZE][MAP_SIZE], int score);
void MoveMap(int(&MAP)[MAP_SIZE][MAP_SIZE], const char command, int &score);
bool IsOver(int(&MAP)[MAP_SIZE][MAP_SIZE]);