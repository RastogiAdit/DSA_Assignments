#include <stdio.h>
#include <stdlib.h>

#define max(x, y) (((x) > (y)) ? (x) : (y)) 
#define min(x, y) (((x) < (y)) ? (x) : (y)) 

int kira(int *price, int start, int end) 
{ 
    if (end <= start) 
        return 0; 

    int profit = 0; 
  
    for (int i = start; i < end; i++) { 

        for (int j = i + 1; j <= end; j++) { 
  
            if (price[j] > price[i]) { 
  
                int curr_profit 
                    = price[j] - price[i] 
                      + kira(price, start, i - 1) 
                      + kira(price, j + 1, end); 

                profit = max(profit, curr_profit); 
            } 
        } 
    } 
    return profit; 
} 

int main()
{
    int n;
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));

    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }



    printf("%d", kira(arr, 0, n - 1)); 


    free(arr);

    return 0;
}