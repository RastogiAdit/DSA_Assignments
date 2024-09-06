#include <stdio.h>
#include <gmp.h>

int main() {
    // Set the precision to the maximum value
    // mp_bitcnt_t precision = 10100000 * 8;
    // mpf_set_default_prec(precision);

    // Input
    mpz_t num1, num2, result;
    mpz_init(num1);
    mpz_init(num2);
    mpz_init(result);

    gmp_scanf("%Zd", num1);
    gmp_scanf("%Zd", num2);

    // Multiply the numbers
    mpz_mul(result, num1, num2);

    // Output
    gmp_printf("%Zd\n", result);

    // Free allocated memory
    mpz_clear(num1);
    mpz_clear(num2);
    mpz_clear(result);

    return 0;
}