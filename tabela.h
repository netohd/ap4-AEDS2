//ADRIANO MARQUES MARTINS 02640
//ANTONIO ALMEIDA 02632
#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

//Definindo cada caractere ao seu código morse para simplificação
#define A ".-"
#define B "-..."
#define C "-.-."
#define D "-.."
#define E "."
#define F "..-."
#define G "--."
#define H "...."
#define I ".."
#define J ".---"
#define K "-.-"
#define L ".-.."
#define M "--"
#define N "-."
#define O "---"
#define P ".--."
#define Q "--.-"
#define R ".-."
#define S "..."
#define T "-"
#define U "..-"
#define V "...-"
#define W ".--"
#define X "-..-"
#define Y "-.--"
#define Z "--.."

typedef char tabelaMorse[26][7];

void criarTabela(char t[][7]);
void imprimirTabela(char t[][7]);
void codificarTexto(char t[][7], char * txt, char * out);

#endif
