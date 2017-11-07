/***********************************************
Dinic算法，求最大费用只需建图时cost取相反数，结
果取相反数即可
************************************************
@接口: void Init ()
@功能: 初始化邻接表
@时间复杂度: O (1)

@接口: bool spfa (int s, int e)
@功能: 构造伴随网络寻找最优增广路
@时间复杂度: O (km)
@s: 源点的下标
@e: 汇点的下标

@接口: int MinCostMaxFlow (int s, int e)
@功能: 返回网络最大流
@时间复杂度: (n ^ 2 * m)
@s: 源点的下标
@e: 汇点的下标
************************************************/

struct Node
{
	int v, nxt, c, f, cost;	
};

Node edge[maxn*maxn];
int head[maxn], edgelen;

void Init ()
{
	memset (head, -1, sizeof (head));
	memset (edge, -1, sizeof (edge));
	edgelen = 0;
}

void AddEdge (int cost, int u, int v, int w, int rw = 0)
{
	edge[edgelen].v = v, edge[edgelen].c = w, edge[edgelen].f = 0;
	edge[edgelen].cost = cost, edge[edgelen].nxt = head[u], head[u] = edgelen++;
	edge[edgelen].v = u, edge[edgelen].c = rw, edge[edgelen].f = 0;
	edge[edgelen].cost = -cost, edge[edgelen].nxt = head[v], head[v] = edgelen++;
}

int dis[maxn], cnt[maxn], inq[maxn], par[maxn];
int N;//图中顶点总数

bool spfa (int s, int e)
{
	for	(int i = 0; i <= N; i++)
	{
		dis[i] = INF;
		inq[i] = cnt[i] = 0;
		par[i] = -1;
	}
	dis[s] = 0;
	queue <int> qu;
	qu.push (s);
	inq[s]++, cnt[s]++;
	while (!qu.empty ())
	{
		int u = qu.front (); qu.pop (); inq[u]--;
		if (cnt[u] > N) return false;	

		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			int v = edge[i].v;
			if (edge[i].c > edge[i].f && dis[u] < INF && dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				par[v] = i; 
				if (!inq[v])
				{
					qu.push (v);
					inq[v]++, cnt[v]++;
				}
			}
		}
	}
	if (par[e] == -1) return false;
	return true;
}

int allcost;//返回最大流，allcost存的是最小费用
int MinCostMaxFlow (int s, int e)
{
	int res = 0;
	allcost = 0;
	while (spfa (s, e))
	{
		int minval = INF;
		for (int i = par[e]; i != -1; i = par[edge[i^1].v])
			minval = min (minval, edge[i].c - edge[i].f);
		for (int i = par[e]; i != -1; i = par[edge[i^1].v])
		{
			edge[i].f += minval;
			edge[i^1].f -= minval;
			allcost += edge[i].cost * minval;
		}
		res += minval;
	}
	return res;
}
