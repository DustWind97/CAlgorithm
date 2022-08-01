#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        for (int i = min(m, n); i <= m * n; i++)
        {
            if (i % m == 0 && i % n == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}