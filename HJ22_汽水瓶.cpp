#include <iostream>
#include <string>
#include <vector>

/*
解题思路：题目描述中有讲到：剩2个空瓶子时，可以先找老板借一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。 也就是说2个空瓶子即可换一瓶汽水喝，而且喝完之后手里也没有空瓶子。求解时直接把空瓶数除以2，即可得到正解。 .........（无语ing）
注：由于两个空瓶就可以找老板借一个空瓶换一瓶饮料，喝完归还老板，因此可以考虑将饮料以两个空瓶为一个单位换饮料喝，故剩余的空瓶数量只会有0个或者1个
*/
/*
规律如下：
数量	喝	剩
3	    1	1
4	    2	0	
5	    2	1
6	    3	0	
7	    3	1
8	    4	0
9	    4	1
10	    5	0
11      5   1
12      6   0
    ......
*/

using namespace std;

// //数据迭代
// int roll(int input)
// {
//     int output;
//     if (input % 3 == 2)
//     {
//         int part1 = roll(input / 3);
//         output = part1 + 1;
//     }
//     else
//     {
//         output = roll(input / 3);
//     }
//     if (input / 3 == 0)
//     {
//         return output;
//     }
//     return
// }

int main()
{
    string str;
    vector<string> set;
    while (cin >> str)
    {
        if (str == "0")
        {
            break;
        }
        set.push_back(str);
    }

    //对set进行处理 对set遍历处理
    for (vector<string>::iterator it = set.begin(); it != set.end(); it++)
    {
        //对每一个元素量化成整数
        int input = atoi((*it).c_str());
        // output = roll(input);
        cout << input / 2 << endl;
    }

    return 0;
}