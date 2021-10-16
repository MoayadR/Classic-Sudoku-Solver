#include <iostream>
#include <fstream>
#include "Header.h"

int Grid[9][9];

int main()
{
    GetFromFile(&Grid, "Board.txt");
    Solve(Grid);

    return 0;
}
