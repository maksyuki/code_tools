/***********************************************
POJ1637
问题：对于无向边和有向边组成的混合图，判断是否存在
欧拉回路

求解
其实问题的难点在于图中的无向边，需要对所有的无向边
定向(指定一个方向，使之变为有向边)，使整个图变成一
个有向欧拉图(或有向半欧拉图)。若存在一个定向满足此
条件，则原图是欧拉图(或半欧拉图)否则不是。关键就是
如何定向？

首先给原图中的每条无向边随便指定一个方向(称为初始定
向)，将原图改为有向图G'。然后的任务就是改变G'中某些
边的方向(当然是无向边转化来的，原混合图中的有向边不
能动)，使其满足每个点的入度等于出度
设D[i]为G'中(点i的出度 - 点i的入度)。可以发现，在改
变G'中边的方向的过程中，任何点的D值的奇偶性都不会发
生改变(设将边<i, j>改为<j, i>，则i入度加1出度减1，j
入度减1出度加1，两者之差加2或减2，奇偶性不变)！而最
终要求的是每个点的入度等于出度，即每个点的D值都为0，
是偶数，故可得：若初始定向得到的G'中任意一个点的D值
是奇数，那么原图中一定不存在欧拉环！

若初始D值都是偶数，则将G'改装成网络：设立源点S和汇点
T，对于每个D[i]>0的点i，连边<S, i>，容量为D[i]/2；对
于每个D[j]<0的点j，连边<j, T>，容量为-D[j]/2；G'中的
每条边在网络中仍保留，容量为1(表示该边最多只能被改变
方向一次)。求这个网络的最大流，若S引出的所有边均满流
，则原混合图是欧拉图，将网络中所有流量为1的中间边(就
是不与S或T关联的边)在G'中改变方向，形成的新图G''一定
是有向欧拉图；若S引出的边中有的没有满流，则原混合图
不是欧拉图。

为什么能这样建图？
考虑网络中的一条增广路径S-->i-->...-->j-->T，将这条从
i到j的路径在G'中全部反向，则i的入度加1出度减1，j的入度
减1出度加1，路径中其它点的入度出度均不变。而i是和S相连
的，因此初始D[i]>0，即i的出度大于入度，故这样反向之后
D[i]减少2；同理，j是和T相连的，这样反向之后D[j]增加2。
因此，若最大流中边<S, i>满流(流量为初始D[i]/2)，此时
D[i]值就变成了0，也就是i的入度等于出度。因此只要使所
有S引出的边全部满流，所有初始D值>0的点的D值将等于0，
又因为将边变向后所有点的D值之和不变，所有初始D值小于0
的点的D值也将等于0，而初始D值等于0的D点既不与S相连也不
与T相连，所以它们是网络中的中间点，而中间点的流入量等
于流出量，故它们的入度和出度一直不变，即D值一直为0。因
此，整个图G'成为欧拉图

扩展问题：欧拉路径的判定
求解
首先可以想到的是枚举欧拉路径的起点i和终点j，然后在
图中添加边<j, i>，再求图中是否有欧拉回路即可。但是
，该算法的时间复杂度达到了O(M * 最大流的时间)，需
要优化
前面已经说过，在将边变向的过程中任何点的D值的奇偶
性都不会改变，而一个有向图有欧拉路径的充要条件是基
图连通且有且只有一个点的入度比出度少1(作为欧拉路径
的起点)，有且只有一个点的入度比出度多1(作为终点)，
其余点的入度等于出度。这就说明，先把图中的无向边随
便定向，然后求每个点的D值，若有且只有两个点的初始D
值为奇数，其余的点初始D值都为偶数，则有可能存在欧拉
路径(否则不可能存在)。进一步，检查这两个初始D值为奇
数的点，设为点i和点j，若有D[i]>0且D[j]<0，则i作起点
j作终点(否则若D[i]与D[j]同号则不存在欧拉路径)，连边
<j, i>，求是否存在欧拉环即可(将求出的欧拉环中删去边
<j, i>即可)。这样只需求一次最大流
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
const int maxn = 3000 + 66;

struct Node
{
	int to, nxt, c, f;	
};

Node edge[maxn];
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
	edge[edgelen].to = v, edge[edgelen].c = w, edge[edgelen].f = 0;
	edge[edgelen].nxt = head[u], head[u] = edgelen++;
	edge[edgelen].to = u, edge[edgelen].c = rw, edge[edgelen].f = 0;
	edge[edgelen].nxt = head[v], head[v] = edgelen++;
}

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

int sta[maxn];

int MaxFlow (int s, int e, int n)
{
	Bfs (s, e);
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
			u = edge[sta[top]^1].to;
		}
		else
		{
			bool is_have = false;
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
			int minval = n;
			for (int i = head[u]; i != -1; i = edge[i].nxt)
				if (edge[i].c - edge[i].f && dep[edge[i].to] < minval)
				{
					minval = dep[edge[i].to];
					cur[u] = i;
				}
			cnt[dep[u]]--;
			if (!cnt[dep[u]]) return res;
			dep[u] = minval + 1;
			cnt[dep[u]]++;
			if (u != s) u= edge[sta[--top]^1].to;
		}
	}
	return res;
}

int indeg[maxn], outdeg[maxn];
int n, m;

void SS ()
{
	bool is_have = true;
	int full = 0;
	for (int i = 1; i <= n; i++)
	{
		if (abs (indeg[i] - outdeg[i]) & 1)
		{
			is_have = false;
			break;
		}
		if (indeg[i] > outdeg[i])
		{
			AddEdge (i, n + 1, (indeg[i] - outdeg[i]) / 2);
			full += (indeg[i] - outdeg[i]) / 2;		
		}
		else if (indeg[i] < outdeg[i])
			AddEdge (0, i, (outdeg[i] - indeg[i]) / 2);
	}

	if (!is_have) puts ("impossible");
	else
	{
		if (MaxFlow (0, n + 1, n + 2) == full) puts ("possible");
		else puts ("impossible");
	}
}

int main()
{
    //CFF;
    //CPPFF;
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		Init ();
		memset (indeg, 0, sizeof (indeg));
		memset (outdeg, 0, sizeof (outdeg));

		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			int u, v, w;
			scanf ("%d%d%d", &u, &v, &w);
			outdeg[u]++, indeg[v]++;
			if (!w) AddEdge (u, v, 1);			
		}
		SS ();
	}
    return 0;
}
