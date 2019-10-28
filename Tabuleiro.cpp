#include <iostream>
#include <experimental/random>
#include "Tabuleiro.h"

using namespace std;

//Inicia o Tabuleiro com o mar '~' 
void Tabuleiro::Inicia_Campo(char Campo[][15])
{
    //enche todos os espaços com caracter '~'
    for(int linha = 0; linha < 15; linha++){
        for(int coluna = 0; coluna < 15; coluna++){
            Campo[linha][coluna] = '~';
        }
    }
}

//Imprime o campo na tela
void Tabuleiro::Imprime_Campo(char Campo[][15])
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
void Tabuleiro::Colocar_Barco(char Campo[][15], char Que_barco, char Orientacao)
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
    //variaveis para linha e coluna e para tratar a sobreposicao
    int linha, coluna, disponivel = 0;
    //Tratando cada possibilidade de inserir barco

    //Colocando o barco Vertical
    if(Orientacao == 'V'){
        //verificando se nao ha sobreposicao e se a insersao nao sai do campo
        while(disponivel != tamanho_barco){
            disponivel = 0;
            Posicao_correta(&linha,&coluna,tamanho_barco, 'V');
            for(int i = 0; i < tamanho_barco; i++){
                if(Campo[linha+i][coluna]=='~'){
                    disponivel++;
                }
            }
        }
        //tudo ok, insero o barco vertical
        for(int i = 0; i < tamanho_barco; i++){
            Campo[linha+i][coluna] = Que_barco;
        }
    }
    
    //Colocando o barco na horizontal
    if(Orientacao == 'H'){
        //verificando se nao ha sobreposicao
        while(disponivel != tamanho_barco){
            disponivel = 0;
            Posicao_correta(&linha,&coluna,tamanho_barco, 'H');
            for(int i = 0; i < tamanho_barco; i++){
                if(Campo[linha][coluna + i]=='~'){
                    disponivel++;
                }
            }
        }
        //tudo ok, inserindo o barco horizontal
        for(int i = 0; i < tamanho_barco; i++){
            Campo[linha][coluna + i] = Que_barco;
        }
    }

    //Colocando o barco na diagonal
    if(Orientacao == 'D'){
        //verificando se nao ha sobreposicao
        int i=0,j=0;
        while(disponivel != tamanho_barco){
            disponivel = 0;
            i=0;j=0;
            Posicao_correta(&linha,&coluna,tamanho_barco,'D');
            while(i<tamanho_barco && j<tamanho_barco){
                if(Campo[linha+i][coluna+j] == '~'){
                    disponivel++;
                }
                i++;
                j++;
            }
        }
        //Tudo certo, insere o barco na diagonal
        i=0;j=0;
        while(i<tamanho_barco && j<tamanho_barco){
            Campo[linha+i][coluna+j] = Que_barco;
            i++;
            j++;
        }
    }
}
//Entrega uma posicao aleatoria e ja trata se ela nao tera problema
void Tabuleiro::Posicao_correta(int *linha,int *coluna,int tamanho_barco,char Orientacao)
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
        while(posicao_possivel==false){
            *coluna = experimental::randint(0,14);
            *linha = experimental::randint(0,14);
            if((14 - *coluna >= tamanho_barco) && (14 - *linha >= tamanho_barco)){posicao_possivel = true;}
        }
    }
}

//Funcao que gerencia a disposicao dos barcos
void Tabuleiro::Distribui_Barcos(char Campo[][15])
{
    for(int i=0; i<3; i++){
        Colocar_Barco(Campo,'F','V');
        Colocar_Barco(Campo,'B','V');
    }
    for(int i=0; i<2; i++){
        Colocar_Barco(Campo,'C','H');
        Colocar_Barco(Campo,'+','H');
    }
    Colocar_Barco(Campo,'P','D');
}
