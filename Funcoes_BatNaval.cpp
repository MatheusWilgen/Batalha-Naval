#include "Batalha_Naval.h"
#include <iostream>
using namespace std;


void JOGO()
{
    char Campo[15][15];
    
    Mostra_Campo(Campo);

}

void Mostra_Campo(char Campo[15][15])
{
    //enche todos os espaços com caracter 'a'
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            Campo[i][j] = 'a';
        }
    }
    for(int i = 0 ; i < 15; i++){
        for(int j = 0 ; j < 15 ; j++){
            if(j==14){cout << endl;}
            cout << Campo[i][j];
        }
    }
}