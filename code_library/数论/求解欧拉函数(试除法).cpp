/***********************************************
求解欧拉函数在val处的值
************************************************
@接口: long long GetEuler (long long val)
@时间复杂度: O (sqrt (n))
@val: 由上说明
************************************************/

long long GetEuler (long long val)
{
    long long ans = val;
    for (long long i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            ans -= ans / i;
            while (val % i == 0)
            {
                val /= i;
            }
        }
    }

    if (val > 1)
        ans -= ans / val;

return ans;
}
