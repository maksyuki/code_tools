/***********************************************
SPFA算法推荐使用邻接表作为存图的数据结构
************************************************
@接口: bool spfa (int s)
@功能: 求解从源点s开始的最短路，若无解则返回false
@时间复杂度: O(k * m)
@s: 源点
************************************************/

//分别表示顶点v。w和下一个邻接的位置
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

//分别表示源点到其他顶点的最短距离、顶点是否在队列中的判断数组、顶点入队列的次数和顶点个数
int dis[maxn], inq[maxn], cnt[maxn];
int n;

//表示是否存在负权值回路，true表示不存在，false表示存在
//bool is_valid;

//数组下标从1开始
bool spfa (int s)
{
    for (int i = 1; i <= n; i++)//初始化dis数组和inq数组
    {
        dis[i] = INF;
        inq[i] = cnt[i] = 0;
    }

    dis[s] = 0;//将源点的dis数组值初始化为0，重要！！
    //is_valid = true;//初始化标记
    queue <int> qu;
    qu.push (s);
    inq[s]++, cnt[s]++;//将源点标志为在队列中
    while (!qu.empty ())
    {
        int u = qu.front(); qu.pop (); inq[u]--;
        if (cnt[u] > n) return false;

        for (int i = head[u]; i != -1; i = edge[i].nxt)
        {
            int v = edge[i].v;
            if (dis[u] < INF && dis[v] > dis[u] + edge[i].w)//松弛操作
            {
                dis[v] = dis[u] + edge[i].w;
                if (!inq[v])//如果被松弛的节点不在队列中，则将该节入队
                {
                    qu.push (v);
                    inq[v]++, cnt[v]++;
                }
            }
        }
    }
	return true;
}
