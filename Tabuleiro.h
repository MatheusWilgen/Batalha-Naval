#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro
{
public:
    Tabuleiro(int dificuldade,int opcao){//para um tabuleiro com barcos randomicos ou colocados por jogador
        Inicia_Campo(Campo_Secreto);
        Inicia_Campointeiros(Campo_Codigos);
        Inicia_Campo(Campo_Mascara);
        if(opcao == 1){
            Distribui_Barcos(Campo_Secreto,Campo_Codigos,dificuldade);
        }
        if(opcao == 2){
            Distribui_Barcos_JOGADOR();
        }
        //Imprime_Campo();
        //Imprime_Campo_inteiros();
    }
    void setMascara(int linha,int coluna);
    void Inicia_Campo(char Campo[][15]);
    void Inicia_Campointeiros(int Campo[][15]);
    void Colocar_Barco(int linha,int coluna,char Que_barco, char Orientacao,int codigoBarco);
    void Colocar_Barco_JOGADOR(int lin,int col,char Que_barco, char Orientacao,int codigoBarco);
    void Imprime_Campo_Mascara();
    void Imprime_Campo();
    void Imprime_Campo_inteiros();
    char verifica_orientacao();
    void Posicao_correta(int *linha,int *coluna,int tamanho_barco,char Orientacao);
    int  Verifica_Colocando_Manual(int linha,int coluna,int tamanho_barco,char orientacao);
    void entrada_posicao(int* linha,int* coluna,int tamanho_barco,char orientacao);
    void Distribui_Barcos(char Campo[][15],int Campo2[][15],int dificuldade);
    void Distribui_Barcos_JOGADOR();
    int  getCampo_inteiros(int x, int y);
    int  getCampo_Mascara(int linha,int coluna);
private:
    char Campo_Secreto[15][15];
    int  Campo_Codigos[15][15];
    char Campo_Mascara[15][15];
};



#endif