/***********************************************
************************************************
@接口: string Sub (string a, string b)
@功能:
@时间复杂度: O (n)
@:
************************************************/

string Sub (string a, string b)//适用于两个非负整数的相减
{
    bool is_neg = false;//表示结果的正负
    if ((a.size () < b.size ()) || (a.size () == b.size () && a < b))
    {
        is_neg = true;
        swap (a, b);
    }

    string ans;
    int na[maxn] = {0}, nb[maxn] = {0};// maxn表示两个相减的数的位数

    int la = a.size (), lb = b.size ();

    for (int i = 0; i < la; i++)
        na[la-1-i] = a[i] - '0';

    for (int i = 0; i < lb; i++)
        nb[lb-1-i] = b[i] - '0';

    int lmax = la > lb ? la : lb;

    for (int i = 0; i < lmax; i++)
    {
        na[i] -= nb[i];
        if (na[i] < 0)
        {
            na[i] += 10;
            na[i+1]--;
        }
    }

    while (!na[--lmax] && lmax > 0) ;

    lmax++;

    if (is_neg)
        ans += "-";

    for (int i = lmax - 1; i >= 0; i--)
        ans += na[i] + '0';

return ans;
}
