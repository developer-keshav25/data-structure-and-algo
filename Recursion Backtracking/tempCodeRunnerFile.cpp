#include <iostream>
#include <vector>
using namespace std;

void PrintKnightsTour(vector<vector<int>> cboard, int row, int col, int mov)
{
    if (row < 0 || col < 0 || row >= cboard.size() || col >= cboard.size() || cboard[row][col] !=-1)
    {
        return;
    }
    else if (mov = cboard.size() * cboard.size())
    {
        cboard[row][col] = mov;
        for (int i = 0; i < cboard.size(); i++)
        {
            for (int j = 0; j < cboard[0].size(); j++)
            {
                cout << cboard[i][j] << " ";
            }
            cout << '\n';
        }
        cboard[row][col] = 0;
        return;
    }
    else{
    cboard[row][col] = mov;
    PrintKnightsTour(cboard, row - 2, col + 1, mov + 1);
    PrintKnightsTour(cboard, row - 1, col + 2, mov + 1);
    PrintKnightsTour(cboard, row + 1, col + 2, mov + 1);
    PrintKnightsTour(cboard, row + 2, col + 1, mov + 1);
    PrintKnightsTour(cboard, row + 2, col - 1, mov + 1);
    PrintKnightsTour(cboard, row + 1, col - 2, mov + 1);
    PrintKnightsTour(cboard, row - 1, col - 2, mov + 1);
    PrintKnightsTour(cboard, row - 2, col - 1, mov + 1);
    cboard[row][col] = 0;
    }
}
int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> cboard(n, vector<int>(n, 0));
    PrintKnightsTour(cboard, r, c, -1);
    return 0;
}