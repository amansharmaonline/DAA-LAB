#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int dp[101][101];
    int m, n, i, j;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    m = strlen(s1);
    n = strlen(s2);

    // Step 1: initialize first row and column to 0
    for (i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Step 2: fill dp table (same as before)
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {

            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];  // characters match
            }
            else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];     // choose top
                } else {
                    dp[i][j] = dp[i][j-1];     // choose left
                }
            }
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    // Step 3: find the actual LCS by backtracking
    int index = dp[m][n];      // length of LCS
    char lcs[101];
    lcs[index] = '\0';         // null terminate

    i = m;
    j = n;

    // Start from dp[m][n] and move backwards
    while (i > 0 && j > 0) {

        // If characters match, they are part of the LCS
        if (s1[i-1] == s2[j-1]) {
            lcs[index - 1] = s1[i - 1]; // put character into LCS
            i--;
            j--;
            index--;
        }
        else {
            // Move in direction of larger dp value
            if (dp[i-1][j] > dp[i][j-1]) {
                i--;    // move up
            } else {
                j--;    // move left
            }
        }
    }

    printf("LCS = %s\n", lcs);

    return 0;
}
