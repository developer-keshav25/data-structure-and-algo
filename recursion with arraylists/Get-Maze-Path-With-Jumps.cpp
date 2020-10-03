#include <iostream>
#include <vector>
using namespace std;
vector<string> getstairpath(int row, int col, int n, int m)
{
    // if (row >= n || col >= m)
    // {
    //     vector<string> b;
    //     return b;
    // }
    if (row == n - 1 && col == m - 1)
    {
        vector<string> b;
        b.push_back("");
        return b;
    }
    vector<string> ans1;
    vector<string> ans2;
    vector<string> ans3;
    vector<string> ans;
    for (int i = 1; i < m; i++)
    {

        if (col < m)
        {
            ans1 = getstairpath(row, col + i, n, m);
        }
        for (string s : ans1)
        {
            ans.push_back("h" + to_string(i) + s);
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (row < n)
        {
            ans2 = getstairpath(row + i, col, n, m);
        }
        for (string s : ans2)
        {
            ans.push_back("v" + to_string(i) + s);
        }
    }

    for (int i = 1; i < (n < m ? n : m); i++)
    {
        if (row < n && col < m)
        {
            ans3 = getstairpath(row + i, col + i, n, m);
        }
        for (string s : ans3)
        {
            ans.push_back("d" + to_string(i) + s);
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> res = getstairpath(0, 0, n, m);
    if (res.size() > 0)
    {
        cout << "[";
        for (int i = 0; i < res.size() - 1; i++)
        {
            cout << res[i] << ", ";
        }
        cout << res.back();
        cout << "]";
    }
    else
    {
        cout << "[]";
    }
    return 0;
}