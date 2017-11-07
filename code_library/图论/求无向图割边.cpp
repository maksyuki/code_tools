/***********************************************
以ZOJ 2588为例 Tarjan算法(有重边)
Tarjan算法本质上是构建一个dfs优先生成树，然后在
树上通过引入回边的概念来求解
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
const int maxn = 10000 + 66;

int vis[maxn], dfn[maxn], low[maxn], out[maxn*10];
int n, m, id, len;
map <PII, int> overedge;
vector <PII> edge[maxn*10];

void Init (int rt)
{
	overedge.clear ();
	for (int i = 0; i < maxn * 10; i++)
		edge[i].clear ();
	dfn[rt] = low[rt] = id = 1;
	memset (vis, 0, sizeof (vis));
	vis[rt] = 1;
	len = 0;
}

void dfs (int u, int par)
{
	for (int i = 0; i < edge[u].size (); i++)
	{
		int v = edge[u][i].first;
		if (!vis[v])
		{
			vis[v] = 1;
			dfn[v] = low[v] = ++id;
			dfs (v, u);
			low[u] = min (low[u], low[v]);
			if (low[v] > dfn[u] && overedge[PII(u,v)] == 1)//有重边时需要特判，此时(u,v)之间没有割边
				out[++len] = edge[u][i].second;
		}

		else if (v != par)
			low[u] = min (low[u], dfn[v]);
	}
}

int main()
{
    //CFF;
    //CPPFF;
	int t, flag = 1;
	scanf ("%d", &t);
	while (t--)
	{
		if (flag++ > 1) puts ("");
		scanf ("%d%d", &n, &m);

		Init (1);
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf ("%d%d", &u, &v);
			edge[u].push_back (PII (v, i));
			edge[v].push_back (PII (u, i));
			if (overedge.find (PII (u, v)) == overedge.end ())
				overedge[PII(u,v)] = overedge[PII(v,u)] = 1;

			else
				overedge[PII(u,v)]++, overedge[PII(v,u)]++;
		}

		dfs (1, -1);

		printf ("%d\n", len);
		sort (out + 1, out + 1 + len);
		for (int i = 1; i <= len; i++)
		{
			if (i == 1) printf ("%d", out[i]);
			else printf (" %d", out[i]);
		}
		if (len) puts ("");
	}
    return 0;
}
