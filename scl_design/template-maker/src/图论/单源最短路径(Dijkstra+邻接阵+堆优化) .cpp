/***********************************************
************************************************
@接口: void Init ()
@功能: 初始化邻接矩阵
@时间复杂度: O (n ^ 2)
@:

@接口: void Dijkstra (int s)
@功能: 求解从s开始的最短路
@时间复杂度: O(nlogn)
@s: 源点
************************************************/
typedef pair <int, int> PII;

const int maxn = 1000 + 66;
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
    fill (dis, dis + maxn, INF);
    dis[s] = 0;//源点到自己的最短路是0，十分重要!!!
    priority_queue <PII, vector <PII>, greater <PII> > qu;
    qu.push (PII (0, s));
    while (!qu.empty ())
    {
        PII tt = qu.top (); qu.pop ();
        int ta = tt.second, tb = tt.first;
        if (dis[ta] < tb) continue;
        for (int i = 1; i <= n; i++)
            if (i != s && edge[ta][i] < INF && dis[i] > edge[ta][i] + dis[ta])
            {
                dis[i] = edge[ta][i] + dis[ta];
                qu.push (PII (dis[i], i));
            }
    }
}
