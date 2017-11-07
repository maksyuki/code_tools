/***********************************************
使用dfs进行增广，适用于稠密图
************************************************
@接口: void Init ()
@功能: 初始化邻接矩阵
@时间复杂度: O (n ^ 2)

@接口: int dfs (int u)
@功能: 进行dfs增广
@时间复杂度:
@u: 表示一个非饱和点

@接口: long long MaxMatch ()
@功能: 依次查找非饱和点进行匹配尝试
@时间复杂度: O (n ^ 3)
************************************************/

//分别表示邻接矩阵和顶点的访问标志
int edge[maxn][maxn], vis[maxn];
int cx[maxn], cy[maxn], cxlen, cylen;//cx[i]表示集合cx中与i匹配的cy集合中的节点和集合中点的个数

void Init ()//初始化邻接矩阵
{
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            edge[i][j] = INF;
}

//进行dfs增广
int dfs (int u)
{
    for (int v = 1; v <= cylen; v++)
        if (edge[u][v] < INF && !vis[v])
        {
            vis[v] = 1;
            if (cy[v] == -1 || dfs (cy[v]))
            {
                cy[v] = u;
                cx[u] = v;
                return 1;
            }
        } 
    return 0;
}

//数组下标从1开始
long long MaxMatch ()
{
    long long res = 0;
    memset (cx, -1, sizeof (cx));//初始化集合cx
    memset (cy, -1, sizeof (cy));//初始化集合cy
    for (int i = 1; i <= cxlen; i++)
        if (cx[i] == -1)
        {
            memset (vis, 0, sizeof (vis));
            res += dfs (i);
        }
    return res;
}
