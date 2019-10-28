#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H
#include "Tabuleiro.h"
#include "Barcos.h"

void JOGO();
int ATIRAR(Tabuleiro *tabuleiro);
void Vetor_de_Barcos(Barco V[10]);
void Onde_atirou(int a, Barco V[11]);

#endif