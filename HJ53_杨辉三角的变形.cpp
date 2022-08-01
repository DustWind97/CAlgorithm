#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
//分析思路:
                                         1
                                    1    1    1
                               1    2    3    2     1
                          1    3    6    7    6     3    1
                     1    4    10   16   19   16    10   4    1
                 1   5    15   30   45   51   45    30   15   5    1
             1   6   21   50   90   126  141  126   90   50   21   6    1
         1   7   28  77
     1   8   36  112
 1   9   51  156

分析第n行第一个偶数出现的位置，如果没有偶数，则输出-1
    n=1,则输出-1
    n=2,则输出-1
    n=3,则输出2
    n=4,则输出3
通过以上的数据分析规律为 {-1,-1,2,3,2,4,2,3,2,4,...}
*/

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 1 || n == 2)
            cout << -1 << endl;
        else if ((n - 2) % 2 == 1)
        {
            cout << 2 << endl;
        }
        else if ((n - 2) % 4 == 2)
        {
            cout << 3 << endl;
        }
        else if ((n - 2) % 4 == 0)
        {
            cout << 4 << endl;
        }
    }

    return 0;
}
