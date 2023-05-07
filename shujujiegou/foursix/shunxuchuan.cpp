#include <bits/stdc++.h>
using namespace std;
#define MAXNUM 100
typedef struct
{
    char c[MAXNUM]; //串允许的最大长度
    int n;          //串的长度
} SeqString;
typedef struct
{ //定义(2)堆分配存储
    char *str;
    int length;
} STRING;
STRING STRINGInit()
{              //创建空顺序串
    STRING *s; //*s!!
    s->str = new char[1];
    s->str[0] = '\0';
    s->length = 0;
    return *s;
}
int StringAssign(STRING *s, STRING *t)
{ //串的赋值
    if (s->str)
        delete (s->str); //删除串
    int len = t->length;
    s->length = len;
    if (len == 0)
    {
        s->str = new char[1];
        s->str[0] = '\0';
    }
    else
    {
        s->str = new char[len + 1];
        if (s->str == NULL)
            return 0;
        for (int i = 0; i <= len; i++)
        {
            s->str[i] = t->str[i];
        }
    }
    return 1;
}
int StringConcat(STRING *s, STRING *t)
{ //串连接
    STRING temp;
    StringAssign(&temp, s);
    int len = s->length + t->length;
    s->length = len;
    delete (s->str);
    s->str = new char[len + 1];
    int i, j;
    if (!s->str)
        return 0;
    else
    {
        for (i = 0; i < temp.length; i++)
        {
            s->str[i] = temp.str[i];
        }
        for (j = 0; j <= t->length; j++, i++)
        {
            s->str[i] = t->str[j];
        }
        free(temp.str);
        return 1;
    }
}
int Index(STRING *s, STRING *t)
{ //串定位
    int i = 0, j = 0;
    while (i < s->length && j < t->length)
    {
        if (s->str[i] == t->str[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == t->length)
        return i - t->length + 1;
    else
        return 0;
}
int main()
{

    system("pause");
}