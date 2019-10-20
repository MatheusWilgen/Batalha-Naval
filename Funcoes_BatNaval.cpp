#include "Batalha_Naval.h"
#include <iostream>
#include <experimental/random>
using namespace std;

//Função principal para o jogo
void JOGO()
{
    char Campo[15][15];
    Inicia_Campo(Campo);
    //Imprime_Campo(Campo);
    Colocar_Barco(Campo,'F','V');
    Imprime_Campo(Campo);

}

//Inicia o Tabuleiro com o mar '~' 
void Inicia_Campo(char Campo[15][15])
{
    //enche todos os espaços com caracter '~'
    for(int linha = 0; linha < 15; linha++){
        for(int coluna = 0; coluna < 15; coluna++){
            Campo[linha][coluna] = '~';
        }
    }
}

//Imprime o campo na tela
void Imprime_Campo(char Campo[][15])
{  
    cout << "   A B C D E F G H I J K L M N O" << endl;
    for(int linha = 0 ; linha < 15; linha++){
        if(linha < 9){
            cout << ' ' <<linha+1 << ' ';
        }else{
            cout << linha+1 << ' ';
        }
        for(int coluna = 0 ; coluna < 15 ; coluna++){
            cout << Campo[linha][coluna] << ' ';
            if(coluna==14){cout << endl;}
        }
    }
}

//Coloca os barcos em posiçoes aleatorias 
//'F' - Fragata 
//'B' - Balizador 
//'C' - Contratorpedeiro
//'+' - Cruzador
//'P' - Porta avioes
void Colocar_Barco(char Campo[][15], char Que_barco, char Orientacao)
{
    int tamanho_barco;
    //Definindo o tamanho do barco
    if(Que_barco == 'F' || Que_barco == 'B'){
        tamanho_barco = 2;
    }
    if(Que_barco == 'C' || Que_barco == '+'){
        tamanho_barco = 3;
    }
    if(Que_barco == 'P'){
        tamanho_barco = 4;
    }
    //variaveis para linha e coluna
    int linha, coluna;
    if(Orientacao == 'V'){
        Posicao_correta(&linha,&coluna,tamanho_barco, 'V');
        //Colocando o barco Vertical
        for(int i = 0; i < tamanho_barco; i++){
            Campo[linha+i][coluna] = Que_barco;
        }
    }
    if(Orientacao == 'H'){
        Posicao_correta(&linha,&coluna,tamanho_barco, 'H');
        //Colocando o barco na Horizontal
        for(int i = 0; i < tamanho_barco; i++){
            Campo[linha][coluna + i] = Que_barco;
        }
    }
}
void Posicao_correta(int *linha,int *coluna,int tamanho_barco,char Orientacao)
{
    bool posicao_possivel = false;
    if(Orientacao == 'V'){
        *coluna = experimental::randint(0,14);
        while(posicao_possivel==false){
            //Posicao aleatoria para colocar o barco
            *linha = experimental::randint(0,14);
            if(14 - *linha >= tamanho_barco){posicao_possivel = true;}
        }
    }
    if(Orientacao == 'H'){
        *linha = experimental::randint(0,14);
        while(posicao_possivel==false){
            //Posicao aleatoria para colocar o barco
            *coluna = experimental::randint(0,14);
            if(14 - *coluna >= tamanho_barco){posicao_possivel = true;}
        }
    }
    if(Orientacao == 'D'){
        
    }
}