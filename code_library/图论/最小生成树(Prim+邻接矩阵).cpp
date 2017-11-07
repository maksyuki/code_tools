/***********************************************
************************************************
@接口: void Init ()
@功能: 初始化邻接矩阵
@时间复杂度: O (n^2)
@:

@接口: long long Prim (int s)
@功能: 求解最小生成树
@时间复杂度: O (n^2)
@s: 源点
************************************************/

const int maxn = 100 + 66;

bool vis[maxn];//表示节点是否在最小生成树中
//分别表示邻接矩阵、节点距离最小生成树的距离和顶点的个数
int edge[maxn][maxn], dis[maxn], n;

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

long long Prim (int s)
{
    memset (vis, false, sizeof (vis));
    long long res = 0;
    vis[s] = true;

    for (int i = 1; i <= n; i++)//初始化源点相邻接的节点的最小生成树距离
        dis[i] = edge[s][i];

    for (int i = 2; i <= n; i++)
    {
        int minval = INF, minpos = s;
        for (int j = 1; j <= n; j++)//遍历将还未在MST中具有最小距离的的节点找到
            if (j != s && !vis[j] && minval > dis[j])
            {
                minval = dis[j];
                minpos = j;
            }

        vis[minpos] = true;//访问该节点
        res += minval;//累加边权

        for (int j = 1; j <= n; j++)//更新由于minpos节点加入到MST导致的最小距离变化
            if (j != s && !vis[j] && edge[minpos][j] < dis[j])
                dis[j] = edge[minpos][j];
    }

    return res;
}
