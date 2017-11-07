
//注意：dp数组只计算一遍！！！即只在程序的开始初始化一次dp数组
LL dp[maxn][STATE_NUMBER], bit[maxn];

LL SS (int pos, int st, bool flag)
{
	if (pos == 0) return st == TARGET_STATE;
	if (flag && dp[pos][st] != -1) return dp[pos][st];

	LL res = 0;
	int x = flag ? 9 : bit[pos];
	for (int i = 0; i <= x; i++)
	{
		if (CONDITION_1) res += SS (pos - 1, STATE_1, flag || i < x);
		else if (CONDITION_2) res += SS (pos - 1, STATE_2, flag || i < x);	
		else if ...
		else res += SS (pos - 1, STATE_n, flag || i < x);
	}

	return flag? dp[pos][st] = res : res;
}

//计算[0, val]范围内的所有满足条件的数
LL Calc (LL val)
{
	int len = 0;
	while (val)
	{
		bit[++len] = val % 10;
		val /= 10;
	}
    return SS (len, 0, 0); 
}
