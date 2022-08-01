/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
              心中有海，不赶浪潮！
*/
#include <iostream>
#include <algorithm> //直接用算法库
#include <vector>
using namespace std;
// int main()
// {
//     int n;
//     string text;
//     vector<string> vec;
//     cin >> n;
//     cin.get(); //这里容易出错，输入数字后我们按下回车，在输入字符串之前，要将键盘缓冲器的换行符读取出来
//     for (int i = 0; i < n; i++)
//     {
//         getline(cin, text);
//         vec.push_back(text);
//     }
//     sort(vec.begin(), vec.end());
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << endl;
//     }
//     return 0;
// }

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> vec;
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            vec.push_back(temp);
        }

        sort(vec.begin(), vec.end());

        for (auto elem : vec)
        {
            cout << elem << endl;
        }
    }

    return 0;
}