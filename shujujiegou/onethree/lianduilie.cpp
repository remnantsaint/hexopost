#include<stdlib.h>
#include<stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}LQNode,*LinkQNode;
typedef struct{
    LQNode *front,*rear;//将头尾指针封装在一起
}LQueue,*LinkQueue;
LinkQueue Q;
int QueueInit(LinkQueue &Q){
    LinkQNode p;
    Q=(LinkQueue)malloc(sizeof(LQueue));//申请头尾指针节点
    p=(LinkQNode)malloc(sizeof(LQNode));//申请链队头节点
    p->next=NULL;
    Q->front=Q->rear=p;
    return 1;
}
void QueueIn(LinkQueue &Q,int x){//入队
    LinkQNode p;
    p=(LinkQNode)malloc(sizeof(LQNode));
    p->data=x;
    p->next=NULL;
    Q->rear->next=p;//从队尾入队
    Q->rear=p;
}
int QueueEmpty(LinkQueue Q){
    if(Q->front==Q->rear){
        return 1;
    }
    else return 0;
}
int QueueOut(LinkQueue &Q,int &x){
    if(Q->front==Q->rear){
        printf("Queue Empty!\n");return 0;
    }
    LinkQNode p;
    p=Q->front->next;
    Q->front->next=p->next;//两段出队
    x=p->data;
    if(p==Q->rear)Q->rear=Q->front;//!!只有一个元素的时候，需要修改队尾指针
    delete p;
    return 1;
}
int main(){
    LinkQueue Q;
}