#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H


void JOGO();
void Inicia_Campo(char Campo[15][15]);
void Colocar_Barco(char Campo[][15], char Que_barco, char Orientacao);
void Imprime_Campo(char Campo[][15]);
void Posicao_correta(int *linha,int *coluna,int tamanho_barco,char Orientacao);


#endif