#include <iostream>
#include <string>
#include <map>
#include <deque>

using namespace std;

int main()
{
    string instr;
    map<string, int> result; //第一个参数key存放文件名，第二个参数value统计该文件次数
    deque<string> deq;       //队列（先进先出）----始终保持队列长度为8
    while (getline(cin, instr))
    {
        string file_path, file_name, code_row_num;
        int pos_slash = instr.find_last_of("\\");
        int pos_space = instr.find_last_of(" ");

        file_path = instr.substr(0, pos_space);
        code_row_num = instr.substr(pos_space + 1, instr.length() - pos_space); //得到代码行

        // cout << file_path << endl;

        string temp = file_path.substr(pos_slash + 1, file_path.length() - pos_slash); //临时存放文件名
        if (temp.length() > 16)                                                        //最终得到文件名
        {
            for (int i = temp.length() - 16; i < temp.length(); i++)
            {
                file_name += temp[i];
            }
        }
        else
        {
            file_name = temp;
        }
        // cout << " 结果 | " << file_name << " | " << code_row_num << endl;

        //这里将文件名和代码行合并为一个
        string name_and_rownum = file_name + " " + code_row_num;

        //在map（文件名+代码行 与 次数的键值对）和deq（队列）当中进行处理
        if (result.find(name_and_rownum) == result.end())
        {   
            deq.push_back(name_and_rownum);
        }
        ++result[name_and_rownum];
        if (deq.size() > 8) //长度超过8，出队列一个元素
        {
            deq.pop_front();
        }
    }
    for (auto x : deq)//（x）为（文件名+代码行） 的键，而（result[x]）为（文件名+代码行）的值
    {
        cout << x << " " << result[x] << endl;
    }

    return 0;
}
