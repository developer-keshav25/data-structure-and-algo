#include <iostream>
using namespace std;
void printStairPath(int n, string ans)
{
    if (n < 0)
    {
        return;
    }
    if (n == 0)
    {
        cout << ans << '\n';
        return;
    }
    printStairPath(n - 1, ans + to_string(1));
    printStairPath(n - 2, ans + to_string(2));
    printStairPath(n - 3, ans + to_string(3));
}
int main()
{
    int n;cin>>n;
    printStairPath(n,"");
    return 0;
}