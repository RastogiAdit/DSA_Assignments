#include <stdio.h>
#include <gmp.h>

int countSetBits(mpz_t num) {
    int count = 0;

    while (mpz_cmp_ui(num, 0) > 0) {
        if (mpz_tstbit(num, 0) == 1) {
            count++;
        }
        mpz_div_ui(num, num, 2);
    }

    return count;
}

int main() {
    // Set the precision to the maximum value
    // mp_bitcnt_t precision = 1010000 * 8;
    // mpf_set_default_prec(precision);

    // Input
    mpz_t num;
    mpz_init(num);

    gmp_scanf("%Zd", num);

    // Count set bits (number of 1s) in binary representation
    int result = countSetBits(num);

    // Output
    printf("%d\n", result);

    // Free allocated memory
    // mpz_clear(num);

    return 0;
}