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

void show_graphic()
{
    printf("please input a integer:\n");

    int n;
    scanf("%d", &n);

    for (int i=1; i<n; i++){
        for (int j=1; j<n-1; j++){
            printf(" ");
        }
        for (int j=1; j<i; j++){
            printf("*");
        }

        printf("\n");
    }
}

int main()
{
    printf("welcom to use xxxx system\n");
    printf("  1. 9x9\n");
    printf("  2. guess\n");
    printf("  3. add\n");
    printf("  4. show graphic\n");

    printf("please input your choise:[ ]\b\b");

    int select;
    scanf("%d", &select);

    switch (select){
    case 1:
        func_9x9();
        break;
    case 2:
        func_guess();
        break;
    case 3:
        {
            int s = add(100, 200);

            printf("sum:%d", s);    
        }
        break;
    case 4:
        show_graphic();
        break;
    case 5:
        break;

    }
    
    return 0;
}