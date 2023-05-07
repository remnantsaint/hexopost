#include <bits/stdc++.h>
using namespace std;
//定义函数时用BinTree和SeQueue,需要改变结构的时候加&，不改变就不加
typedef struct BinNode
{ //正常定义
    char data;
    struct BinNode *left;
    struct BinNode *right;
} BinNode, *BinTree;
#define MAXSIZE 1024 //用了循环结构
typedef struct
{                          //节点定义
    BinTree data[MAXSIZE]; //存放树结点
    int front, rear;       //front为头节点，rear为尾节点，树的结点有rear端插入，如果front==rear就是空
} SeQueue;
void QueueInit(SeQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
}
void QueuePush(SeQueue &Q, BinTree x)
{ //入队列
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}
void GetHead(SeQueue Q, BinTree &x)
{ //取头节点
    x = Q.data[Q.front];
}
bool QueueEmpty(SeQueue Q)
{ //判空
    if (Q.front == Q.rear)
        return 1;
    return 0;
}
void QueuePop(SeQueue &Q, BinTree &x)
{ //出队列
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
}

void CreateBinTree(BinTree &T)
{ //先正常先序创二叉树，写法不变
    char ch;
    cin >> ch;
    if (ch == '@')
        T = NULL;
    else
    {
        T = new BinNode;
        T->data = ch;
        CreateBinTree(T->left);
        CreateBinTree(T->right);
    }
}

void BfsTree(BinTree T)
{ //广度层次遍历
    SeQueue Q;
    QueueInit(Q);
    QueuePush(Q, T); //直接入队整棵树的头节点
    while (!QueueEmpty(Q))
    { //如果Q不为空就一直循环
        BinTree output;
        output = new BinNode;
        QueuePop(Q, output);  //让output等于结点
        cout << output->data; //输出该结点值
        if (output->left != NULL)
            QueuePush(Q, output->left); //一点点加入遍历，固定写法
        if (output->right != NULL)
            QueuePush(Q, output->right);
    }
}

int main()
{
    BinTree T;
    CreateBinTree(T);
    BfsTree(T);
    return 0;
}
