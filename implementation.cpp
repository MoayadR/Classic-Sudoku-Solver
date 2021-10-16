#include <fstream>

bool isValidRow(int Grid[9][9], int row, int Guess)
{
    for (int columnIndex = 0; columnIndex < 9; columnIndex++)
    {
        if (Grid[row][columnIndex] == Guess)
        {
            return false;
        }
    }
    return true;
}

bool isValidColumn(int Grid[9][9], int column, int Guess)
{
    for (int rowIndex = 0; rowIndex < 9; rowIndex++)
    {
        if (Grid[rowIndex][column] == Guess)
        {
            return false;
        }
    }
    return true;
}

bool isValidBlock(int Grid[9][9], int row, int column, int Guess)
{
    int BlockStartingRow = (row / 3) * 3;
    int BlockStartingColumn = (column / 3) * 3;

    for (int i = BlockStartingRow; i < BlockStartingRow + 3; i++)
    {
        for (int j = BlockStartingColumn; j < BlockStartingColumn + 3; j++)
        {
            if (Grid[i][j] == Guess)
            {
                return false;
            }
        }
    }
    return true;
}

bool isPossible(int Grid[9][9], int row, int column, int Guess)
{
    if (isValidRow(Grid, row, Guess) && isValidColumn(Grid, column, Guess) && isValidBlock(Grid, row, column, Guess))
    {
        return true;
    }
    return false;
}

void PrintBoard(int Grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            std::cout << Grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}

void Solve(int Grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if (Grid[row][column] == 0)
            {
                for (int Guess = 1; Guess <= 9; Guess++)
                {
                    if (isPossible(Grid, row, column, Guess))
                    {
                        Grid[row][column] = Guess;
                        Solve(Grid);
                        Grid[row][column] = 0;
                    }
                }
                return;
            }
        }
    }
    PrintBoard(Grid);
}

void GetFromFile(int (*Grid)[9][9], std::string TextFile)
{
    std::fstream fp(TextFile);

    if (!fp)
    {
        std::cout << "Error , File couldn't be open" << std::endl;
        return;
    }
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            fp >> (*Grid)[row][column];
            if (!fp)
            {
                std::cout << "Error reading file for element " << row << " , " << column << std::endl;
                std::cout<< "Please correct your Board.txt file "<<std::endl;
                std::cout << "The Game will consider the missing input as a blank box" << std::endl;
                return;
            }
        }
    }
}