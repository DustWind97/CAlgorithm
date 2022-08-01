// #include <iostream>
// #include <string>
// #include <list>

// using namespace std;

// int main()
// {
//     string str;
//     getline(cin, str);
//     int len = str.length();
//     int count = 0;
//     int row = len / 8; //向下取整

//     for (int i = 0; i < len; i++)
//     {
//         string temp;
//         if (count != row + 1) //处理前面完整组
//         {
//             for (int j = 0; j < 8; j++)
//             {
//                 temp += str[i * 8 + j];
//             }
//         }
//         else //处理剩下一组
//         {
//             for (int j = row*8; j < len; j++)
//             {
//                 temp += str[i * 8 + j];
//             }
//             for (int j = len; j < (row+1)*8; j++)
//             {
//                 temp+= "0";
//             }
//         }
//         cout << temp << endl;
//         count++;
//     }

//     return 0;
// }

#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string str;
    while(cin >> str) {
        while(str.size() >= 8) {
            cout << str.substr(0, 8) << endl;
            str = str.substr(8);//从8到结尾
        }
        if(str.size() > 0) {
            str += "00000000";
            cout << str.substr(0, 8) << endl;
        }
    }
    return 0;
}
