#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t n,m,ans;
    mpz_init(n);
    mpz_init(m);
    mpz_init(ans);
    gmp_scanf("%Zd",&n);
    gmp_scanf("%Zd",&m);
    
    //calculating multiplicative inverse 
    mpz_invert(ans,n,m);
    gmp_printf("%Zd",ans);

    // mpz_clear(n);
    // mpz_clear(m);
    // mpz_clear(inv_n);


    return 0;
}