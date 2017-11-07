/***********************************************
�������expnum��ֵĸ���
************************************************
@�ӿ�: void GenerFunction (long long expnum, long long val)
@ʱ�临�Ӷ�: o (n ^ 3)
@val: ����ֵ���
@expnum: ����ʽ�ĸ���
************************************************/

const int maxn = 100 + 66;//maxnҪ���ڴ������

int coeff[maxn], temp[maxn];//coeff����洢����ʽ�����ݵ�ϵ����temp����洢��ǰ��������ʽ��˵���ʱ���

void Init ()
{
    memset (coeff, 0, sizeof (coeff));
    memset (temp, 0, sizeof (temp));
}

void GenerFunction (long long expnum, long long val)//�ڵ���GenerFunction֮ǰһ���ȵ���Init����
{
    for (long long i = 0; i <= val * 1; i += 1)
        coeff[i] = 1;

    for (long long i = 2; i <= expnum; i++)
    {
        for (long long j = 0; j <= val; j++)
        {
            for (long long k = 0; k + j <= val; k += i)
                temp[k+j] += coeff[j];
        }

        for (long long j = 0; j <= val; j++)
        {
            coeff[j] = temp[j];
            temp[j] = 0;
        }
    }
}
