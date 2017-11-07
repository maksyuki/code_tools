/***********************************************
POJ2762
问题：判定所给的个有向图是否是单连通的

求解：易知同一个强连通分量中的点都是单连通的，所以
可以缩点。对缩点后的图进行拓扑排序。若拓扑序列所有
相邻的点之间邻接，则所给的有向图是单连通的，否则不
是。这是自己简单画画图就出来了
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

int dfn[maxn], low[maxn], belong[maxn];
bool instack[maxn];
stack <int> sta;
vector <int> g[maxn];
int n, m, id, tot;
int gg[maxn][maxn], indeg[maxn], topo[maxn];

void Init ()
{
	for (int i = 0; i < maxn; i++)
		g[i].clear ();
}

void dfs (int u)
{
	dfn[u] = low[u] = ++id;
	sta.push (u);
	instack[u] = true;
	for (int i = 0; i < g[u].size (); i++)
	{
		int v = g[u][i];
		if (!dfn[v])
		{
			dfs (v);
			low[u] = min (low[u], low[v]);
		}
		else if (instack[v])
			low[u] = min (low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		tot++;
		int tt;
		do
		{
			tt = sta.top (); sta.pop ();
			instack[tt] = false;
			belong[tt] = tot;
		} while (!sta.empty () && tt != u);
	}
}

void SS ()
{
	memset (dfn, 0, sizeof (dfn));
	memset (low, 0, sizeof (low));
	memset (instack, false, sizeof (instack));
	while (!sta.empty ()) sta.pop ();
	tot = id = 0;	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			dfs (i);
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
		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf ("%d%d", &u, &v);
			g[u].push_back (v);
		}
		SS ();
		memset (gg, 0, sizeof (gg));
		memset (indeg, 0, sizeof (indeg));
		for (int u = 1; u <= n; u++)
			for (int i = 0; i < g[u].size (); i++)
			{
				int v = g[u][i];
				if (belong[u] != belong[v])
				{
					gg[belong[u]][belong[v]] = 1;
					indeg[belong[v]]++;
				}
			}
	
		queue <int> qua;
		for (int i = 1; i <= tot; i++)
			if (!indeg[i])
				qua.push (i);

		int len = 0;
		while (!qua.empty ())
		{
			int u = qua.front (); qua.pop ();
			topo[++len] = u;
			for (int v = 1; v <= tot; v++)
				if (u != v && gg[u][v])
				{
					indeg[v]--;
					if (!indeg[v])
						qua.push (v);
				}
		}
		
		bool is_valid = true;
		for (int i = 1; i <= tot - 1; i++)
			if (!gg[topo[i]][topo[i+1]])	
			{
				is_valid = false;
				break;
			}
		if (is_valid) puts ("Yes");
		else puts ("No");
	}
    return 0;
}
