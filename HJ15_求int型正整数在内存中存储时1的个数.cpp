#include <iostream>
#include <bitset>
#include <bits/stdc++.h> ///万能头文件，如果选用此头文件，就不用其他所有头文件
#include <string>

using namespace std;

int main()
{
    // string str;
    // cin >> str;
    // string bitstr;
    // bitstr = bitset<32>(stoi(str, 0, 10)).to_string(); //比特流准换成字符串
    // cout << count(bitstr.begin(), bitstr.end(), '1');

    int n;
    cin >> n;
    string bitstr = bitset<32>(n).to_string();
    cout << count(bitstr.begin(), bitstr.end(), '1');

    return 0;
}