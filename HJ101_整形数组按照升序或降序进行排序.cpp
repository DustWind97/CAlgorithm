#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n; // n个元素的数组
    while (cin >> n)
    {
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }

        //升降序方式    0为升序，1为降序
        int type;
        cin >> type;
        if (type == 0)
        {
            sort(vec.begin(), vec.end());
        }
        else if (type == 1)
        {
            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());
        }

        for (int i = 0; i < vec.size() - 1; i++)
        {
            cout << vec[i] << " ";
        }
        cout << vec[vec.size() - 1] << endl;
    }

    return 0;
}
