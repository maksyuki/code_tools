/***********************************************
Best Coder #45 B
************************************************
@接口:
@功能:
@时间复杂度:
@:
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

#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r

const int INF = 0x7FFFFFFF;
const double EPS = 1e-10;
const int mod = 1000000000 + 7;
const int maxn = 1000 + 66;

int a[maxn];
int dp[maxn][maxn];

int main()
{
//    freopen ("aaa.txt", "r", stdin);

    int n, q;
    while (scanf ("%d%d", &n, &q) != EOF)
    {
        memset (dp, 0, sizeof (dp));
        for (int i = 1; i <= n; i++)
        {
            scanf ("%d", &a[i]);
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[j] > a[i])
                    dp[j][i] = dp[j+1][i] + 1;

                else
                dp[j][i] = dp[j+1][i];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                dp[i][j] += dp[i][j-1];
        }

        int L, R;
        for (int i = 1; i <= q; i++)
        {
            scanf ("%d%d", &L, &R);
            printf ("%d\n", dp[L][R]);
        }
    }

return 0;
}
