/***********************************************
POJ2299 线段树+离散化
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
const int maxn = 500000 + 66;

int a[maxn], temp[maxn], avr[maxn], len;

int lowbit (int x)
{
    return x & (-x);
}


int GetSum (int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += avr[x];
        x -= lowbit (x);
    }

return sum;
}

void UpDate (int x)
{
    while (x <= len)
    {
        avr[x]++;
        x += lowbit (x);
    }
}

int main()
{
//    freopen ("aaa.txt", "r", stdin);

    int n;
    while (scanf ("%d", &n) != EOF)
    {
        if (n == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            scanf ("%d", &a[i]);
            temp[i] = a[i];
        }

        sort (temp + 1, temp + 1 + n);
        len = unique (temp + 1, temp + 1 + n) - (temp + 1);
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound (temp + 1, temp + 1 + len, a[i]) - temp;

        long long res = 0;
        memset (avr, 0, sizeof (avr));

        for (int i = 1; i <= n; i++)
        {
            res += GetSum (len) - GetSum (a[i]);
            UpDate (a[i]);
        }

        printf ("%lld\n", res);
    }
return 0;
}
