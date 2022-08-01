#include <iostream>
#include <string>
#include <vector>

using namespace std;

//判断完全数
bool isPerfectNumber(int num)
{
    vector<int> val;
    int sum= 0;

    val.clear();

    for (int i = 1; i < num; i++) //从1到它本身找到所有约数
    {
        if (num % i == 0)
        {
            val.push_back(i);
        }
    }

    for (int elem : val)
    {
        sum += elem;
    }

    if (sum == num)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isPerfectNumber(i))
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}