#include <bits/stdc++.h>

using namespace std;

// int main()
// {
// 	string str, temp, dst;
// 	getline(cin, str);

// 	for (char c : str)//str中的char元素
// 	{
// 		if (c != ' ')
// 			temp += c; //左右拼接有差异的
// 		else
// 		{
// 			dst = ' ' + temp + dst;
// 			temp.clear();  //注意清除容器
// 		}
//         //判断c是否为最后一个字符
// 		if ((dst.length() + temp.length()) == str.length())
// 		{
// 			dst = temp + dst;
// 		}
// 	}
// 	cout << dst;
// 	return 0;
// }

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> vec;
		string temp = "";
		for (int i = 0; i <= str.length(); i++)
		{
			if (str[i] != ' ' && i != str.length())
			{
				temp+=str[i];
			}
			else
			{
				vec.push_back(temp);
				temp.clear();
			}
		}

		// reverse(vec.begin(),vec.end());
		// for (auto it:vec)
		// {
		// 	cout << it << " " ;
		// }
		for (auto it = vec.rbegin(); it != vec.rend(); it++)
		{
			cout << *it << " " ;
		}
		
		
	}

	return 0;
}