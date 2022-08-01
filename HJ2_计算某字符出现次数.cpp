#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    char ch = tolower(getchar());
    int count = 0;
    // for (auto i : str) {
    //     if (tolower(i) == c) {
    //         count++;
    //     }
    // }
    for (int i = 0; i < str.length(); i++)
    {
        if (ch == tolower(str[i]))
        {
            count++;
        }
    }
    cout << count << endl;
}

//为啥下面这个是错误的
// #include <iostream>
// #include <string>

// using namespace std;

// //思路：逐个对比，注意不区分大小写
// int main() {
//     string str;
//     getline(cin, str);
//     char ch;
//     int count = 0;
//     cin >> ch;
//     for (int i = 0; i < str.length(); i++) {
//         if (ch == str[i] - 32 || ch == str[i] || ch == str[i] + 32) {   //这种判断太武断
//             count++;
//         }
//     }
//     cout << count << endl;
//     return 0;
// }