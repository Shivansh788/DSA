#include <stdio.h>

// Function to perform the knapsack
void knapsack(int n, float weight[], float profit[], float capacity) {
    //initalizing variables 
    float x[20], total_profit = 0;
    int i, j, u;
    u = capacity; // Remaining capacity of the knapsack

    for (i = 0; i < n; i++)
        x[i] = 0.0; // Initialize result array element x to 0

    // Loop through all items
    for (i = 0; i < n; i++) {
        // If the item can fit into the remaining capacity
        if (weight[i] > u)
            break; // Stop if the item is too heavy to fit
        else {
            x[i] = 1.0; // Take the whole item
            total_profit = total_profit + profit[i]; // Add profit
            u = u - weight[i]; // Reduce remaining capacity
        }
    }

    // If there's still some capacity left, take fraction of the next item
    if (i < n)
        x[i] = u / weight[i];

    total_profit = total_profit + (x[i] * profit[i]); // Add profit of fractional item

    // Print the result
    printf("\nThe result is: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", x[i]);

    printf("\nMaximum profit is: %.2f\n", total_profit); // Print total profit
}

int main() {
    //initalizing arrays to [20]
    float weight[20], profit[20], capacity;
    //initailizing variables
    int num, i, j;
    //intializing variable of profit/wieght ratio and temprary variable for swaping
    float ratio[20], temp;

    // taking input number of objects
    printf("Enter the number of objects: ");
    scanf("%d", &num);

    // taking input weights and profits of each object
    printf("Enter the weights and profits of each object:\n");
    for (i = 0; i < num; i++) {
        printf("Weight[%d]: ", i);
        scanf("%f", &weight[i]);
        printf("Profit[%d]: ", i);
        scanf("%f", &profit[i]);
    }

    // taking input total the capacity of the knapsack box or bag
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Calculate profit/weight ratio for each object
    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sorting objects by profit/weight ratio in descending order
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity); // Call knapsack function
    return 0; // End of program
}

// OUTPUT
// Enter the number of objects: 5
// Enter the weights and profits of each object:
// Weight[0]: 4
// Profit[0]: 10
// Weight[1]: 5
// Profit[1]: 12
// Weight[2]: 6
// Profit[2]: 14
// Weight[3]: 7
// Profit[3]: 16
// Weight[4]: 8
// Profit[4]: 18
// Enter the capacity of the knapsack: 20

// The result is: 1.00 1.00 1.00 0.71 0.00
// Maximum profit is: 47.43