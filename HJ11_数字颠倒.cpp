#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for (auto it = str.rbegin(); it != str.rend(); it++)
    {
        cout << *it;
    }

    return 0;
}