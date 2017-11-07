bool Bin (long long vv)
{
    long long l = 0, r = len - 1, m;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (d[m] == vv)
            return true;

        if (d[m] < vv)
            l = m + 1;

        else
            r = m - 1;
    }

return false;
}

//һ�ֳ�����д��������
int l, r, mid;
while (l < r)
{
    mid = (l + r) >> 1;
    if (PP (mid)) l = mid + 1;
    else r = mid - 1;
}

//һ�ֳ�����д��������
double l, r, mid;
while (r - l > EPS)
{
    mid = (l + r) >> 1;
    if (PP (mid)) l = mid;
    else r = mid;
}


