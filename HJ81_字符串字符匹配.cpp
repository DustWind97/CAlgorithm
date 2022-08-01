#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string smaller;
    string longer;
    cin >> smaller; //短串
    cin >> longer;  //长串

    int counter = 0;
    for (int i = 0; i < smaller.length(); i++)
    {
        if (longer.find(smaller[i]) != string::npos)
        {
            counter++;
        }
    }

    if (counter == smaller.length())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}