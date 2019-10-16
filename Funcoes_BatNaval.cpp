#include "Batalha_Naval.h"
#include <iostream>
using namespace std;


void JOGO()
{
    char Campo[15][15];
    Inicia_Campo(Campo);

}

void Inicia_Campo(char Campo[15][15])
{
    //enche todos os espaços com caracter 'a'
    for(int linha = 0; linha < 15; linha++){
        for(int coluna = 0; coluna < 15; coluna++){
            Campo[linha][coluna] = 'a';
        }
    //mostrando campo por enquanto    
    }
    for(int linha = 0 ; linha < 15; linha++){
        for(int coluna = 0 ; coluna < 15 ; coluna++){
            cout << Campo[linha][coluna];
            if(coluna==14){cout << endl;}
        }
    }
}

void Colocar_Barcos(char Campo[15][15])
{
    
}