#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void insere(char * morse, char letra, int tamMorse, struct TipoNo * no)
{
    int cont = 0;

    while(morse[cont] != '0'){
        if(no == NULL){
            no = (struct TipoNo *) malloc(sizeof(TipoNo));
            no->esq = NULL;
            no->dir = NULL;

            if(cont == 0)
                no->chave = letra;
            else
                no->chave = -1;

            return;
        }
        if(morse[cont] == '-'){
            cont++;
            insere(morse, letra, tamMorse, no->dir);
            return;
        }
        if(morse[cont] == '.'){
            cont++;
            insere(morse, letra, tamMorse, no->esq);
            return;
        }
        else{
            printf("\nJa existente!\n");
            return;
        }
    }
}

void imprime(struct TipoNo * no){
    if(no == NULL)
        return;
    imprime(no->esq);
    printf("%c\n",no->chave);
    imprime(no->dir);
}