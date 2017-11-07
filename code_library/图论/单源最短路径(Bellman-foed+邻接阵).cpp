/***********************************************
************************************************
@接口: void Init ()
@功能:  初始化邻接矩阵
@时间复杂度: O (n ^ 2)

@接口: void Bellman_ford (int s)
@功能: 求解从开始的但源最短路
@时间复杂度:  O (n ^ 3)
@s: 源点
************************************************/

//分别表示节点到源点的最短距离、邻接矩阵和顶点个数
int dis[maxn], edge[maxn][maxn], n;

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
void Bellman_ford (int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    dis[s] = 0;
    for (int i = 1; i < n; i++)//迭代n-1次
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != s)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (dis[k] < INF && edge[k][j] < INF && dis[k] + edge[k][j] < dis[j])
                        dis[j] = dis[k] + edge[k][j];
                }
            }
        }
    }
    //判断负圈的话需要再进行一次迭代，看是否存在一个点v的dis[v]会再次被松弛
    //如果存在，则说明图中存在负圈
}
