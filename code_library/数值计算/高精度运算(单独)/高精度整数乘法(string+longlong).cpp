/***********************************************
************************************************
@�ӿ�: string Mul (string a, long long b)
@ʱ�临�Ӷ�: O(n)
@:
************************************************/

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

    while (La >= 0)
        ans += na[La--] + '0';

return ans;
}
