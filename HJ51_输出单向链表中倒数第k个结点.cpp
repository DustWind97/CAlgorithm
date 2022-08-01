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

//创建节点（中间节点）
// ListNode *Create_ListNode(int data)
// {
//     ListNode *node;
//     node = (ListNode *)malloc(sizeof(ListNode)); //分配内存
//     node->m_nKey = data;
//     node->m_pNext = NULL; //指针域置空（数据域可以不管）
//     return node;
// }

//遍历操作
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

//尾插法建立单链表  在L的尾部插入数据
void TailInsert(ListNode *L, vector<int> val, int n)
{
    ListNode *newnode, *tail;
    tail = L; // r始终指向尾结点，开始时指向头结点
    for (int i = 0; i < n; i++)
    {
        newnode = (ListNode *)malloc(sizeof(ListNode)); //分配内存
        newnode->m_nKey = val[i];                       //将待插值赋给新节点
        tail->m_pNext = newnode;                        //将新节点设置为当前尾部节点的新节点
        tail = newnode;                                 //把当前新节点定义为尾部节点
    }
    tail->m_pNext = NULL; //最后将尾结点置为空
}

//双指针法查找倒数第k个节点
int MultiPointer_To_Find(ListNode *head, int k)
{
    ListNode *fast = head;
    ListNode *slow = head;
    for (int i = 0; i < k; i++) // fast先到达第k个节点
    {
        fast = fast->m_pNext;
    }
    while (fast != nullptr)
    {                         //使slow最终到达倒数第k个节点
        fast = fast->m_pNext; //注意fast与slow的顺序
        slow = slow->m_pNext;
    }
    return slow->m_nKey;
}

int main()
{
    //输入链表结点个数
    int n;
    // cin >> n;
    while (cin >> n)
    {
        //输入链表的值
        vector<int> val(n);
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        //输入k的值
        int k;
        cin >> k;

        //正序构建链表，构建后要忘记链表长度
        ListNode *head;
        //链表初始化    Init_LinkList
        head = Init_LinkList();
        //创建链表
        TailInsert(head, val, val.size());

        // Print_LinkList(head);
        cout << MultiPointer_To_Find(head, k) << endl;
    }

    return 0;
}