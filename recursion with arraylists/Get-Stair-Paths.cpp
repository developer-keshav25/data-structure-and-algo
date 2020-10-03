#include <iostream>
#include <vector>
using namespace std;
vector<string> getstairpath(int n)
{
    if (n < 0)
    {
        vector<string> b;
        return b;
    }
    if (n == 0)
    {
        vector<string> b;
        b.push_back("");
        return b;
    }
    vector<string> ans;
    vector<string> ans1 = getstairpath(n - 1);
    for (string s : ans1)
    {
        ans.push_back(to_string(1) + s);
    }

    vector<string> ans2 = getstairpath(n - 2);
    for (string s : ans2)
    {
        ans.push_back(to_string(2) + s);
    }

    vector<string> ans3 = getstairpath(n - 3);
    for (string s : ans3)
    {
        ans.push_back(to_string(3) + s);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> res = getstairpath(n);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res.back();
    cout << "]";
    return 0;
}