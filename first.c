# include <stdio.h>


int main () {

    int n=7;
    int m=6;
    char mat[n][m];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            mat[i][j] = 0 ;
            printf("%d | ",mat[i][j]);
        }
        printf("\n");
        printf("-----------------------");
        printf("\n");
    }

     

    // printf("Player 1 turn\n");
    // printf("Choose a column : \n");



    



    










    return 0 ;
}