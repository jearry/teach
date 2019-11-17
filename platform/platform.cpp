#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>

static struct termios initial_settings, new_settings;


void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}


void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

class platform_init{
public:
    platform_init(){
        init_keyboard();
    }
    ~platform_init(){
        close_keyboard();
    }
};

static platform_init pi;