/***********************************************
以POJ 2449为例

求解过程：
1.将图反向，用dijstra + heap求出t到所有点的最短距离
，目的是求所有点到点t的最短路，用dis[i]表示i到t的最
短路，其实这就是A*的启发函数，显然：h(n) <= n到t的实
际代价
2.定义估价函数。我们定义g(n)为从s到n所花费的代价，h(
n)为dis[n]，显然这符合A*算法的要求
3.初始化状态。状态中存放当前到达的点i, fi, gi。显然，
fi = gi + dis[i]。初始状态为(0, S, dis[S],)，存入优先
级队列中。
4.状态转移。假设当前状态所在的点u相邻的点v，我们可以
得到转换：(gu, u, fu) --> (gu + w[u][v], v, fu + w[u][v])。
5.终止条件。每个节点最多入队列K次，当t出队列K次时，即
找到解。
************************************************
@接口: void Dij (int s)
@功能: 求解从s开始的最短路
@时间复杂度: O (nlogn)
@s: 源点

@接口: int A_star (int s, int k)
@功能: 求解从s开始的第k小值
@时间复杂度: O (nk)
@s: 源点
@k: 表示要求解第k小的值
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
const int maxn = 1000 + 66;

int n, m, dis[maxn], cnt[maxn];
vector <PII> edge[maxn], g[maxn];

struct Node
{
	int g, v, f;
	Node () {}
	Node (int gg, int vv, int ff) : g (gg), v (vv), f (ff) {}
	bool operator < (const Node &a) const
	{
		return f > a.f;
	}
};

void Dij (int s)
{
	fill (dis, dis + maxn, INF);
	dis[s] = 0;
	priority_queue <PII, vector <PII>, greater <PII> > qu;
	qu.push (PII (0, s));
	while (!qu.empty())
	{
		PII tt = qu.top (); qu.pop ();
		int ta = tt.second, tb = tt.first;
		if (dis[ta] < tb) continue;
		for (int i = 0; i < edge[ta].size (); i++)
		{
			PII v = edge[ta][i];
			if (v.first != s && dis[v.first] > v.second + dis[ta])
			{
				dis[v.first] = v.second + dis[ta];
				qu.push (PII (dis[v.first], v.first));
			}
		}
	}
}

int A_star (int s, int k)
{
	if (dis[s] == INF) return -1;
	priority_queue <Node> qu;
	qu.push (Node (0, s, dis[s]));
	Node nxt = Node (0, 0, 0);
	while (!qu.empty ())
	{
		Node tt = qu.top (); qu.pop ();
		cnt[tt.v]++;
		if (cnt[tt.v] > k) continue;
		if (cnt[tt.v] == k) return tt.f;
		for (int i = 0; i < g[tt.v].size (); i++)
		{
			PII vv = g[tt.v][i];
			nxt.g = tt.g + vv.second;
			nxt.v = vv.first;
			nxt.f = nxt.g + dis[vv.first];
			qu.push (nxt);
		}
	}	
	return -1;
}

int main()
{
    //CFF;
    //CPPFF;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i < maxn; i++)
			edge[i].clear (), g[i].clear ();
		memset (cnt, 0, sizeof (cnt));
		for (int i = 1; i <= m; i++)
		{
			int u, v, w;
			scanf ("%d%d%d", &u, &v, &w);
			edge[v].push_back (PII (u, w));
			g[u].push_back (PII (v, w));
		}
		int s, e, k;
		scanf ("%d%d%d", &s, &e, &k);
		if (s == e) k++;
		Dij (e);
		printf ("%d\n", A_star (s, k));
	}
    return 0;
}
