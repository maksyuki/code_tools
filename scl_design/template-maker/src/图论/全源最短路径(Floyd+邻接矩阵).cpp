/***********************************************
求全源最短路径，可以使用邻接矩阵或者是邻接表来初
始化最短距离数组
************************************************
@接口: void floyd ()
@功能: 求全源最短路径
@时间复杂度: O (n^3)
************************************************/

//分别表示邻接矩阵和最短距离数组
int edge[maxn][maxn], dis[maxn][maxn];
//分别表示顶点个数和边数
int n, m;

//初始化邻接矩阵
void Init ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                edge[i][j] = 0;

            else
                edge[i][j] = INF;
        }
}

//数组下标从1开始
void floyd ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = edge[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == k || j == k)
                    continue;

                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
            }
}
