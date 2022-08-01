#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int character = 0, space = 0, number = 0, other = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z')
            {
                character++;
            }
            else if (str[i] == ' ')
            {
                space++;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                number++;
            }
            else
            {
                other++;
            }
        }
        cout << character << endl;
        cout << space << endl;
        cout << number << endl;
        cout << other << endl;
    }

    return 0;
}