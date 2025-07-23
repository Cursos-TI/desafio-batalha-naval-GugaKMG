#include <stdio.h>
#include <stdlib.h>

int main(){
    int navio1[3] = {3, 3, 3},
        navio2[3] = {3, 3, 3},
        navio3[3] = {3, 3, 3},
        navio4[3] = {3, 3, 3};

    int tabuleiro[10][10] =
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

     //Tratamento da sobreposição dos navios.
     if(tabuleiro[7][0] == 0 && tabuleiro[8][0] == 0 && tabuleiro[9][0] == 0){
        tabuleiro[7][0] = navio1[0];
        tabuleiro[8][0] = navio1[1];
        tabuleiro[9][0] = navio1[2];
     } else{
        printf("Navios sobrepostos.");
        exit(1);
     }

     if(tabuleiro[0][7] == 0 && tabuleiro[0][8] == 0 && tabuleiro[0][9] == 0){
        tabuleiro[0][7] = navio2[0];
        tabuleiro[0][8] = navio2[1];
        tabuleiro[0][9] = navio2[2];
     } else{
        printf("Navios sobrepostos.");
        exit(1);
     }

     if(tabuleiro[0][0] == 0 && tabuleiro[1][1] == 0 && tabuleiro[2][2] == 0){
        tabuleiro[0][0] = navio3[0];
        tabuleiro[1][1] = navio3[1];
        tabuleiro[2][2] = navio3[2];
     } else{
        printf("Navios sobrepostos.");
        exit(1);
     }

     if(tabuleiro[7][7] == 0 && tabuleiro[7][8] == 0 && tabuleiro[7][9] == 0){
        tabuleiro[7][7] = navio4[0];
        tabuleiro[8][8] = navio4[1];
        tabuleiro[9][9] = navio4[2];
     } else{
        printf("Navios sobrepostos.");
        exit(1);
     }

    //Exibição do tabuleiro.
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
                printf(" %d ", tabuleiro[i][j]);
            }

        printf("\n");
    }

    return 0;
}
