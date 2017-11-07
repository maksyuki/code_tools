/***********************************************
POJ2175
问题：给定n个建筑物，每个建筑物里有若干人，还有m
个避难所，每个避难所可以容纳有限的人数。给出每个
建筑物和避难所的坐标。现在给出了一个避难方案，问
这个方案是否是最优的。若不是则输出一个更优的方案
(不一定是最优的)

求解：直接建图使用最小费用流给出最优方案会TLE，这
里需要使用费用流的消圈算法
消圈定理：若残余网络中存在负费用圈，则当前流不是最
小费用流。负费用圈指的是费用总和为负数，且每条边的
剩余流量大于0的圈。
那么如果在原图中能够找到一个总费用为负的圈的话，那
么沿这个圈流量增加1就能够在不改变原始总流量的基础
上使总费用变得更低，于是只要去找这样一个负圈即可。
具体方法是根据输入先构建残余网络，然后使用SPFA判负
圈，并对负圈上边的流量进行修改
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
	int v, nxt, c, f, cost; 	
};

struct Point
{
	int x, y, v;	
};

Point aa[maxn], bb[maxn];
Node edge[maxn*maxn];
int head[maxn], edgelen;
int allrow[maxn], allcol[maxn], cap[maxn][maxn];

int Dis (int i, int j)
{
	return abs (aa[i].x - bb[j].x) + abs (aa[i].y - bb[j].y) + 1;
}

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
int N, rt = -1;

bool spfa (int s)
{
	for (int i = 0; i <= N; i++)
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
		if (cnt[u] > N)
		{
			rt = u;
			return false;
		}

		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			int v = edge[i].v;
			if (edge[i].c && dis[u] < INF && dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				par[v] = u;
				if (!inq[v])
				{
					qu.push (v);
					inq[v]++, cnt[v]++;
				}
			}
		}
	}
	return true;
}

int n, m;
void SS (int s)
{
	if (spfa (s))
		puts ("OPTIMAL");
	else
	{
		puts ("SUBOPTIMAL");
		int sta = rt;
		memset (inq, 0, sizeof (inq));
		while (1)
		{
			if (!inq[sta]) 
			{
				inq[sta]++, sta = par[sta];
			}
			else
			{
				rt = sta;
				break;
			}
		}
		do
		{
			int u = par[sta], v = sta;
			if (u <= n && v > n) cap[u][v-n]++;
			if (v <= n && u > n) cap[v][u-n]--;
			sta = par[sta];
		} while (sta != rt);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (j == 1) printf ("%d", cap[i][j]);
				else printf (" %d", cap[i][j]);
			}
			puts ("");
		}
	}
}


int main()
{
    //CFF;
    //CPPFF;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf ("%d%d%d", &aa[i].x, &aa[i].y, &aa[i].v);

		for (int i = 1; i <= m; i++) 
			scanf ("%d%d%d", &bb[i].x, &bb[i].y, &bb[i].v);
		
		Init ();
		memset (allrow, 0, sizeof (allrow));
		memset (allcol, 0, sizeof (allcol));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf ("%d", &cap[i][j]);
				allrow[i] += cap[i][j];
				allcol[j] += cap[i][j]; 
				AddEdge (Dis (i, j), i, n + j, INF - cap[i][j], cap[i][j]);
			}
		
		for (int i = 1; i <= n; i++)
			AddEdge (0, 0, i, aa[i].v - allrow[i], allrow[i]);

		for (int i = 1; i <= m; i++)
			AddEdge (0, n + i, n + m + 1, bb[i].v - allcol[i], allcol[i]);

		N = n + m + 2;
		SS (N - 1);
	}
    return 0;
}
