#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    sort(val.begin(), val.end()); //对val进行排序
    
    for (int i = 0; i < k - 1; i++)
    {
        cout << val[i] << " ";
    }
    cout << val[k-1] << endl;

    return 0;
}