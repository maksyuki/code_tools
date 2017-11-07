/***********************************************
以POJ 3177为例 Tarjan算法(有重边)
Tarjan算法本质上是构建一个dfs优先生成树，然后在
树上通过引入回边的概念来求解

注意：
这个算法同样适用于无重边的情况。这里没有使用并查
集来缩点，而是使用在同一个边重连通分量中的点的low
值相同这个性质来求解的
************************************************
@接口: void Init (int rt)
@功能:初始化邻接表和其他变量
@时间复杂度: O (n ^ 2)
@rt: 表示dfs生成树中的根(可任意指定)

@接口: void dfs (int u, int par)
@功能: dfs求解所有节点的dfn和low值
@时间复杂度: O (n ^ 2)
@u: 当前节点
@par: 当前节点的父节点
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
const int maxn = 5000 + 6;

int dfn[maxn], low[maxn], vis[maxn], deg[maxn];
int n, m, id;
vector <int> g[maxn];
set <PII> seta;

void Init (int rt)
{	
	for (int i = 0; i < maxn; i++)
		g[i].clear ();
	seta.clear ();
	dfn[rt] = low[rt] = id = 1;
	memset (vis, 0, sizeof (vis));
	memset (deg, 0, sizeof (deg));
	vis[rt] = 1;
}

void dfs (int u, int par)
{
	for (int i = 0; i < g[u].size (); i++)
	{
		int v = g[u][i];
		if (!vis[v])
		{
			vis[v] = 1;
			dfn[v] = low[v] = ++id;
			dfs (v, u);
			low[u] = min (low[u], low[v]);
		}
		else if (v != par)
			low[u] = min (low[u], dfn[v]);
	}
}

void SS ()
{
	for (int u = 1; u <= n; u++)
		for (int i = 0; i < g[u].size (); i++)
		{
			int v = g[u][i];
			if (low[u] != low[v])
				deg[low[u]]++;
		}
}

int main()
{
    CFF;
    //CPPFF;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		Init (1);
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf ("%d%d", &u, &v);
			if (seta.find (PII (u, v)) != seta.end ()) continue;
			seta.insert (PII (u, v)), seta.insert (PII (v, u));
			g[u].push_back (v);
			g[v].push_back (u);
		}

		dfs (1, -1);
		SS ();

		int res = 0;
		for (int i = 1; i <= n; i++)
			if (deg[i] == 1) 
				res++;

		printf ("%d\n", (res + 1) / 2);
	}
    return 0;
}
