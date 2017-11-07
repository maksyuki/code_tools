/***********************************************
以POJ2528为例
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
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 20000 + 6666;

struct Node
{
	int x, y;
};

Node a[maxn];
int xx[maxn*3], xxlen, lazy[maxn<<4];
bool have[maxn];
long long res;

void PushDown (int rt, int l, int m, int r)
{
    if (lazy[rt] != -1)
	{
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;
	}
}

void UpDate (int rt, int l, int r, int L, int R, int id)
{
    if (L <= l && r <= R)
	{
        lazy[rt] = id;
        return ;
	}

    int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
    if (L <= m)
		UpDate (lson, L, R, id);

	if (R > m)
		UpDate (rson, L, R, id);
}

void Query (int rt, int l, int r)
{
   	if (lazy[rt] != -1)
	{
		if (!have[lazy[rt]])
		{
			have[lazy[rt]] = true;
			res++;
		}
		return ;
	}

	if (l == r)
		return ;

	int m = (l + r) >> 1;
//	PushDown (rt, l, m, r);

	Query (lson);
	Query (rson);
}

int main()
{
//	ifstream cin ("aaa.txt");
//	freopen ("aaa.txt", "r", stdin);

	int t;
	scanf ("%d", &t);

	while (t--)
	{
        int n;
        scanf ("%d", &n);

		xxlen= 0;
        for (int i = 1; i<= n; i++)
		{
			scanf ("%d%d", &a[i].x, &a[i].y);
			xx[xxlen++] = a[i].x, xx[xxlen++] = a[i].y;
		}

        sort (xx, xx + xxlen);
        xxlen = unique (xx, xx + xxlen) - xx;

        for (int i = xxlen - 1; i >= 1; i--)
            if (xx[i] != xx[i-1] + 1)
                xx[xxlen++] = xx[i-1] + 1;

		sort (xx, xx  + xxlen);
//		for (int i = 0; i < xxlen;i++)
//			cout << xx[i] << endl;

		fill (lazy, lazy + (maxn<<4), -1);

        for (int i = 1; i <= n; i++)
		{
            int sx = lower_bound (xx, xx + xxlen, a[i].x) - xx;
            int sy = lower_bound (xx, xx + xxlen, a[i].y) - xx;
 //           cout << sx << " " << sy << endl;

            UpDate (1, 0, xxlen, sx, sy, i);
		}

		memset (have, false, sizeof (have));

		res = 0;
        Query (1, 0, xxlen);
        printf ("%lld\n", res);
	}
return 0;
}
