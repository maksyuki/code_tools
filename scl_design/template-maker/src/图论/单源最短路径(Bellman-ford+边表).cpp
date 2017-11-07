/***********************************************
求解从源点到其他节点的最短路，注意下面的算法适用
于无向图和有向图，只是对于无向图来说在构造边表时
同一个边要插入两次
************************************************
@接口: void bellman_ford (int s)
@时间复杂度: O (n * m)
@s: 源点
************************************************/

int dis[maxn], path[maxn];

void Bellman_ford (int s)
{
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
        path[i] = -1;
    }

    dis[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[edge[j].u] < INF && dis[edge[j].v] > dis[edge[j].u] + edge[j].w)
            {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
                path[edge[j].v] = edge[j].u;
            }
        }
    }
}
