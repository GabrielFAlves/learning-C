#include <stdio.h>
#include <locale.h> //importando caracteres especiais
#include <stdlib.h> //importando abs()
#include <time.h> //importando fun��o time()

// Necess�rio uso do int main() para iniciar o programa
int main(){

    // Para usar os caracteres especiais
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Imprime o cabe�alho do nosso jogo
    printf("----------------------------------------\n");
    printf("* Bem vindo ao meu jogo de adivinha��o *\n");
    printf("----------------------------------------\n");

    // devolve o numero de segundos passados desde primeiro de janeiro de 1970
    int segundos = time(0);
    // passando numeros diferentes para a fun��o rand()
    srand(segundos);

    // criando numero randomico
    int numerogrande = rand();

    // declara��o de variaveis
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    // scanf() � o input
    // %d sinaliza que � um inteiro
    // estrutura de repeti��o for e while
    // loop vai continuar enquanto for verdadeiro e encerra no break,(1 = true, 0 = false, boolean)
    while(1){
        printf("Tentativa %d\n", tentativas);
        printf("Qual � o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        // Valida��o de n�meros positivos
        if(chute < 0){
            printf("Voc� n�o pode chutar n�meros negativos!\n");

            // diferente do break que encerraria o jogo, o continue para a intera��o mas continua o loop
            continue;
        }

        // vari�veis
        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        // estrutura condicional similar a do python
        if (acertou){
            printf("Voce acertou!\n");
            printf("Jogue de novo, voc� � um bom jogador!\n");

            // encerra o la�o break
            break;
        }
        else if(maior){
            printf("Seu chute foi maior que o n�mero secreto!\n");
        }
        else{
            printf("Seu chute foi menor que o n�mero secreto\n");
        }

        // contador de tentativas
        tentativas++;

        // abs � uma fun��o para transformar o numero em absoluto
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de jogo!\n");
    printf("Voc� acertou em %d tentativas\n", tentativas);

    // %f sinaliza que � um double, decimal
    printf("Total de pontos: %.1f\n", pontos);
}
