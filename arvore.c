//ADRIANO MARQUES MARTINS 02640
//ANTONIO ALMEIDA 02632
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


void init_root(Node ** root){
  (*root) = NULL;
}
//INSERE UM NO NA ÁRVORE
void insert_node(Node ** n, char key, char * morse){
  int i = 0, tamMorse = strlen(morse);
  insert_node2(n, key, morse, &i, tamMorse-1);
  // passa o no raiz, o caractere, o codigo morse, a posição do vetor morse, e o tamanho da string
}

void insert_node2(Node ** n, char key, char * morse, int * i, int tamMorse){
 while (1) {
    if(*n==NULL){
      *n = (Node*)malloc(sizeof(Node));
      (*n)->left = NULL;
      (*n)->right = NULL;
    }
    if(morse[*i]=='.'){
      *i=*i+1; // incremente uma posição no vetor e vai para a esquerda
      insert_node2(&(*n)->left, key, morse, i, tamMorse-1);
    }
    if(morse[*i]=='-'){
      *i=*i+1; // incrementa uma posição no vetor e vai para a direita
      insert_node2(&(*n)->right, key, morse, i, tamMorse-1);
    }
    if(morse[*i]== 0){//termina o while quando o vetor do código morse chegou ao fim;
      if(tamMorse==-1){ //confirmando mesmo que chegou ao fim...
        (*n)->key = key;
      }
      return;
    }
  }
}
//Utiliza a tabela de códigos morse ordenado alfabeticamente
void criarArvore(Node ** root, char t[][7]){
  int i;
  init_root(root); //inicializa a raiz
  for(i=0;i<26;i++)//insere 26 caracteres
    insert_node(root, 65+i, t[i]); // passa a raiz, o valor ascII do caractere, e a posição no vetor de morse
}

void traduzirCodigoMorse(char * texto, Node ** n, char * saida ){
  int i = 0, j =0, k = 0, l;
  char morse[7];
  char letra;
  int tam = strlen(texto);

  while (tam > 0) {//enquanto o numero de caracteres do texto for maior que zero
    for(l=0;l<7;l++) // zera o vetor auxliar par guardar parte da string do texto
      morse[l] = 0;
    if(texto[i] == 32){ // se for um espaço sequido de outro espaço
      saida[k++] = ' '; // a saída recebe um espaço para separar as palaras
      i++;
    }else{ // caso contrário
      j=0;
      while (texto[i] != 32) { //enquanto não houver um espaço, então pega o codigo morse do texto
          morse[j] = texto[i];
          if(morse[j]==0)
            break;
          i++;
          j++;
          tam--;
      }
      i++;
      tam--;
      busca_node(morse, n, &letra);//Após pegar uma parte válida do código morse, busca a qual letra ele pertence na arvore
      if(letra == 0){ // caso a letra retornada seja nula, a saída então é nula
        saida[0]=0;
      }
      saida[k++] = letra; // caso contrário concatena aletra na string de saida;
    }
  }
  saida[k] = 0; //Define o final da string de saída.
}

void busca_node(char * morse, Node ** n, char * letra){
  int i = 0, tam = strlen(morse);
  int flag;//flag para definir se existe o código na árvore ou caractere inválido
  busca_node2(morse, n, letra, &i, tam-1, &flag);
  if(flag)
    *letra = 0;
}

void busca_node2(char * morse, Node ** n, char * letra, int * i, int tam, int * flag){
if((*n) == NULL) // caso chega ao filho da raiz, logo não existe o caractere na árvore
  *flag = 1;
if(morse[*i]== 0){ // final do código morse
  if(tam==-1){ // tamanho do morse chegou mesmo ao final
    *letra = (*n)->key;
    *flag = 0; // então existe o caractere
    return;
  }
}
  if(morse[*i]=='.'){
    *i=*i+1;
    busca_node2(morse, &(*n)->left, letra, i, tam-1, flag);
  }else if(morse[*i]=='-'){
    *i=*i+1;
    busca_node2(morse, &(*n)->right, letra, i, tam-1, flag);
  }else{
    *flag = 1; // caso não seja '.' ou '-' então é um código morse inválido
  }
}
