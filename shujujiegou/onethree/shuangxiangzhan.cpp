#include<stdlib.h>
#include<stdio.h>
const int M = 100;
typedef struct DStack{//双向栈是顺序栈
    int v[M];
    int top1,top2;//s.top1=-1和s.top2=M表示栈空，栈顶相遇表示满
}DStack;
DStack s;
int push(DStack &s,int i,int x){
    if(s.top2-s.top1==1)return 0;//栈满
    else{
        switch(i){
            case 1:s.v[++s.top1]=x;break;
            case 2:s.v[--s.top2]=x;break;
            default:printf("栈编号输入错误");return 0;
        }
    }
    return 1;
}
int pop(DStack &s,int i,int &x){
    switch(i){
        case 1:if(s.top1==-1)return 0;
                else x=s.v[s.top1--];break;
        case 2:if(s.top2==M)return 0;
                else x=s.v[s.top2++];break;
        default:printf("栈编号输入错误");return 0;
    }
    return 1;
}
int top(DStack s,int i){
    int x;
    switch(i){
        case 1:if(s.top1==-1)return 0;
                x=s.v[s.top1];break;
        case 2:if(s.top2==M)return 0;
                x=s.v[s.top2];break;
        default:printf("栈编号输入错误");return 0;
    }
    return x;
}
int main(){
    
}