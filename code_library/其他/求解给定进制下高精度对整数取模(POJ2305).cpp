/**************************************************
filename       :a.cpp
author         :maksyuki
created time   :2017/2/5 17:33:09
last modified  :2017/2/6 15:46:15
file location  :/home/maksyuki/Desktop/TheEternalPoet
***************************************************/

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

#define CFF freopen ("in", "r", stdin)
#define CPPFF ifstream cin ("in")
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

char p[1000+66], m[1000+66];
long long mt, tmp, pt; 
int ans[1000+66];

int main()
{
    //CFF;
    //CPPFF;
    int b;    
    while(scanf("%d", &b) && b)
    {
        scanf("%s%s", p, m);
         
        mt = 0;
        tmp = 1;
        int len = strlen(m);
        for(int i = len - 1; i >= 0; i--)
        {
            mt += tmp * (m[i] - '0');
            tmp *= b;
        }
        
        pt = 0;
        tmp = 1;
        len = strlen(p);
        for(int i = len - 1; i >= 0; i--)
        {
            pt += tmp * (p[i] - '0');
            pt %= mt;
            tmp *= b;
            tmp %= mt;
        }
        len = 0;
        while(pt)
        {
           ans[len++] = pt % b;
           pt /= b;
        }
        
        if(len == 0)
            puts("0");
        else
        {
            for(int i = len - 1; i >= 0; i--)
                printf("%d", ans[i]);
            puts("");
        }
    }
    return 0;
}
