#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
解题思路一：
步骤一：用b 除以a，得商数q 及余数r。（r=b - a*q）
步骤二：把a/b 记作：a/b=1/(q+1）+(a-r)/b(q+1）
步骤三：重复步骤2，直到分解完毕
PS: 以上其实是数学家斐波那契提出的一种求解埃及分数的贪心算法，准确的算法表述应该是这样的：
    设某个真分数的分子为a，分母为b;
    把b除以a的商部分加1后的值作为埃及分数的某一个分母c；
    将a乘以c再减去b，作为新的a；
    将b乘以c，得到新的b；
    如果a大于1且能整除b，则最后一个分母为b/a；算法结束；
    或者，如果a等于1，则，最后一个分母为b；算法结束；
    否则重复上面的步骤。
    备注：事实上，后面判断a是否大于1和a是否等于1的两个判断可以合在一起，
    即：判断b%a是否等于0，最后一个分母为b/a，显然是正确的。

解题思路二：
 * 若真分数的分子a能整除分母b，则真分数经过化简就可以得到埃及分数，
 * 若真分数的分子不能整除分母，则可以从原来的分数中分解出一个分母为b/a+1的埃及分数。
 * 用这种方法将剩余部分反复分解，最后可得到结果。
*/

// int main()
// {
//     string str;
//     while (cin >> str)
//     {
//         int len = str.length();
//         int pos = str.find('/');
//         string fenzi = str.substr(0, pos);  //分子字符串
//         string fenmu = str.substr(pos + 1); //分母字符串

//         int numerator = atoi(fenzi.c_str());   //分子
//         int denominator = atoi(fenmu.c_str()); //分母
//     }
//     return 0;
// }


using namespace std;



int gcd(int a,int b) //获取a和b的最大公因数
{    
    return b>0 ? gcd(b,a%b):a;//如果b>0继续递归运算，如果b=0则输出a
}


int main()
{
    string str;
    while (cin >> str)
    {
        int index = str.find('/');
        string z = str.substr(0, index);
        string m = str.substr(index + 1);
        int n = stoi(z);
        string res;
        while (n--)
        {
            res += "1/" + m + "+";
        }
        res = res.substr(0, res.size() - 1);
        cout << res << endl;
    }
    return 0;
}
