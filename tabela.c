//ADRIANO MARQUES MARTINS 02640
//ANTONIO ALMEIDA 02632
#include "tabela.h"
#include <stdio.h>
#include <string.h>

void criarTabela(char t[][7]){
  strcpy(t[0], A); // copia o código morse no define A para a posição zero o vetor de strings
  strcpy(t[1], B);
  strcpy(t[2], C);
  strcpy(t[3], D);
  strcpy(t[4], E);
  strcpy(t[5], F);
  strcpy(t[6], G);
  strcpy(t[7], H);
  strcpy(t[8], I);
  strcpy(t[9], J);
  strcpy(t[10], K);
  strcpy(t[11], L);
  strcpy(t[12], M);
  strcpy(t[13], N);
  strcpy(t[14], O);
  strcpy(t[15], P);
  strcpy(t[16], Q);
  strcpy(t[17], R);
  strcpy(t[18], S);
  strcpy(t[19], T);
  strcpy(t[20], U);
  strcpy(t[21], V);
  strcpy(t[22], W);
  strcpy(t[23], X);
  strcpy(t[24], Y);
  strcpy(t[25], Z);

}
void imprimirTabela(char t[][7]){
  int i, j;
  for(i=0;i<26;i++){
    printf("%c -> %s \n", i+65, t[i]);
    //apenas percorre a tabela printando o valor ascII do caractere seguido do morse referente na tabela
  }
}
void codificarTexto(char t[][7], char * txt, char * out){
  int i=0;
  while (txt[i] != 0) {
    if((txt[i]<65||txt[i]>90)){ // caso o valor ascII do caractere não tiver no intervalo
      if(txt[i]!=32){ // e não for um espaço, então a sequencia não é válida
        out[0] = 0;
        break;
      }else if(txt[i]==32 && txt[i+1]==32){ // ou existirem uma sequencia de dois ou mais caracteres
        out[0] = 0;
        break;
      }

    }
    if(txt[i] != 32){ //nao e um espaco entao
      strcat(out, t[txt[i]-65]); //a saida recebe o conteúdo da tabela de morse, com o valor asc do caractere do texto -65
      strcat(out, " "); // e insere um espaço
    }else{
        strcat(out, " "); // caso contrário, apenas um espaço
    }
    i++;
  }
}
