// File Name: CTC17147.c
//==================================
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int g;
    scanf("%d", &g);
    int p;
    scanf("%d", &p);

    int group[g];
    int plane[p];

    for (int i = 0; i < g; i++)
    {
        scanf("%d", &group[i]);
    }

    for (int i = 0; i < p; i++)
    {
        scanf("%d", &plane[i]);
    }

    // Arranging people
    int temp;
    for (int i = 0; i <= g; i++)
    {
        for (int j = 0; j < g - 1; j++)
        {
            if (group[j] > group[j + 1])
            {
                temp = group[j + 1];
                group[j + 1] = group[j];
                group[j] = temp;
            }
        }
    }

    // Arranging plane

    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j < p - 1; j++)
        {
            if (plane[j] > plane[j + 1])
            {
                temp = plane[j + 1];
                plane[j + 1] = plane[j];
                plane[j] = temp;
            }
        }
    }
    

    if (group[g - 1] > plane[p - 1])
    {
        printf("-1\n");
        return 0;
    }

    int k = 0;
    int count = 0;
    int j = 0;

    for (int i = 0; i < g; i++)
    {

        if (j == p)
        {
            count++;
            j = k;
        }

        if (group[i] <= plane[j])
        {
            j++;
        }

        else
        {
            while (group[i] > plane[j])
            {
                j++;
            }

            k = j;
            j++;
        }
    }

    printf("%d", 2 * count + 1);

    return 0;
}
