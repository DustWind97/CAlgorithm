#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
方法一：
    二分查找求解立方根
        如果 x>1 ,那么立方根一定在1到x之间
        如果 0<x<1 ,那么立方根在x到1之间
        如果 -1<x<0 ,那么立方根在-1到x之间
        如果 x<-1 ,那么立方根在x到-1之间
*/
double Calculate_Binary(double x) //二分查找
{
    double left = min(-1.0, x); //正负数都有
    double right = max(1.0, x);
    double y;
    while (abs(right - left) > 0.01)
    {                           //立方根的精度值
        y = (left + right) / 2; //二分中值
        if (y * y * y > x)      //比较选取二分哪一边
            right = y;
        else
            left = y;
    }
    return y;
}

/*
方法二：
    牛顿迭代法求解立方根
        设方程 f(x) = x^3 - y，当 f(x)=0 时的解 x 就是 y 的立方根。根据牛顿迭代法，我们有 x = x-( x^3 - y )/( 3*x^2 )
        因此只需要控制 x^3 和 y 的精度在一定范围之内迭代即可
*/
double Calculate_Newton(double x) //牛顿迭代法
{
    double y = 1;
    // while (((y * y * y - x) >= 0.01) || (x - y * y * y) >= 0.01) //精度控制1e-2=0.01
    while (fabs(x - y * y * y) >= 0.01) //精度控制1e-2=0.01
        y = (y - y / 3 + x / (3 * y * y));
    return y;
}

int main()
{
    double val;
    while (cin >> val)
    {
        cout << setprecision(1) << fixed << Calculate_Binary(val) << endl; //控制小数位输出      二分查找法
        cout << setprecision(1) << fixed << Calculate_Newton(val) << endl; //控制小数位输出      牛顿迭代法
    }
    return 0;
}