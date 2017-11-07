/***********************************************
以POJ1785为例
************************************************
@接口:
@功能:
@时间复杂度:
@:
************************************************/

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
#define LL long long
#define ULL unsigned long long
#define	DB(ccc)	cout << #ccc << " = " << ccc << endl

const int INF = 0x7FFFFFFF;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 5e4 + 66;

struct node
{
    int l, r, par;
    int v;
    char s[66];
};

node dt[maxn];

void dfs (int rt)
{
    printf ("(");
    if (dt[rt].l) dfs (dt[rt].l);
    printf ("%s/%d", dt[rt].s, dt[rt].v);
    if (dt[rt].r) dfs (dt[rt].r);
    printf (")");
}

void Init ()
{
    for (int i = 0; i < maxn; i++)
    {
        dt[i].l = dt[i].r = dt[i].par = 0;
        dt[i].v = INF;
    }
}

bool cmp (node a, node b)
{
    return strcmp (a.s, b.s) < 0;
}

//插入节点来构建笛卡尔树
void Insert (int rt)
{
    int i = rt - 1;
    while (dt[i].v < dt[rt].v) i = dt[i].par;
    dt[rt].l = dt[i].r;
    dt[dt[i].r].par = rt;//非常重要，如果没有修改会导致从孩子回溯时出现错误！！！
    dt[rt].par = i;
    dt[i].r = rt;
}


int main()
{
//    CFF;
    int n;
    while (scanf ("%d", &n) != EOF)
    {
        if (n == 0)
            break;

        Init ();
        for (int i = 1; i <= n; i++)
            scanf (" %[a-z]/%d", dt[i].s, &dt[i].v);

        sort (dt + 1, dt + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            Insert (i);

        dfs (dt[0].r);

        puts ("");
    }
    return 0;
}

