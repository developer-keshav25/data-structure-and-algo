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
    vector<string>ans1;
    vector<string>ans2;
    vector<string> ans;
    if(col<m){
    ans1 = getstairpath(row, col + 1, n, m);
    }
    for (string s : ans1)
    {
        ans.push_back("h" + s);
    }
    if(row<n){
    ans2 = getstairpath(row + 1, col, n, m);
    }
    for (string s : ans2)
    {
        ans.push_back("v" + s);
    }

    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> res = getstairpath(0, 0, n, m);
    if(res.size()>0){
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res.back();
    cout << "]";
    }
    else{
        cout<<"[]";
    }
    return 0;
}