#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}