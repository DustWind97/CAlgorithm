#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; //初始高度
    cin >> n;

    double height = (double)n; //初始高度
    double distance = 0;
    int i = 0;
    while (i < 5)
    {
        distance += (height + height / 2.0);
        height /= 2.0;
        i++;
    }

    cout << distance - height << endl; //注意此处多加了一个高度，应当减去
    cout << height << endl;

    return 0;
}