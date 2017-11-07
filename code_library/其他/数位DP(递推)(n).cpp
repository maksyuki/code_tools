/***********************************************
以HDU2089为例
************************************************
dp[i][0]表示长度为i不含有不吉利数字的数的个数
dp[i][1]表示长度为i不含有不吉利数字且高位为2的数的个数
dp[i][2]表示长度为i含有不吉利数字的数的个数
注意：(1)第97行是非常重要的！！！
	  (2)这里求解的是(0, n)范围内满足条件的数的个数
************************************************/

/*************************************************
Author        :supermaker
Created Time  :2015/12/1 0:04:06
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

LL dp[26][3], bit[66];

void PP ()
{
	memset (dp, 0, sizeof (dp));
	dp[0][0] = 1;
	for (int i = 1; i < 26; i++)
	{
		dp[i][0] = dp[i-1][0] * 9 - dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1] + dp[i-1][0];
	}
}

LL SS (LL n)
{
	int len = 0;
	LL tt = n;
	while (n)
	{
		bit[++len] = n % 10;
		n /= 10;
	}
	bit[len+1] = 0;
	LL res = 0;
	bool is_have = false;
	for (int i = len; i >= 1; i--)
	{
		res += dp[i-1][2] * bit[i];
		if (is_have) res += dp[i-1][0] * bit[i];
		if (!is_have && bit[i] > 6) res += dp[i-1][1];
		if (!is_have && bit[i] > 4) res += dp[i-1][0];
		if (!is_have && bit[i+1] == 6 && bit[i] > 2) res += dp[i][1];
		if ((bit[i+1] == 6 && bit[i] == 2) || bit[i] == 4) 
			is_have = true;
	}
	return tt - res;
}

int main()
{
	PP ();
    //CFF;
    //CPPFF;
	LL n, m;
	while (scanf ("%I64d%I64d", &n, &m) != EOF)
	{	
		if (n == 0 && m == 0)
			break;

		LL vala = SS (n);
		LL valb = SS (m + 1);
		printf ("%I64d\n", valb - vala);
	}
    return 0;
}
