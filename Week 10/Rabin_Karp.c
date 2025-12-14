#include <stdio.h>
#include <string.h>

#define d 256
#define q 13

int main()
{
    char text[100];
    char pat[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search: ");
    scanf("%s", pat);

    int n = strlen(text);
    int m = strlen(pat);

    int p = 0, t = 0, h = 1;
    
    // compute hash function
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // pattern, block 1
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // iterate blocks
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int match = 1;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                  match = 0;
            }
            if (match)
                printf("Match at index %d\n", i);
        }

        if (i < n - m) 
        {
            t = (d * (t - text[i] * h)  + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }

    return 0;
}
