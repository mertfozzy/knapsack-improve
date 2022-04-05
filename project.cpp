#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int weights[], int values[], int n)
{
    //base case
    if (n == 0 || W == 0)
        return 0;

    //if nth item's weight is more than knapsack capacity (W), not optimal solution
    if (weights[n - 1] > W)
        return knapSack(W, weights, values, n - 1);
  
    else
        return max(
            values[n - 1]
                + knapSack(W - weights[n - 1], 
                           weights, values, n - 1),
            knapSack(W, weights, values, n - 1));
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

