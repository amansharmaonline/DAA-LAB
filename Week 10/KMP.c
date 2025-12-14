#include <stdio.h>
#include <string.h>

void computepi(char pat[], int m, int lps[])
{
    int len = 0;
    lps[0] = 0;

    for (int i = 1; i < m; i++)
    {
        while (len > 0 && pat[i] != pat[len])
        {
            len = lps[len - 1];
        }

        if (pat[i] == pat[len])
        {
            len++;
        }

        lps[i] = len;
    }
}

int main() {
    char text[1000];
    char pat[1000];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pat);

    int n = strlen(text);
    int m = strlen(pat);

    int lps[m];
    
    computepi(pat, m, lps);

    int i = 0; // text index
    int j = 0; // pattern index
    int found = 0;

    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("Match at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }

        else if (i < n && text[i] != pat[j])
        {
          
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (!found)
    {
        printf("No match found\n");
    }

    return 0;
}
