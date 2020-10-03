#include <iostream>
using namespace std;

void printMazePath(int row, int col, int n, int m, string ans)
{
    if (row >= n || col >= m)
    {
        return;
    }
    if (row == n - 1 && col == m - 1)
    {
        cout << ans << '\n';
        return;
    }
    for (int i = 1; i < m; i++)
    {
        printMazePath(row, col + i, n, m, ans + "h" + to_string(i));
    }
    for (int i = 1; i < n; i++)
    {
        printMazePath(row + i, col, n, m, ans + "v" + to_string(i));
    }
    for (int i = 1; i < (n < m ? n : m); i++)
    {
        printMazePath(row + i, col + i, n, m, ans + "d" + to_string(i));
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    printMazePath(0, 0, n, m, "");
    return 0;
}