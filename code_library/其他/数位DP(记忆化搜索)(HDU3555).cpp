/***********************************************
以HDU2089为例
************************************************
dp[i][0]表示i位数中没有49的数的个数
dp[i][1]表示i位数中没有49但高位数字是4的数的个数
dp[i][2]表示i位数中有49的数的个数
注意：dp数组只计算一遍！！！即只在程序的开始初始化一次dp数组
************************************************/


/*************************************************
Author        :supermaker
Created Time  :2015/12/3 23:38:07
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

//flag目的是为了能够枚举小于该位的下一位上的所有合理的数，比如对于653来说，此时若pos == 3(即bit[pos] == 6)，则
//只要pos枚举的值小于6，则pos - 1位上的值可以枚举0~9(例：59x、37x等)，若pos位置的值恰好枚举到bit[pos] == 6，则
//pos - 1位上的值只能枚举0~bit[pos-1]

//bit数组从1~len存储val的低位到高位的每一位上的数
LL dp[166][3], bit[166];

LL SS (int pos, int st, bool flag)
{
	if (pos == 0) return st == 2;//目的是给dp[1][2]赋值！！！比如此时低两位为"49"，则赋值为1
	if (flag && dp[pos][st] != -1) return dp[pos][st];//flag == true表示此时1~pos - 1位上的值全部都计算过了，所以可
													  //以直接返回结果
	LL res = 0;
	int x = flag ? 9 : bit[pos];
	for (int i = 0; i <= x; i++)
	{
		if ((st == 2) || (st == 1 && i == 9)) res += SS (pos - 1, 2, flag || i < x);//若pos位数中有49或者是pos+1位
		else if (i == 4) res += SS (pos - 1, 1, flag || i < x);						//上是4，pos位上是9
		else res += SS (pos - 1, 0, flag || i < x);
	}

	return flag? dp[pos][st] = res : res;
}

//计算[0, val]范围内的所有含有"49"的数的个数
LL Calc (LL val)
{
	int len = 0;
	while (val)
	{
		bit[++len] = val % 10;
		val /= 10;
	}
    return SS (len, 0, 0);
}

int main()
{
    CFF;
    //CPPFF;
	int t;
	memset (dp, -1, sizeof (dp));
	scanf ("%d", &t);
	while (t--)
	{
		LL val;
		scanf ("%I64d", &val);
		printf ("%I64d\n", Calc (val));
	}
    return 0;
}
