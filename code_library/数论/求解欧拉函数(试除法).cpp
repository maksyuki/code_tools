/***********************************************
���ŷ��������val����ֵ
************************************************
@�ӿ�: long long GetEuler (long long val)
@ʱ�临�Ӷ�: O (sqrt (n))
@val: ����˵��
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
