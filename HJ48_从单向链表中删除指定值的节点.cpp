#include <iostream>
#include <string>
#include <vector>

using namespace std;

//单向链表节点
struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};

//创建一个链表（链表初始化）(头结点)
ListNode *Init_LinkList(void)
{
    ListNode *head;                              //创建头节点
    head = (ListNode *)malloc(sizeof(ListNode)); //分配内存
    head->m_pNext = NULL;                        //指针域置空（数据域可以不管）
    return head;
}

//查找元素
ListNode *Search_LinkList(ListNode *head, int elem) //在head链表中查找elem元素
{
    ListNode *pMove = head->m_pNext;
    while (pMove->m_nKey != elem)
    {
        pMove = pMove->m_pNext;
    }
    //找到了指定元素返回此时的指针域
    return pMove;
}

//遍历打印操作
void Print_LinkList(ListNode *head)
{
    ListNode *pMove = head->m_pNext;
    while (pMove)
    {
        cout << pMove->m_nKey << " ";
        pMove = pMove->m_pNext;
    }
    cout << endl;
}

//建立单链表  在L的尾部插入数据
void Insert(ListNode *L, vector<int> val, int n) //此处的n指的是链表的长度
{
    // ListNode *newnode, *tail;
    // tail = L; // tail始终指向尾结点，开始时指向头结点
    // for (int i = 0; i < n; i++)
    // {
    //     newnode = (ListNode *)malloc(sizeof(ListNode)); //分配内存
    //     newnode->m_nKey = val[i];                       //将待插值赋给新节点
    //     tail->m_pNext = newnode;                        //将新节点设置为当前尾部节点的新节点
    //     tail = newnode;                                 //把当前新节点定义为尾部节点
    // }
    // tail->m_pNext = NULL; //最后将尾结点置为空

    ListNode *node_to, *node_from, *tail;
    tail = L; // tail始终指向尾结点，开始时指向头结点

    //先建立第一组的链表
    node_from = (ListNode *)malloc(sizeof(ListNode)); //分配内存
    node_from->m_nKey = val[1];
    tail->m_pNext = node_from;
    tail = node_from;

    node_to = (ListNode *)malloc(sizeof(ListNode)); //分配内存
    node_to->m_nKey = val[0];
    tail->m_pNext = node_to;
    tail = node_to;

    for (int i = 1; i < n - 1; i++) //后续插入要在链表当中查找指定元素并插入在其后面
    {
        //分两种情况，第一种，在中间插入，第二种，在尾部插入
        ListNode *pFind = Search_LinkList(L, val[2 * i + 1]);
        if (pFind->m_pNext == NULL) //在尾部插入
        {
            ListNode *newnode = (ListNode *)malloc(sizeof(ListNode)); //分配内存
            newnode->m_nKey = val[2 * i];                             //将待插值赋给新节点
            tail->m_pNext = newnode;                                  //将新节点设置为当前尾部节点的新节点
            tail = newnode;                                           //把当前新节点定义为尾部节点
        }
        else //在中间插入
        {
            ListNode *newnode = (ListNode *)malloc(sizeof(ListNode)); //分配内存
            newnode->m_nKey = val[2 * i];                             //将待插值赋给新节点

            ListNode *temp = (ListNode *)malloc(sizeof(ListNode)); //分配内存
            temp->m_pNext = pFind->m_pNext;
            pFind->m_pNext = newnode;
            newnode->m_pNext = temp->m_pNext;
        }
    }
    tail = NULL; //插入完成将尾指针置空
}

int main()
{
    // 1.输入链表结点个数
    int n;
    cin >> n;

    // 2.输入头结点的值
    int head_num;
    cin >> head_num;

    // 3.按照格式插入各个结点(n-1组数据)
    /*
    说明一下，把两两一组放入vec中，其中偶数下标的为to，奇数下标的为from
    长度为n的链表要输入n-1组数据
    */
    vector<int> val(2 * (n - 1));
    for (int i = 0; i < n - 1; i++)
    {
        int to, from;
        cin >> to >> from;
        val[2 * i] = to;
        val[2 * i + 1] = from;
    }

    // 4.输入要删除的结点的值
    int delete_num;
    cin >> delete_num;

    //生成链表

    ListNode *head;
    //链表初始化    Init_LinkList
    head = Init_LinkList();
    //创建链表
    Insert(head, val, n - 1);

    Print_LinkList(head);//打印链表         -------------------------------------------------------这一方法有问题

    return 0;
}



/********************************************************************************************************************************************************/
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n,head;
//     cin>>n>>head;    //输入结点数和头结点的值
//     forward_list<int> linklist;    //创建一个单向链表
//     linklist.push_front(head);    //初始化头结点
//     for(int i=1;i<n;i++) {
//         int front,back;
//         cin>>back>>front;
//         auto it=find(linklist.begin(), linklist.end(), front);
//         linklist.insert_after(it, back);    //逐个插入结点
//     }
//     int last;
//     cin>>last;    //输入要删除的结点值
//     linklist.remove(last);    //移除具有该值的节点
//     for(auto it=linklist.begin();it!=linklist.end();it++) {
//         cout<<*it<<" ";    //从头到尾输出链表的值
//     }
//     cout<<endl;
//     return 0;
// }

/********************************************************************************************************************************************************/
// #include <iostream>
// #include <forward_list>
// #include <algorithm>
// #include <vector>
// using namespace std;

// #ifdef FIRST_METHOD
// /*
// 方法一：
// 思路：将头结点插入forward_list, find函数查找第一个元素，若查找到数字的位置，则下一位插入；通过remove函数删除节点。
// */
// /*
// void RemoveNodeFromForwardList(int num, int  head)
// {
//     forward_list<int> forwardList; // 创建一个单链表
//     forwardList.push_front(head); // 初始化头结点
//     for(int i = 1; i < num; i++) {
//         int front, back;
//         cin>>back>>front;
//         auto iter = find(forwardList.begin(), forwardList.end(), front);
//         forwardList.insert_after(iter, back);
//     }
//     int last;
//     cin>>last; // 输入要删除的节点
//     forwardList.remove(last);
//     for(auto iter = forwardList.begin(); iter != forwardList.end(); iter++) {
//         cout<<*iter<<" ";
//     }
//     cout<<endl;
// }
// */
// /*
// 方法二：
// 思路：将头结点插入vector, find函数查找第一个元素，若查找到数字的位置，则下一位插入；
// 若最后位置查找到，则直接插入；通过erase函数删除节点。
// */
// void RemoveNodeFromForwardList(int num, int  head)
// {
//     vector<int> vec; 
//     vec.push_back(head); // 初始化头结点
//     for(int i = 1; i < num; i++) {
//         int front, back;
//         cin>>back>>front;
//         auto iter = find(vec.begin(), vec.end(), front);
//         if (iter != vec.end()) {
//             vec.insert(iter+1, back);
//         } else {
//             ec.push_back(back);
//         }
        
//     }
//     int last;
//     cin>>last; // 输入要删除的节点
//     vec.erase(vec.begin(), vec.end(), remove);
//     for(auto iter = forwardList.begin(); iter != forwardList.end(); iter++) {
//         cout<<*iter<<" ";
//     }
//     cout<<endl;
// }

// #else


// /*
// 思路：我们也可以用正统的链表做法。构建链表，然后依次将结点插入。
// 插入的时候遍历链表找到插入结点的前序结点（因为表中元素互异），断开前序结点与后序结点的连接，插入结点连接后续结点，前序结点连接插入结点。
// 后续直接遍历链表输出，当遇到要删除的结点值时不输出即可。
// */

// struct Node {
//     int data;
//     struct Node * next;
//     Node(int x) : data(x), next(nullptr) {}
// };
// void RemoveNodeFromForwardList(int num, int  head)
// {
//      Node *pHead = new Node(head); //head = 2
//      for(int i = 1; i < num; i++) {
//         int pre, cur;
//         cin>>cur>>pre; // cur = 1, pre =2
//         Node *pCurNode = new Node(cur);
//         Node *pPreNode = pHead;
//         while(pPreNode->data != pre) {
//             pPreNode = pPreNode->next;
//         }
//         pCurNode->next = pPreNode->next; // 断开
//         pPreNode->next = pCurNode; //插入
//     }
//     int remove;
//     cin>>remove;
//     Node *pNewNode = pHead;
//     while(pNewNode !=nullptr) {
//         if(pNewNode->data != remove) {
//             cout<<pNewNode->data<<" ";
//         }
//         pNewNode = pNewNode->next;
//     }
//     cout<<endl;
// }
// #endif

// int main()
// {
//     int num, head;
//     while(cin>>num>>head) {
//         RemoveNodeFromForwardList(num, head);
//     }
// }
/********************************************************************************************************************************************************/