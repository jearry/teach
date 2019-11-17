#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void func_9x9()
{
    for (int a=1; a<=9; a++){

        for (int b=1; b<=a; b++){
            printf("%d * %d = %d  ", b, a, a*b);
        }
        printf("\n");
    }
}

int func_guess()
{
    int v;
    srand(time(NULL));

    v = rand() % 1000;
    
    //printf("my secret:%d\n", v);

    while(1) {
        int input;
        printf("please input an interger:\n");
        scanf("%d", &input);

        if (input == v){
            printf("congratulations\n");
            break;
        }else if (input < v){
            printf("too small\n");
        }else if (input > v){
            printf("too big\n");
        }
    }
    
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    printf("welcom to use xxxx system\n");
    printf("  1. 9x9\n");
    printf("  2. guess\n");
    printf("  3. add\n");

    printf("please input your choise:[ ]\b\b");

    int select;
    scanf("%d", &select);

    if (select == 1){
        func_9x9();
    }else if (select == 2){
        func_guess();
    }else if (select == 3){
        int s = add(100, 200);

        printf("sum:%d", s);    
    }
    
    return 0;
}