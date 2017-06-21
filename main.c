#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.c"

// É feita a leitura de um arquivo txt que possui o código morse de todas as letras,
// onde a sequência é: "<LETRA><COD.MORSE>0" para todas as letras do alfabeto.
// Um vetor (morseVet) é utilizado para armazenar os "." e "-" de cada letra e é
// feita a inserção na árvore binária letra por letra.
//
// O número 0 em cada sequência serve para identificar o fim da mesma.

int main()
{
    struct TipoNo root;
    int tamMorse, cont = 0, i, inicio = TRUE, aux;
    char leitor, letra, morse[5];
    FILE * arq;

    arq = fopen("morse.txt","r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");

    inicializa(&root);

    while((fscanf(arq,"%c",&leitor)) != EOF) { // FAZ A LEITURA DO ARQUIVO
        if (inicio == TRUE) { // SE FOR O INÍCIO DE UMA SEQUÊNCIA, O PRIMEIRO CARACTERE É A LETRA
            letra = leitor;
            inicio = FALSE;
        }
        else { // SENÃO, É PARTE DO CÓDIGO MORSE (. ou -)
            morse[cont] = leitor;
            cont++;
        }

        if (leitor == '0') { // SE FOR O FIM DE UMA SEQUÊNCIA
            tamMorse = cont - 1;
            aux = cont - 1;
            cont = 0;
            inicio = TRUE;

            char morseVet[tamMorse]; // ARMAZENA O CÓDIGO MORSE
            for(i = 0; i <= tamMorse; i++)
                morseVet[i] = morse[i];

            // TESTES (VALORES DAS VARIAVEIS)
            printf("Tamanho morse: %d\n",tamMorse);
            printf("Letra: %c\n",letra);
            printf("MorseVet: %s\n",morseVet);
            printf("Morse: %s\n",morse);

            insere(morseVet, letra, tamMorse, &root);
        }
    }

    //imprime(&root);

    fclose(arq);

  return 0;
}
