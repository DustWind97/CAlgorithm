#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//判断年份是否为闰年（400年一润，或者4年一润且100年不润）
bool isLeapYear(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        return true;
    }
    return false;
}

int main()
{
    vector<pair<int, int>> vec = {{},        /*下标为零占位*/
                                  {31, 31},  /*1月天数*/
                                  {28, 29},  /*2月天数*/
                                  {31, 31},  /*3月天数*/
                                  {30, 30},  /*4月天数*/
                                  {31, 31},  /*5月天数*/
                                  {30, 30},  /*6月天数*/
                                  {31, 31},  /*7月天数*/
                                  {31, 31},  /*8月天数*/
                                  {30, 30},  /*9月天数*/
                                  {31, 31},  /*10月天数*/
                                  {30, 30},  /*11月天数*/
                                  {31, 31}}; /*12月天数*/
    // cout << vec[3].first << endl;
    int year, month, day;
    cin >> year >> month >> day;

    int sum = 0;
    if (isLeapYear(year)) //润年
    {
        for (int i = 1; i < month; i++)
        {
            sum += vec[i].second;
        }
        sum += day;
    }
    else //平年
    {
        for (int i = 1; i < month; i++)
        {
            sum += vec[i].first;
        }
        sum += day;
    }
    cout << sum;

    return 0;
}