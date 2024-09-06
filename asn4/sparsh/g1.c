#include <stdio.h>
#include <string.h>

char lcm[1000001];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


char* findLCM(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    int lcmLen = (lenA * lenB) / gcd(lenA, lenB);
    
    // Construct the LCM string by repeating both strings alternately
    for (int i = 0; i < lcmLen; i++) {
        lcm[i] = a[i % lenA];
        if (lcm[i] != b[i % lenB]) {
            //free(lcm);
            return "-1";
        }
    }
    
    lcm[lcmLen] = '\0';
    
    return lcm;
}

int main() {
    char a[1000001], b[1000001];
    
    // Read input strings
    scanf("%s", a);
    scanf("%s", b);
    
    // Find and print the LCM of the strings
    printf("%s\n", findLCM(a, b));
    
    return 0;
}