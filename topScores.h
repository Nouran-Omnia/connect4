#ifndef TOPSCORES_H_INCLUDED
#define max 10000
int n, m;
player player1, player2;
void winnerHvH(player player1, player player2)
{
    char name[10000];
    int k;
    if( player1.points > player2.points )
    {
        printf("\n\033[0;34mplayer 1 wins %d - %d ", player1.points, player2.points);
        printf("\nPlayer 1 \033[0;37m, Please enter your name :\n ");
        fflush(stdin);
        FILE* fp ;
        fp = fopen("topScores.txt", "a" );
        fgets(player1.name, 10000, stdin);
        for(k=0 ; k<strlen(player1.name) ; k++)
        {
            player1.name[k] = tolower(player1.name[k]);
        }
        fprintf(fp, "%s\n", player1.name);
        fprintf(fp, "%d\n", player1.points);
        fclose (fp);
    }
    else if( player1.points < player2.points )
    {
        printf("\n\033[1;35mplayer 2 wins %d - %d ", player1.points, player2.points);
        printf("\nPlayer 2\033[0;37m, Please enter your name :\n ");
        fflush(stdin);
        FILE* fp ;
        fp = fopen("topScores.txt", "a" );
        fgets(player2.name, 10000, stdin);
        for(k=0 ; k<strlen(player1.name) ; k++)
        {
            player1.name[k] = tolower(player1.name[k]);
        }
        fprintf(fp, "%s\n", player2.name);
        fprintf(fp, "%d\n", player2.points);
        fclose (fp);
    }
    else
    {
        printf("\n\033[0;34mplayer 1 & \033[1;35mplayer 2 \033[0;37mgot equal points %d - %d \n",player1.points, player2.points);
    }
}
//insertion sort.
void sorting (int a[], int sizes)
{
    int x, y ;
    for( x=1 ; x<sizes ; x++ )
    {
        int next = a[x];
        for( y=x-1 ; y>=0 && a[y] > next ; y-- )
        {
            a[y+1] = a[y];
        }
        a[y+1] = next;
    }


}
#define TOPSCORES_H_INCLUDED



#endif // TOPSCORES_H_INCLUDED
