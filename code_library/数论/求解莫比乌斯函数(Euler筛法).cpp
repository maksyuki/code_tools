/***********************************************
���Ī����˹������1 ~ maxn�ϵĺ���ֵ
************************************************
@�ӿ�: void GetMobi ()
@����:
@ʱ�临�Ӷ�: O (n)
@:
************************************************/

//���������жϱ��������Ī����˹����
bool prime[maxn+10];
long long primelist[maxn+10], prime_len, mu[maxn+10];

void GetMobi ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    mu[1] = 1;
    for (long long i = 2; i <= maxn; i++)
    {
        if (prime[i])
        {
            primelist[prime_len++] = i;
            mu[i] = -1;
        }

        for (long long j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            if (i % primelist[j] == 0)
            {
                mu[i*primelist[j]] = 0;
                break;
            }

            else
                mu[i*primelist[j]] = -mu[i];
        }
    }
}
