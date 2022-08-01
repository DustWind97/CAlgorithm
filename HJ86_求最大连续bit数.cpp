#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bitset<32> bit(n); //把n转换成32位二进制流
    //cout<<bit<<endl;

    string str(bit.to_string());

    int maxlen = 0;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            temp += str[i];
            if (str[i + 1] == '0' || i == str.length()-1)
            {
                maxlen = max(maxlen, (int)temp.length());
                temp.clear();
            }
        }
    }
    cout << maxlen << endl;

    return 0;
}