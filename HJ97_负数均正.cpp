#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    //输入n个数字
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        vec.push_back(temp);
        temp.clear();
        // cout<<atoi(vec[i].c_str());
    }
    double sum = 0;
    int counter = 0, zero = 0; // counter记录非负数个数
    for (int i = 0; i < n; i++)
    {
        if (atoi(vec[i].c_str()) > 0)
        {
            sum += atoi(vec[i].c_str());
            counter++;
        }
        if (atoi(vec[i].c_str()) == 0)
        {
            zero++;
        }
    }
    if (counter == 0)
    {
        cout << (n - zero) << " 0.0" << endl;
    }
    else
    {
        cout << (n - counter - zero) << " ";
        cout << setiosflags(ios::fixed) << setprecision(1) << sum / (double)counter << endl;
    }

    return 0;
}