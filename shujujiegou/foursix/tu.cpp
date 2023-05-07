#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105; //最大顶点数
bool vis[MAXN];
typedef struct ArcNode
{                            //边结点
    int adjvex;              //该边所指向的顶点的位置
    struct ArcNode *nextarc; //指向下一条边的指针
} ArcNode;
typedef struct VNode
{ //顶点信息
    int data;
    ArcNode *firstarc;  //指向第一条依附该节点的边的指针
} VNode, AdjList[MAXN]; // AdjList表示邻接表类型
typedef struct
{ //邻接表
    AdjList verlist;
    int vexnum, arcnum; //图的当前顶点数和边数
} Graph;

void WCreateUDG(Graph &G)
{ //创建无向图
    cin >> G.vexnum >> G.arcnum;
    for (int i = 1; i <= G.vexnum; i++)
    { // vexnum个结点
        cin >> G.verlist[i].data;
        G.verlist[i].firstarc = NULL; //先设定没有依附该结点的边
    }
    for (int i = 1; i <= G.arcnum; i++)
    {
        int x, y;
        cin >> x >> y;
        ArcNode *p1 = new ArcNode;
        ArcNode *p2 = new ArcNode;
        p1->adjvex = y;
        p1->nextarc = G.verlist[x].firstarc;
        G.verlist[x].firstarc = p1; //类似于头插法，把结点看成头节点，附属边为链点
        p2->adjvex = x;
        p2->nextarc = G.verlist[y].firstarc;
        G.verlist[y].firstarc = p2;
    }
}

void YCreateUDG(Graph &G)
{ //创建有向图
    cin >> G.vexnum >> G.arcnum;
    for (int i = 1; i <= G.vexnum; i++)
    {
        cin >> G.verlist[i].data;
        G.verlist[i].firstarc = NULL;
    }
    for (int i = 1; i <= G.arcnum; i++)
    {
        int x, y;
        cin >> x >> y;
        ArcNode *p1 = new ArcNode;
        p1->adjvex = y;
        p1->nextarc = G.verlist[x].firstarc;
        G.verlist[x].firstarc = p1;
    }
}

void DFS(Graph G, int u)
{ // u一开始为1,调用dfs函数
    ArcNode *p = G.verlist[u].firstarc;
    vis[u] = true; //标记
    cout << u << " ";
    while (p != NULL)
    {
        if (!vis[p->adjvex])
        { //如果u结点附属的边没有标记过就深搜
            DFS(G, p->adjvex);
        }
        p = p->nextarc; //背
    }
}

void BFS(Graph G)
{ //不调用BFS函数，用while(!Q.empty())判空
    queue<int> Q;
    memset(vis, 0, sizeof(vis));
    cout << "v1 ";
    Q.push(1);     //从1开始
    vis[1] = true; //标记
    while (!Q.empty())
    { //若不为空则循环
        int u = Q.front();
        Q.pop();
        ArcNode *p = G.verlist[u].firstarc; //连接的第一个边
        while (p != NULL)
        {
            if (!vis[p->adjvex])
            {                                    //如果没标记
                cout << "v" << p->adjvex << " "; //直接输出
                vis[p->adjvex] = true;           //标记
                Q.push(p->adjvex);               //入队
            }
            p = p->nextarc; //背
        }
    }
}

int in[MAXN], out[MAXN];
void GetInfo(Graph G)
{ //计算入度和出度
    for (int i = 1; i <= G.vexnum; i++)
    {
        ArcNode *p = G.verlist[i].firstarc;
        while (p != NULL)
        {
            in[p->adjvex]++;
            out[i]++;
            p = p->nextarc;
        }
    }
}

void Print(Graph G)
{ //输出邻接表
    for (int i = 1; i <= G.vexnum; i++)
    {
        ArcNode *p = G.verlist[i].firstarc;
        cout << i << ":";
        while (p != NULL)
        {
            cout << p->adjvex;
            if (p->nextarc != NULL)
                cout << " ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

void tuopu(Graph G)
{ //拓扑排序
    stack<int> s;
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (in[i] == 0)
            s.push(i);
    }
    while (!s.empty())
    {
        int m = s.top();
        cout << "v" << m << " ";
        s.pop();
        ArcNode *p = new ArcNode;
        p = G.verlist[m].firstarc;
        while (p != NULL)
        {
            in[p->adjvex]--;
            if (in[p->adjvex] == 0)
            {
                s.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

int main()
{
    Graph G;
    YCreateUDG(G); //创建有向图
    WCreateUDG(G); //创建无向图
    DFS(G, 1);     //深搜递归遍历
    BFS(G);        //广搜遍历（用队列）
    GetInfo(G);    //计算入度和出度
    Print(G);      //输出邻接表
    return 0;
}
