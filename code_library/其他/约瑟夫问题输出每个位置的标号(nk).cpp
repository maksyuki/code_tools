long long val, p = 0;
bool is_first = true;

    while (++p <= n)
    {
        val = p * k;
        while (val > n)
            val = val - n + (val - n - 1) / (k - 1);

        if (is_first)
        {
            is_first = false;
            printf ("%lld\n", val);
        }

        else
            printf (" %lld\n", val);
    }
    puts ("");
