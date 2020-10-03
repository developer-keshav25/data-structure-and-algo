#include <iostream>
using namespace std;
void printSS(string qsf, string asf)
{
    if (qsf.length() == 0)
    {
        cout << asf << '\n';
        return;
    }
    printSS(qsf.substr(1, qsf.length()), asf + qsf[0]);
    printSS(qsf.substr(1, qsf.length()), asf);
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");
    return 0;
}