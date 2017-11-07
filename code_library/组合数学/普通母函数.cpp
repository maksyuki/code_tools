/***********************************************
������ʽ�˷��е�ϵ��
************************************************
@�ӿ�: void GenerFunction (long long expnum, long long upp)
@����:
@ʱ�临�Ӷ�: O (n ^ 3)
@expnum: ���ʽ�ĸ���
@upp: ����ʽ��ָ�����ֵ
************************************************/

const int maxn = 100 + 66;//ע��maxnҪ���ڶ���ʽָ�������ֵ
const int step[] = {6666, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21
, 22, 23, 24, 25, 26};//ÿ�����ʽ�Ĳ���

//step������԰�����ĿҪ����Ԥ�ȶ���ã������ɳ�����룡����������

//coeff����洢ÿһָ��ֵ�µ�ϵ��ֵ��temp����洢��ǰ��������ʽ��˵�ϵ��ֵ��ans����洢��������ʽ�ĸ���
long long coeff[maxn], temp[maxn], ans[maxn];

//ans������԰�����Ŀ��Ҫ���Ǳ�ʾÿһ������ʽ�����ĸ������Ƿ��ɳ�����룬����
//ʹ����������s[maxn]��e[maxn]��ʾָ�������½�

void Init ()
{
    memset (coeff, 0, sizeof (coeff));
    memset (temp, 0, sizeof (temp));
}

//�ڵ���GenerFunction֮ǰһ���ȵ���Init����
void GenerFunction (long long expnum, long long upp)//����������±��1��ʼ
{
    for (long long i = 0; i <= ans[1] * step[1]; i += step[1]) //��ʼ����һ������ʽ��ϵ��ֵ
        coeff[i] = 1;

    for (long long i = 2; i <= expnum; i++)
    {
        for (long long j = 0; j <= upp; j++)
        {
            for (long long k = 0; j + k <= upp && k <= ans[i] * step[i]; k += step[i])
                temp[k+j] += coeff[j];//x ^ k * x ^ j = x ^ (k + j)��ϵ��ֵ
        }

        for (long long j = 0; j <= upp; j++)
        {
            coeff[j] = temp[j];
            temp[j] = 0;
        }
    }
}
