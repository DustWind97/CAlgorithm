#include <iostream>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    cout<<str;
    return 0;
}