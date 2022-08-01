#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int m;
    while (cin >> m)
    {
        int cube = m * m * m;
        vector<int> vec(m);
        vec.clear();
        //查找m个奇数相加等于 cube的情况
        for (int n = 1; n < cube; n++)
        {
            if (n % 2 == 1)
            {
                int sum = 0; //假设的求和
                // vec.push_back(n);
                for (int i = 0; i < m; i++)
                {
                    sum += (n + 2 * i);
                    vec.push_back(n + 2 * i);
                }
                if (sum == cube)
                {
                    //输出vec
                    for (int i = 0; i < vec.size() - 1; i++)
                    {
                        cout << vec[i];
                        cout << "+";
                    }
                    cout << vec[vec.size() - 1] << endl;
                    break;
                }
                else
                {
                    vec.clear();
                }
            }
        }
    }

    return 0;
}