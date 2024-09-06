#include <stdio.h>
#include <string.h>

long long int countSalaries(int n, int k, long long int l, long long int r, char* digits) {
    // Initialize the count of possible salaries
    long long int count = 0;
    
    // Generate all possible combinations of digits for the unknown positions
    for (long long int i = l; i <= r; i++) {
        char str[20];
        sprintf(str, "%lld", i);
        
        // Check if the sum of digits is equal to k and matches the known digits
        int sum = 0;
        int valid = 1;
        
        for (int j = 0; j < n; j++) {
            if (digits[j] == '?') {
                sum += str[j] - '0';
            } else if (digits[j] != str[j]) {
                valid = 0;
                break;
            }
        }
        
        if (valid && sum == k) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n, k;
    long long int l, r;
    
    // Read input values
    scanf("%d %d %lld %lld", &n, &k, &l, &r);
    
    char digits[20];
    
    // Read the string of digits
    scanf("%s", digits);
    
    // Find and print the number of different possible salaries
    printf("%lld\n", countSalaries(n, k, l, r, digits));
    
    return 0;
}