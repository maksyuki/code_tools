/***********************************************
��HDU2222Ϊ��
************************************************
@�ӿ�: void Init ()
@����: ��ʼ��root�ڵ�
@ʱ�临�Ӷ�: O (1)

@�ӿ�: void Insert (char *s) 
@����: ��AC�Զ����в����ַ���s
@ʱ�临�Ӷ�: O (len(s))
@s: ��������ַ���

@�ӿ�: void Build ()
@����: ����AC�Զ���
@ʱ�临�Ӷ�: O (all_len(si))

@�ӿ�: int Query (char *s) 
@����: ��ѯs�г��ֵ��ַ����ĸ���
@ʱ�临�Ӷ�: O (len(s))
@s: �����ҵ��ַ���
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

char ss[1000000+maxn];

struct Node
{
    Node *next[maxn], *pre;
    int last;
    Node ()
    {
        memset (next, 0, sizeof (next));
        pre = 0, last = 0;
    }
};

Node *root;

void Init ()
{
    root = new Node;
}

void Insert (char *s)
{
    if (!s[0]) return;

    Node *p = root;
    for (int i = 0; s[i]; i++)
    {
        if (!p -> next[s[i]-'a'])
            p -> next[s[i]-'a'] = new Node;
        p = p -> next[s[i]-'a'];
    }
    p -> last++;
}

void Build ()
{
    queue <Node*> qu;
    for (int i = 0; i < maxn; i++)
        if (root -> next[i])
        {
            root -> next[i] -> pre = root;
            qu.push (root -> next[i]);
        }

    while (!qu.empty ())
    {
        Node *temp = qu.front (); qu.pop ();
        for (int i = 0; i < maxn; i++)
        {
            Node *pp = temp -> next[i];
            if (pp)
            {
                Node *par = temp -> pre;
                do
                {
                    if (par -> next[i])
                    {
                        pp -> pre = par -> next[i];
                        break;
                    }

                    else
                        par = par -> pre;
                } while (par);

                if (!par) pp -> pre = root;
                qu.push (pp);
            }
        }
    }
}

int Query (char *s)
{
    if (!s[0]) return 0;

    Node *p = root;
    int cnt = 0;
    for (int i = 0; s[i]; i++)
    {
        while (p != root && !p -> next[s[i]-'a'])
            p = p -> pre;
        p = p -> next[s[i]-'a'];
        if (!p) p = root;

        Node *pp = p;
        while (pp != root && pp -> last != -1)
        {
            cnt += pp -> last;
            pp -> last = -1;
            pp = pp -> pre;
        }
    }
    return cnt;
}

void DelTree (Node *s)
{
    if (!s) return ;
    for (int i = 0; i < maxn; i++)
    {
        if (s -> next[i])
            DelTree (s -> next[i]);
    }
    delete s;
}

int main()
{
//    freopen ("aaa.txt", "r", stdin);

    int t;
    scanf ("%d", &t);
    while (t--)
    {
        int n;
        scanf ("%d",&n);
        Init ();

        for (int i = 1; i <= n; i++)
        {
            scanf ("%s", ss);
            Insert (ss);
        }

        gets (ss);
        gets (ss);
        Build ();
        printf ("%d\n", Query (ss));
        DelTree (root);
    }
    return 0;
}
