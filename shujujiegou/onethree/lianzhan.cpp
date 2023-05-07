//#include<stdio.h>
//#include<stdlib.h>
//typedef struct StackNode{//栈只在栈顶操作，不设头节点
//    int data;
//    struct StackNode *next;
//}StackNode,*LinkStack;
//int StackInit(LinkStack &top){
//    top=NULL;
//    return 1;
//}
//int StackEmpty(LinkStack top){
//    if(top==NULL)return 1;
//    else return 0;
//}
//void StackPush(LinkStack &top,int x){//入栈
//    StackNode *s;
//    s=new StackNode;
//    s->data=x;
//    s->next=top;
//    top=s;//top时栈顶
//}
//int StackPop(LinkStack &top,int &x){
//    if(top==NULL){
//        printf("Stack Empty!");
//        return 0;
//    }
//    x=top->data;
//    StackNode *p;
//    p=top;
//    top=top->next;
//    delete p;
//}
//int main(){
//  引用的时候用push(s,x);不加符号
//}

#include <stdio.h>
#include <stdlib.h>
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, *node;
int Push(node &s, int x)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = s;
    s = p;
    return 1;
}
int Pop(StackNode *&s, int *x)
{
    //StackNode *p;
    if (s == NULL)
        return 0;
    *x = s->data;
    s = s->next;
    return 1;
}
int empty(StackNode *&s)
{
    if (s == NULL)
        return 1;
    return 0;
}
int main()
{
    StackNode *s;
    s = NULL;
    int x;
    while (~scanf("%d", &x) && x)
    {
        Push(s, x);
    }
    while (!empty(s))
    {
        Pop(s, &x);
        printf("%d ", x);
    }
    system("pause");
    return 0;
}
/*
1 2 3 4 5 6 0
*/
