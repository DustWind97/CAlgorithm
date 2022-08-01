#include <iostream>
#include <cmath>
#include<time.h>
#include <iomanip>

using namespace std;

int main()
{
    int t_start,t_end;
    t_start = clock();
    long input;
    cin >> input;
    for (long int factor = 2; factor <= sqrt(input); factor++)
    {
        while (input % factor == 0)
        {
            cout << factor << " ";
            input = input / factor;
        }
    }
    //注意整除到最后剩下的一个必是质数
    if (input - 1)
    {
        cout << input << " ";
    }

    //计算时间复杂度
    t_end = clock();
    cout <<setprecision(10)<< (double)(t_end - t_start) / CLOCKS_PER_SEC << endl;
    return 0;
}
