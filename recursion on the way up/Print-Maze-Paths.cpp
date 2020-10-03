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
    printMazePath(row, col + 1, n, m, ans + "h");
    printMazePath(row + 1, col, n, m, ans + "v");
}
int main()
{
    int n,m;cin>>n>>m;
    printMazePath(0,0,n,m,"");
    return 0;
}