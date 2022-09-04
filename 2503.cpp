#include <stdio.h>

int main()
{
    int bbc, ssc, cnt, n, i, j, S[105], B[105], Q[105];
    int a, b, c, aa, bb, cc, result = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &Q[i], &S[i], &B[i]);
    }
    for (i = 100; i <= 999; i++)
    {
        a = i / 100;
        b = i % 100 / 10;
        c = i % 10;
        if (a == b || b == c || a == c || b == 0 || c == 0)
            continue;

        cnt = 0;
        for (j = 0; j < n; j++)
        {
            ssc = 0;
            bbc = 0;

            aa = Q[j] / 100;
            bb = Q[j] % 100 / 10;
            cc = Q[j] % 10;

            if (a == aa)
                ssc++;
            if (b == bb)
                ssc++;
            if (c == cc)
                ssc++;
            if (a == bb || a == cc)
                bbc++;
            if (b == aa || b == cc)
                bbc++;
            if (c == aa || c == bb)
                bbc++;

            if (S[j] == ssc && B[j] == bbc)
                cnt++;
        }

        if (cnt == n)
            result++;
    }
    printf("%d", result);
}