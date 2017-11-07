/*************************************************
以POJ1780为例
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
const int maxn = 1e6 + 6666;

struct Node
{
	int v, w, nxt;	
};

int head[maxn], edgelen;
Node edge[maxn];

void Init ()
{
	memset (head, -1, sizeof (head));
	memset (edge, -1, sizeof (edge));
	edgelen = 0;
}

void AddEdge (int u, int v, int w)
{
	edge[edgelen].v = v, edge[edgelen].w = w;
	edge[edgelen].nxt = head[u];
	head[u] = edgelen++;
}

bool vis[maxn];
int out[maxn], len, dfstack[maxn], slen;

void SDfs (int val)
{
	slen = len = 0, dfstack[slen++] = val;
	while (slen > 0)
	{
		int tt = dfstack[--slen];
		bool is_find = false;
		for (int i = head[tt]; i != -1; i = edge[i].nxt)
			if (!vis[edge[i].w])
			{
				vis[edge[i].w] = true;
				dfstack[slen++] = tt;
				dfstack[slen++] = edge[i].v;
				is_find = true;
				break;
			}
		if (!is_find)
			out[len++] = tt;
	}
}

int main()
{
    //CFF;
    //CPPFF;
   	int n;
	while (scanf ("%d", &n))
	{
		if (n == 0) break;
		if (n == 1) puts ("0123456789");
		else
		{
			int nodenum = 1;
			for (int i = 1; i <= n - 1; i++)
				nodenum *= 10;
			
			Init ();
			for (int i = 0; i < nodenum; i++)
			{
				int tt = i % (nodenum / 10);
				for (int j = 9; j >= 0; j--)
					AddEdge (i, tt * 10 + j, i * 10 + j); 
			}
			memset (vis, false, sizeof (vis));
			SDfs (0);
			for (int i = 1; i <= n - 2; i++)
				printf ("0"); 	
			for (int i = len - 1; i >= 0; i--)
				printf ("%d", out[i] % 10);
			puts ("");
		}
	}
    return 0;
}
