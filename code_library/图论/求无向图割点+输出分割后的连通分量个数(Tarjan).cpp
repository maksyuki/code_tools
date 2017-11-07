/***********************************************
��POJ 1523Ϊ�� Tarjan�㷨
Tarjan�㷨�������ǹ���һ��dfs������������Ȼ����
����ͨ������رߵĸ��������

ע��
(1)����subnets[i]����0�ķǸ��ڵ�i��˵�������仹
��һ�����ڵ����ڵ���ͨ�������������ʱҪ��1

(2)����subnets[i]����0�ĸ��ڵ���˵��ֻ����subnets
ֵ����1�����ڵ���Ǹ��
************************************************
@�ӿ�: void Init (int rt)
@����:��ʼ���ڽӾ������������
@ʱ�临�Ӷ�: O (n ^ 2)
@rt: ��ʾdfs�������еĸ�(������ָ��)

@�ӿ�: void dfs (int u, int par)
@����: dfs������нڵ��dfn��lowֵ
@ʱ�临�Ӷ�: O (n ^ 2)
@u: ��ǰ�ڵ�
@par: ��ǰ�ڵ�ĸ��ڵ�
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

#define CFF freopen ("aaa.txt", "r", stdin)
#define CPPFF ifstream cin ("aaa.txt")
#define i64 long long

const int INF = 0x7FFFFFFF;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 1000 + 66;

//�ֱ��ʾ�ڽӾ��󡢷������顢dfs�������������ǰ�ڵ���Ե���������������ÿ���ڵ����ͨ������(ɾȥ�ýڵ�)
int edge[maxn][maxn], vis[maxn], dfn[maxn], low[maxn], subnets[maxn];
int n, id;//�ֱ��ʾ����������ȫ�ֱ�־(���dfs���������)

void Init (int rt)
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            edge[i][j] = INF;
    dfn[rt] = low[rt] = id = 1;//�����ڵ��dfn��lowֵ����Ϊ1
    memset (vis, 0, sizeof (vis));
    vis[rt] = 1;//��ʼ����������vis
    memset (subnets, 0, sizeof (subnets));//��ʼ����ͨ��������subnets
}

void dfs (int u, int par)
{
    for (int v = 1; v <= n; v++)//�����ж����е��ڽӵ�
    {
        if (edge[u][v] < INF && !vis[v])//����ڽ���vΪu�ĺ��ӽڵ�
        {
            vis[v] = 1;
            dfn[v] = low[v] = ++id;//���ʸú��ӽڵ㲢���ϱ�־
            dfs (v, u);//�ݹ�ط���v�ĺ��ӽڵ�
            low[u] = min (low[u], low[v]);//ʹ��u�ĺ��ӽڵ�v��lowֵ������u��lowֵ

            if (low[v] >= dfn[u])//������ӽڵ��lowֵ(���)���ڵ��ڵ�ǰ�ڵ�u��dfnֵ(���)����ͨ���������Լ�1
                subnets[u]++;
        }

        else if (edge[u][v] < INF && vis[v] && v != par)//����ڽ���vΪu�����Ƚڵ�(�����Ǹ��ڵ�)
            low[u] = min (low[u], dfn[v]);//ֱ��ʹ�ûر������Ƚڵ��dfnֵ����u��lowֵ����
    }
}

int main()
{
//    CPPFF;
    int flag = 1, u, v;
    while (cin >> u)
    {
        if (u == 0)
            break;

        Init(1);

        cin >> v;
        n = -INF;
        n = max (n, u);
        n = max (n, v);
        edge[u][v] = edge[v][u] = 1;
        while (cin >> u)
        {
            if (u == 0)
                break;

            cin >> v;
            n = max (n, u);
            n = max (n, v);
            edge[u][v] = edge[v][u] = 1;
        }

        if (flag > 1)
            cout << endl;

        cout << "Network #" << flag++ << endl;

        dfs (1, -1);
        bool is_find = false;
        for (int i = 1; i <= n; i++)
        {
            if (subnets[i])
            {
                if (i == 1 && subnets[i] > 1)//�����ǰ�ڵ��Ǹ��ڵ�������ͨ����������1�������
                {
                        cout << "  SPF node " << i << " leaves " << subnets[i] << " subnets" << endl;
                        is_find = true;
                }

                else if (i != 1)//���������ڵ�(��root�ڵ�)����ֱ�ӽ�����ͨ�������Լ�1���(��Ϊ����i�ڵ�һ�����ڵ����ڵ���ͨ����)
                {
                    cout << "  SPF node " << i << " leaves " << subnets[i] + 1 << " subnets" << endl;
                    is_find = true;
                }
            }
        }

        if (!is_find)
            cout << "  No SPF nodes" << endl;
    }
    return 0;
}

