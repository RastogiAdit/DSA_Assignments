#include <stdio.h>

int main() {
    char a[1001];
    char b[1001];
    
    // Input two numbers as strings
    scanf("%s", a);
    scanf("%s", b);

    int x[1001] = {0};
    int y[1001] = {0};
    int result[2002] = {0}; 

    int len_a = 0;
    int len_b = 0;

    // Calculate length of a
    while (a[len_a] != '\0') {
        len_a++;
    }

    // Calculate length of b
    while (b[len_b] != '\0') {
        len_b++;
    }

    // Convert characters to integers and reverse the arrays
    for (int i = 0; i < len_a; i++) {
        x[i] = a[len_a - 1 - i] - '0';
    }

    for (int i = 0; i < len_b; i++) {
        y[i] = b[len_b - 1 - i] - '0';
    }

    // Perform multiplication
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            result[i + j] += x[i] * y[j];
        }
    }

    // Perform carry operations
    for (int i = 0; i < len_a + len_b - 1; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    // Find the first non-zero digit in the result
    int startPrinting = len_a + len_b - 1;
    while (startPrinting >= 0 && result[startPrinting] == 0) {
        startPrinting--;
    }

    // If the result is zero, print 0
    if (startPrinting < 0) {
        printf("0");
    } else {
        // Print the result
        for (int i = startPrinting; i >= 0; i--) {
            printf("%d", result[i]);
        }
    }

    return 0;
}
