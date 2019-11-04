#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H
#include "Tabuleiro.h"
#include "Barcos.h"

void    MENU();
void    JOGO_SOZINHO(int dificuldade);
void    JOGO_EM_DUPLA(int dificuldade);
void    JOGO_CONTRA_COMPUTADOR(int dificuldade);
int     ATIRAR(Tabuleiro *tabuleiro,int*);
int     ATIRAR_COMPUTADOR(Tabuleiro *tabuleiro,int *num_tiros,int dificuldade);
void    Vetor_de_Barcos(Barco V[]);
void    Onde_atirou(int a, Barco V[11]);
int     dificuldade();
int     opcao_deJogo(int* nivel);
void    Atualiza_score(int a,int* score);
void    Quem_Venceu(int score,int score2);
void    Quem_Venceu_PC(int score,int score2);

#endif