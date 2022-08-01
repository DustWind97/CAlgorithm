#include <iostream>
#include <string>

using namespace std;

/*
动态规划
思路：arr[i][j]表示A的i的字母和B的j字母之间的间距。A字符串用arr[i][0]表示，间距arr[i-1][j] + 1；
B字符串用arr[0][j]表示，间距用arr[i][j-1] + 1；A与B组层一个二维数组arr[i-1][j-1]，查看A与B的字母不相等，则累加arr[i-1][j-1]+ = 1；
比较他们最小间距。
三种操作：
一，在单词A插入一个字符；
二，在单词B插入一个字符；
三，修改单词A的一个字符；
如果A与B的字符相同，则不需要进行;如果A与B不相同，则查看
*/
int MinDistance(string firstStr, string &secondStr)//&secondStr为常引用，保证形参与实参一直
{
    int n = firstStr.size();//第一个字符串的长度
    int m = secondStr.size();//第二个字符串的长度
    int arr[n + 1][m + 1];//动态规划辅助数组
    // A或B单词为空
    if (n * m == 0)
    {
        return n * m;
    }
    // A单词删除或插入
    for (int i = 0; i < n + 1; i++)
    {
        arr[i][0] = i;
    }
    // B单词, 删除B或插入A
    for (int j = 0; j < m + 1; j++)
    {
        arr[0][j] = j;
    }

    //循环查找
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            int left = arr[i - 1][j] + 1; //左, 第一个字符串的1个间距
            int down = arr[i][j - 1] + 1; //右，第二个字符串的1个间距
            int leftDown = arr[i - 1][j - 1];
            if (firstStr[i - 1] != secondStr[j - 1])
            {                  //比较第一个字符与第二个字符
                leftDown += 1; // 查看他们间距
            }
            arr[i][j] = min(left, min(down, leftDown)); //获取最小间距，状态转移方程
        }
    }

    return arr[n][m];
}

int main()
{
    string firstStr, secondStr;
    while (cin >> firstStr >> secondStr)
    {
        cout << MinDistance(firstStr, secondStr) << endl;
    }
}

//最简方法
// #include <string>
// #include <iostream>
// using namespace std;
// int main()
// {
//     string w1,w2;
//     while(cin>>w1>>w2)
//     {
//         int n = w1.length(),m = w2.length();
//         int D[n + 1][m + 1];
//         for(int i=0;i<=n;i++)D[i][0] = i;//从空串打出
//         for(int j=0;j<=m;j++)D[0][j] = j;//从空串打出
//         for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
//         {
//             int l = D[i-1][j]+1;//l代表删去第一个串的j
//             int d = D[i][j-1]+1;//d代表删去第二个串的i
//             int ld=D[i-1][j-1]+(w1[i-1]!=w2[j-1]?1:0);//ld代表把第一个串的j和第二个串的i替换
//             D[i][j] = min(l, min(d, ld));
//         }
//         cout<<D[n][m]<<endl;
//     }
// }
