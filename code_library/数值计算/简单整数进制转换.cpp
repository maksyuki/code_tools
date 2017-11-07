/***********************************************
求解M进制到N进制的一般精度转换(转换的数小于十进制
下的10^18)
************************************************
@接口: long long TransOld (char *val, int base)
@功能: 将M进制转换为10进制
@时间复杂度: O (n)
@val: 待转换的数
@base: 待转换的数制

@接口: string TransNew (long long val, int base)
@功能: 将10进制转换为N进制
@时间复杂度: O (n)
@val: 待转换数的值
@base: 目标进制
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
