/***********************************************
链式前向星适用于有向图(其实也适用于无向图)
是一种邻接表的静态实现，比直接使用vector要好
默认构造的是出边表
************************************************
@接口: void Init ()
@功能: 初始化变量
@时间复杂度: O (1)

@接口: void AddEdge (int u, int v, int w)
@功能: 构建链式前向星
@时间复杂度: O (1)
@u: 始点
@v: 终点
@w: 边权
************************************************/

//分别表示顶点v、w和下一个邻接的位置
struct Node
{
    int v, w, nxt;
};

Node edge[maxn*maxn];
int head[maxn], edgelen;//分别表示顶点的表头节点和边的数量

//将所有的数组均初始化为-1
void Init ()
{
    memset (head, -1, sizeof (head));
    memset (edge, -1, sizeof (edge));
    edgelen = 0;
}

//使用头插法构建
void AddEdge (int u, int v, int w)
{
    edge[edgelen].v = v;
    edge[edgelen].w = w;
    edge[edgelen].nxt = head[u];
    head[u] = edgelen++;
}
