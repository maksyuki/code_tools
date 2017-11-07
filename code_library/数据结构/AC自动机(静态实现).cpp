/***********************************************
以HDU2222为例
************************************************
@接口:
@功能:
@时间复杂度:
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
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r

using namespace std;

const int INF = 0x7FFFFFFF;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int MOD = 1e9 + 7;
const int maxn = 26;


struct ACNode
{
    int next[500010][maxn], pre[500010], last[500010];
    int root, len;

    void Init ()
    {
        len = 0;
        root = newnode ();
    }

    int newnode ()
    {
        for (int i = 0; i < maxn; i++)
            next[len][i] = -1;
        last[len++] = 0;

        return len - 1;
    }

    void Insert (char *s)
    {
        int p = root;
        for(int i = 0; s[i]; i++)
        {
            if(next[p][s[i]-'a'] == -1)
                next[p][s[i]-'a'] = newnode ();

            p = next[p][s[i]-'a'];
        }
        last[p]++;
    }

    void Build ()
    {
        queue <int> qu;
        pre[root] = root;
        for(int i = 0; i < maxn; i++)
        {
            if(next[root][i] == -1)
                next[root][i] = root;

            else
            {
                pre[next[root][i]] = root;
                qu.push (next[root][i]);
            }
        }

        while (!qu.empty ())
        {
            int p = qu.front(); qu.pop ();
            for (int i = 0; i < maxn; i++)
            {
                if (next[p][i] == -1)
                    next[p][i] = next[pre[p]][i];

                else
                {
                    pre[next[p][i]] =  next[pre[p]][i];
                    qu.push (next[p][i]);
                }
            }
        }
    }

    int Query (char *s)
    {
        int p = root, res = 0;
        for (int i = 0; s[i]; i++)
        {
            p = next[p][s[i]-'a'];
            int temp = p;
            while (temp != root)
            {
                res += last[temp];
                last[temp] = 0;
                temp = pre[temp];
            }
        }
        return res;
    }
};

char ss[1000010];
ACNode ac;

int main()
{
//    freopen ("aaa.txt", "r", stdin);

    int t, n;
    scanf ("%d",&t);

    while (t--)
    {
        scanf ("%d", &n);
        ac.Init ();

        for (int i = 0; i < n; i++)
        {
            scanf("%s", ss);
            ac.Insert (ss);
        }
        ac.Build ();

        scanf ("%s", ss);
        printf ("%d\n", ac.Query (ss));
    }
return 0;
}
