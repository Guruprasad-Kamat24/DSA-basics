
#include <stdio.h>

#include <time.h>
int main()
{
    // Calculate the time taken by fun()
    clock_t t;
    t = clock();
    int a=2,b=3,c;
    c=pow(a,b);
    printf("Ans:%d\n",c);
    t = clock() - t;
    double long time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("Code took %f seconds to execute \n", time_taken);
    return 0;
}
