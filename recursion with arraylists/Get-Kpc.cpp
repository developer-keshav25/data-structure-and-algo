#include <iostream>
#include <vector>
using namespace std;
string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
vector<string> getKpc(string qsf)
{
    if (qsf.length() == 0)
    {
        vector<string> b;
        b.push_back("");
        return b;
    }
    int ch = qsf[0] - '0';
    string roq = qsf.substr(1, qsf.length());
    vector<string> ca = getKpc(roq);
    vector<string> ans;
    for (char c : codes[ch])
    {
        for (string s : ca)
        {
            ans.push_back(c + s);
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    vector<string> res = getKpc(str);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res.back();
    cout << "]";
    return 0;
}