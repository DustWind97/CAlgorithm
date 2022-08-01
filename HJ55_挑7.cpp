#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> val;
    val.clear();

    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0)
        {
            val.push_back(i);
            // cout << i << endl;
        }
        else if (to_string(i).find("7") + 1) //注意下标可能返回为0，则将其处理为一个非零数
        {

            val.push_back(i);
            // cout << to_string(i) << endl;
            // cout << to_string(i).find("7") << endl;
        }
        // cout << endl;
    }

    for (int elem : val)
    {
        cout << elem << " ";        
    }

    cout << val.size() << endl;

    return 0;
}