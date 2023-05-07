#include <bits/stdc++.h>
using namespace std;
/*typedef struct StrNode{//单节点链
    char c;
    struct StrNode *next;
}Lstring,*LinkedString;*/
#define CHUNKSIZE 80
typedef struct Chunk
{ //串的结点结构
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;
typedef struct
{                       //串的链表结构
    Chunk *head, *tail; //串的头尾指针
    int curlen;
} LString;

//模式匹配
void makeNext(STRING *p, int *next)
{
    int j, k, i;
    i = 1;
    j = 0;
    next[0] = -1;
    next[1] = 0;
    while (i < p->length)
    {
        if (j == 0 || t[i] == t[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
void makeNextval(STRING *p, int *nextval)
{
    int i = 1;
    nextval[1] = 0;
    int j = 0;
    whlie(i < p->length)
    {
        if (j == 0 || p->str[i] == p->str[j])
        {
            i++;
            j++;
            if (p->str[i] != p->str[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}
int index(STRING *s, STRING *p, int *next)
{
    int i, j;
    i = 0, j = 0;
    while (i < s->length && j < p->length)
    {
        if (j == -1 || s->str[i] == p->str[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= p->length)
    {
        return (i - p->length + 1);
    }
    else
        return 0;
}