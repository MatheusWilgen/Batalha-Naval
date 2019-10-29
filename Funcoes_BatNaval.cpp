#include "Batalha_Naval.h"
#include <iostream>
#include "Barcos.h"
#include "Tabuleiro.h"
#include <string>


using namespace std;

void MENU()
{
    
    int opcao;
    cout<<endl<< "BEM VINDO AO BATALHA NAVAL!"<<endl<<endl;
    cout<< "Para jogar sozinho digite 1"<<endl;

    cout<< "Para sair digite 0"<<endl<<endl;

    //outras opçoes

    cin >> opcao;
    switch(opcao)
    {
        case(0):
            return;
        case(1):
            int nivel = dificuldade();
            JOGO_SOZINHO(nivel);
    }

}

int dificuldade()
{   
    int a=0;
    while(a<1 || a>3){
        cout<<"Qual dificuldade voce deseja jogar?"<<endl
        <<"Para facil digite 1"<<endl<<"Para medio digite 2"<<endl
        <<"Para dificil digite 3"<<endl;
    
        cin >> a;
    }
    return a;
}

//Função principal para o jogar sozinho
void JOGO_SOZINHO(int dificuldade)
{
    system("clear");
    Barco V[11];
    Vetor_de_Barcos(V);
    Tabuleiro primeiro(dificuldade);
    int num_tiros = 50;

    primeiro.Imprime_Campo_Mascara();
    //primeiro.Imprime_Campo();
    int a = ATIRAR(&primeiro,&num_tiros);

    while(a!=-10){
        system("clear");
        Onde_atirou(a,V);
        primeiro.Imprime_Campo_Mascara();
        //primeiro.Imprime_Campo();
        a = ATIRAR(&primeiro,&num_tiros);
    }
    system("clear");
    primeiro.Imprime_Campo();
    
}

//inicializa o vetor contendo os barcos
void Vetor_de_Barcos(Barco V[]){
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

//Gerencia os tiros ou a desistencia
int ATIRAR(Tabuleiro *tabuleiro,int *num_tiros){
    //Entrada do local do tiro
    bool entrada_correta = false,desistir=false;
    int linha=-1, coluna=-1;
    //enquanto nao entrar com o dado certo nao continua o prog
    while(entrada_correta == false){
        cout << "Entre com o local do tiro ex: A2 ou M4"<< endl
             <<"Voce pode desistir a qualquer momento escrevendo desisto"<<endl<<"tiros restantes = "<<*num_tiros<<endl;
        string TIRO;
        cin >> TIRO;
        if(TIRO == "desisto"){desistir = true;break;}
        //tratando a entrada pois é do tipo A2
        coluna = TIRO[0]- 'A';
        if(TIRO.length() == 3){
            linha = ((TIRO[1]-'0')*10) + (TIRO[2] - '0') -1;
        }else if(TIRO.length() == 2){
            linha = TIRO[1] - '0' -1;
        }
        if(linha>=0 && linha <= 14 && coluna >= 0 && coluna <= 14){entrada_correta = true;}
    }
    *num_tiros-=1;
    if(*num_tiros == 0){
        cout<<"acabou os tiros"<<endl;
        return -10;
    }
    if(desistir == true)
    {
        return -10;
    }
    tabuleiro->setMascara(linha,coluna);
    //retorna o numero do barco ou -1 se foi na agua
    int a = tabuleiro->getCampo_inteiros(linha,coluna);
    return a;
}

//Se o a contem -1 significa que foi um tiro na agua, caso contrario o a 
//contem exatamente o barco que foi atingido
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
  
