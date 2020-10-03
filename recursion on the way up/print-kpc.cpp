#include <iostream>
#include <string>
using namespace std;
string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
void printKPC(string qsf, string asf)
{
    if (qsf.length() == 0)
    {
        cout << asf << '\n';
        return;
    }
    int  ch  = qsf[0] - '0';
    string roq = qsf.substr(1, qsf.length());
    string codeforch = codes[ch]; 
    for (int i = 0; i < codeforch.length(); i++)
    {
        char cho = codeforch[i];
        printKPC(roq,asf+cho);
    }
    
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
    return 0;
}