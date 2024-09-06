//gcc -I /opt/homebrew/include -L/opt/homebrew/lib gmp.c -lgmp
    // printf("%s\n",mpz_get_str(a, stdin, 10));
    // printf("%s\n",mpz_get_str(b, stdin, 10));

#include <stdio.h>
#include <gmp.h>

int main(int argc, char *argv[])
{
  mpz_t a, b;                 		/* working numbers */
  if (argc<3)
    {					/* not enough words */
    printf("Please supply two numbers to add.\n");
    return 1;
  }
  mpz_init_set_str (a, argv[1], 10);	/* Assume decimal integers */
  mpz_init_set_str (b, argv[2], 10);	/* Assume decimal integers */
  mpz_mul (a, a, b);			/* a=a+b */

  printf("%s \n",mpz_get_str (NULL, 10, a));
  return 0;
}