#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;

    //穷举法
    /*
    思路：
        鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一
        令鸡翁为x个，鸡母为y个，鸡雏为z列出方程
          x +  y + z = 100
        15x + 9y + z = 300（原方程为:5x+3y+z/3=100）
    */
    int x, y, z;
    for (x = 0; x <= 20; x++)
    {
        for (y = 0; y <= 33; y++)
        {
            for (z = 0; z <= 300; z++)
            {
                if ((x + y + z == 100) && (15 * x + 9 * y + z == 300))
                {
                    cout << x << " " << y << " " << z << endl;
                }
            }
        }
    }

    return 0;
}