/***********************************************
************************************************
@接口:
@功能:
@时间复杂度: O(nlogn)
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

#define CFF freopen ("aaa.txt", "r", stdin)
#define CPPFF ifstream cin ("aaa.txt")
#define LL long long

const int INF = 0x7FFFFFFF;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = 2 * acos (0.0);
const int maxn = 4e6 + 66;

LL euler[maxn], aa[maxn];

void Get ()
{
    memset (aa, 0, sizeof (aa));
    for (LL i = 0; i < maxn; i++)
        euler[i] = i;

    for (LL i = 2; i < maxn; i += 2)
        euler[i] >>= 1;

    for (LL i = 2; i < maxn; i++)
    {
        if (euler[i] == i)
        {
            for (LL j = i; j < maxn; j += i)
                euler[j] -= euler[j] / i;
        }
        //时间复杂度的主要部分，总结起来是一个调和级数*n，即时间复杂度是O(nlogn)
        for (LL j = 1; j * i < maxn; j++)//此时euler[i]的值已经计算出来
            aa[j*i] += j * euler[i];

    }
    for (LL i = 1; i < maxn; i++)
        aa[i] += aa[i-1];
}


int main()
{
    Get ();
//    CFF;
    LL n;
    while (scanf ("%lld", &n) != EOF)
    {
        if (n == 0)
            break;

        printf ("%lld\n", aa[n]);
    }
    return 0;
}

