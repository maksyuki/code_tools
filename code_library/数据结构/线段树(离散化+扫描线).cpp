/***********************************************
以POJ1151为例
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
const int maxn = 6000;

struct Node
{
	double l, r, h;
	int id;
};

Node a[maxn];
int len, hhlen;
double sum[maxn<<2], Hash[maxn<<2];
int lazy[maxn<<2];

bool cmp (Node aa, Node bb)
{
	return aa.h < bb.h;
}

void PushUp (int rt, int l, int r)
{
	if (lazy[rt])
		sum[rt] = Hash[r+1] - Hash[l];

    else if (l == r)
		sum[rt] = 0;

	else
		sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void UpDate (int rt, int l, int r, int L, int R, int id)
{
	if (L <= l && r <= R)
	{
		lazy[rt] += id;
		PushUp (rt, l, r);
        return ;
	}

	int m = (l + r) >> 1;
    if (L <= m)
		UpDate (lson, L, R, id);

	if (R > m)
		UpDate (rson, L, R, id);

	PushUp (rt, l, r);
}

int main()
{
//	ifstream cin ("aaa.txt");
//	freopen ("aaa.txt", "r", stdin);

	int flag = 1, n;
	while (cin >> n)
	{
		if (n == 0)
			break;

		cout << "Test case #" << flag++ << endl;

		len = hhlen = 0;
		double x1, y1, x2, y2;
        for (int i = 1; i <= n; i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			a[len].l = x1, a[len].r = x2, a[len].h =y2, a[len++].id = -1;
			a[len].l = x1, a[len].r = x2, a[len].h = y1, a[len++].id = 1;
			Hash[hhlen++] = x1, Hash[hhlen++] = x2;
		}

        sort (a, a + len, cmp);
		sort (Hash, Hash + hhlen);
        hhlen = unique (Hash, Hash + hhlen) - Hash;

		memset (sum, 0, sizeof (sum));
		memset (lazy, 0, sizeof (lazy));
		double res = 0;
		for (int i = 0; i < len - 1; i++)
		{
//			cout << a[i].l << " " << a[i].r << " " <<a[i].h<< " " << a[i].id << endl;
//			cout << res << endl;
			int sx = lower_bound (Hash, Hash + hhlen, a[i].l) - Hash;
			int sy = lower_bound (Hash, Hash + hhlen, a[i].r) - Hash - 1;

			if (sx <= sy)
				UpDate (1, 0, hhlen - 1, sx, sy, a[i].id);
			res += sum[1] * (a[i+1].h - a[i].h);
		}

		cout << "Total explored area: " << fixed << setprecision(2) << res << endl << endl;
	}
return 0;
}
