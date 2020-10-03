#include <iostream>
using namespace std;
void printpermuatations(string qsf, string asf)
{
    if (qsf.length() == 0)
    {
        cout << asf << '\n';
        return;
    }
    for (int i = 0; i < qsf.length(); i++)
    {
        char ch = qsf[i];
        string roq = qsf.substr(0, i) + qsf.substr(i + 1, qsf.length());
        printpermuatations(roq, asf + ch);
    }
}

int main()
{
    string str;cin>>str;
    printpermuatations(str,"");
    return 0;
}