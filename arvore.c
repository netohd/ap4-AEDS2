#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void inicializa(struct TipoNo ** no){
    (*no) = NULL;
//  (*no) = (struct TipoNo *) malloc(sizeof(TipoNo));
//  (*no)->chave = (char) 2;
//  (*no)->esq = NULL;
//  (*no)->dir = NULL;

  return;
}

void insere(char * morse, char letra, int tamMorse, TipoNo ** no)
{
    int cont = 0;

    while(morse[cont] != '0'){
        if(no == NULL){
            *no = (TipoNo *) malloc(sizeof(TipoNo));
            (*no)->esq = NULL;
            (*no)->dir = NULL;

            if(cont == tamMorse)
                (*no)->chave = letra;
            else
                (*no)->chave = (char) 2;

            //return;
        }

        else{
            if(morse[cont] == '-'){
                cont++;
                insere(morse, letra, tamMorse, &(*no)->dir);
                //return;
            }
            if(morse[cont] == '.'){
                cont++;
                insere(morse, letra, tamMorse, &(*no)->esq);
                //return;
            }
        }
//        else{
//            printf("\nJa existente!\n");
//            return;
//        }
    }
}

void imprime(struct TipoNo * no){
    if(no == NULL)
        return;
    imprime(no->esq);
    printf("%c\n",no->chave);
    imprime(no->dir);
}