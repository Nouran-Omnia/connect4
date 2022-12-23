# include <stdio.h>

int main (){

    printf("* To ");
    printf("\033[0;35m");
    printf("START A NEW GAME ");
    printf("\033[0;37m");
    printf("press 1\n");

    printf("* To ");
    printf("\033[0;35m");
    printf("LOAD A GAME ");
    printf("\033[0;37m");
    printf("press 2\n");

    printf("* To ");
    printf("\033[0;35m");
    printf("SHOW TOP PLAYERS ");
    printf("\033[0;37m");
    printf("press 3\n");

    printf("* To ");
    printf("\033[0;35m");
    printf("QUIT ");
    printf("\033[0;37m");
    printf("the game press 4\n");

    int n;
    scanf ("%d",&n);

    if( n == 1 ){

    }else if( n == 2 ){

    }else if( n == 3 ){

    }else if( n == 4 ){

    }else{
        printf("ERROR");
    }
    











    return 0 ;
}