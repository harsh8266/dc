#include <stdio.h>

int knapsack(int num, float weight[], float profit[], int capacity)
{
    int tp = 0;
    for (int i = 0; i < num; i++)
    {
        if (weight[i] <= capacity)
        {
            capacity = capacity - weight[i];
            tp = tp + profit[i];
        }
        else
        {
            tp += (capacity / weight[i]) * profit[i];
            break;
        }
    }
    return tp;
}

int main()
{
    float weight[20], profit[20], capacity;
    int num;
    printf("Enter the number of items: ");
    scanf("%d", &num);

    float ratio[20];
    for (int i = 0; i < num; i++)
    {
        printf("Enter weight and profit of item %d: ", i);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter Capacity: ");
    scanf("%f", &capacity);

    // Sort in non-increasing order
    int temp;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                float tempRatio = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = tempRatio;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    int totalProfit = knapsack(num, weight, profit, capacity);
    printf("Total profit: %d\n", totalProfit);

    return 0;
}
