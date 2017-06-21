#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.c"

//

int main()
{
    struct TipoNo root;
    int tamMorse, cont = 0, i;
    char leitor, letra, morse[4];
    FILE * alfabeto = fopen("morse.txt","rt");

    while((fscanf(alfabeto,"%c",&leitor)) != EOF) {
        printf("CHEGOU1\n");
        //fscanf(alfabeto, "%c", leitor);

        if (cont == 0)
            letra = leitor;
        else
            morse[cont] = leitor;

        cont++;

        if (leitor == '0') {
            cont = 0;
            tamMorse = strlen(morse);
            printf("Tamanho norse: %d\n",tamMorse);
            insere(morse, letra, tamMorse, &root);
        }
    }

    //imprime(&root);

    fclose(alfabeto);

  return 0;
}
