#include <iostream>
using namespace std;
//sos:sum of set
void tss(int arr[], int tar, int idx, int sos, string set, int n)
{
    if(sos>tar){
        return;
    }
    
    if (idx == n)
    {
        if (sos == tar)
        {
            cout << set << "." << endl;
        }
        return;
    }

    tss(arr, tar, idx + 1, sos + arr[idx], set + std::to_string(arr[idx]) + ", ", n);
    tss(arr, tar, idx + 1, sos, set, n);
    return;
    
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tar;
    cin >> tar;
    tss(arr, tar, 0, 0, "", n);

    return 0;
}