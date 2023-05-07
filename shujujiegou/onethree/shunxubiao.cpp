#include<stdio.h>
#include<stdlib.h>
const int MAXSIZE = 200;
typedef struct 
{
    int data[MAXSIZE];//顺序表元素是从下标0开始的
    int length;
}SeqList;
SeqList L;
int SeqLInit(SeqList &L){
    L.length=0;
    return 1;
}
int SeqLInsert(SeqList &L,int i,int x){//插入元素
    if(L.length==MAXSIZE){
        printf("Full");return 0;
    }
    if(i<1||i>L.length+1){
        printf("Error");return 0;
    }
    for(int j=L.length-1;j>=i-1;j++){
        L.data[j+1]=L.data[j];
    }
    L.data[i-1]=x;
    L.length++;
    return 1;
}
int SeqLDelete(SeqList &L,int i,int &x){//删除元素
    if((i<1)||(i>L.length)){
        printf("Error");return 0;
    }
    x=L.data[i-1];
    for(int j=i;j<=L.length-1;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return 1;
}
int SeqListLocate(SeqList L,int x){//按值查找
    int i;i=1;
    while(i<=L.length&&L.data[i-1]!=x){
        i++;
    }
    if(i<=L.length)return i;
    else return 0;
}
void Union(SeqList &LA,SeqList &LB){//LA和LB递增，将LB合并到LA中，元素仍递增
    int m=LA.length;int n=LB.length;
    int k=m+n-1;
    int i=m-1;int j=n-1;
    while(i>=0&&j>=0){
        if(LA.data[i]>=LB.data[j]){
            LA.data[k--]=LA.data[i--];
        }
        else LA.data[k--]=LB.data[j--];
    }
    while(j>=0){
        LA.data[k--]=LB.data[j--];
    }
    LA.length=m+n;
}
void Seqlnvert(SeqList &A){
    for(int i=0,j=A.length-1;i<j;i++,j--){
        int t=A.data[i];A.data[i]=A.data[j];A.data[j]=t;
    }
}
int main(){
    for(int i=0;i<=9;i++){
        L.data[i]=i;
    }
    SeqLInit(L);
    L.length=10;//很重要，得先求顺序表的长度，很多函数都要用长度
    Seqlnvert(L);
    system("pause");
}
