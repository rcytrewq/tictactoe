#include <stdio.h>
#include <stdlib.h>




#define dim 3
int i,j;
int linha, coluna;
int valid;
int matrix[3][3];




void assemble(){
    printf("\n\n\t\tlin | col->   1   2   3  \n\t\t |  |-------------------");
    printf("\n\t\t v  |\n\t\t    |\n");
    for (i=0; i<dim; i++){
        printf("\t\t %d  |\t     ", i+1);
        for (j=0; j<dim; j++){
            if(matrix[i][j] == 0){
                printf("   ");
            }
            else if (matrix[i][j] == 1){
                printf(" X ");
            }
            else{
                printf(" O ");
            }

            if(j!=2) printf("|");
        }
        if (i!=2) printf("\t\t\n\t\t    |\t     -----------\n");
    }
    printf("\t\t\n\n");
    return;
}

void result(){
    for (i=0; i<dim; i++){
        if(matrix[i][0]== matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != 0){
            printf("\t\tFim de Jogo!\nJogador %d venceu!", matrix[i][0]);
        
        break;
        }

        if(matrix[0][i]== matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != 0){
            printf("\t\tFim de Jogo!\nJogador %d venceu!", matrix[0][i]);
        
        break;
        }

        if(matrix[1][1]== matrix[2][2] && matrix[1][1] == matrix[0][0] && matrix[0][0] != 0){
            printf("\t\tFim de Jogo!\nJogador %d venceu!", matrix[0][0]);
        
        break;
        }

        if(matrix[0][2]== matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != 0){
            printf("\t\tFim de Jogo!\nJogador %d venceu!", matrix[1][1]);
        
        break;
        }
    }
    return;

}

int check(int linha, int coluna){
    if( matrix[linha][coluna]!=0){
        printf("\t\tPosição inválida; Digite novamente\n\n");
        return 0;
    }
    return 1;
}

void player1(){
    valid = 0;
    printf("\t\tJOGADOR 1, eh a sua vez de jogar!\n\t\tVoce deve inserir a linha e a coluna em que deseja jogar\n\n");
    
    while (valid!=1){
        printf("\t\tInsira a linha: ");
        scanf("%d", &linha);
        printf("\t\tInsira a coluna: ");
        scanf("%d", &coluna);
        valid = check(linha-1, coluna-1);
    }
    
    matrix[linha-1][coluna-1] = 1;
    return;
}

int main(){
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            if(j+i==2) matrix[i][j] = 1;
            else matrix[i][j] = 0;
    }
    
}
    assemble();
    player1();
    assemble();
    result();
    return 0;
}