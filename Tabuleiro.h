#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro
{
public:
    Tabuleiro(){
        Inicia_Campo(Campo);
        Distribui_Barcos(Campo);
        Imprime_Campo(Campo);
    }
    void Inicia_Campo(char Campo[15][15]);
    void Colocar_Barco(char Campo[][15], char Que_barco, char Orientacao);
    void Imprime_Campo(char Campo[][15]);
    void Posicao_correta(int *linha,int *coluna,int tamanho_barco,char Orientacao);
    void Distribui_Barcos(char Campo[][15]);
private:
    char Campo[15][15];
};



#endif