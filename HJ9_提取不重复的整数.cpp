#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    unordered_set<char> set;
    for (auto it = str.rbegin(); it != str.rend(); ++it)//it是地址，*it是解引用
    {
        if (set.count(*it))
            continue;
        set.insert(*it);
        cout << *it;
    }
}
