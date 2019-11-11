#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
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