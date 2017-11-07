/***********************************************
以POJ 1523为例 Tarjan算法
Tarjan算法本质上是构建一个dfs优先生成树，然后在
树上通过引入回边的概念来求解

注意
(1)对于subnets[i]大于0的非根节点i来说，由于其还
有一个父节点所在的连通分量，所以输出时要加1

(2)对于subnets[i]大于0的根节点来说，只有其subnets
值大于1，根节点才是割点
************************************************
@接口: void Init (int rt)
@功能:初始化邻接矩阵和其他变量
@时间复杂度: O (n ^ 2)
@rt: 表示dfs生成树中的根(可任意指定)

@接口: void dfs (int u, int par)
@功能: dfs求解所有节点的dfn和low值
@时间复杂度: O (n ^ 2)
@u: 当前节点
@par: 当前节点的父节点
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

#define CFF freopen ("aaa.txt", "r", stdin)
#define CPPFF ifstream cin ("aaa.txt")
#define i64 long long

const int INF = 0x7FFFFFFF;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 1000 + 66;

//分别表示邻接矩阵、访问数组、dfs深度优先数、当前节点可以到达的最低优先数和每个节点的连通分量数(删去该节点)
int edge[maxn][maxn], vis[maxn], dfn[maxn], low[maxn], subnets[maxn];
int n, id;//分别表示顶点总数和全局标志(标记dfs深度优先数)

void Init (int rt)
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            edge[i][j] = INF;
    dfn[rt] = low[rt] = id = 1;//将根节点的dfn和low值都置为1
    memset (vis, 0, sizeof (vis));
    vis[rt] = 1;//初始化访问数组vis
    memset (subnets, 0, sizeof (subnets));//初始化连通分量数组subnets
}

void dfs (int u, int par)
{
    for (int v = 1; v <= n; v++)//依次判断所有的邻接点
    {
        if (edge[u][v] < INF && !vis[v])//如果邻接且v为u的孩子节点
        {
            vis[v] = 1;
            dfn[v] = low[v] = ++id;//访问该孩子节点并打上标志
            dfs (v, u);//递归地访问v的孩子节点
            low[u] = min (low[u], low[v]);//使用u的孩子节点v的low值来更新u的low值

            if (low[v] >= dfn[u])//如果孩子节点的low值(深度)大于等于当前节点u的dfn值(深度)，连通分量个数自加1
                subnets[u]++;
        }

        else if (edge[u][v] < INF && vis[v] && v != par)//如果邻接且v为u的祖先节点(而不是父节点)
            low[u] = min (low[u], dfn[v]);//直接使用回边中祖先节点的dfn值更新u的low值即可
    }
}

int main()
{
//    CPPFF;
    int flag = 1, u, v;
    while (cin >> u)
    {
        if (u == 0)
            break;

        Init(1);

        cin >> v;
        n = -INF;
        n = max (n, u);
        n = max (n, v);
        edge[u][v] = edge[v][u] = 1;
        while (cin >> u)
        {
            if (u == 0)
                break;

            cin >> v;
            n = max (n, u);
            n = max (n, v);
            edge[u][v] = edge[v][u] = 1;
        }

        if (flag > 1)
            cout << endl;

        cout << "Network #" << flag++ << endl;

        dfs (1, -1);
        bool is_find = false;
        for (int i = 1; i <= n; i++)
        {
            if (subnets[i])
            {
                if (i == 1 && subnets[i] > 1)//如果当前节点是根节点且其连通分量数大于1，则输出
                {
                        cout << "  SPF node " << i << " leaves " << subnets[i] << " subnets" << endl;
                        is_find = true;
                }

                else if (i != 1)//对于其他节点(非root节点)，则直接将其连通分量数自加1输出(因为还有i节点一个父节点所在的连通分量)
                {
                    cout << "  SPF node " << i << " leaves " << subnets[i] + 1 << " subnets" << endl;
                    is_find = true;
                }
            }
        }

        if (!is_find)
            cout << "  No SPF nodes" << endl;
    }
    return 0;
}

