
#include <stdio.h>
#include <stdlib.h>

#include "platform.h"
#include "plan_game.h"

void ball()
{
    int i,j;
    int x = 0;
    int y = 5;

    int v_x = 1;
    int v_y = 1;

    int left = 0;
    int right = 40;
    int top = 0;
    int bottom = 20;

    while (1){
        x = x + v_x;
        y = y + v_y;

        clrsrc();
        // 输出小球前的空行
        for(i=0;i<x;i++)
            printf("\n");
        for (j=0;j<y;j++)
            printf(" ");
        printf("o");  // 输出小球o
        printf("\n");

        if ((x==top)||(x==bottom))
            v_x = -v_x;
        if ((y==left)||(y==right))
            v_y = -v_y;

        Sleep(100);
    }
}

void plane()
{
    int i,j;
    int x = 5;
    int y = 10;
    char input;
    int isFire = 0;

    int ny = 5; // 一个靶子，放在第一行，ny列上
    int isKilled = 0;

    while (1) {
        clrsrc();   // 清屏函数

        if (!isKilled){  // 输出靶子

            for (j=0;j<ny;j++)
                printf(" ");
            printf("+\n");
        }

        if (isFire==0) {// 输出飞机上面的空行

            for(i=0;i<x;i++)
                printf("\n");
        } else {   // 输出飞机上面的激光竖线

            for(i=0;i<x;i++) {
                for (j=0;j<y;j++)
                    printf(" ");
                printf("  |\n");
            }

            if (y+2==ny)  // +2是因为激光在飞机的正中间，距最左边2个坐标
                isKilled = 1; // 击中靶子
            isFire = 0;
        }

        // 下面输出一个复杂的飞机图案
        for (j=0;j<y;j++)
            printf(" ");
        printf("  *\n");

        for (j=0;j<y;j++)
            printf(" ");

        printf("*****\n");

        for (j=0;j<y;j++)
            printf(" ");
        printf(" * * \n");


        if(kbhit()){  // 判断是否有输入
            input = getchar();  // 根据用户的不同输入来移动，不必输入回车
            if (input == 'a')
                y--;  // 位置左移
            if (input == 'd')
                y++;  // 位置右移
            if (input == 'w')
                x--;  // 位置上移
            if (input == 's')
                x++;  // 位置下移
            if (input == ' ')
                isFire = 1;
        }
        Sleep(20);
    }
}



int main()
{
    //ball();
    //plane();
    plan_game();
}
