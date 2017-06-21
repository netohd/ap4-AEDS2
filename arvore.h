#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
//#include "arvore.c"

//typedef struct TipoNo* Apontador;

struct TipoNo {
    char chave;
    struct TipoNo *esq, *dir;
}TipoNo;

void inicializa(struct TipoNo * no);
void insere(char * morse, char letra, int tamNorse, struct TipoNo * no);
void imprime(struct TipoNo * no);

#endif // ARVORE_H_INCLUDED
