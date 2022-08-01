#include <iostream>
#include <string>

using namespace std;

bool isAN(int &num)
{
    int num_2 = num * num;
    string s1, s2;
    s1 = to_string(num);
    s2 = to_string(num_2);
    //cout << s1 << " | " << s2 << endl;
    int len1 = s1.length();
    int len2 = s2.length();
    //在s2中查找s1,
    if (s2.substr(len2-len1,len1)==s1) //找到
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int counter = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isAN(i) == true)
        {
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}