#include <stdio.h>
#include <string.h>

void modifyString(char s[])
{
    int freq[256] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++)
        freq[(unsigned char)s[i]]++;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (freq[(unsigned char)s[i]] != 0)
        {
            printf("%c%d ", s[i], freq[(unsigned char)s[i]]);
            freq[(unsigned char)s[i]] = 0;
        }
    }
}

int main()
{
    char s[] = "ABRAKADABRA";

    modifyString(s);

    return 0;
}
