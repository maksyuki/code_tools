

long long GetFactorSum (long long val)
{
    long long ans = 1, temp;
    for (long long i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            temp = 1;
            while (val % i == 0)
            {
                temp *= i;
                val /= i;
            }
        }

        ans *= (temp * i - 1) / (i - 1);
    }

    if (val > 1)
        ans *= (val + 1);

return ans;
}
