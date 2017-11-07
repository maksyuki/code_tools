/***********************************************
POJ1236
问题1：求解在一个有向图中至少选择几个顶点，才能做
到从这些点出发，可以到达全部顶点
问题2：求解在一个有向图中至少添加几条边，才能使得
从任何一个顶点出发，可以到达全部顶点

易知问题1的求解只需要找缩点后出度为0的点即可
对于问题2，只要找出度为0的点的个数和入度为0的个数
的较大值即可。首先是若图中存在出度为0的点和入度为
0的点话，这个图一定不是强连通图。即需要消去这些点
，所以优先这些点之间连边。每一次从出度为0的点向入
度为0的点连一条边，就会构建出一个强连通分量，直到
所有出度为0的点后入度为0的点都被消去为止。注意当
原图中只有一个强连通分量时，结果需要特判为0！！！
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
const int maxn = 166 + 66;

int dfn[maxn], low[maxn], belong[maxn], indeg[maxn], outdeg[maxn];
int n, id, tot;
bool instack[maxn];
vector <int> g[maxn];
stack <int> sta;

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
	id = tot = 0;
	while (!sta.empty ()) sta.pop ();
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			dfs (i);
}

int main()
{
    //CFF;
    //CPPFF;
	while (scanf ("%d", &n) != EOF)
	{
		for (int i = 0; i < maxn; i++)
			g[i].clear ();
		for (int i = 1; i <= n; i++)
		{
			int u;
			while (scanf ("%d", &u) != EOF)
			{
				if (u == 0) break;
				g[i].push_back (u);
			}
		}
		SS ();
		set <PII> seta;
		memset (indeg, 0, sizeof (indeg));
		memset (outdeg, 0, sizeof (outdeg));
		for (int u = 1; u <= n; u++)
			for (int i = 0; i < g[u].size (); i++)
			{
				int v = g[u][i];
				if (belong[u] != belong[v] && seta.find (PII (belong[u], belong[v])) == seta.end ())
				{
					indeg[belong[v]]++;
					outdeg[belong[u]]++;
					seta.insert (PII (belong[u], belong[v]));
				}
			}

		int resa = 0, resb = 0;
		for (int i = 1; i <= tot; i++)
		{
			if (!indeg[i]) resa++;
			if (!outdeg[i]) resb++;
		}
		
		printf ("%d\n", resa);
		if (tot == 1) puts ("0");
		else printf ("%d\n", max (resa, resb));
	}
    return 0;
}
