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
const int maxn = 30 + 6;

//ans数组存储输入的矩阵，dp[i][j][k][q]表示两个
//线程分别到达(i,j)和(k,q)时所获得最大数
int ans[maxn][maxn], dp[maxn][maxn][maxn][maxn];

int main()
{
//    ifstream cin ("aaa.txt");

    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> ans[i][j];

        memset (dp, 0, sizeof (dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n ;j++)
                for (int k = 1; k <= n; k++)
                    for (int q = 1; q <= n; q++)
                    {
                        int tempa = max (dp[i-1][j][k-1][q], dp[i-1][j][k][q-1]);
                        int tempb = max (dp[i][j-1][k-1][q], dp[i][j-1][k][q-1]);
                        tempa = max (tempa, tempb);

                        if ((i == k) && (j == q))
                            dp[i][j][k][q] = tempa + ans[i][j];

                        else
                            dp[i][j][k][q] = tempa + ans[i][j] + ans[k][q];
                    }

        cout << dp[n][n][n][n] << endl;//直接输出结果
    }

return 0;
}
