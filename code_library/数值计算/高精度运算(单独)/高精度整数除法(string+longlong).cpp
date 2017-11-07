/***********************************************
************************************************
@接口: string Div (string a, long long b)
@功能:
@时间复杂度: O (n)
@:
************************************************/

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
