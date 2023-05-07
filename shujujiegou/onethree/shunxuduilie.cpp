#include<stdio.h>
#include<stdlib.h>
/*
一般队列定义：
#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int front,rear;//初值均为0
}SeQueue;
SeQueue Q;

  空队列条件：Q.fear==Q.rear
  入队列：Q.daat[Q.reat]=x;Q.rear++;
  出队列：x=Q.data[Q.fear];Q.fear++;
  当fear=0,rear=M时，再有元素入队发生真溢出
  当fear!=0,rear=M时，再有元素入队发生假溢出
  用循环队列解决:
  基本思想：把队列设想乘环型，让q[0]接在q[M-1]之后，若rear==M,则令r=0;(取模实现)
  实现：利用模运算
  入队:q[rear]=x;r=(r+1)%M;
  出队：x=q[fear];f=(f+1)%M;
  队空：Q.fear==Q.rear
  队满：Q.fear==Q.rear
  区别队空和队满：{
      1.少用一个存储空间
      2.引入一个标志变量区别空和满
      3.使用计数器
  }
*/

//循环队列定义：
#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int front,rear;
}SeQueue;
SeQueue Q;
int QueueInit(SeQueue &Q){
    Q.front=0;Q.rear=0;
    return 1;
}
int QueueIn(SeQueue &Q,int x){
    if((Q.rear+1)%MAXSIZE==Q.front){
        printf("队列满\n");
        return 0;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return 1;
}
int QueueOut(SeQueue &Q,int &x){
    if(Q.front==Q.rear){
        printf("Empty\n");return 0;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return 1;
}
int GetHead(SeQueue Q){
    return Q.data[Q.front];
}
int SeQueueEmpty(SeQueue Q){
    if(Q.front==Q.rear)return 1;
    else return 0;
}
int main(){

}
