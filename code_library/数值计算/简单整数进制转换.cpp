/***********************************************
���M���Ƶ�N���Ƶ�һ�㾫��ת��(ת������С��ʮ����
�µ�10^18)
************************************************
@�ӿ�: long long TransOld (char *val, int base)
@����: ��M����ת��Ϊ10����
@ʱ�临�Ӷ�: O (n)
@val: ��ת������
@base: ��ת��������

@�ӿ�: string TransNew (long long val, int base)
@����: ��10����ת��ΪN����
@ʱ�临�Ӷ�: O (n)
@val: ��ת������ֵ
@base: Ŀ�����
************************************************/

long long TransOld (char *val, int base)
{
	long long sum = 0, wei = 1, len = strlen (val);
	for (long long i = len - 1; i >= 0; i--)
	{
		if (val[i] >= 'A' && val[i] <= 'Z')
			sum += (val[i] - 'A' + 10) * wei;

		else
			sum += (val[i] - '0') * wei;

		wei *= base;
	}

return sum;
}

string TransNew (long long val, int base)
{
    string ans;
    long long temp;
    do
    {
        temp = val % base;
        if (temp > 9)
            ans += (temp - 10 + 'A');

        else
            ans += temp + '0';

        val /= base;
    } while (val);

    reverse (ans.begin (), ans.end ());

return ans;
}
