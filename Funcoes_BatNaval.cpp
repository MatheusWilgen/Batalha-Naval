#include "Batalha_Naval.h"
#include <iostream>
#include "Barcos.h"
#include "Tabuleiro.h"
#include <string>

using namespace std;

//Função principal para o jogo
void JOGO()
{
    Barco V[11];
    Vetor_de_Barcos(V);
    Tabuleiro primeiro;
    primeiro.Imprime_Campo_Mascara();
    primeiro.Imprime_Campo();
    int a = ATIRAR(&primeiro);

    while(1){
        
        system("clear");
        Onde_atirou(a,V);
        primeiro.Imprime_Campo_Mascara();
        //primeiro.Imprime_Campo();
        
        a = ATIRAR(&primeiro);
    }
    
    
}

void Vetor_de_Barcos(Barco V[10]){
    for(int i = 0; i<3; i++){
        V[i].setBarco("Fragata",2);
        V[i+3].setBarco("Balizador",2);
    }
    for(int i=6 ; i<8; i++){
        V[i].setBarco("Contratorpedeiro",3);
        V[i+2].setBarco("Cruzador",3);
    }
    V[10].setBarco("Porta avioes",4);
}

int ATIRAR(Tabuleiro *tabuleiro){
    //Entrada do local do tiro
    bool entrada_correta = false;
    int linha=-1, coluna=-1;
    //enquanto nao entrar com o dado certo nao continua o prog
    while(entrada_correta == false){
        cout << "Entre com o local do tiro ex: A2 ou M4"<< endl;
        string TIRO;
        cin >> TIRO;
        //tratando a entrada pois é do tipo A2
        coluna = TIRO[0]- 'A';
        if(TIRO.length() == 3){
            linha = ((TIRO[1]-'0')*10) + (TIRO[2] - '0') -1;
        }else if(TIRO.length() == 2){
            linha = TIRO[1] - '0' -1;
        }
        if(linha>=0 && linha <= 14 && coluna >= 0 && coluna <= 14){entrada_correta = true;}
    }
    //cout<< "linha = " << linha<< endl<< "coluna = "<< coluna<<endl;
    tabuleiro->setMascara(linha,coluna);
        
    //cout << coluna <<endl<< linha << endl;
    //retorna o numero do barco ou -1 se foi na agua
    int a = tabuleiro->getCampo_inteiros(linha,coluna);
    return a;
}

void Onde_atirou(int a, Barco V[11])
{ 
    if(a!=-1){
        V[a].set_atingido();
        cout<<"Tiro em Navio"<<endl;
        //V[a].getBarco();
    }else{
        cout << "TIRO NA AGUA"<<endl;
    }
}
  
