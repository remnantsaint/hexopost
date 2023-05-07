#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef struct BinNode
{
    char data;
    struct BinNode *left, *right;
} BinNode, *BinTree;

void CreatBinTree(BinTree &T)
{ //先序创建二叉树
    char ch;
    cin >> ch;
    if (ch == '@')
        T = NULL;
    else
    {
        T = new BinNode;
        T->data = ch;
        CreatBinTree(T->left);
        CreatBinTree(T->right);
    }
}

void PreOrder(BinTree T)
{ //先序遍历输出
    if (T != NULL)
    {
        cout << T->data;
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void InOrder(BinTree T)
{ //中序遍历输出
    if (T != NULL)
    {
        InOrder(T->left);
        cout << T->data;
        InOrder(T->right);
    }
}

void BackOrder(BinTree T)
{ //后序遍历输出
    if (T != NULL)
    {
        BackOrder(T->left);
        BackOrder(T->right);
        cout << T->data;
    }
}

#define MAXSIZE 1024 //层次遍历非stl写法
typedef struct
{                          //建队列结构体
    BinTree data[MAXSIZE]; //存放结构体的顺序结构
    int front, rear;
} SeQueue;
void QueueInit(SeQueue &Q)
{
    Q.front = 0;
    Q.rear = 0; //初始化令front和rear都为0
}
void QueuePush(SeQueue &Q, BinTree x)
{
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}
void GetHead(SeQueue Q, BinTree &x) { x = Q.data[Q.front]; }
int QueueEmpty(SeQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
}
void QueuePop(SeQueue &Q, BinTree &x)
{
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
}
void BfsTree(BinTree T)
{
    SeQueue Q;
    QueueInit(Q);
    QueuePush(Q, T); //直接将根节点入队
    while (!QueueEmpty(Q))
    {
        BinTree output;
        output = new BinNode;
        QueuePop(Q, output);
        cout << output->data; //先输出后遍历
        if (output->left != NULL)
            QueuePush(Q, output->left);
        if (output->right != NULL)
            QueuePush(Q, output->right);
    }
}

void BFS(BinTree T)
{ //层次遍历stl写法
    queue<BinTree> Q;
    Q.push(T);
    while (!Q.empty())
    {
        BinTree output;
        output = new BinNode;
        output = Q.front();
        Q.pop();
        cout << output->data;
        if (output->left != NULL)
            Q.push(output->left);
        if (output->right != NULL)
            Q.push(output->right);
    }
}

int CountLeaf(BinTree T)
{ //统计叶子个数
    int res = 0;
    if (T == NULL)
        return 0;
    else
    {
        if (T->left == NULL && T->right == NULL)
            return 1;
        else
            return CountLeaf(T->left) + CountLeaf(T->right);
    }
}

int GetDepth(BinTree T)
{
    int ld = 0, rd = 0;
    if (T == NULL)
        return 0;
    else
    {
        ld = GetDepth(T->left); //先搜索后计算
        rd = GetDepth(T->right);
        if (ld > rd)
            return ld + 1;
        else
            return rd + 1;
    }
}

int main()
{
    BinTree T;
    CreatBinTree(T);
    cout << GetDepth(T);
    return 0;
}

//树或森林转变为二叉树：左指针指向左孩子，右指针指向右边第一个兄弟
//二叉树转变为树或森林：左子树转变为它的子树，右子树转变为他的兄弟，若为根节点就转变为另一棵树