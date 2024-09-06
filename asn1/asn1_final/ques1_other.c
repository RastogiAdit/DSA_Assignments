#include <stdio.h>
#include <string.h>

void multiply(char *num1, char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char product[len1 + len2 + 1];
    for (int i = 0; i <= len1 + len2; i++) {
        product[i] = '0';
    }
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = (product[i + j + 1] - '0') + mul;

            product[i + j + 1] = (sum % 10) + '0';
            product[i + j] += sum / 10;
        }
    }
    int index = 0;
    while (index < len1 + len2 && product[index] == '0') {
        index++;
    }

    if (index == len1 + len2) {
        result[0] = '0';
        result[1] = '\0';
    } else {

        for (int i = 0; i < len1 + len2 - index; i++) {
            result[i] = product[index + i];
        }
        result[len1 + len2 - index] = '\0';
    }
}

int main() {
    char num1[1001];
    char num2[1001];
    char result[2002]; 
    scanf("%s", num1);
    scanf("%s", num2);
    multiply(num1, num2, result);
    printf("%s\n", result);
    return 0;
}
