#include "implementation.cpp"

bool isValidRow(int[9][9], int, int);

bool isValidColumn(int[9][9], int, int);

bool isValidBlock(int[9][9], int, int, int);

bool isPossible(int[9][9], int, int, int);

void PrintBoard(int[9][9]);

void Solve(int[9][9]);

void GetFromFile(int *[9][9], std::string);
