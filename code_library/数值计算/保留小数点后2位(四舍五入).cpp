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

#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r

using namespace std;

const int INF = 0x7FFFFFFF;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int MOD = 10000 + 7;

const int maxn = 10000 + 66;

int main()
{
//    ifstream cin ("aaa.txt");
//    freopen ("aaa.txt", "r", stdin);

    long long a;
    while (scanf ("%lld", &a) != EOF)
    {

        if (a % 10 >= 5)
        {
            a += 10;
        }

        printf ("%lld.%02lld\n", a / 1000, a / 10 % 100);
    }

return 0;
}
