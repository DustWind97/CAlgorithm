#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int index;
            cin >> index;
            int value;
            cin >> value;

            mp[index] += value;
        }

        for (auto it : mp)
        {
            cout << it.first << " " << it.second << endl;
        }
    }

    return 0;
}