void Sqrt (char *str)
{
    double i, r, n;
    int L, len, num, x[1000];
    len = strlen(str);
    if (len == 1 && str[0] == '0' )
    {
        printf("0\n");
        return;
    }

    if (len % 2 == 1)
    {
        n = str[0] - 48; L = -1;
    }

    else
    {
        n = (str[0] - 48) * 10 + str[1] - 48; L = 0;
    }

    r = 0; num = 0;

    while (1)
    {
        i = 0;
        while (i * (i + 20 * r) <= n) ++i;
        --i;

        n -= i * (i + 20 * r);
        r = r * 10 + i;
        x[num] = (int) i;
        ++num;
        L += 2;
        if (L >= len)
            break;

        n = n * 100 + (double) (str[L] - 48) * 10 + (double) (str[L+1] - 48);
    }

    for(int j = 0; j < num; j++) printf("%d", x[j]);
    printf("\n");
}
