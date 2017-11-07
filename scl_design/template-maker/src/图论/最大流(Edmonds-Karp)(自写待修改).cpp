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

const int INF = 0x7FFFFFFF;
const int MOD = 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 100 + 66;


struct Node
{
	int c, f;//分别表示弧之间的容量和流量
};

Node edge[maxn][maxn];
int n, m;
int vis[maxn], pre[maxn], res[maxn][maxn];

void FindAugmentPath (int s, int t)
{
	memset (vis, 0, sizeof (vis));
	memset (res, -1, sizeof (res));
	memset (pre, -1, sizeof (pre));
	pre[s] = INF, vis[s] = 1;
	queue <int> qu;
	qu.push(s);

	while(!qu.empty() && pre[t] == -1)
	{
        int tt = qu.front(); qu.pop ();
        for (int i = 0; i <= n + 1; i++)
		{
            if (!vis[i])
			{
                if (edge[tt][i].f < edge[tt][i].c)
				{
					res[tt][i] = edge[tt][i].c - edge[tt][i].f;
					vis[i] = 1, pre[i] = tt, qu.push(i);
				}

				else if (edge[i][tt].f > 0)
				{
					res[tt][i] = edge[i][tt].f;
					vis[i] = 1, pre[i] = tt, qu.push(i);
				}
			}
		}
	}
}

long long GetAugmentFlow (int s, int t)
{
    if (pre[t] == -1)
		return 0;

	int pa = t, pb = INF;
	while (pa != s)
	{
        if (res[pre[pa]][pa] < pb)
			pb = res[pre[pa]][pa];

		pa = pre[pa];
	}

	return pb;
}

void UpDateFlow (int s, int t, int v)
{
	if (pre[t] == -1)
		return ;

    int pa = t;
    while (pa != s)
	{
        if (edge[pre[pa]][pa].c > edge[pre[pa]][pa].f)
			edge[pre[pa]][pa].f += v;

		else if (edge[pa][pre[pa]] .f > 0)
			edge[pre[pa]][pa].f += v;

		pa = pre[pa];
	}
}

long long Ford_Fulkerson (int s, int t)
{
    long long maxflow = 0, tt;
    while (1)
	{
        FindAugmentPath (s, t);
        tt = GetAugmentFlow (s, t);
        maxflow += tt;
        if (tt > 0)
			UpDateFlow (s, t, tt);

		else
			return maxflow;
	}
}

int pig[maxn], last[maxn];

int main()
{
//	ifstream cin ("aaa.txt");

    while (cin >> m >> n)
	{
		memset (edge, 0, sizeof (edge));
        memset (last, 0, sizeof (last));

        for (int i =1;  i <= m; i++)
            cin >> pig[i];

        for (int i = 1; i <= n; i++)
        {
            int tt;
            cin >> tt;
            for (int j = 1; j <= tt; j++)
            {
                int k;
                cin >> k;
                if (!last[k])
                    edge[0][i].c += pig[k];

                else
                    edge[last[k]][i].c = INF;

                last[k] = i;
            }
            cin >> edge[i][n+1].c;
        }

        cout << Ford_Fulkerson (0, n + 1) << endl;
	}

return 0;
}
