/***********************************************
POJ1904
问题：一个国王有n个王子和n个女孩。每个王子都有自己
喜欢的若干个女孩，现给定一个合法的完备匹配（也就是
一个王子娶其中一个自己喜欢女孩），求每个王子可以选
择哪些女孩可以让剩下的每个王子依旧能够选择到自己喜
欢的一个女孩

首先最直观的想法就是枚举+二分匹配判定。但是点数n高
达2000，边数e高达200000；所以枚举的复杂度O (e + n)
 * O (n ^ 2) = O( n ^ 2 * (e + n))太大了，显然超时

因为题目已经给定了一个完备匹配，而上述算法还没有利
用这个完备匹配。若已经有了一个完备匹配，假如王子xi
对应女孩yi是完备匹配中的一条边，那么yi肯定是必定属
于可选集合的。对于不是yi的yj，如果王子喜欢yj，那么
假设我们现在让王子选择yj，由于必须形成一个完备匹配
，如果match[yj]==xj (match[yj]保存的是给定的完备匹
配中与女孩yj匹配的王子xj)，那么只要能从xj出发找到
一条新的增广路径，则我们的假设可以成立。这个优化的
本质还是在进行匹配，只不过我们没有重新进行新的匹配
，而是充分利用已给出的匹配，仅仅试探性的寻找，看看
是否存在可行的增广路。这个算法的时间复杂度是：
O((e + n) * n)，已经优化掉了1维，但是在单case2000ms
的限制下还是会挂掉的。

可以发现，我们刚才虽然优化了，但是算法依旧做了一些
无用功，对于每次枚举，我们只希望知道是否存在新的增
广路径，而上面的优化显然已经找出了可行增广链。我们
如何才能不通过寻找增广链而直接确定是否存在增广链呢
？可以的。让我们再次回到初始的想法，如果给定的完备
匹配中xi->yi，现在我们想让xi指向yj。如果让xi->yj的
话，那么yi显然对于xi已经没用了，又因为最终的匹配必
然是一个完备匹配，所以假如寻找到了增广链，那么增广
链的最后一条边所指向的节点必然是yi。假如我们由yi向
xi再连一条边会发生什么呢？很明显，形成了一个环！也
就是说，形成了一个强连通分量。所以说，如果xi可以选
择yj，那么xi和yj必然属于同一个强连通分量。所以此题
可用强连通分量来求解
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
const int maxn = 2 * 2000 + 66;

int dfn[maxn], low[maxn], belong[maxn];
int n, id, tot;
bool instack[maxn], gg[maxn][maxn];
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
		memset (gg, false, sizeof (gg));

		for (int i = 1; i <= n; i++)
		{
			int num;
			scanf ("%d", &num);
			for (int j = 1; j <= num; j++)
			{
				int u;
				scanf ("%d", &u);
				g[i].push_back (n + u);
				gg[i][u] = true;
			}
		}
		
		for (int i = 1; i <= n; i++)
		{
			int u;
			scanf ("%d", &u);
			g[n+u].push_back (i);
		}

		SS ();
		vector <int> temp;
		for (int i = 1; i <= n; i++)
		{
			temp.clear ();
			for (int j = n + 1; j <= 2 * n; j++)
				if (gg[i][j-n] && belong[i] == belong[j])
					temp.push_back (j - n);
			sort (temp.begin (), temp.end ());
			printf ("%d", temp.size ());
			for (int j = 0; j < temp.size (); j++)
				printf (" %d", temp[j]);
			puts ("");
		}
	}
    return 0;
}
