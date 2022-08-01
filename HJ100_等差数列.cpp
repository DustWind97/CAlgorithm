#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a0 = 2;
    int d = 3;
    int n;
    cin >> n;
    //计算前n项和
    int sn = 0;
    sn = n * (a0 + a0 + d * (n - 1)) / 2;

    cout << sn << endl;

    return 0;
}