#include <iostream>
using namespace std;
string codes[] = {" ", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
void printEncodings(string qsf, string asf)
{
    if (qsf.length() == 0)
    {
        cout << asf << '\n';
        return;
    }
    int ch1 = qsf[0] - '0';
    if(ch1==0)
    return;
    string roq = qsf.substr(1, qsf.length());
    printEncodings(roq, asf + codes[ch1]);
    if (qsf.length() >= 2)
    {
        int ch2 = stoi(qsf.substr(0, 2));
        if (ch2 >= 1 && ch2 <= 26)
        {
            string roq = qsf.substr(2, qsf.length());
            printEncodings(roq, asf + codes[ch2]);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    printEncodings(str, "");
    return 0;
}