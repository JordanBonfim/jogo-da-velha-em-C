#include <stdio.h>

int vet[3][3];

void print_winner(int jogador){
    printf("JOGADOR %d GANHOU\n", jogador);  
}

void printar_tab(int (*ponte)[3]) {
    printf("\n");
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(ponte[i][j]==1){
                printf(" x ");
            }else if(ponte[i][j]==2){
                printf(" o ");
            }else{
                printf(" - ");
            }
        }
        switch (k){
            case 0:
                printf("       1 2 3");
                break;
            case 1:
                printf("       4 5 6");
                break;
            case 2:
                printf("       7 8 9");
                break;
        }
        k++;
        printf("\n");
    }
    printf("\n\n");
}

int main() {
    printf("Olha que programa legal\n");
    printf("Jogador 1: x\n");
    printf("Jogador 2: o\n");
    int c = 0;
    // Inicializa o vetor com 0 e imprime
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vet[i][j] = 0;
            c++;
        }
        printf("\n");
    }

    int win = 0;
    int jogador = 1;
    int plays = 0;
    int numero;

    while(win==0){
        printf("Vez de jogador: %d\n", jogador);
        printf("Digite um número de 1 a 9:");
        scanf("%d", &numero);
        printf("\n");

        // Verifica se o número está entre 1 e 9
        if (numero >= 1 && numero <= 9) {
            // Calcula o índice correspondente
            int index = numero - 1; // De 1-9 para 0-8
            int i = index / 3;      // Linha
            int j = index % 3;      // Coluna
            if(vet[i][j]==0){
                vet[i][j] = jogador;
                            for(int i = 0; i<3; i++){
                    if(vet[i][0] != 0 && vet[i][0] == vet[i][1] && vet[i][1] == vet[i][2]){
                        win = 1;
                    }
                    for (int j = 0; j<3; j++){
                        if(vet[0][j] != 0 && vet[0][j] == vet[1][j] && vet[1][j] == vet[2][j]){
                            win = 1;
                        }
                    }
                }

                if(vet[0][0]!=0 && vet[0][0] == vet[1][1] && vet[1][1] == vet[2][2]){
                    win=1;
                }else if(vet[2][0]!=0 && (vet[2][0] == vet[1][1] && vet[1][1] == vet[0][2])){
                    win=1;
                }

                plays++;

                if(win==1){
                    print_winner(jogador);
                }else if(plays==9){
                    printf("VELHA!");
                    win=1;
                }else{

                    
                    if(jogador==1){
                        jogador++;
                    }else{
                        jogador--;
                    };
                }
            }else{
                printf("Número inválido! Escolha uma posição valida\n");
                printf("Vez de jogador: %d\n", jogador);
            }
            printar_tab(vet);
        } else {
            printf("Número inválido! Por favor, digite um número de 1 a 9.\n");
            printf("Vez de jogador: %d\n", jogador);
        }
    }
    return 0;
}
