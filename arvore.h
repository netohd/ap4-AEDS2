#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#define TRUE 1
#define FALSE 0

struct TipoNo {
    char chave;
    struct TipoNo *esq, *dir;
};

typedef struct TipoNo TipoNo;

void inicializa(TipoNo ** no);
void insere(char * morse, char letra, int tamNorse, TipoNo ** no);
void imprime(TipoNo * no);

#endif // ARVORE_H_INCLUDED
