#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

//typedef struct TipoNo* Apontador;

struct TipoNo {
    char chave;
    struct TipoNo *esq, *dir;
}TipoNo;

void insere(char * morse, char letra, int tamNorse, struct TipoNo * no);
void imprime(struct TipoNo * no);

#endif // ARVORE_H_INCLUDED
