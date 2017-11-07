/***********************************************
Dinic算法
************************************************
@接口: void Init ()
@功能: 初始化邻接表
@时间复杂度: O (1)

@接口: void Bfs (int s, int e)
@功能: 构造层次网络
@时间复杂度: O (m)
@s: 源点的下标
@e: 汇点的下标

@接口: int MaxFlow (int s, int e, int n)
@功能: 返回网络最大流
@时间复杂度: (n ^ 2 * m)
@s: 源点的下标
@e: 汇点的下标
@n: 顶点个数
************************************************/

//分别表示邻接节点的下标、邻接表中下一个位置、当前边的容量和流量
struct Node
{
	int to, nxt, c, f;	
};

Node edge[maxn];
int head[maxn], edgelen;
int dep[maxn], cnt[maxn], cur[maxn];//分别表示顶点的层次值、层次值出现的次数和临时head表

void Init ()
{
	memset (head, -1, sizeof (head));
	memset (edge, -1, sizeof (edge));
	edgelen = 0;
}

//edge从0开始，所以顶点对为(0,1)、(2,3)...，即任意顶点值对1取异或得到的还是顶点对中的数，保证逆向路径转换为正向路径
void AddEdge (int u, int v, int w, int rw = 0)
{
	edge[edgelen].to = v, edge[edgelen].c = w, edge[edgelen].f = 0;
	edge[edgelen].nxt = head[u], head[u] = edgelen++;
	edge[edgelen].to = u, edge[edgelen].c = rw, edge[edgelen].f = 0;
	edge[edgelen].nxt = head[v], head[v] = edgelen++;
}

//从汇点e开始反向构建层次表(即e的dep值为0)
void Bfs (int s, int e)
{
	memset (dep, -1, sizeof (dep));
	memset (cnt, 0, sizeof (cnt));
	dep[e] = 0;
	cnt[dep[e]]++;
	queue <int> qu;
	qu.push (e);
	while (!qu.empty ())
	{
		int u = qu.front (); qu.pop ();
		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dep[v] != -1) continue;
			qu.push (v);
			dep[v] = dep[u] + 1;
			cnt[dep[v]]++;
		}
	}
}

int sta[maxn];//栈

int MaxFlow (int s, int e, int n)
{
	Bfs (s, e);	
	int res = 0, top = 0, u = s;
	memcpy (cur, head, sizeof (head));
	while (dep[s] < n)
	{
		if (u == e)//若当前顶点为汇点则表示找到增广路，此时寻找路径上最小剩余流量并修改路径上的所有点的流量值
		{
			int minval = INF, minval_pos = -1;
			for (int i = 0; i < top; i++)
				if (minval > edge[sta[i]].c - edge[sta[i]].f)
				{
					minval = edge[sta[i]].c - edge[sta[i]].f;
					minval_pos = i;
				}
			for (int i = 0; i < top; i++)
			{
				edge[sta[i]].f += minval;
				edge[sta[i]^1].f -= minval;
			}
			res += minval;
			top = minval_pos;
			u = edge[sta[top]^1].to;
		}
		else
		{
			bool is_have = false;//判断是否能够向更低层次的点移动，若可以则移动
			for (int i = cur[u]; i != -1; i = edge[i].nxt)
			{
				int v = edge[i].to;
				if (edge[i].c - edge[i].f && dep[v] + 1 == dep[u])
				{
					cur[u] = i;
					sta[top++] = cur[u];
					u = v;
					is_have = true;
					break;
				}
			}
			if (is_have) continue;

			int minval = n;//若不可移动，则回退离源点最远满足条件的点继续判断
			for (int i = head[u]; i != -1; i = edge[i].nxt)
				if (edge[i].c - edge[i].f && dep[edge[i].to] < minval)
				{
					minval = dep[edge[i].to];
					cur[u] = i;
				}
			cnt[dep[u]]--;
			if (!cnt[dep[u]]) return res;//回退之后发现所有层次值为dep[u]的顶点都没有了，则一定不会有增广路了
			dep[u] = minval + 1;
			cnt[dep[u]]++;//若层次值为dep[u]的顶点还有，则将当前顶点u的dep值和数量cnt还原
			if (u != s) u = edge[sta[--top]^1].to;
		}
	}
	return res;
}
