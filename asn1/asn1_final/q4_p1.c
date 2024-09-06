#include <stdio.h>
#include <gmp.h>


int countSetBits(mpz_t num)
{
    int count = 0;

    while(mpz_cmp_ui(num,0)>0)
    {
        if(mpz_tstbit(num,0) == 1)
        {
            count++;
        }
        mpz_div_ui(num,num,2);
    }
    return count;
}


int main()
{
    mpz_t num;
    mpz_init(num);
    gmp_scanf("%Zd",num);
    int result =  countSetBits(num);
    printf("%d\n", result);


    return 0;
}