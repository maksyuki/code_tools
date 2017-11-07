/***********************************************
求解1~mod % mod的逆元
************************************************
@接口:
@功能:
@时间复杂度:
@:
************************************************/

long long inv[maxn];

void Get (long long mod)
{
    inv[1] = 1;
    for (long long i = 2; i < maxn; i++)
    {
        if (i >= mod)
            break;

        inv[i] = (mod - mod / i) * inv[mod%i] % mod;
    }
}
