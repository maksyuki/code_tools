/***********************************************
POJ2125
问题：给出一个有向图，定义两种操作：删除i点的所有
入边；删除i点的所有出边，每种操作有对应的花费，问
最后删除所有边的最小花费

求解：每个点都有两种属性(删除入边的权值和删除出边
的权值)，所以先拆点一个处理入边，一个处理出边。经
过拆点，原图转化为二分图。现在所有删除入边的操作对
应于删除拆点后的出点，同理删除出边的操作对应于删除
拆点后的入点。点覆盖的限制在边上，所以使用最小割模
型进行转化。对于给出的边<u, v>，从u向n+v连一条容量
为INF的有向边，从源点向点1~n分别连一条容量为对应点
出边点权的有向边，从点n~2n分别向汇点连一条容量为对
应点入边点权的有向边。最后跑一个最大流就可得到最小
费用值。最后从源点s开始dfs将在残余网络中在同一个连
通分量中的点打上标记，所有1~n中没有标记的点就是选
择删除出边的，n~2n中被标记的点就是选择删除入边的
************************************************/

#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <bitset>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;

#define CFF freopen ("aaa.txt", "r", stdin)
#define CPPFF ifstream cin ("aaa.txt")
#define	DB(ccc)	cout << #ccc << " = " << ccc << endl
#define PB push_back
#define MP(A, B) make_pair(A, B)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef pair <int, int> PII;
typedef pair <int, bool> PIB;

const int INF = 0x7F7F7F7F;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 200 + 66;

struct Node
{
	int v, nxt, c, f;	
};

Node edge[maxn*maxn];
int head[maxn], edgelen;
int dep[maxn], cnt[maxn], cur[maxn];

void Init ()
{
	memset (head, -1, sizeof (head));
	memset (edge, -1, sizeof (edge));
	edgelen = 0;
}

void AddEdge (int u, int v, int w, int rw = 0)
{
	edge[edgelen].v = v, edge[edgelen].c = w, edge[edgelen].f = 0;
	edge[edgelen].nxt = head[u], head[u] = edgelen++;
	edge[edgelen].v = u, edge[edgelen].c = rw, edge[edgelen].f = 0;
	edge[edgelen].nxt = head[v], head[v] = edgelen++;
}

void bfs (int s, int e)
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
			int v = edge[i].v;
			if (dep[v] != -1) continue;
			qu.push (v);
			dep[v] = dep[u] + 1;
			cnt[dep[v]]++;
		}
	}
}

int sta[maxn];
int MaxFlow (int s, int e, int n)
{
	bfs (s, e);
	int res = 0, top = 0, u = s;
	memcpy (cur, head, sizeof (head));
	while (dep[s] < n)
	{
		if (u == e)
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
			u = edge[sta[top]^1].v;
		}
		else
		{
			bool is_have = false;
			for (int i = cur[u]; i != -1; i = edge[i].nxt)
			{
				int v = edge[i].v;
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
			int minval = n;
			for (int i = head[u]; i != -1; i = edge[i].nxt)
				if (edge[i].c - edge[i].f && dep[edge[i].v] < minval)
				{
					minval = dep[edge[i].v];
					cur[u] = i;
				}
			cnt[dep[u]]--;
			if (!cnt[dep[u]]) return res;
			dep[u] = minval + 1;
			cnt[dep[u]]++;
			if (u != s) u = edge[sta[--top]^1].v;
		}
	}
	return res;
}

int in[maxn], out[maxn];
bool vis[maxn];

void dfs (int u)
{
	vis[u] = true;
	for (int i = head[u]; i != -1; i = edge[i].nxt)
	{
		int v = edge[i].v;
		if (edge[i].c - edge[i].f && !vis[v])
			dfs (v);
	}
}

int main()
{
    //CFF;
    //CPPFF;
	int n, m;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf ("%d", &in[i]);
		for (int i = 1; i <= n; i++)
			scanf ("%d", &out[i]);

		Init ();
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf ("%d%d", &u, &v);
			AddEdge (u, n + v, INF);
		}
		for (int i = 1; i <= n; i++)
			AddEdge (0, i, out[i]);
		for (int i = 1; i <= n; i++)
			AddEdge (n + i, 2 * n + 1, in[i]);

		printf ("%d\n", MaxFlow (0, 2 * n + 1, 2 * n + 2));
		memset (vis, false, sizeof (vis));
		dfs (0);
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i]) tot++;
			if (vis[n+i]) tot++;
		}
		printf ("%d\n", tot);
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i]) printf ("%d -\n", i);
			if (vis[n+i]) printf ("%d +\n", i);
		}
	}
    return 0;
}
