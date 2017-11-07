/***********************************************
以HDU1512为例
************************************************
@接口: void Init ()
@功能: 初始化堆
@时间复杂度: O (n)

@接口: int Merge (int a, int b)
@功能: 将堆顶元素编号是a和b的两个堆合并成一个堆
@时间复杂度: O (logn)
@a: 一个堆堆顶元素的标号
@b: 另一个堆堆顶元素的标号

@接口: int Del (int a)
@功能: 删去堆顶元素标号是a的堆顶元素
@时间复杂度: O (logn)
@a:堆顶元素标号
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
const int maxn = 1e6 + 66;


struct node
{
    int key, lson, rson, par, dis;
};

node tr[maxn];

int UnFind (int rt)
{
    if (tr[rt].par == rt) return rt;
    else return tr[rt].par = UnFind (tr[rt].par);
}

void Init ()
{
    for (int i = 0; i < maxn; i++)
    {
        tr[i].key = tr[i].lson = tr[i].rson = -1;
        tr[i].par = i;
    }
}

int Merge (int a, int b)
{
    if (a == -1) return b;
    if (b == -1) return a;
    if (tr[a].key < tr[b].key) swap (a, b);

    tr[a].rson = Merge (tr[a].rson, b);
    tr[tr[a].rson].par = a;

    if (tr[tr[a].rson].dis > tr[tr[a].lson].dis)
        swap (tr[a].rson, tr[a].lson);

    tr[a].dis = tr[tr[a].rson].dis + 1;
    return a;
}

int Del (int a)
{
    int lch = tr[a].lson, rch = tr[a].rson;
    tr[lch].par = lch, tr[rch].par = rch;
    tr[a].lson = tr[a].rson = tr[a].dis = -1;
    return Merge (lch, rch);
}

int main()
{
//    CFF;
    int n;
    while (scanf ("%d", &n) != EOF)
    {
        Init ();
        for (int i = 1; i <= n; i++)
            scanf ("%d", &tr[i].key);

        int q;
        scanf ("%d", &q);
        for (int i = 1; i <= q; i++)
        {
            int u, v;
            scanf ("%d%d", &u, &v);
            u = UnFind (u);
            v = UnFind (v);
            if(u == v)
                puts ("-1");

            else
            {
                int ta = Del (u);
                int tb = Del (v);
                tr[u].key /= 2;
                tr[v].key /= 2;
                ta = Merge (u, ta);
                tb = Merge (v, tb);
                int tt = Merge (ta, tb);
                printf ("%d\n", tr[tt].key);
            }
        }
    }
    return 0;
}

