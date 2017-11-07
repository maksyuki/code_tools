/***********************************************
求解由小写字母组成的字符串s在字典中的序号(字符串a为1)
************************************************
@接口: long long GetPerNumber (string s)
@时间复杂度:O (n)
@s:
************************************************/
const int maxn = 666;

long long C[maxn][maxn];

void GetCom (long long val)
{
    memset (C, 0, sizeof (C));
    for (long long i = 0; i <= val; i++)
    {
        for (long long j = 0; j <= i; j++)
        {
            if (!j || i == j)
                C[i][j] = 1;

            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    C[0][0] = 0;
}


long long GetPerNumber (string s)
{
    long long res = 0;  //s的值，初始为0

		/*计算长度比s小的字符串个数*/

    for (long long i = 1; i < s.size (); i++)
			res += C[26][i];  //C[26][i]表示 长度为i的字符串的个数

		/*计算长度等于len，但值比s小的字符串个数*/

    for (long long i = 0; i < s.size (); i++)  //i为s的指针，对每一个位置枚举 允许选择的字符ch
    {
        char ch = (!i) ? 'a' : s[i-1] + 1;   //ch = s[i-1]+1 根据升序规则，当前位置的ch至少要比s前一位置的字符大1
        while (ch <= s[i] - 1)   //ch<=s[i]-1 根据升序规则，当前位置的ch最多只能比 s这个位置实际上的字符 小1
        {
            res += C['z'-ch][s.size ()-1-i];  //'z'-ch ： 小于等于ch的字符不允许再被选择，所以当前能够选择的字符总数为'z'-ch
				ch++;                     //len-1-i  ： ch位置后面（不包括ch）剩下的位数，就是从'z'-ch选择len-1-i个字符
        }
    }

return res + 1;
// 此前的操作都是寻找比s小的所有字符串的个数，并不包括s本身，因此这里要+1
}
