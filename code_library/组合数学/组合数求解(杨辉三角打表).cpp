/***********************************************
���õ��ƹ�ϵ���Com (val, 0)��Com (val, val)����
ֵ���洢������com[maxn][maxn]��
************************************************
@�ӿ�: void getCom (long long val)
@ʱ�临�Ӷ�: O (n ^ 2)
@val:
************************************************/

const int maxn = 666;
long long com[maxn][maxn];

void getCom (long long val)
{
    memset (com, 0, sizeof (com));
    for (long long i = 0; i <= val; i++)
        for (long long j = 0; j <= i; j++)
        {
            if (!j || i == j) com[i][j] = 1;
            else com[i][j] = com[i-1][j-1] + com[i-1][j];
        }
    com[0][0] = 0;
}
