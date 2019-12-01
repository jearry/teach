#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>


void changemode(int dir)
{
    static struct termios oldt, newt;

    if ( dir == 1 ){
        tcgetattr( STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    }else{
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    }
}


#if defined(_WINDOWS)
void gotoxy(int x, int y)
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
#else
void gotoxy(int x,int y)   //Fantasy
{
   printf("%c[%d;%df",0x1B,y,x);
}
#endif


void clrsrc()
{
    printf("\033c");
}



class platform_init{
public:
    platform_init(){
        changemode(1);
    }
    ~platform_init(){
        changemode(0);
    }
};

static platform_init s_pi;

int kbhit (void)
{
    struct timeval tv;
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET (STDIN_FILENO, &rdfs);

    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

void Sleep(int ms)
{
    usleep(ms * 1000);
}


