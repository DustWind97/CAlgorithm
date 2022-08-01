#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*用面向对象的思想处理程序*/

//定义商品类
class Stuff
{
private:
    string stuff_name;
    int stuff_price;
    int stuff_num;

public:
    Stuff()
    {
        stuff_name = "";
        stuff_price = 0;
        stuff_num = 0;
    }                                      //默认构造函数
    Stuff(string name, int price, int num) //重构构造函数，绑定对象的三个成员
    {
        stuff_name = name;
        stuff_price = price;
        stuff_num = num;
    }

    void InitNum(int num) //重构数量
    {
        stuff_num = num;
    }

    string &GET_NAME() { return stuff_name; } //获取名称
    int &GET_PRICE() { return stuff_price; }  //获取价格
    int &GET_NUM() { return stuff_num; }      //获取数量
    void addStuff(int i = 1)
    {
        stuff_num += i;
    }
    void reduceStuff(int i = 1)
    {
        stuff_num -= i;
    }
};

//定义存钱罐类
class SaveBox
{
private:
    unordered_map<int, int> savebox;

public:
    SaveBox() //默认构造函数
    {
        savebox = {{1, 0},
                   {2, 0},
                   {5, 0},
                   {10, 0}};
    }
    SaveBox(unordered_map<int, int> &index) //重构构造函数
    {
        for (auto iter = index.begin(); iter != index.end(); iter++)
        {
            savebox[iter->first] = iter->second;
        }
    }

    void addCoin(int i, int num = 1) //第i个面值添加num个数量
    {
        savebox[i] += num;
    }
    void reduceCoin(int i, int num = 1)
    {
        savebox[i] -= num;
    }
    int getCoinNum(int i) //获取第i个面值的数量
    {
        if (savebox.count(i))
        {
            return savebox[i];
        }
        else
        {
            throw("输入错误");
        }
    }
};

//定义系统类
class System
{
private:
    vector<string> names = {"A1", "A2", "A3", "A4", "A5", "A6"}; //商品名称
    vector<int> prices = {2, 3, 4, 5, 8, 6};                     //单价
    vector<int> coins = {1, 2, 5, 10};                           //币值

    //创建商品对象向量
    vector<Stuff> stf; //创建多个stuff对象,每个对象单独维护
    //创建一个存钱罐对象
    SaveBox box; //
    //投币数余额
    int balance;

public:
    /*
    构造函数
    */
    System()
    {
        //初始化商品信息（只初始化商品的名称和单价）
        for (int i = 0; i < 6; i++)
        {
            stf.push_back(Stuff(names[i], prices[i], 0));
        }

        //初始化存钱罐（只初始化存钱罐的面额）
        unordered_map<int, int> index;
        for (int i = 0; i < 4; i++)
        {
            index[coins[i]] = 0; //数量初始化为零
        }
        box = SaveBox(index);

        //初始化投币余额
        balance = 0;
    }

    /*
    程序轮询
    */
    void Run(string str)
    {
        if (str[0] == 'r') //初始化
        {
            Init(str);
        }
        else if (str[0] == 'p') //投币
        {
            Coin(str);
        }
        else if (str[0] == 'b') //购买
        {
            Buy(str);
        }
        else if (str[0] == 'c') //退币
        {
            SendBack(str);
        }
        else if (str[0] == 'q') //查询
        {
            Search(str);
        }
        else
        {
            throw("输入错误");
        }
    }
    /*
    1.系统初始化
        r A1 数量 -A2 数量 -A3 数量 -A4 数量 -A5 数量 -A6 数量 1 元张数 -2 元张数 -5 元张数 -10 元张数
    */
    void Init(string cmd)
    {
        balance = 0;

        //解析命令串
        vector<string> vec;
        string temp = "";
        for (int i = 0; i <= cmd.length(); i++)
        {
            if (cmd[i] != ' ' && i != cmd.length())
            {
                temp += cmd[i];
            }
            else //找到空格或者到达长度
            {
                vec.push_back(temp);
                temp.clear();
            }
        }

        //初始化商品--vec[1]当中
        vector<int> temp_stf;
        string temps = "";
        for (int i = 0; i <= vec[1].length(); i++)
        {
            if (vec[1][i] != '-' && i != vec[1].length())
            {
                temps += vec[1][i];
            }
            else
            {
                temp_stf.push_back(atoi(temps.c_str()));
                temps.clear();
            }
        }
        for (int i = 0; i < 6; i++)
        {
            stf[i].InitNum(temp_stf[i]);

            //打印出来看看
            // cout << stf[i].GET_NAME() << " | " << stf[i].GET_PRICE() << " | " << temp_stf[i] << endl;
        }

        //初始化存钱盒--vec[2]当中
        vector<int> temp_box;
        string tempb = "";
        for (int i = 0; i <= vec[2].length(); i++)
        {
            if (vec[2][i] != '-' && i != vec[2].length())
            {
                tempb += vec[2][i];
            }
            else
            {
                temp_box.push_back(atoi(tempb.c_str()));
                tempb.clear();
            }
        }
        for (int i = 0; i < 4; i++)
        {
            box.addCoin(coins[i], temp_box[i]); //数量初始化为零

            //打印出来看看
            // cout << coins[i] << " | " << temp_box[i] << endl;
        }

        cout << "S001:Initialization is successful" << endl;
    }

    /*
    2.投币
        命令格式：p 钱币面额
    */
    void Coin(string cmd)
    {
        int pay = atoi(cmd.substr(cmd.find(" "), cmd.length() - cmd.find(" ")).c_str()); //获取面值
        if (!count(coins.begin(), coins.end(), pay))                                     //如果非面值1 2 5 10
        {
            cout << "E002:Denomination error" << endl;
            return;
        }

        if (pay == 5 || pay == 10)
        {
            if (box.getCoinNum(1) * 1 + box.getCoinNum(2) * 2 < pay)
            {
                cout << "E003:Change is not enough, pay fail" << endl;
                return;
            }
        }

        //判定是否还有库存
        int counter = 0;
        for (auto it : stf)
        {
            if (it.GET_NUM() > 0)
            {
                counter++;
            }
        }
        if (!counter)
        {
            cout << "E005:All the goods sold out" << endl;
        }

        //投币成功处理
        balance += pay;
        box.addCoin(coins[balance]); //面值增加

        cout << "S002:Pay success,balance=" << balance << endl;
    }

    /*
    3.购买商品
        命令格式：b 商品名称
    */
    void Buy(string cmd)
    {
        string name = cmd.substr(2, cmd.size() - 1);
        if (!count(names.begin(), names.end(), name))
        {
            cout << "E006:Goods does not exist" << endl;
            return;
        }
        Stuff &shop = stf[distance(names.begin(), find(names.begin(), names.end(), name))];
        if (shop.GET_NUM() == 0)
        {
            cout << "E007:The goods sold out" << endl;
            return;
        }
        if (shop.GET_PRICE() > balance)
        {
            cout << "E008:Lack of balance" << endl;
            return;
        }
        //购买成功
        shop.reduceStuff();
        balance -= shop.GET_PRICE();
        cout << "S003:Buy success,balance=" << balance << endl;
    }

    /*
    4.退币
        命令格式：c
    */
    void SendBack(string cmd)
    {
        if (balance == 0)
        {
            cout << "E009:Work failure" << endl;
            return;
        }
        vector<int> info(coins.size());
        for (int i = coins.size() - 1; i >= 0; i--)
        {
            int coin = coins[i];
            while (balance >= coin && box.getCoinNum(coin) > 0)
            {
                balance -= coin;
                box.reduceCoin(coin);
                info[i]++;
            }
        }
        for (int i = 0; i < int(info.size()); i++)
        {
            cout << coins[i] << " yuan coin number=" << info[i] << endl;
        }
    }

    /*
    5.查询
        命令格式：q 查询类别
    */
    static bool cmp(Stuff s1, Stuff s2)
    {
        return s1.GET_NUM() < s2.GET_NUM();
    }
    void Search(string cmd)
    {
        if (cmd == "q 0")
        {
            // 根据商品数量从大到小排序
            vector<Stuff> stf_ = stf;
            sort(stf_.begin(), stf_.end(), cmp);
            for (auto elem : stf_)
            {
                cout << elem.GET_NAME() << " " << elem.GET_PRICE() << " " << elem.GET_NUM() << endl;
            }
            return;
        }
        if (cmd == "q 1")
        {
            for (int coin : coins)
            {
                cout << coin << "yuan coin number=" << box.getCoinNum(coin) << endl;
            }
            return;
        }
        cout << "E010:Parameter error" << endl;
    }
};

int main()
{
    string str; //输入初始化信息
    System sys; //创建一个system对象
    while (getline(cin, str))
    {
        //解析指令集
        vector<string> cmds;
        string temp = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ';')
            {
                temp += str[i];
            }
            else
            {
                cmds.push_back(temp);
                temp.clear();
            }
        }

        for (int i = 0; i < cmds.size(); i++)
        {
            cout << cmds[i] << endl;
            sys.Run(cmds[i]);
        }
    }

    return 0;
}