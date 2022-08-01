#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
1010.00的测试用例无法通过但是判题系统是通过了的
*/


int main()
{
    string input;
    cin >> input;

    vector<string> ones = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    vector<string> tens = {"", "拾", "佰", "仟", "万", "亿"};
    vector<string> unit = {"元", "角", "分"};

    int integer = atoi(input.substr(0, input.find(".")).c_str()); //整数部分
    // cout << "整数部分:" << integer << endl;

    //处理整数部分
    string integer_str = to_string(integer);
    reverse(integer_str.begin(), integer_str.end());
    cout << integer_str << endl; //颠倒过的

    string temp = "";
    if (integer_str[0] - '0' != 0)
    {
        temp.insert(0, ones[integer_str[0] - '0'] + "元");
    }

    for (int i = 1; i < integer_str.length(); i++)
    {
        temp.insert(0, tens[i % 4]);
        if ((i == 1 || i == 5 || i == 9) && integer_str[i] - '0' == 1)
        {
        }
        else
        {
            temp.insert(0, ones[integer_str[i] - '0']);
        }

        if (i == 3 && integer_str[4] >= '0' && integer_str[4] <= '9')
        {
            temp.insert(0, "万");
        }
        else if (i == 7&& integer_str[8] >= '0' && integer_str[8] <= '9')
        {
            temp.insert(0, "亿");
        }
    }
    cout << "人民币" << temp;

    /*******************************************************************************************************************************/
    //处理小数部分
    int decimal;
    if (input.find(".") == string::npos)
    {
        cout << "整" << endl;
    }
    else
    {
        decimal = atoi(input.substr(input.find(".") + 1).c_str());
        // cout << "小数部分:" << decimal << endl;
        int carry, base;
        carry = decimal / 10;
        base = decimal % 10;
        if (carry == 0)
        {
            cout << ones[base] << "分" << endl;
        }
        else if (base == 0)
        {
            cout << ones[carry] << "角" << endl;
        }
        else
        {
            cout << ones[carry] << "角" << ones[base] << "分" << endl;
        }
    }

    return 0;
}




// /*
// 本文系「人工智能安全」（微信公众号）原创，转载请联系本文作者（同博客作者）。
// 欢迎你转发分享至朋友圈，并给予「关注、星标、点赞」三连支持。互相欣赏，互相批判。
// 我是一名有诗人气质的网络安全工程师
// 期待与你的思想交流碰撞出智慧的花火
// 水木清华
// 2020-03-18
// 人民币转换
// 基于 ultraji 朋友的代码
// 输出模式：个位与其他单位的组合 + 元 + 个位 + 角 + 个位 + 分，或，个位与其他单位的组合 + 元整。
// */
// #include <iostream>
// using namespace std;
// //构建个位的字典（数组）
// string gewei[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
// //构建十位、百位、千位、万位、亿位等其他单位的字典（数组），ot[10] 实际表示 "拾亿"，ot[15] 实际表示 "佰万亿"
// string other[17] = {"", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟", "万", "拾", "佰", "仟","万"};
// //获取元钱的函数接口，即小数点之前的部分
// void Get_Before_Plot(string str)
// {
//     if (str == "0")
//     {
//         return;
//     }
//     int j = str.size() - 1;
//     if(!(j % 4 == 1 && str[0] == '1'))
//     {
//         cout << gewei[str[0]-'0'];
//     }
//     cout << other[j];
//     for(int i = 1; i < str.size(); i++)
//     {
//         if( (j - i) % 4 == 0  && str[i] == '0')
//         {
//             if (i >= 4 && j - i == 4 && str[i - 1] + str[i - 2] + str[i - 3] == '0' * 3)
//             {
//                 continue;
//                 cout << other[j - i];
//             }
//             continue;
//         }
//         if(str[i] != '0')
//         {
//             if(str[i - 1] == '0')
//             {
//                 cout << "零";
//             }
//             cout << gewei[str[i] - '0'];
//             cout << other[j - i];
//         }
//     }
//     cout << "元";
//     return;
// }
// //获取角分零钱的函数接口，即小数点之后的部分
// void Get_After_Plot(string str)
// {
//     if(str == "00")
//     {
//         cout << "整";
//         return;
//     }
//     if (str[0] > '0')
//     {
//         cout << gewei[str[0]-'0'] << "角";
//     }
//     if (str[1] > '0')
//     {
//         cout << gewei[str[1]-'0'] << "分";
//     }
//     return;
// }
// //主函数 
// int main()
// {
//     string str;
//     while(getline(cin, str))
//     {
//         //获取小数点的位置
//         int Plot = str.find('.');
//         //获取小数点前的子字符串
//         string str1 = str.substr(0, Plot);
//         //获取小数点后的子字符串
//         string str2 = str.substr(Plot + 1);
//         //输出人民币
//         cout << "人民币";
//         //输出元钱
//         Get_Before_Plot(str1);
//         //输出角分零钱
//         Get_After_Plot(str2);
//         //换行
//         cout << endl;
//     }
//     return 0;
// }