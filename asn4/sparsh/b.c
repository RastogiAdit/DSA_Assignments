#include <stdio.h>


int minBeauty(int weights[], int n, int k, int currDistribution[], int currIndex) 
{
    //base case
    if (currIndex == n) 
    {
        int maxWeight = 0;
        for (int i = 0; i < k; i++) {
            if (currDistribution[i] > maxWeight) {
                maxWeight = currDistribution[i];
            }
        }
        return maxWeight;
    }

    //assigning max value to minBeautyVal
    int minBeautyVal = 1e6; 

    for (int i = 0; i < k; i++) 
    {
        currDistribution[i] += weights[currIndex]; //assigning packets to people

        int beautyVal = minBeauty(weights, n, k, currDistribution, currIndex + 1);
        
        if(minBeautyVal > beautyVal)
        {
            minBeautyVal = beautyVal;
        }

        currDistribution[i] -= weights[currIndex];
    }

    return minBeautyVal;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int weights[n];
    int currDistribution[n];

    for (int i = 0; i < n; i++) {scanf("%d", &weights[i]);}

    //initialize currDistribution array to 0
    for(int i = 0; i<n ;i++){currDistribution[i] = 0;}

    int result = minBeauty(weights, n, k, currDistribution, 0);

    printf("%d\n", result);

    return 0;
}
