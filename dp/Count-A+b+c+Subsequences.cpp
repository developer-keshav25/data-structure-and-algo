#include <iostream>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int a = 0;
    int ab = 0;
    int abc = 0;
    for (char ch : str)
    {
        if (ch == 'a')
        {
            a = 2 * a + 1;
        }
        else if (ch == 'b')
        {
            ab = 2 * ab + a;
        }
        else if (ch == 'c')
        {
            abc = 2 * abc + ab;
        }
    }
    cout << abc;
    return 0;
}