/***********************************************
************************************************
@�ӿ�: string Add (string a,string b)
@ʱ�临�Ӷ�: O (n)
@:
************************************************/
string Add (string a,string b)//ֻ�������Ǹ��������
{
    string ans;
    int na[maxn]= {0}, nb[maxn] = {0};// maxn��ʾ���ӵ�����λ��

    int la = a.size (), lb = b.size ();

    for (int i = 0; i < la; i++)
        na[la-1-i] = a[i] - '0';

    for (int i = 0;i < lb; i++)
        nb[lb-1-i] = b[i] - '0';

    int lmax = la > lb ? la : lb;

    for (int i = 0; i < lmax; i++)
    {
        na[i] += nb[i];
        na[i+1] += na[i] / 10;
        na[i] %= 10;
    }

    if (na[lmax])
        lmax++;

    for (int i = lmax - 1; i >= 0; i--)
        ans += na[i] + '0';

return ans;
}
