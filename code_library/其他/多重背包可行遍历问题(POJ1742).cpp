
/*************************************************
Author        :supermaker
Created Time  :2016/4/16 20:16:26
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
const int maxn = 1e5 + 66;

int c[166], m[166], sum[maxn];
bool dp[maxn];

int main()
{
    //CFF;
    //CPPFF;
	int N, M;
	while (scanf ("%d%d", &N, &M) != EOF)
	{
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++)
			scanf ("%d", &c[i]);
		for (int i = 1; i <= N; i++)
			scanf ("%d", &m[i]);

		memset (dp, false, sizeof (dp));
		dp[0] = true;
		int res = 0;
		for (int i = 1; i <= N; i++)
		{
			memset (sum, 0, sizeof (sum));
			for (int j = c[i]; j <= M; j++)
				if (!dp[j] && dp[j-c[i]] && sum[j-c[i]] < m[i])
				{
					dp[j] = true;
					sum[j] = sum[j-c[i]] + 1;
					res++;
				}
		}
		printf ("%d\n", res);
	}
    return 0;
}
