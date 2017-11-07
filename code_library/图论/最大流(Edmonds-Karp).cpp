/***********************************************
以POJ 2173为例
************************************************
@接口: long long Edmonds_Karp (int s, int t)
@功能: 返回最大流
@时间复杂度: O (n * m ^ 2)
@s: 源点的下标
@t: 汇点的下标
************************************************/

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
const int maxn = 200 + 66;


struct Node
{
	int c, f;//分别表示弧之间的容量和流量
};

Node edge[maxn][maxn];
//n表示顶点的个数，m表示边的个数，pre表示当前节点的前缀节点，a表示当前节点的可增广量，其中a[i] = 0表示
//当前节点不可以增广或者是还没有被访问
int n, m, pre[maxn], a[maxn];

//在调用函数前要将流量初始化成零流!!!
long long Edmonds_Karp (int s, int t)
{
    queue <int> q;
    memset (a, 0, sizeof(a));
    memset (pre, 0, sizeof(pre));
    long long maxflow = 0;

    while (1)
    {
        memset (a, 0, sizeof(a));
        a[s] = INF;//赋值INF表示源点可以满足所有邻接节点的流量需求
        q.push(s);
        while (!q.empty())
        {
            int tt = q.front(); q.pop();

            for (int i = 1; i <= n; i++)
            if(!a[i] && edge[tt][i].c > edge[tt][i].f)
            {
                pre[i] = tt;
                q.push (i);
                a[i] = a[tt] < edge[tt][i].c - edge[tt][i].f ? a[tt]:edge[tt][i].c - edge[tt][i].f;
            }
        }

        if(a[t] == 0) break;

        for(int i = t; i != s; i = pre[i])
        {
            edge[pre[i]][i].f += a[t];
            edge[i][pre[i]].f -= a[t];
        }

        maxflow += a[t];
    }
    return maxflow;
}


int main()
{
//    ifstream cin ("aaa.txt");

    while (cin >> m >> n)
	{
		memset (edge, 0, sizeof (edge));

        int u, v, w;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            edge[u][v].c += w;
        }

        cout << Edmonds_Karp (1, n) << endl;
	}

return 0;
}
