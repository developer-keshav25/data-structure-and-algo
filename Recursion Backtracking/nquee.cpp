#include <iostream>
#include <vector>
using namespace std;

bool isitSafePlaceforQueen(vector<vector<int>> cboard, int row, int col)
{
    for (int i = row - 1, j = col; i >= 0; i--)
    {
        if (cboard[i][j] == 1)
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (cboard[i][j] == 1)
            return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < cboard.size(); i--, j++)
    {
        if (cboard[i][j] == 1)
            return false;
    }
    return true;
}
void printNQueen(vector<vector<int>> cboard, string qsf, int row)
{
    if (row == cboard.size())
    {
        cout << qsf << '.' << endl;
        return;
    }
    for (int col = 0; col < cboard.size(); col++)
    {
        if (isitSafePlaceforQueen(cboard, row, col))
        {
            cboard[row][col] = 1;
            printNQueen(cboard, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            cboard[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cboard(n, vector<int>(n, 0));
    printNQueen(cboard, "", 0);

    return 0;
}