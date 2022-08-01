#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//************************************************************
//存放从0-19的数
vector<string> twenties = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                           "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
//存放整十数
vector<string> tens = {"ten", "twenty", "thirty", "forty", "fifty",
                       "sixty", "seventy", "eighty", "ninety"};
//存放单位
vector<string> thousands = {"and", "billion", "million", "thousand", "hundred"}; //记录单位
//************************************************************

//三位数的处理
string dealer(int num)
{
    if (num >=0 && num <= 20)
    {
        return twenties[num];
    }
    else if (num > 20 && num <= 99)
    {
        int decade, single;
        decade = num / 10;
        single = num % 10;
        if (single == 0)
        {
            return tens[decade - 1];
        }
        else
        {
            return tens[decade - 1] + " " + twenties[single];
        }
    }
    int hundred, right;
    hundred = num / 100;
    right = num % 100;
    if (dealer(right) == "zero")
    {
        return twenties[hundred] +" hundred";
    }
    return twenties[hundred] + " hundred and " + dealer(right);
}

int main()
{

    long num;
    while (cin >> num)
    {
        //先将其分断
        int left, middle, right;

        left = num / 1000000;            //高三位（可能不满三位）
        middle = (num % 1000000) / 1000; //中间三位
        right = num % 1000;              //低三位

        if (left != 0 && middle != 0 && right != 0)
        {
            cout << dealer(left) + " million " + dealer(middle) + " thousand " + dealer(right) << endl;
        }
        if (left == 0 && middle != 0 && right != 0)
        {
            cout << dealer(middle) + " thousand " + dealer(right) << endl;
        }
        if (left != 0 && middle == 0 && right != 0)
        {
            cout << dealer(left) + " million " + dealer(right) << endl;
        }
        if (left != 0 && middle != 0 && right == 0)
        {
            cout << dealer(left) + " million " + dealer(middle) + " thousand " << endl;
        }
        if (left == 0 && middle == 0 && right != 0)
        {
            cout << dealer(right) << endl;
        }
        if (left == 0 && middle != 0 && right == 0)
        {
            cout << dealer(middle) + " thousand " << endl;
        }
        if (left != 0 && middle == 0 && right == 0)
        {
            cout << dealer(left) + " million " << endl;
        }
        if (left == 0 && middle == 0 && right == 0)
        {
            cout << dealer(left) + " million " + dealer(middle) + " thousand " + dealer(right) << endl;
        }
    }

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// string ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
// string tens[] = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
// string twenties[] = { "zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
// string hundreds[] = { "hundred", "thousand", "million", "billion" };
// int ihundreds[] = { (int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12 };
// string itoe(long long n)
// {
//     if (n<=9)return ones[n];
//     else if (n<20)return tens[n%10];
//     else if (n<1e2)return twenties[n/10] + (n%10 ? " " + ones[n%10] : "");
//     else for (int i=0; i < 4; i++)
//         if (n < ihundreds[i+1])
//             return itoe(n/ihundreds[i]) + " "
//             + hundreds[i]
//             + (n%ihundreds[i] ? (i ? " ": " and ") + itoe(n%ihundreds[i]) : "");
//     return "";
// }
// int main()
// {
//     long long n;
//     while (cin>>n)
//         cout<<itoe(n)<<endl;
// }
