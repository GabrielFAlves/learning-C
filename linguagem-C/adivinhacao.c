#include <stdio.h>
#include <locale.h> //importando caracteres especiais
#include <stdlib.h> //importando abs()
#include <time.h> //importando função time()

// Necessário uso do int main() para iniciar o programa
int main(){

    // Para usar os caracteres especiais
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Imprime o cabeçalho do nosso jogo
    printf("----------------------------------------\n");
    printf("* Bem vindo ao meu jogo de adivinhação *\n");
    printf("----------------------------------------\n");

    // devolve o numero de segundos passados desde primeiro de janeiro de 1970
    int segundos = time(0);
    // passando numeros diferentes para a função rand()
    srand(segundos);

    // criando numero randomico
    int numerogrande = rand();

    // declaração de variaveis
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    // scanf() é o input
    // %d sinaliza que é um inteiro
    // estrutura de repetição for e while
    // loop vai continuar enquanto for verdadeiro e encerra no break,(1 = true, 0 = false, boolean)
    while(1){
        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        // Validação de números positivos
        if(chute < 0){
            printf("Você não pode chutar números negativos!\n");

            // diferente do break que encerraria o jogo, o continue para a interação mas continua o loop
            continue;
        }

        // variáveis
        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        // estrutura condicional similar a do python
        if (acertou){
            printf("Voce acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");

            // encerra o laço break
            break;
        }
        else if(maior){
            printf("Seu chute foi maior que o número secreto!\n");
        }
        else{
            printf("Seu chute foi menor que o número secreto\n");
        }

        // contador de tentativas
        tentativas++;

        // abs é uma função para transformar o numero em absoluto
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas\n", tentativas);

    // %f sinaliza que é um double, decimal
    printf("Total de pontos: %.1f\n", pontos);
}
