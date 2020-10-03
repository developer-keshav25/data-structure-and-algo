#include <iostream>
#include <vector>
using namespace std;

void PrintKnightsTour(int** cboard, int row, int col, int mov,int n)
{
    if (row < 0 || col < 0 || row >= n || col >= n || cboard[row][col] !=-1)
    {
        return;
    }
    else if (mov = n * n)
    {
        cboard[row][col] = mov;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << cboard[i][j] << " ";
            }
            cout << '\n';
        }
        cboard[row][col] = -1;
        return;
    }
    else{
    cboard[row][col] = mov;
    PrintKnightsTour(cboard, row - 2, col + 1, mov + 1,n);
    PrintKnightsTour(cboard, row - 1, col + 2, mov + 1,n);
    PrintKnightsTour(cboard, row + 1, col + 2, mov + 1,n);
    PrintKnightsTour(cboard, row + 2, col + 1, mov + 1,n);
    PrintKnightsTour(cboard, row + 2, col - 1, mov + 1,n);
    PrintKnightsTour(cboard, row + 1, col - 2, mov + 1,n);
    PrintKnightsTour(cboard, row - 1, col - 2, mov + 1,n);
    PrintKnightsTour(cboard, row - 2, col - 1, mov + 1,n);
    cboard[row][col] = -1;
    }
}
int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    int **cboard  = new int*[n];
    for (int i = 0; i < n; i++)
    {
        cboard[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cboard[i][j] = -1;
        }
        
    }
    
    PrintKnightsTour(cboard, r, c, 1,n);
    return 0;
}