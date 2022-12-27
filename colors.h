#ifndef COLORS_H_INCLUDED

void green(int state)
{
    system("");
    printf("\033[%d;32m", state);
}
void red(int state)
{
    system("");
    printf("\033[%d;31m", state);
}
void yellow(int state)
{
    system("");
    printf("\033[%d;33m", state);
}
void blue(int state)
{
    system("");
    printf("\033[%d;34m", state);
}
void purple(int state)
{
    system("");
    printf("\033[%d;35m", state);
}
void cyan(int state)
{
    system("");
    printf("\033[%d;36m", state);
}
void white(int state)
{
    system("");
    printf("\033[%d;37m", state);
}
void black(int state)
{
    system("");
    printf("\033[%d;30m", state);
}
#define COLORS_H_INCLUDED



#endif // COLORS_H_INCLUDED
