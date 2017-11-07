long long GetFactorNum (long long val)
{
    long long tot = 1;
    for (long long i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            long long temp = 0;
            do
            {
                val /= i;
                temp++;
            } while (val % i == 0);

            tot = tot * (temp + 1);
        }
    }

    if (val > 1)
        tot *= 2;

return tot;
}
