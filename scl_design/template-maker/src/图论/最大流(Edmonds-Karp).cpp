/***********************************************
��POJ 2173Ϊ��
************************************************
@�ӿ�: long long Edmonds_Karp (int s, int t)
@����: ���������
@ʱ�临�Ӷ�: O (n * m ^ 2)
@s: Դ����±�
@t: �����±�
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
using namespace std;

const int INF = 0x7FFFFFFF;
const int MOD = 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 200 + 66;


struct Node
{
	int c, f;//�ֱ��ʾ��֮�������������
};

Node edge[maxn][maxn];
//n��ʾ����ĸ�����m��ʾ�ߵĸ�����pre��ʾ��ǰ�ڵ��ǰ׺�ڵ㣬a��ʾ��ǰ�ڵ�Ŀ�������������a[i] = 0��ʾ
//��ǰ�ڵ㲻������������ǻ�û�б�����
int n, m, pre[maxn], a[maxn];

//�ڵ��ú���ǰҪ��������ʼ��������!!!
long long Edmonds_Karp (int s, int t)
{
    queue <int> q;
    memset (a, 0, sizeof(a));
    memset (pre, 0, sizeof(pre));
    long long maxflow = 0;

    while (1)
    {
        memset (a, 0, sizeof(a));
        a[s] = INF;//��ֵINF��ʾԴ��������������ڽӽڵ����������
        q.push(s);
        while (!q.empty())
        {
            int tt = q.front(); q.pop();

            for (int i = 1; i <= n; i++)
            if(!a[i] && edge[tt][i].c > edge[tt][i].f)
            {
                pre[i] = tt;
                q.push (i);
                a[i] = a[tt] < edge[tt][i].c - edge[tt][i].f ? a[tt]:edge[tt][i].c - edge[tt][i].f;
            }
        }

        if(a[t] == 0) break;

        for(int i = t; i != s; i = pre[i])
        {
            edge[pre[i]][i].f += a[t];
            edge[i][pre[i]].f -= a[t];
        }

        maxflow += a[t];
    }
    return maxflow;
}


int main()
{
//    ifstream cin ("aaa.txt");

    while (cin >> m >> n)
	{
		memset (edge, 0, sizeof (edge));

        int u, v, w;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            edge[u][v].c += w;
        }

        cout << Edmonds_Karp (1, n) << endl;
	}

return 0;
}
