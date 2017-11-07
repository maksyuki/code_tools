/*************************************************
Author        :supermaker
Created Time  :2016/2/16 22:08:21
File Location :C:\Users\abcd\Desktop\TheEternalPoet
**************************************************/

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
const int maxn = 6666;

int deg[maxn], g[maxn][maxn];
int n, m;
stack <int> sta;

void Init ()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			g[i][j] = INF;
	memset (deg, 0, sizeof (deg));
	while (!sta.empty ()) sta.pop ();
}

void dfs (int u)
{
	sta.push (u);
	for (int i = 1; i <= n; i++)
		if (g[u][i] < INF)
		{
			g[u][i] = g[i][u] = INF;
			dfs (i);
			break;
		}
}

void GetEulerPath (int u)
{
	sta.push (u);
	while (!sta.empty ())
	{
		bool is_have = false;
		int tt = sta.top ();
		for (int i = 1; i <= n; i++)
			if (g[tt][i] < INF)
			{
				is_have = true;
				break;
			}
		if (is_have)
		{
			sta.pop ();
			dfs (tt);
		}
		else
		{
			sta.pop ();
			printf ("%d ", tt);
		}
	}
	puts ("");
}

int main()
{
    CFF;
    //CPPFF;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		Init ();
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf ("%d%d", &u, &v);
			g[u][v] = g[v][u] = 1;
			deg[u]++, deg[v]++;
		}
		int num = 0, start_pos = 1;
		for (int i = 1; i <= n; i++)
			if (deg[i] & 1)
			{
				num++;
				start_pos = i;	
			}
		
		if (num == 0 || num == 2) 
			GetEulerPath (start_pos);

		else
			puts ("No");
	}
    return 0;
}
