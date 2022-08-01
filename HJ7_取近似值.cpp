#include <iostream>

using namespace std;

int main()
{
    float num;
    cin >> num;
    int num_int = num; //隐含向下取整的强制类型转换
    float differ = num - (float)num_int;
    if (differ >= 0.5)
    {
        num_int += 1;
    }
    cout << num_int;
    return 0;
}