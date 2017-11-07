/***********************************************
高精度求解第n个Catalan数
************************************************
@接口: string Catalan (long long val)
@时间复杂度: O (n)
@val:
************************************************/

const int maxn = 1000 + 666;

string Mul (string a, long long b)//高精度a乘单精度b
{
    string ans;
    long long na[maxn], La = a.size ();// maxn表示相乘结果的最大可能位数

    fill (na, na + maxn, 0);

    for (long long i = La - 1; i >= 0; i--)
        na[La-i-1] = a[i] - '0';

    long long w = 0;

    for (long long i = 0; i < La; i++)
    {
        na[i] = na[i] * b + w;
        w = na[i] / 10;
        na[i] = na[i] % 10;
    }

    while (w)
    {
        na[La++] = w % 10;
        w /= 10;
    }

    La--;

    while (La >= 0) ans += na[La--] + '0';

return ans;
}

string Div (string a, long long b)//高精度a除以单精度b
{
    string r;
    long long d = 0;

    if(a == "0")
        return a;//特判

    for (long long i = 0; i < a.size (); i++)
    {
        r += (d * 10 + a[i] - '0') / b + '0';//求出商
        d = (d * 10 + (a[i] - '0')) % b;//求出余数
    }

    long long p = 0;
    for (long long i = 0; i < r.size (); i++)
        if (r[i] != '0')
        {
            p = i;
            break;
        }

return r.substr (p);
}

string Catalan (long long val)
{
    string a("1");
    for (long long i = 1; i <= val; i++)
    {
        a = Mul (a, (4 * i - 2));
        a = Div (a, (i + 1));
    }

return a;
}
