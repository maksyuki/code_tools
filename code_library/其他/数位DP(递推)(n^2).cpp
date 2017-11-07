/***********************************************
以HDU2089为例
************************************************
dp[i][j]表示高位数字是j的i位数中满足条件的数的个数
注意：(1)只要遇到一个不满足条件的数就直接break
	  (2)这里求解的是(0, n)范围内满足条件的数的个数
************************************************/


/*************************************************
Author        :supermaker
Created Time  :2015/12/1 1:39:44
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
const int maxn = 1e5 + 6666;

int dp[66][66], bit[66];

void PP ()
{
	memset (dp, 0, sizeof (dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 8; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				if (j != 4 && ! (j == 6 && k == 2))
					dp[i][j] += dp[i-1][k];
}

int SS (int n)
{
	int len = 0;
	while (n)
	{
		bit[++len] = n % 10;
		n /= 10;
	}
	bit[len+1] = 0;

	int res = 0;
	for (int i = len; i >= 1; i--)
	{
		for (int j = 0; j < bit[i]; j++)
		{
			if (j != 4 && !(bit[i+1] == 6 && j == 2))
				res += dp[i][j];
		}
		if (bit[i] == 4 || (bit[i+1] == 6 && bit[i] == 2))
			break;
	}
	return res;
}

int main()
{
    //CFF;
    //CPPFF;
	PP ();
	int n, m;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;

		printf ("%d\n", SS (m + 1) - SS (n));
	}
    return 0;
}
