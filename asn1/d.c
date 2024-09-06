// gcc -I /opt/homebrew/include -L/opt/homebrew/lib gmp.c -lgmp
#include <stdio.h>
#include <gmp.h>

int main(int argc, char *argv[])
{
    mpz_t crrNum;
    mpz_init_set_str (crrNum, argv[1], 10);
    mpz_t numOneBits;
    mpz_init_set_str (numOneBits, 0, 10);
    while(mpz_cmp_ui (crrNum, 0))
    {
        
    }


    return 0;
}


/*
int numberOfOneBitsInInteger(int input) {
      int numOneBits = 0;

      int currNum = input;
      while (currNum != 0) {
        if ((currNum & 1) == 1) {
          numOneBits++;
        }
        currNum = currNum >> 1;
      }
      return numOneBits;
    }

*/