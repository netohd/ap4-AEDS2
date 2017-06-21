#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.c"

//

int main()
{
    struct TipoNo root;
    int tamMorse, cont = 0, i;
    char leitor, letra, morse[5];
    FILE * arq;

    arq = fopen("morse.txt","r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");

    inicializa(&root);

//    letra = (char) fgetc(arq);
//    //letra = leitor;
//    printf("%c",letra);
//
//    for(i = 0; i < 3; i++) {
//        morse[i] = (char) fgetc(arq);
//        printf("%c", morse[i]);
//    }

//    fscanf(alfabeto, "%c", leitor);
//    morse[0] = leitor;
//    printf("%c",morse[0]);
//
//    fscanf(alfabeto, "%c", leitor);
//    morse[1] = leitor;
//    printf("%c",morse[1]);
//
//    fscanf(alfabeto, "%c", leitor);
//    morse[2] = leitor;
//    printf("%c",morse[2]);
//
//    fscanf(alfabeto, "%c", leitor);
//    morse[3] = leitor;
//    printf("%c",morse[3]);
//
//    fscanf(alfabeto, "%c", leitor);
//    morse[4] = leitor;
//    printf("%c",morse[4]);

//    printf("Tam: %d",strlen(morse));

    while((fscanf(arq,"%c",&leitor)) != EOF) {
        //printf("CHEGOU1\n");
        //fscanf(alfabeto, "%c", leitor);

        if (cont == 0)
            letra = leitor;
        else
            morse[cont] = leitor;

        cont++;

        if (leitor == '0') {
            tamMorse = cont - 2;
            cont = 0;
            printf("Tamanho norse: %d\n",tamMorse);
            insere(morse, letra, tamMorse, &root);
        }
    }

    //imprime(&root);

    fclose(arq);

  return 0;
}
