#include <stdio.h>

int vet[3][3];

void printar_tab(int (*ponte)[3]) {
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
        printf("\n");
    }
}

int main() {
    printf("Olha que programa legal\n");
    int c = 0;
    // Inicializa o vetor com 0 e imprime
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vet[i][j] = 0;
            // printf("%d ", vet[i][j]);
            c++;
        }
        printf("\n");
    }

    // Chama a função para imprimir a tabela

    int win = 0;
    int jogador = 1;
    
    int numero;

    while(win==0){
        printf("Vez de jogador: %d\n", jogador);
        printf("Digite um número de 1 a 9:");
        scanf("%d", &numero);

        // Verifica se o número está entre 1 e 9
        if (numero >= 1 && numero <= 9) {
            // Calcula o índice correspondente
            int index = numero - 1; // De 1-9 para 0-8
            int i = index / 3;      // Linha
            int j = index % 3;      // Coluna
            if(vet[i][j]==0){
                vet[i][j] = jogador;
                if(jogador==1){
                    jogador++;
                }else{
                    jogador--;
                };


                for(int i = 0; i<3; i++){
                    if(vet[i][0] != 0 && vet[i][0] == vet[i][1] && vet[i][1] == vet[i][2]){
                        printf("JOGADOR %d GANHOU\n", jogador);  
                        win = 1;
                    }
                    for (int j = 0; j<3; j++){
                        if(vet[0][j] != 0 && vet[0][j] == vet[1][j] && vet[1][j] == vet[2][j]){
                            printf("JOGADOR %d GANHOU\n", jogador);  
                            win = 1;
                        }
                    }
                    
                }
                // if(vet[0][0] == vet[0][1] && vet[0][1] == vet[0][2]){
                //     printf("JOGADOR %d GANHOU\n", jogador);
                // }else if(){
                //     printf("JOGADOR %d GANHOU\n", jogador);
                // }
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
