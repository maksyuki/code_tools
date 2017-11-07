/*************************************************
Author        :supermaker
Created Time  :2015/12/3 14:36:11
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
const int maxn = 1e5 + 6666;

int dp[1666][36], c[1666], w[1666], ta[36], tb[36], N, V, K;

void Kth_ZeroOnePack (int c, int w)
{
	for (int i = V; i >= c; i--)
	{
		for (int k = 1; k <= K; k++)
		{
			ta[k] = dp[i][k];
			tb[k] = dp[i-c][k] + w;
		}
		
		ta[K+1] = tb[K+1] = -1;
		for (int j = 1, k = 1, q = 1; j <= K && (ta[k] != -1 || tb[q] != -1); )
		{
			if (ta[k] >= tb[q]) dp[i][j] = ta[k++];
			else dp[i][j] = tb[q++];
			if (dp[i][j] != dp[i][j-1]) j++;
		}
	}
}

void Solve ()
{
	
	memset (dp, 0, sizeof (dp));
	for (int i = 1; i <= N; i++)
			Kth_ZeroOnePack (c[i], w[i]);
}

int main()
{
    CFF;
    //CPPFF;
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d%d%d", &N, &V, &K);
		for (int i = 1; i <= N; i++)
			scanf ("%d", &w[i]);

		for (int i = 1; i <= N; i++)
			scanf ("%d", &c[i]);

		Solve ();		
		printf ("%d\n", dp[V][K]);
	}
    return 0;
}
