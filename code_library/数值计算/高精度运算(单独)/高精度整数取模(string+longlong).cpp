/***********************************************
************************************************
@接口: long long Mod (string a, long long b)
@时间复杂度:O (n)
@:
************************************************/

long long Mod (string a, long long b)//高精度a除以单精度b
{
    long long d = 0;
    for (long long i = 0; i < a.size(); i++) d = (d * 10 + (a[i] - '0')) % b;//求出余数

return d;
}
