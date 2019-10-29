#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H
#include "Tabuleiro.h"
#include "Barcos.h"

void MENU();
void JOGO_SOZINHO(int dificuldade);
int ATIRAR(Tabuleiro *tabuleiro,int*);
void Vetor_de_Barcos(Barco V[]);
void Onde_atirou(int a, Barco V[11]);
int dificuldade();

#endif