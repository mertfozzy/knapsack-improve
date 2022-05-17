#include <bits/stdc++.h>
using namespace std;
 
int knapSack(int W, int weights[], int values[], int n)
{
    int i, w;
    int K[2][W + 1];
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i % 2][w] = 0;
            else if (weights[i - 1] <= w)
                K[i % 2][w] = max(
                    values[i - 1]
                        + K[(i - 1) % 2][w - weights[i - 1]],
                    K[(i - 1) % 2][w]);
            else
                K[i % 2][w] = K[(i - 1) % 2][w];
        }
    }
    return K[n % 2][W];
}


int main(){
    printf("\n=== WELCOME TO THE KNAPSACK SOLVER ===\n\n");

    //constructing value table :
    int i, count, W;
    
    printf("How many values you have ? : \t");
    scanf("%d", &count);
    
    int values[count];

    for (i = 0; i < count; i++)
    {
        printf("Enter value %d : ", i+1);
        scanf("%d", &values[i]);
    }

    printf("Your values are : ");
    for (i = 0; i < count; i++)
    {
       printf("%d ", values[i]);
    }
    
    //constructing the weights table :

    int j, count2;
    
    printf("\n\nHow many weights you have ? : \t");
    scanf("%d", &count2);
    
    int weights[count2];

    for (j = 0; j < count2; j++)
    {
        printf("Enter weights %d : ", j+1);
        scanf("%d", &weights[j]);
    }

    printf("Your weights are : ");
    for (j = 0; j < count2; j++)
    {
       printf("%d ", weights[j]);
    }

    //Knapsack Capacity :
    printf("\n\nWhat is your Knapsack Capacity (W) ? : \t");
    scanf("%d", &W);

    //driver code :
    int n = sizeof(values) / sizeof(values[0]);
    printf ("\n\nKnapsack Solution is Calculated : %d\n\n", knapSack(W, weights, values, n));
    //cout << knapSack(W, weights, values, n);
    return 0;

}

