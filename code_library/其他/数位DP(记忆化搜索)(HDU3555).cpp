/***********************************************
��HDU2089Ϊ��
************************************************
dp[i][0]��ʾiλ����û��49�����ĸ���
dp[i][1]��ʾiλ����û��49����λ������4�����ĸ���
dp[i][2]��ʾiλ������49�����ĸ���
ע�⣺dp����ֻ����һ�飡������ֻ�ڳ���Ŀ�ʼ��ʼ��һ��dp����
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

//flagĿ����Ϊ���ܹ�ö��С�ڸ�λ����һλ�ϵ����к���������������653��˵����ʱ��pos == 3(��bit[pos] == 6)����
//ֻҪposö�ٵ�ֵС��6����pos - 1λ�ϵ�ֵ����ö��0~9(����59x��37x��)����posλ�õ�ֵǡ��ö�ٵ�bit[pos] == 6����
//pos - 1λ�ϵ�ֵֻ��ö��0~bit[pos-1]

//bit�����1~len�洢val�ĵ�λ����λ��ÿһλ�ϵ���
LL dp[166][3], bit[166];

LL SS (int pos, int st, bool flag)
{
	if (pos == 0) return st == 2;//Ŀ���Ǹ�dp[1][2]��ֵ�����������ʱ����λΪ"49"����ֵΪ1
	if (flag && dp[pos][st] != -1) return dp[pos][st];//flag == true��ʾ��ʱ1~pos - 1λ�ϵ�ֵȫ����������ˣ����Կ�
													  //��ֱ�ӷ��ؽ��
	LL res = 0;
	int x = flag ? 9 : bit[pos];
	for (int i = 0; i <= x; i++)
	{
		if ((st == 2) || (st == 1 && i == 9)) res += SS (pos - 1, 2, flag || i < x);//��posλ������49������pos+1λ
		else if (i == 4) res += SS (pos - 1, 1, flag || i < x);						//����4��posλ����9
		else res += SS (pos - 1, 0, flag || i < x);
	}

	return flag? dp[pos][st] = res : res;
}

//����[0, val]��Χ�ڵ����к���"49"�����ĸ���
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
