#include <stdio.h>

int maxConsecutiveTroops(char *str, int n) {
    int maxLength = 1;
    int currentLength = 1;
    int lastPosition[26]; // Array to store the last position of each character

    for (int i = 0; i < 26; i++) {
        lastPosition[i] = -1; // Initialize last positions to -1
    }

    lastPosition[str[0] - 'a'] = 0; // Update the last position of the first character

    for (int i = 1; i < n; i++) {
        int prevIndex = lastPosition[str[i] - 'a'];

        // If the current character is not present in the current
        // substring or its last occurrence is before the current substring
        if (prevIndex == -1 || i - currentLength > prevIndex) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = i - prevIndex;
        }

        lastPosition[str[i] - 'a'] = i; // Update the last position of the current character
    }

    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}

int main() {
    int n;
    scanf("%d", &n);

    char str[100001]; // Assuming the maximum length is 100000
    scanf("%s", str);

    int result = maxConsecutiveTroops(str, n);

    printf("%d\n", result);

    return 0;
}