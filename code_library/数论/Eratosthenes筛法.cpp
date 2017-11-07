/***********************************************
ɸѡ��������
************************************************
@�ӿ�: void GetPrime ()
@����: ɸѡ��������
@ʱ�临�Ӷ�: O (nloglog (n))
************************************************/

//���������жϱ��������
bool prime[maxn+10];
long long primelist[maxn+10], prime_len;

//Eratosthenesɸ��
void GetPrime ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    for (long long i = 2; i <= maxn; i++)
        if (prime[i])
        {
            primelist[prime_len++] = i;
            for (long long j = 2; j * i <= maxn; j++)
                prime[j*i] = false;
        }
}
