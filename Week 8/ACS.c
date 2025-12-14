#include <stdio.h>

void sortArrays(int start[], int finish[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (finish[j] < finish[min])
                min = j;
        }

        temp = finish[i];
        finish[i] = finish[min];
        finish[min] = temp;

        temp = start[i];
        start[i] = start[min];
        start[min] = temp;
    }
}

int activitySelection(int start[], int finish[], int n)
{
    int count = 1;
    int lastFinish;
    int i;

    sortArrays(start, finish, n);

    lastFinish = finish[0];

    for (i = 1; i < n; i++)
    {
        if (start[i] > lastFinish)
        {
            count++;
            lastFinish = finish[i];
        }
    }

    return count;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    int result = activitySelection(start, finish, n);

    printf("Maximum number of activities: %d", result);

    return 0;
}
