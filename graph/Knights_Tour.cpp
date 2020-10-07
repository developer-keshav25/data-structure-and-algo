#include <iostream>
#include <vector>
using namespace std;
#define N 5
int row[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;

    return true;
}

void displayboard(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void knightstour(vector<vector<int>> board, int r, int c, int move)
{
    board[r][c] = move;
    if (move >= N * N)
    {
        displayboard(board);
        board[r][c] = 0;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int newR = r + row[i];
        int newC = c + col[i];
        if (isValid(newR, newC)&&board[newR][newC]==0)
        {
            knightstour(board, newR, newC, move + 1);
        }
    }

    // knightstour(board, r - 2, c + 1, move + 1, n);
    // knightstour(board, r - 1, c + 2, move + 1, n);
    // knightstour(board, r + 1, c + 2, move + 1, n);
    // knightstour(board, r + 2, c + 1, move + 1, n);
    // knightstour(board, r + 2, c - 1, move + 1, n);
    // knightstour(board, r + 1, c - 2, move + 1, n);
    // knightstour(board, r - 1, c - 2, move + 1, n);
    // knightstour(board, r - 2, c - 1, move + 1, n);
    board[r][c] = 0;
}
int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> board(n, vector<int>(n, 0));
    knightstour(board, r, c, 1);

    return 0;
}