
#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#define TRUE 1
#define FALSE 0
//ADRIANO MARQUES MARTINS 02640
//ANTONIO ALMEIDA 02632

#include "tabela.h"

typedef struct _Node {
  char key;
  int tamMorse;
  struct _Node *left, *right;
}Node;

//BST
void criarArvore(Node ** root, char t[][7]);
void init_root(Node ** root);
void traduzirCodigoMorse(char * texto, Node ** n, char * saida );
void insert_node(Node ** n, char key, char * morse);
void insert_node2(Node ** n, char key, char * morse, int * i, int tamMorse);
void busca_node(char * morse, Node ** n, char * letra);
void busca_node2(char * morse, Node ** n, char * letra, int * i, int tam, int * flag);
#endif // ARVORE_H_INCLUDED
