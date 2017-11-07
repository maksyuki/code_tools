/***********************************************
************************************************
@接口: void Init ()
@功能: 初始化邻接矩阵
@时间复杂度: O (n ^ 2)
@:

@接口: void Dijkstra (int s)
@功能: 求解从s开始的最短路
@时间复杂度: O(n…^ 2)
@s: 源点
************************************************/

const int maxn = 1000 + 66;

bool vis[maxn];//表示节点的最短路是否已经得到
//分别表示邻接矩阵、节点最短路的长度和顶点的个数
int edge[maxn][maxn], dis[maxn], n;

void Init ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j) edge[i][j] = 0;
            else edge[i][j] = INF;
        }
}

void Dijkstra (int s)
{
    memset (vis, false, sizeof (vis));;
    vis[s] = true;
    for (int i = 1; i <= n; i++)//初始化源点相邻接的节点的最短距离
        dis[i] = edge[s][i];

    dis[s] = 0;//源点到自己的最短路是0，十分重要!!!
    for (int i = 2; i <= n; i++)
    {
        int minval = INF, minpos = s;
        for (int j = 1; j <= n; j++)//遍历将还未确定最短路的节点中具有最小距离的的节点找到
            if (j != s && !vis[j] && minval > dis[j])
            {
                minval = dis[j];
                minpos = j;
            }

        vis[minpos] = true;//访问该节点
        for (int j = 1; j <= n; j++)//更新由于minpos节点确定最短路之后导致的最小距离变化
            if (j != s && !vis[j] && edge[minpos][j] < INF && edge[minpos][j] + dis[minpos] < dis[j])
                dis[j] = edge[minpos][j] + dis[minpos];
    }
}
