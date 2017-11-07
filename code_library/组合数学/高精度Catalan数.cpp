/***********************************************
�߾�������n��Catalan��
************************************************
@�ӿ�: string Catalan (long long val)
@ʱ�临�Ӷ�: O (n)
@val:
************************************************/

const int maxn = 1000 + 666;

string Mul (string a, long long b)//�߾���a�˵�����b
{
    string ans;
    long long na[maxn], La = a.size ();// maxn��ʾ��˽����������λ��

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

string Div (string a, long long b)//�߾���a���Ե�����b
{
    string r;
    long long d = 0;

    if(a == "0")
        return a;//����

    for (long long i = 0; i < a.size (); i++)
    {
        r += (d * 10 + a[i] - '0') / b + '0';//�����
        d = (d * 10 + (a[i] - '0')) % b;//�������
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
