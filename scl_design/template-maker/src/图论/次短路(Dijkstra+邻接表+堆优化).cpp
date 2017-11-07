/***********************************************
��POJ3255Ϊ��
************************************************
@�ӿ�:  void Dijkstra (int s)
@����: ����Դ��s��ʼ�Ĵζ�·
@ʱ�临�Ӷ�: O (nlogn)
@s: Դ��
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
#define	DB(ccc)	cout << #ccc << " = " << ccc << endl
#define PB push_back
#define MP(A, B) make_pair(A, B)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef pair <int, int> PII;
typedef pair <int, bool> PIB;

const int INF = 0x7FFFFFFF;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 5e3 + 66;

vector <PII> edge[maxn];
int n, dis[maxn][2];//n��ʾ�ڵ�ĸ�����dis[i][0]��ʾ��Դ�㵽i�����·��dis[i][1]��ʾ��Դ�㵽i�Ĵζ�·

void Dijkstra (int s)
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 2; j++)
            dis[i][j] = INF;

    dis[s][0] = 0;//Դ�㵽�Լ������·��0��ʮ����Ҫ!!!
    priority_queue <PII, vector <PII>, greater <PII> > qu;
    qu.push (PII (0, s));
    while (!qu.empty ())
    {
        PII ta = qu.top (); qu.pop ();
        int v1 = ta.second, d1 = ta.first;
        if (dis[v1][1] < d1) continue;
        for (int i = 0; i < edge[v1].size (); i++)
        {
            PII tb = edge[v1][i];
            int v2 = tb.first, w2 = tb.second;
            int d2 = d1 + w2;
            if (dis[v2][0] > d2)
            {
                swap (dis[v2][0], d2);
                qu.push (PII (dis[v2][0], v2));
            }

            if (dis[v2][0] < d2 && dis[v2][1] > d2)
            {
                dis[v2][1] = d2;
                qu.push (PII (dis[v2][1], v2));
            }
        }
    }
}


int main()
{
//    CFF;
    int m;
    while (scanf ("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < maxn; i++) edge[i].clear ();

        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf ("%d %d %d", &u, &v, &w);
            edge[u].PB (PII (v, w));
            edge[v].PB (PII (u, w));
        }

        Dijkstra (1);
        printf ("%d\n", dis[n][1]);
    }
    return 0;
}

