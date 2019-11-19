#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H
#include "Tabuleiro.h"
#include "Barcos.h"

class Batalha_naval
{
public:
    void    MENU();
    void    JOGO_SOZINHO(int dificuldade);
    void    JOGO_EM_DUPLA(int dificuldade);
    void    JOGO_CONTRA_COMPUTADOR(int dificuldade);
    int     ATIRAR(Tabuleiro *tabuleiro,int*);
    int     ATIRAR_COMPUTADOR(Tabuleiro *tabuleiro,int *num_tiros,int dificuldade);
    void    Vetor_de_Barcos(Barco V[]);
    void    Onde_atirou(int a, Barco V[11]);
    template <typename level>
    level   dificuldade();
    int     opcao_deJogo(int* nivel);
    void    Atualiza_score(int a,int* score);
    void    Quem_Venceu(int score,int score2);
    void    Quem_Venceu_PC(int score,int score2);
private:
    Barco V[11],V2[11];
};


#endif