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
const int MOD = 7;

const int maxn = 50000 + 66;

bool prime[maxn*20];
long long primelist[maxn+10], prime_len;
long long primelist2[maxn*20], prime_len2;

void GetPrime ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    for (long long i = 2; i <= maxn; i++)
    {
        if (prime[i])
            primelist[prime_len++] = i;

        for (long long j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            if (i % primelist[j] == 0)
                break;
        }
    }
}


void Solve (long long a, long long b)
{
    memset (prime, true, sizeof (prime));
    for (long long i = 0; i < prime_len; i++)
    {
        long long temp = a / primelist[i];

        while (temp * primelist[i] < a || temp <= 1)
            temp++;

        for (long long j = temp * primelist[i]; j <= b; j += primelist[i])
        {
            if (j >= a)
                prime[j-a] = false;
        }
    }

    if (a == 1)
        prime[0] = false;

    prime_len2 = 0;
    for (long long i = a; i <= b; i++)
    {
        if (prime[i-a])
            primelist2[prime_len2++] = i;
    }
}


int main()
{
    GetPrime ();

//    freopen ("aaa.txt", "r", stdin);

    long long a, b;
    while (scanf ("%lld%lld", &a, &b) != EOF)
    {
        Solve (a, b);

        if (prime_len2 < 2)
            printf ("There are no adjacent primes.\n");

        else
        {
            long long minval = INF, maxval = -INF, minval_a = -1, minval_b = -1, maxval_a = -1;
            long long maxval_b = -1;

            for (long long i = 1; i < prime_len2; i++)
            {
                if (minval > primelist2[i] - primelist2[i-1])
                {
                    minval = primelist2[i] - primelist2[i-1];
                    minval_a = primelist2[i-1], minval_b = primelist2[i];
                }

                if (maxval < primelist2[i] - primelist2[i-1])
                {
                    maxval = primelist2[i] - primelist2[i-1];
                    maxval_a = primelist2[i-1], maxval_b = primelist2[i];
                }
            }

            printf ("%lld,%lld are closest, %lld,%lld are most distant.\n", minval_a, minval_b
                    , maxval_a, maxval_b);
        }
    }

return 0;
}
