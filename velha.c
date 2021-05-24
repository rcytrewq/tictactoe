#include <stdio.h>
#include <stdlib.h>


//VERIFICAR SE A LINHA E COLUNA INSERIDA SAO VALIDAS
    


#define dim 3
int i,j,i_,j_;
int linha, coluna;
int valid;
char buffer;
int esc;
int matrix[3][3];
int mode;
int play1, play2, vel;



void assemble(){
    printf("\n\n\t\tlin | col->   1   2   3  \n\t\t |  |-------------------");
    printf("\n\t\t v  |\n\t\t    |\n");
    for (i_=0; i_<dim; i_++){
        printf("\t\t %d  |\t     ", i_+1);
        for (j_=0; j_<dim; j_++){
            if(matrix[i_][j_] == 0){
                printf("   ");
            }
            else if (matrix[i_][j_] == 1){
                printf(" X ");
                
            }
            else{
                printf(" O ");
                
            }

            if(j_!=2) printf("|");
        }
        if (i_!=2) printf("\t\t\n\t\t    |\t     -----------\n");
    }
    printf("\t\t\n\n");
    return;
}

int result(){
    for (i=0; i<dim; i++){
        if(matrix[i][0]== matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != 0){
            system("clear");
            assemble();
            printf("\t\tFim de Jogo!\n\t\tJogador %d venceu!\n\n", matrix[i][0]);
            if(matrix[i][0]==1) play1++;
            else play2++;
            
            return 1;
        }
        if(matrix[0][i]== matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != 0){
            system("clear");
            assemble();
            printf("\t\tFim de Jogo!\n\t\tJogador %d venceu!\n\n", matrix[0][i]);
            if(matrix[0][i]==1) play1++;
            else play2++;
        
        return 1;
        }

        if(matrix[1][1]== matrix[2][2] && matrix[1][1] == matrix[0][0] && matrix[0][0] != 0){
            system("clear");
            assemble();
            printf("\t\tFim de Jogo!\n\t\tJogador %d venceu!\n\n", matrix[0][0]);
            if(matrix[0][0]==1) play1++;
            else play2++;
        
        return 1;
        }

        if(matrix[0][2]== matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != 0){
            system("clear");
            assemble();
            printf("\t\tFim de Jogo!\n\t\tJogador %d venceu!\n\n", matrix[1][1]);
            if(matrix[1][1]==1) play1++;
            else play2++;
        
        return 1;
        }

        if(matrix[0][0] != 0 && matrix[0][1] != 0 && matrix[0][2] != 0 && matrix[1][0] != 0 && matrix[1][1] != 0 && matrix[1][2] != 0 && matrix[2][0] != 0 && matrix[2][1] != 0 && matrix[2][2] != 0){
            system("clear");
            assemble();
            printf("\t\tFim de Jogo!\n\t\tTemos um empate!\n\n");
            vel++;
        
        return 1;
        }
    }
    return 0;

}

int check(int linha, int coluna){
    if( matrix[linha][coluna]!=0 || linha<0 || linha>=3 || coluna<0 || coluna>=3){
        system("clear");
        assemble();
        printf("\n\t\tPosição inválida;\n\t\tDigite novamente\n\n");
        return 0;
    }
    return 1;
}

void player1(){
    system("clear");
    assemble();
    valid = 0;
    printf("\n\n\t\tJOGADOR 1, eh a sua vez de jogar!\n\t\tVoce deve inserir a linha e a coluna em que deseja jogar\n\n");
    
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

void player2(){
    system("clear");
    assemble();
    valid = 0;
    printf("\n\n\t\tJOGADOR 2, eh a sua vez de jogar!\n\t\tVoce deve inserir a linha e a coluna em que deseja jogar\n\n");
    
    while (valid!=1){
        printf("\t\tInsira a linha: ");
        scanf("%d", &linha);
        printf("\t\tInsira a coluna: ");
        scanf("%d", &coluna);
        valid = check(linha-1, coluna-1);
    }
    
    matrix[linha-1][coluna-1] = 2;
    
    return;
}




void matrixreset(){
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            matrix[i][j] = 0;            
        }   
    
    }
}



void replaymenu(){

    printf("\n\n\t\tAperte enter para ir ao menu\n");
    scanf("%c%c", &buffer, &buffer);
    system("clear");
    printf("\n\n\t\t DESEJA JOGAR NOVAMENTE?");
    printf("\n\n\t\t1 - Sim\n\t\t2 - Nao\n\n\t\t");
    scanf("%c", &buffer);
    if(buffer!='1'){
        esc=1;
    }  

    return;
}
void score(){
    system("clear");
    printf("\n\t\t\t|-----------|\n");
    printf("\t\t\t|   SCORE   |\n");
    printf("\t\t\t|           |\n");
    printf("\t\t\t|Player1 - %d|\n", play1);
    printf("\t\t\t|Player2 - %d|\n", play2);
    printf("\t\t\t|Tie     - %d|\n", vel);
    printf("\t\t\t|-----------|\n");
    printf("\n\n\n\n\t\tAperte enter para continuar");
    scanf("%c%c", &buffer, &buffer);
    return;
}
void game(){
    //score();
    matrixreset();
    //sorteio de quem começa
    assemble();
    while(1==1){
        player1();
        assemble();
        if (result()==1){
            replaymenu();
            break;
        }
        player2();
        assemble();
        if (result()==1){
            replaymenu();
            break;
        }
    }
    score();

}



void menu(){
    system("clear");
    printf("\n\n\t\t\tTIC TAC TOE");
    printf("\n\n\t\tDigite o modo de jogo:\n\n\t\t1 - Player1 vs Player2\n\n\t\t");
    scanf("%d", &mode);
    if(mode==1){
        play1=0;
        play2=0;
        vel=0;
        while (esc!=1){
            game();
        }
        score();
    }
    return;
}

int main(){
    
    esc=0;
    menu();
    

    printf("\n\n\n");
    return 0;
}