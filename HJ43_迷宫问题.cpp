#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
方法一：采用dfs递归+回溯法
    具体做法：
    我们可以从迷宫入口开始进行dfs搜索，每次进入一个点，将其加入临时路径数组中，把该位改成0表示不能进入，然后依次搜索该位上、右、下、左四个方向的点，如果搜索的这个点可以进入则路径进入，如果四个方向都没有可以走的路表示此路不通，回溯——删去路径最后一个，重置该位为0. 找到横纵坐标都等于矩阵最后一位则表示找到路径，复制现有路径然后返回。
*/
vector<pair<int, int>> res;
//参数的含义
void dfs(vector<vector<int>> &matrix, int n, int m, int i, int j, vector<pair<int, int>> &paths)
{
    paths.push_back(make_pair(i, j)); //记入路径
    matrix[i][j] = 1;                 //经过部分设置为1，表示后续不能经过
    if (i == n - 1 && j == m - 1)
    { //到达终点
        res = paths;
        return;
    }
    //四个方向搜索
    if (i + 1 < n && matrix[i + 1][j] == 0)
        dfs(matrix, n, m, i + 1, j, paths);
    if (j + 1 < m && matrix[i][j + 1] == 0)
        dfs(matrix, n, m, i, j + 1, paths);
    if (i - 1 >= 0 && matrix[i - 1][j] == 0)
        dfs(matrix, n, m, i - 1, j, paths);
    if (j - 1 >= 0 && matrix[i][j - 1] == 0)
        dfs(matrix, n, m, i, j - 1, paths);
    paths.pop_back(); //回溯
    matrix[i][j] = 0;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) //输入迷宫矩阵
                cin >> matrix[i][j];
        vector<pair<int, int>> paths;        //记录临时路径
        dfs(matrix, n, m, 0, 0, paths);      // dfs遍历矩阵
        for (int i = 0; i < res.size(); i++) //输出路径
            cout << "(" << res[i].first << "," << res[i].second << ")" << endl;
    }
    return 0;
}


/*
方法二：DFS非递归+逆向搜索
    具体做法：
    dfs有递归就有非递归，但是因为递归需要不断回溯，而栈一般难以做到连续回溯，我们可以采用别的策略。
    首先注意到这道题矩阵的长和宽都10以内，因此我们可以在dfs到达一个点的时候将这个位置的值改成它是由哪个点过来的，遍历到最后，我们从终点不断反向搜索就可以到达起点，然后反向输出路径即可。
    怎么记录每个点的前序坐标，我们可以用100∗i+j修改该点信息，反向搜索时可以用整除100和对100取模将坐标提取出来。
*/
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;

// int main(){
//     int n, m;
//     int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//     while(cin >> n >> m){
//         vector<vector<int> > matrix(n + 1, vector<int>(m + 1, 0)); 
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= m; j++) //输入迷宫矩阵
//                 cin >> matrix[i][j];
//         stack<pair<int, int> > s; //记录深度优先的栈
//         s.push(make_pair(1, 1)); //第一个结点入栈
//         matrix[1][1] = 1;
//         vector<pair<int, int> > res;
//         while(!s.empty()){
//             auto p = s.top();
//             s.pop();
//             for(int i = 0; i < 4; i++){ //四个方向
//                 int x = p.first + direct[i][0];
//                 int y = p.second + direct[i][1];
//                 if(x > 0 && y > 0 && x <= n && y <= m && matrix[x][y] == 0){ //确保不越界再看是否为0
//                     matrix[x][y] = p.first * 100 + p.second; //修改矩阵为前一个的坐标，百位为i，个位为j
//                     if(x == n && y == m)  //到达终点
//                         break;
//                     s.push(make_pair(x, y));
//                 }
//             }
//         }
//         int i = n;
//         int j = m;
//         while(matrix[i][j] != 1){ //直到遇到起点
//             res.push_back(make_pair(i, j)); //从终点逆向添加
//             int temp = matrix[i][j];
//             i = temp / 100;
//             j = temp % 100;
//         }
//         res.push_back(make_pair(1, 1)); //添加起点
//         for(int i = res.size() - 1; i >= 0; i--) //反向输出路径
//             cout << "(" << res[i].first - 1<< "," << res[i].second - 1<< ")" << endl;
//     }
//     return 0;
// }
