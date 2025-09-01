#include <stdio.h>
#include <stdlib.h>

int main(){
    int habilV = 0, habilH = 0;

    int navio1[3] = {3, 3, 3},
        navio2[3] = {3, 3, 3},
        navio3[3] = {3, 3, 3},
        navio4[3] = {3, 3, 3};

    int habilCone[3][5] = {{0, 0, 5, 0, 0},
                           {0, 5, 5, 5, 0},
                           {5, 5, 5, 5, 5}},

        habilCruz[3][3] = {{0, 4, 0},
                           {4, 4, 4},
                           {0, 4, 0}},

        habilOcta[5][5] = {{0, 0, 1, 0, 0},
                           {0, 1, 1, 1, 0},
                           {1, 1, 1, 1, 1},
                           {0, 1, 1, 1, 0},
                           {0, 0, 1, 0, 0}};

    int tabuleiro[10][10] =
/* 0 */{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 1 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 2 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 3 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 4 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 5 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 6 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 7 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 8 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/* 9 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
      // 0  1  2  3  4  5  6  7  8  9


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

     if(tabuleiro[7][7] == 0 && tabuleiro[8][8] == 0 && tabuleiro[9][9] == 0){
        tabuleiro[7][7] = navio4[0];
        tabuleiro[8][8] = navio4[1];
        tabuleiro[9][9] = navio4[2];
     } else{
        printf("Navios sobrepostos.");
        exit(1);
     }

    //Cálculo de habilidades.
    //Habilidade Cone.
    for(int i = 3; i < 6; i++){
        for(int j = 5; j < 10; j++){
            if(habilH == 5){
                habilH = 0;
            }

            if(tabuleiro[i][j] == 3){
                habilH++;

            }else{
                tabuleiro[i][j] = habilCone[habilV][habilH];
                habilH++;
            }
        }

        habilV++;
    }

    habilH = 0;
    habilV = 0;

    //Habilidade Cruz.
    for(int i = 0; i < 3; i++){
        for(int j = 4; j < 7; j++){
            if(habilH == 3){
                habilH = 0;
            }

            if(tabuleiro[i][j] == 3){
                habilH++;
            }else{
                tabuleiro[i][j] = habilCruz[habilV][habilH];
                habilH++;
            }
        }

        habilV++;
    }

    habilH = 0;
    habilV = 0;

    //Habilidade Octaedro.
    for(int i = 3; i < 8; i++){
        for(int j = 0; j < 5; j++){
            if(habilH == 5){
                habilH = 0;
            }

            if(tabuleiro[i][j] == 3){
                habilH++;
            }else{

            tabuleiro[i][j] = habilOcta[habilV][habilH];
            habilH++;
            }
        }

        habilV++;
    }

    //Exibição do tabuleiro.
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
                printf(" %d ", tabuleiro[i][j]);
            }

        printf("\n");
    }

    return 0;
}
