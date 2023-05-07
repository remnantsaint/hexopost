#include<stdlib.h>
#include<stdio.h>
const int MAXSIZE = 1024;
typedef struct{
    int data[MAXSIZE];
    int top;
}SeqStack;
SeqStack S;
int StackInit(SeqStack &S){
    S.top=-1;//栈顶初值为-1，下溢
    return 1;
}
int StackEmpty(SeqStack S){
    if(S.top==-1){
        return 1;
    }
    else return 0;
}
int StackPush(SeqStack &S,int x){//入栈
    if(S.top==MAXSIZE-1){
        printf("栈满\n");//上溢
        return 0;
    }
    S.top++;
    S.data[S.top]=x;
    return 1;
}
int StackPop(SeqStack &S,int &x){//出栈
    if(S.top==-1){
        printf("栈空\n");
        return 0;
    }
    x=S.data[S.top];
    S.top--;
    return 1;
}
int StackGetTop(SeqStack S){//取栈顶元素
    return S.data[S.top];
}
int main(){
    
}
/*
应用：
回文子串：
int huiwen(char *s){
    char ch,*ps,data[20];
    ps=s;int i=0;//ps=s后默认从第一个元素下标为0开始
    while(*ps!='\0'){
        data[i]=*ps;ps++;i++;
    }
    ps=s;i--;
    while(i>=0){
        ch=data[i];i--;
        if(ch!=*ps)return 0;
        ps++;
    }
    return 1;
}

数制转换:
void convert(){
    StackInit(S);
    scanf("%d",&N);
    while(N!=0){
        Push(S,N%8);
        N=N/8;
    }
    while(!StackEmpty(S)){
        e=Pop(S);
        printf("%d",e);
    }
}

括号匹配:
int check(){
    StackInit(s);char ch;
    while((ch=getchar())!='\n'){
        switch(ch){
            case(ch=='('||ch=='['||ch=='{'):push(s,ch);break;
            case(ch==')')://括号一定能消去，否则就是不规则
                if(StackEmpty(s))return False;
                else {
                    pop(s,c);
                    if(c!='(')return False;
                }
                break;
            case(ch==']'):
                if(StackEmpty(s))return False;
                else {
                    pop(s,c);
                    if(c!='[')return False;
                }
                break;
            case(ch=='}'):
                if(StackEmpty(s))return False;
                else {
                    pop(s,c);
                    if(c!='{')return False;
                }
                break;
            default:break;
        }
    }
    if(StackEmpty(s))return True;
    else return False;
}

中缀表达式求值：
int CalulExp(){
    StackInit(optr);
    Push(optr,'#');
    StackInit(opnd);
    scanf("%c",&ch);
    while(!((ch=='#')&&(StackGetTpo(optr)=='#'))){
        if(ch>='0'&&ch<='9'){
            Push(opnd,ch);
            scanf("%c",&ch);
        }
        else if(ch=='('){
            Push(optr,ch);
            scanf("%c",&ch);
        }
        else if(ch==')'){
            while(StackGetTop(opr)!='('){
                theta=Pop(optr);
                b=Pop(opnd);a=Pop(opnd);
                Push(opnd,operate(a,thrta,b));
            }
            Pop(optr);scanf("%c",&ch);
        }
        else switch(precede(ch,StackGetTop(optr))){
            case '>':Push(optr,ch);scanf("%c",&ch);break;
            case '<=':theta=Pop(optr);
            b=Pop(opnd);a=Pop(opnd);
            Push(opnd,operate(a,thrta,b));
        }
    }
    return StackGetTop(opnd);
}
*/