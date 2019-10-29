#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro
{
public:
    Tabuleiro(int dificuldade){
        Inicia_Campo(Campo_Secreto);
        Inicia_Campointeiros(Campo_Codigos);
        Inicia_Campo(Campo_Mascara);
        Distribui_Barcos(Campo_Secreto,Campo_Codigos,dificuldade);
        //Imprime_Campo();
        //Imprime_Campo_inteiros();
    }
    void setMascara(int linha,int coluna);
    void Inicia_Campo(char Campo[][15]);
    void Inicia_Campointeiros(int Campo[][15]);
    void Colocar_Barco(char Campo[][15],int Campo2[][15], char Que_barco, char Orientacao,int codigoBarco);
    void Imprime_Campo_Mascara();
    void Imprime_Campo();
    void Imprime_Campo_inteiros();
    void Posicao_correta(int *linha,int *coluna,int tamanho_barco,char Orientacao);
    void Distribui_Barcos(char Campo[][15],int Campo2[][15],int dificuldade);
    int  getCampo_inteiros(int x, int y);
    int  getCampo_Mascara(int linha,int coluna);
private:
    char Campo_Secreto[15][15];
    int  Campo_Codigos[15][15];
    char Campo_Mascara[15][15];
};



#endif