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
const int MOD = 7;
const int maxn = 100 + 6;

int ans[maxn][maxn], sum[maxn][maxn];//列前缀和表

int main()
{
//   ifstream cin ("aaa.txt");

    int n;
    while (cin >> n)
    {
        for (int i = 1;i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> ans[i][j];

        memset (sum, 0, sizeof (sum));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                sum[i][j] = sum[i-1][j] + ans[i][j];

        int maxval = -INF, tempsum, tempval;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                tempsum = -INF, tempval = 0;
                for (int k = 1; k <= n; k++)
                {
                    int temp = sum[j][k] - sum[i-1][k];
                    if (tempval > 0)
                        tempval += temp;

                    else
                        tempval = temp;

                    tempsum = max (tempsum, tempval);
                }
                maxval = max (maxval, tempsum);
            }

        cout << maxval << endl;
    }

return 0;
}
