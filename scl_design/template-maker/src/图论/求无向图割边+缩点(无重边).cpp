/***********************************************
以POJ 3352为例 Tarjan算法(无重边)
Tarjan算法本质上是构建一个dfs优先生成树，然后在
树上通过引入回边的概念来求解

注意：
若图中没有重边，则low值相同的顶点一定在一个边重
连通分量中(因为有环)。所以此时可以不使用栈来找点
，而是双重循环枚举找邻接顶点，若两个顶点的low不同
，则它们各自所在的“缩点”的度数自加1
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

int dfn[maxn], low[maxn], vis[maxn];
int n, m, id;
stack <PII> sta;
vector <int> g[maxn];
set <PII> seta;
int parent[maxn], deg[maxn], part[maxn];

int UnFind (int val)
{
	if (parent[val] == val) return val;
	else return parent[val] = UnFind (parent[val]);
}

void Init (int rt)
{
	for (int i = 0; i < maxn; i++)
		parent[i] = i;
	
	for (int i = 0; i < maxn; i++)
		g[i].clear ();
	seta.clear ();
	dfn[rt] = low[rt] = id = 1;
	memset (vis, 0, sizeof (vis));
	memset (deg, 0, sizeof (deg));
	vis[rt] = 1;
	while (!sta.empty ()) sta.pop ();
}

void SS ()
{
	for (int u = 1; u <= n; u++)
		if (part[u])
		{
			for (int i = 0; i < g[u].size (); i++)
			{
				int v = g[u][i];
				if (part[v])
					parent[UnFind(v)] = UnFind (u);
			}
		}
}

void dfs (int u, int par)
{
	for (int i = 0; i < g[u].size (); i++)
	{
		int v = g[u][i];
		if (seta.find (PII (u, v)) == seta.end ())
		{
			seta.insert (PII (u, v));
			seta.insert (PII (v, u));
			sta.push (PII (u, v));
			if (!vis[v])
			{
				vis[v] = 1;
				dfn[v] = low[v] = ++id;
				dfs (v, u);
				low[u] = min (low[u], low[v]);
				if (low[v] > dfn[u])
				{
					memset (part, 0, sizeof (part));
					//bool is_have = false;
					while (!sta.empty ())
					{
						PII temp = sta.top (); sta.pop ();
						if ((temp.first == u && temp.second == v) || (temp.first == v && temp.second == u))
							break;
						part[temp.first] = part[temp.second] = 1;
						//printf (" %d-%d ", temp.first, temp.second);
						//is_have = true;
					}
					//if (is_have)
					//	puts ("");
					SS ();
				}
			}
			else if (v != par)
				low[u] = min (low[u], dfn[v]);	
		}
	}
}

int main()
{
    //CFF;
    //CPPFF;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		Init (1);
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf ("%d%d", &u, &v);
			g[u].push_back (v);
			g[v].push_back (u);
		}
		dfs (1, -1);

		seta.clear ();
		for (int u = 1; u <= n; u++)
			for (int i = 0; i < g[u].size (); i++)
			{
				int v = g[u][i];
				if (seta.find (PII (u, v)) != seta.end ()) continue;
				seta.insert (PII (u, v)), seta.insert (PII (v, u));
				if (UnFind (u) != UnFind (v))
					deg[UnFind(u)]++, deg[UnFind(v)]++;
			}

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			//cout << "i = " << i << " deg[i] = " << deg[i] << endl;
			if (deg[i] == 1) 
				res++;
		}

		printf ("%d\n", (res + 1) / 2);
	}
    return 0;
}