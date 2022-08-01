#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;           //歌曲数量 总共有1-n这么多首歌曲
    string ctrl_str; //控制字符集合
    while (cin >> n >> ctrl_str)
    {
        int index = 1; //记录当前歌曲所在当前页面中的位置，初始为1，index的取值为1-4
        int pos = 1;   //歌曲数量大于4首的时候,记录当前歌曲所在歌单中的位置,初始为1，pos的取值为1-n
        int head = 1;  //歌曲数量大于4首的时候,滑动窗口的头部,初始为1，取值为1-（n-3）

        if (n <= 4) //歌曲数不超过四首
        {
            //遍历控制字符合集
            for (int i = 0; i < ctrl_str.length(); i++)
            {
                if (index == 1 && ctrl_str[i] == 'U') //光标在第一首歌并且向上移动
                {
                    index = n;
                }
                else if (index == n && ctrl_str[i] == 'D') //光标在最后一首歌并且向下移动
                {
                    index = 1;
                }
                else if (ctrl_str[i] == 'U') //在中间向上移动
                {
                    index--;
                }
                else if (ctrl_str[i] == 'D') //在中间向下移动
                {
                    index++;
                }
            }

            //输出显示列表以及当前所在歌曲的光标位置
            for (int i = 1; i < n; i++)
            {
                cout << i << " ";
            }
            cout << n << endl;
            cout << index << endl;
        }
        else //歌曲数大于四首
        {
            //遍历控制字符合集
            for (int i = 0; i < ctrl_str.length(); i++)
            {
                if (index == 1 && pos == 1 && ctrl_str[i] == 'U') //光标在第一首歌并且向上移动
                {
                    index = 4;
                    pos = n;
                    head = n - 3;
                }
                else if (index == 4 && pos == n && ctrl_str[i] == 'D') //光标在最后一首歌并且向下移动
                {
                    index = 1;
                    pos = 1;
                    head = 1;
                }
                else if (ctrl_str[i] == 'U') //在中间向上移动
                {
                    pos--;
                    if (index != 1)
                    {
                        index--;
                    }
                    else
                    {
                        index = 1;
                        head--;
                    }
                }
                else if (ctrl_str[i] == 'D') //在中间向下移动
                {
                    pos++;
                    if (index != 4)
                    {
                        index++;
                    }
                    else
                    {
                        index = 4;
                        head++;
                    }
                }
            }
            //输出显示列表以及当前所在歌曲的光标位置
            for (int i = head; i < head + 3; i++)
            {
                cout << i << " ";
            }
            cout << head + 3 << endl;
            cout << pos << endl;
        }
    }

    return 0;
}