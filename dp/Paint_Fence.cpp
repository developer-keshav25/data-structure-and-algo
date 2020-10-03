#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int ii[n + 1];
    int ij[n + 1];
    int total[n + 1];
    ii[2] = k;
    ij[2] = k * (k - 1);
    total[2] = ii[2] + ij[2];
    for (int i = 3; i <= n; i++)
    {
        ii[i] = ij[i - 1];
        ij[i] = total[i - 1] * (k - 1);
        total[i] = ii[i] + ij[i];
    }
    cout << total[n];

    return 0;
}