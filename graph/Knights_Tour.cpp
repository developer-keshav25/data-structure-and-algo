#include <iostream>
#include<vector>
using namespace std;
void displayboard(vector<vector<int> >&board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void knightstour( vector<vector<int> >&board, int r, int c, int move, int n)
{
    if (r < 0 || c < 0 || r >= n || c >= n || board[r][c] > 0)
        return;
    else if (move = n * n)
    {
        board[r][c] = move;
        displayboard(board, n);
        board[r][c] = 0;
        return;
    }
    board[r][c] = move;
    knightstour(board, r - 2, c + 1, move + 1, n);
    knightstour(board, r - 1, c + 2, move + 1, n);
    knightstour(board, r + 1, c + 2, move + 1, n);
    knightstour(board, r + 2, c + 1, move + 1, n);
    knightstour(board, r + 2, c - 1, move + 1, n);
    knightstour(board, r + 1, c - 2, move + 1, n);
    knightstour(board, r - 1, c - 2, move + 1, n);
    knightstour(board, r - 2, c - 1, move + 1, n);
    board[r][c] = 0;
}
int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int> > board( n , vector<int> (n, 0));
    knightstour(board, r, c, 1, n);

    return 0;
}