//ADRIANO MARQUES MARTINS 02640
//ANTONIO ALMEIDA 02632
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"
#include "tabela.h"


void limparString(char * c){
  int tam = strlen(c);
  int i;
  for(i=0;i<tam;i++){
    c[i] = 0;
  }
}

// É feita a leitura de um arquivo txt que possui o código morse de todas as letras,
// onde a sequência é: "<LETRA><COD.MORSE>0" para todas as letras do alfabeto.
// Um vetor (morseVet) é utilizado para armazenar os "." e "-" de cada letra e é
// feita a inserção na árvore binária letra por letra.
//
// O número 0 em cada sequência serve para identificar o fim da mesma.
int main(){

    tabelaMorse tabela; //criando um vector de strings par armazenar o código morse
    Node * raiz;
    int op, flag=1, i = 0, j;

    char txtIn[1000]; // definindo um tamanho máximo para o texto de entrada das funções
    char txtOut[1000]; // definindo um tamanho máximo para o texto de saída das funções
    char saida[1000][1000]; // definindo um vetor de strings que irá armazenar os resultados de codificação e decodificação

    //inicializando a tabela e a árvore BST
    criarTabela(tabela);
    criarArvore(&raiz, tabela);
    while (flag) {
      scanf("%d", &op); // ler opção do usuário
      limparString(txtIn); //limpar lixo da strins
      limparString(txtOut);
      switch (op) {
        case 1:
            scanf("%[^\n]s", txtIn);// %[^\n]s lê a cadeia de caracteres considerando os espaços
            codificarTexto(tabela, txtIn, txtOut);
            strcat(saida[i++], txtOut);//concatena o texto codificado
            break;
        case 2:
            scanf("%[^\n]s", txtIn);
            traduzirCodigoMorse(txtIn, &raiz, txtOut);
            strcat(saida[i++], txtOut); // concatena o texto decodificado
            break;
        case 3:
            imprimirTabela(tabela);
            break;
        case 0:
            flag = 0; // finaliza o looop;
            break;
        default: printf("opcao invalida, digite novamente: "); // número inválido
      }
    }

    //Após a interção do usuário imprime a saída dos resultados obtidos;
  for(j=1;j<i;j=j+2){
    if(strlen(saida[j])==0)
      printf("Sequencia invalida: caracteres invalidos e/ou espacos em excesso");
    else
      printf("%s",saida[j]);
    printf("\n");
  }
  return 0;
}
