/***********************************************
用求解无向图割点的Tarjan算法来输出重连通分量(点)

求法：建立一个栈，在dfs向下搜索的过程中，每找到一
个生成树的边或者是回边，则该边入栈。若遇到一个割点
u，则将边从栈中退出并输出，直到退出边(u,v)，即退出
的边及其邻接的点组成一个重连通分量(点)

注意：
为了防止访问过的边重复入栈，额外定义edge[i][j]==2
表示顶点i和j之间有边且已经遍历过了
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
const int maxn = 66;

//edge[i][j] == INF表示顶点i和j之间没有边，且没有遍历过
//edge[i][j] == 1表示顶点i和j之间有边
//edge[i][j] == 2表示顶点i和j之间有边，且已经遍历过了
int edge[maxn][maxn], vis[maxn], dfn[maxn], low[maxn];
int n, m, id;
stack <PII> sta;//注意清空

void Init (int rt)
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			edge[i][j] = INF;

	while (!sta.empty ()) sta.pop ();
	dfn[rt] = low[rt] = id = 1;
	memset (vis, 0, sizeof (vis));
	vis[rt] = 1;
}

void dfs (int u, int par)
{
	for (int v = 1; v <= n; v++)
	{
		if (edge[u][v] == 1)
		{
			sta.push (PII (u, v));
			edge[u][v] = edge[v][u] = 2;
			if (!vis[v])
			{
				vis[v] = 1;
				dfn[v] = low[v] = ++id;
				dfs (v, u);
				low[u] = min (low[u], low[v]);
				if (low[v] >= dfn[u])
				{
					while (!sta.empty ())
					{
						PII temp = sta.top ();
						printf (" %d-%d", temp.first, temp.second);
						sta.pop ();
						if ((temp.first == u && temp.second == v) || (temp.first == v && temp.second == u)) 
							break;
					}
					puts ("");
				}
			}

			else if (v != par)
				low[u] = min (low[u], dfn[v]);
		}	
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
			edge[u][v] = edge[v][u] = 1;
		}

		dfs (1, -1);
	}
    return 0;
}
