#include <iostream>
#include <vector>
using namespace std;
vector<string> getsubsequence(string qsf)
{
    if (qsf.length() == 0)
    {
        vector<string> b;
        b.push_back("");
        return b;
    }
    char ch = qsf[0];
    string roq = qsf.substr(1, qsf.length());
    vector<string> ca = getsubsequence(roq);
    vector<string> ans;
    for (string s : ca)
    {
        ans.push_back(s);
    }
    for (string s : ca)
    {
        ans.push_back(ch + s);
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    vector<string> res = getsubsequence(str);
    cout<<"[";
    for (int i = 0; i < res.size()-1; i++)
    {
        cout<<res[i]<<", ";
    }
    cout<<res.back();
    cout<<"]";
    return 0;
}