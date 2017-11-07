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

int a[maxn], sum[maxn<<2], temp[maxn];
int dp[maxn][maxn], len;

void PushUp (int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}


int Query (int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return sum[rt];

    int res = 0, m = (l + r) >> 1;
    if (L <= m)
        res += Query (lson, L, R);

    if (R > m)
        res += Query (rson, L, R);

return res;
}

void UpDate (int rt, int l, int r, int val)
{
    if (l == r)
    {
        sum[rt]++;
        return ;
    }

    int m = (l + r) >> 1;
    if (val <= m)
        UpDate (lson, val);

    else
        UpDate (rson, val);

    PushUp (rt);
}


int main()
{
//    freopen ("aaa.txt", "r", stdin);

    int n, q;
    while (scanf ("%d%d", &n, &q) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf ("%d", &a[i]);
            temp[i] = a[i];
        }

        sort (temp + 1, temp + 1 + n);
        len = unique (temp + 1, temp + 1 + n) - (temp + 1);
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound (temp + 1, temp + 1 + len, a[i]) - temp;

        memset (dp, 0, sizeof (dp));
        for (int i = 1; i <= n; i++)
        {
            memset (sum, 0, sizeof (sum));
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = dp[i][j-1] + Query (1, 1, len, a[j] + 1, len);
                UpDate (1, 1, len, a[j]);
            }
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
