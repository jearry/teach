#include <stdio.h>

int main()
{
    int a = 1;
    int b = 1;

    while (a <= 9){
        b = 1;
        while (b <= a){
            printf("%d * %d = %d  ", b, a, a*b);
            b++;
        }

        printf("\n");
        a++;
    }

    return 0;
}