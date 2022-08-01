#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    long input;

    while (cin >> input)
    {
        bitset<32> bitnum;
        bitnum = bitset<32>(input);
        string bitstr = bitnum.to_string();

        int count = 0;
        for (int i = 0; i < bitstr.length(); i++) 
        {
            if (bitstr[i] == '1')
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}