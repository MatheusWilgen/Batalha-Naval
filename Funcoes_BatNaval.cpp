#include "Batalha_Naval.h"
#include <iostream>
#include "Barcos.h"
#include "Tabuleiro.h"
#include <string>


using namespace std;

void MENU()
{
    
    int opcao,nivel;
    cout<<endl<< "BEM VINDO AO BATALHA NAVAL!"<<endl<<endl;
    cout<< "Para jogar sozinho digite 1"<<endl;
    cout<< "Para jogar em dupla digite 2"<<endl;
    cout<< "Para sair digite 0"<<endl<<endl;

    //outras opçoes
   
    cin >> opcao;
        if(0)
            return;
        if(opcao == 1){
            nivel = dificuldade();
            JOGO_SOZINHO(nivel);
        }
        if(opcao == 2){
            nivel = dificuldade();
            JOGO_EM_DUPLA(nivel);
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

//Função principal para jogar sozinho
void JOGO_SOZINHO(int dificuldade)
{
    system("clear");
    Barco V[11];
    Vetor_de_Barcos(V);
    Tabuleiro tabuleiro(dificuldade,1);
    int num_tiros = 50, a=-2;
    do
    {
        system("clear");
        Onde_atirou(a,V);
        tabuleiro.Imprime_Campo_Mascara();
        tabuleiro.Imprime_Campo();
        a = ATIRAR(&tabuleiro,&num_tiros);
        
        //tabuleiro.Imprime_Campo();
    } while (a != -10);
    system("clear");
    tabuleiro.Imprime_Campo();
    
}

int opcao_deJogo()
{
    int opcao;
    while(opcao<1 || opcao>2){
        cout<<"cuide com a opcao"<<endl;
        cin >> opcao;
    }
    return opcao;
}

void JOGO_EM_DUPLA(int dificuldade)
{
    //Criacao do ambiente
    int opcao;
    Barco V[11],V2[11];
    Vetor_de_Barcos(V);
    Vetor_de_Barcos(V2);
    cout<<"Jogador 1 quer colocar os barcos ou quer que o computador coloque randomicamente?"<<endl
        <<"1 - Randomico"<<endl<<"2 - Colocar"<<endl;
    opcao = opcao_deJogo();
    Tabuleiro tabuleiro(dificuldade,opcao);
    system("clear");
    cout<<"Jogador 2 quer colocar os barcos ou quer que o computador coloque randomicamente?"<<endl
        <<"1 - Randomico"<<endl<<"2 - Colocar"<<endl;
    opcao = opcao_deJogo();
    Tabuleiro tabuleiro2(dificuldade,opcao);
    int num_tiros  = 50, num_tiros2 = 50, a=-2,a2=-2;
    
    do
    {
        system("clear");
        cout<<"Campo do Jogador 1"<<endl;
        Onde_atirou(a,V);a = -2;
        tabuleiro.Imprime_Campo_Mascara();
        cout<<"Campo do Jogador 2"<<endl;
        Onde_atirou(a2,V2);a2 = -2;
        tabuleiro2.Imprime_Campo_Mascara();
        cout << "Jogador 1 Atire!!"<<endl;
        a = ATIRAR(&tabuleiro2,&num_tiros);
        system("clear");
        cout<<"Campo do Jogador 1"<<endl;
        Onde_atirou(a,V);a = -2;
        tabuleiro.Imprime_Campo_Mascara();
        cout<<"Campo do Jogador 2"<<endl;
        Onde_atirou(a2,V2);a2 = -2;
        tabuleiro2.Imprime_Campo_Mascara();
        cout << "Jogador 2 Atire!!"<<endl;
        a2 = ATIRAR(&tabuleiro,&num_tiros2);
        
    } while (a != -10);
    system("clear");
    tabuleiro.Imprime_Campo();
    tabuleiro2.Imprime_Campo();
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
             <<"Voce pode desistir a qualquer momento escrevendo: desisto"<<endl<<"tiros restantes = "<<*num_tiros<<endl;
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
        if(linha>=0 && linha <= 14 && coluna >= 0 && coluna <= 14){
            entrada_correta = true;
        }
        if(tabuleiro->getCampo_Mascara(linha,coluna) == -1){
            entrada_correta = false;
            cout << "Nesse local ja foi dado um tiro, tente outro"<<endl;
        }
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
    //coloca um 0 se um barco foi atingido ou um X se foi na agua
    tabuleiro->setMascara(linha,coluna);

    //retorna o numero do barco ou -1 se foi na agua
    int a = tabuleiro->getCampo_inteiros(linha,coluna);
    return a;
}

//Se o a contem -1 significa que foi um tiro na agua, caso contrario o a 
//contem exatamente onde o barco foi atingido entao essa funcao decrementa a vida do respectivo barco
void Onde_atirou(int a, Barco V[11])
{ 
    if(a==-2)
        return;
    if(a!=-1){
        V[a].set_atingido();
        //V[a].getBarco();
    }
}


  
