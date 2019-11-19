#include "Batalha_Naval.h"
#include <iostream>
#include "Barcos.h"
#include "Tabuleiro.h"
#include <string>
#include <experimental/random>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

void Batalha_naval::MENU()
{
    int opcao,nivel;
    cout<<endl<< "BEM VINDO AO BATALHA NAVAL!"<<endl<<endl;
    cout<< "1 - Para jogar sozinho"<<endl;
    cout<< "2 - Para jogar em dupla"<<endl;
    cout<< "3 - Para jogar contra o computador"<<endl;
    cout<< "0 - Para sair"<<endl<<endl;
   
    cin >> opcao;
        if(0)
            return;
        if(opcao == 1){
            nivel = dificuldade<int>();
            JOGO_SOZINHO(nivel);
        }
        if(opcao == 2){
            JOGO_EM_DUPLA(nivel);
        }
        if(opcao == 3){
            JOGO_CONTRA_COMPUTADOR(nivel);
        }
}
template <typename level>
level Batalha_naval::dificuldade()
{   
    level a = -1;
    while(a<1 || a>3){
        cout<<"Os barcos serão posicionados randomicamente no tabuleiro, qual opçao voce deseja?"<<endl
        <<"1 - Para navios na horizontal ou vertical"<<endl
        <<"2 - Para navios na horizontal e/ou na vertical"<<endl
        <<"3 - Para navios na navios na horizontal e/ou vertical e/ou diagonal"<<endl;
    
        cin >> a;
    }
    return a;
}

void Batalha_naval::Atualiza_score(int a,int* score)
{   
    if(a>-1)
        *score+=1;
    cout<<"score = "<<*score<<endl;
}

//Função principal para jogar sozinho
void Batalha_naval::JOGO_SOZINHO(int dificuldade)
{
    system("clear");
    //agora  Barco V[11];
    Vetor_de_Barcos(V);
    Tabuleiro tabuleiro(dificuldade,1);
    int num_tiros = 50, a=-2,score=0;
    do
    {
        system("clear");
        Atualiza_score(a,&score);
        if(score >= 28)
            break;
        Onde_atirou(a,V);
        tabuleiro.Imprime_Campo_Mascara();
        a = ATIRAR(&tabuleiro,&num_tiros);
        if(a==-10 || a == -9){break;}
        
    } while (1);
    system("clear");
    tabuleiro.Imprime_Campo();
    if(a==-9){
        cout<<"Desistiu"<<endl;
    }else{
        cout<<"Acabou o jogo, sua pontuaçao foi " <<score<<endl;
    }
    
    
}

int Batalha_naval::opcao_deJogo(int* nivel)
{
    int opcao;
    cin >> opcao;
    while(opcao<1 || opcao>2){
        cout<<"cuide com a opcao"<<endl;
        cin >> opcao;
    }
    if(opcao == 1){
        *nivel = dificuldade<int>();
    }
    return opcao;
}

void Batalha_naval::JOGO_EM_DUPLA(int dificuldade)
{
    //Criacao do ambiente
    int opcao;
    Vetor_de_Barcos(V);
    Vetor_de_Barcos(V2);
    cout<<"Jogador 1 quer colocar os barcos ou quer que o computador coloque randomicamente?"<<endl
        <<"1 - Randomico"<<endl<<"2 - Colocar"<<endl;
    opcao = opcao_deJogo(&dificuldade);
    Tabuleiro tabuleiro(dificuldade,opcao);
    system("clear");
    cout<<"Jogador 2 quer colocar os barcos ou quer que o computador coloque randomicamente?"<<endl
        <<"1 - Randomico"<<endl<<"2 - Colocar"<<endl;
    opcao = opcao_deJogo(&dificuldade);
    Tabuleiro tabuleiro2(dificuldade,opcao);
    int num_tiros  = 50, num_tiros2 = 50, a=-2,a2=-2,score=0,score2=0;
    
    do
    {
        system("clear");
        cout<<"Campo do Jogador 1  ";
        Atualiza_score(a,&score);
        if(score >= 28)
            break;
        Onde_atirou(a,V);a = -2;
        tabuleiro.Imprime_Campo_Mascara();
        cout<<"Campo do Jogador 2  ";
        Atualiza_score(a2,&score2);
        if(score2 >= 28)
            break;
        Onde_atirou(a2,V2);a2 = -2;
        tabuleiro2.Imprime_Campo_Mascara();
        cout << "Jogador 1 Atire!!"<<endl;
        a = ATIRAR(&tabuleiro2,&num_tiros);
        if(a==-10 || a == -9){break;}
        system("clear");
        cout<<"Campo do Jogador 1  ";
        Atualiza_score(a,&score);
        if(score >= 28)
            break;
        Onde_atirou(a,V);a = -2;
        tabuleiro.Imprime_Campo_Mascara();
        cout<<"Campo do Jogador 2  ";
        Atualiza_score(a2,&score2);
        if(score2 >= 28)
            break;
        Onde_atirou(a2,V2);a2 = -2;
        tabuleiro2.Imprime_Campo_Mascara();
        cout << "Jogador 2 Atire!!"<<endl;
        a2 = ATIRAR(&tabuleiro,&num_tiros2);
        if(a2==-10 || a2 == -9){break;}
        
    } while (1);
    system("clear");
    cout<<"Campo do Jogador 1  "<<endl;
    tabuleiro.Imprime_Campo();
    cout<<"Campo do Jogador 2  "<<endl;
    tabuleiro2.Imprime_Campo();

    if(a==-9){
        cout<<"Jogador 1 desistiu, Jogador 2 Venceu!"<<endl;
    }else if(a2 == -9){
        cout<<"Jogador 2 desistiu, Jogador 1 Venceu!"<<endl;
    }else{
        Quem_Venceu(score,score2);
    }

}


void Batalha_naval::JOGO_CONTRA_COMPUTADOR(int dificuldade)
{
    //Criacao do ambiente
    int opcao;
    Vetor_de_Barcos(V);
    Vetor_de_Barcos(V2);
    cout<<"Jogador quer colocar os barcos ou quer que o computador coloque randomicamente?"<<endl
        <<"1 - Randomico"<<endl<<"2 - Colocar"<<endl;
    opcao = opcao_deJogo(&dificuldade);
    Tabuleiro tabuleiro(dificuldade,opcao);
    system("clear");
    //para o computador
    cout<<"Qual dificuldade?"<<endl
                <<"1 - Facil"<<endl
                <<"2 - Medio"<<endl
                <<"3 - Dificil"<<endl;
    cin >> opcao;
    dificuldade = experimental::randint(1,3);
    Tabuleiro tabuleiro2(dificuldade,1);
    int num_tiros  = 50, num_tiros2 = 50, a=-2,a2=-2,score=0,score2=0;

    do
    {
        system("clear");
        cout<<"Campo do Jogador  score = "<<score<<endl;
        Onde_atirou(a,V);a = -2;
        tabuleiro.Imprime_Campo_Mascara();
        cout<<"Campo do Computador  ";
        Atualiza_score(a2,&score2);
        if(score2 >= 28)
            break;
        Onde_atirou(a2,V2);a2 = -2;
        tabuleiro2.Imprime_Campo_Mascara();
        cout << "Jogador Atire!!"<<endl;
        a = ATIRAR(&tabuleiro2,&num_tiros);
        if(a==-10||a==-9){break;}
        system("clear");
        cout<<"Campo do Jogador  ";
        Atualiza_score(a,&score);
        if(score >= 28)
            break;
        tabuleiro.Imprime_Campo_Mascara();
        cout<<"Campo do Computador  ";
        Atualiza_score(a2,&score2);
        if(score2 >= 28)
            break;
        Onde_atirou(a2,V2);a2 = -2;
        tabuleiro2.Imprime_Campo_Mascara();
        cout << "Computador Atirando!!"<<endl;
        this_thread::sleep_for (std::chrono::milliseconds(400));
        a2 = ATIRAR_COMPUTADOR(&tabuleiro,&num_tiros2,opcao);
        if(a2==-10){break;}
        
        
    } while (1);
    system("clear");
    cout<<"Campo do Jogador  "<<endl;
    tabuleiro.Imprime_Campo();
    cout<<"Campo do Computador  "<<endl;
    tabuleiro2.Imprime_Campo();
    if(a==-9){
        cout<<"Jogador desistiu, Computador Venceu!"<<endl;
    }else{
        Quem_Venceu_PC(score,score2);
    }
   
}

int Batalha_naval::ATIRAR_COMPUTADOR(Tabuleiro *tabuleiro,int *num_tiros,int dificuldade)
{
    //Entrada do local do tiro
    bool entrada_correta = false;
    int linha=-1, coluna=-1;
    //enquanto nao entrar com o dado certo nao continua o prog
    
    if(dificuldade == 1)
    {
        int sorte;
        while(entrada_correta == false)
        {
        
            linha = experimental::randint(0,14);
            coluna = experimental::randint(0,14);
            sorte  = experimental::randint(0,10);

            if(linha>=0 && linha <= 14 && coluna >= 0 && coluna <= 14){
                entrada_correta = true;
            }

            //Inteligencia
            if(sorte >= 8)
            {
                if(tabuleiro->getCampo_inteiros(linha,coluna) != -1)
                {
                    entrada_correta = true;
                }else{
                    entrada_correta = false;
                }   
            }
             
            
            if(tabuleiro->getCampo_Mascara(linha,coluna) == -1){
                entrada_correta = false;
                //cout << "Nesse local ja foi dado um tiro, tente outro"<<endl;
            }
        }
    }


    if(dificuldade == 2)
    {
        int sorte;
        while(entrada_correta == false)
        {
        
            linha = experimental::randint(0,14);
            coluna = experimental::randint(0,14);
            sorte  = experimental::randint(0,10);

            if(linha>=0 && linha <= 14 && coluna >= 0 && coluna <= 14){
                entrada_correta = true;
            }

            //Inteligencia
            if(sorte >= 3)
            {
                if(tabuleiro->getCampo_inteiros(linha,coluna) != -1)
                {
                    entrada_correta = true;
                }else{
                    entrada_correta = false;
                }   
            }
             
            
            if(tabuleiro->getCampo_Mascara(linha,coluna) == -1){
                entrada_correta = false;
                //cout << "Nesse local ja foi dado um tiro, tente outro"<<endl;
            }
        }
    }


    if(dificuldade == 3)
    {
        while(entrada_correta == false)
        {
            linha = experimental::randint(0,14);
            coluna = experimental::randint(0,14);

            if(linha>=0 && linha <= 14 && coluna >= 0 && coluna <= 14){
                entrada_correta = true;
            }

            //Inteligencia
            //se é uma posicao de navio entao acerta
            if(tabuleiro->getCampo_inteiros(linha,coluna) != -1){
                entrada_correta = true;
            }else{
                entrada_correta = false;
            }
            if(tabuleiro->getCampo_Mascara(linha,coluna) == -1){
                entrada_correta = false;
                //cout << "Nesse local ja foi dado um tiro, tente outro"<<endl;
            }
        }
    }
    
    *num_tiros-=1;
    if(*num_tiros == 0){
        cout<<"acabou os tiros"<<endl;
        return -10;
    }
    
    //coloca um 0 se um barco foi atingido ou um X se foi na agua
    tabuleiro->setMascara(linha,coluna);

    //retorna o numero do barco ou -1 se foi na agua
    int a = tabuleiro->getCampo_inteiros(linha,coluna);
    return a;
}

void Batalha_naval::Quem_Venceu_PC(int score,int score2)
{
    if(score == score2){
        cout << "EMPATOU"<<endl;
    }
    if(score>score2){
        cout<<"Jogador VENCEU!!!"<<endl;
    }
    if(score2>score){
        cout << "Computador VENCEU!!!"<<endl;
    }
}

void Batalha_naval::Quem_Venceu(int score,int score2)
{
    if(score == score2){
        cout << "EMPATOU"<<endl;
    }
    if(score>score2){
        cout<<"Jogador 1 VENCEU!!!"<<endl;
    }
    if(score2>score){
        cout << "Jogador 2 VENCEU!!!"<<endl;
    }
}

//inicializa o vetor contendo os barcos
void Batalha_naval::Vetor_de_Barcos(Barco V[]){
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

//Gerencia os tiros ou a desistencia se desistir retorna -9
int Batalha_naval::ATIRAR(Tabuleiro *tabuleiro,int *num_tiros){
    //Entrada do local do tiro
    bool entrada_correta = false,desistir=false;
    int linha=-1, coluna=-1;
    //enquanto nao entrar com o dado certo nao continua o prog
    while(entrada_correta == false){
        cout << "Entre com o local do tiro ex: A2 ou M4 | "<<"Voce pode desistir a qualquer momento escrevendo: desisto |"<<" tiros restantes = "<<*num_tiros<<endl;
        string TIRO;
        cin >> TIRO;
        if(TIRO == "desisto" || TIRO == "DESISTO"){desistir = true;break;}
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
        return -9;
    }
    //coloca um 0 se um barco foi atingido ou um X se foi na agua
    tabuleiro->setMascara(linha,coluna);

    //retorna o numero do barco ou -1 se foi na agua
    int a = tabuleiro->getCampo_inteiros(linha,coluna);
    return a;
}

//Se o a contem -1 significa que foi um tiro na agua, caso contrario o a 
//contem exatamente onde o barco foi atingido entao essa funcao decrementa a vida do respectivo barco
void Batalha_naval::Onde_atirou(int a, Barco V[11])
{ 
    if(a==-2)
        return;
    if(a!=-1){
        V[a].set_atingido();
    }
}
