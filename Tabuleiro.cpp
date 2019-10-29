#include <iostream>
#include <experimental/random>
#include "Tabuleiro.h"

using namespace std;

// o Tabuleiro com o mar '~' 
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
void Tabuleiro::Imprime_Campo_Mascara()
{  
    cout << "   A B C D E F G H I J K L M N O" << endl;
    for(int linha = 0 ; linha < 15; linha++){
        if(linha < 9){
            cout << ' ' <<linha+1 << ' ';
        }else{
            cout << linha+1 << ' ';
        }
        for(int coluna = 0 ; coluna < 15 ; coluna++){
            cout << Campo_Mascara[linha][coluna] << ' ';
            if(coluna==14){cout << endl;}
        }
    }
}
void Tabuleiro::Imprime_Campo()
{
    cout << "   A B C D E F G H I J K L M N O" << endl;
    for(int linha = 0 ; linha < 15; linha++){
        if(linha < 9){
            cout << ' ' <<linha+1 << ' ';
        }else{
            cout << linha+1 << ' ';
        }
        for(int coluna = 0 ; coluna < 15 ; coluna++){
            cout << Campo_Secreto[linha][coluna] << ' ';
            if(coluna==14){cout << endl;}
        }
    }
}

void Tabuleiro::Imprime_Campo_inteiros()
{  
    cout << "   A B C D E F G H I J K L M N O" << endl;
    for(int linha = 0 ; linha < 15; linha++){
        if(linha < 9){
            cout << ' ' <<linha+1 << ' ';
        }else{
            cout << linha+1 << ' ';
        }
        for(int coluna = 0 ; coluna < 15 ; coluna++){
            cout << Campo_Codigos[linha][coluna] << ' ';
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
void Tabuleiro::Colocar_Barco(char Campo[][15],int Campo2[][15], char Que_barco, char Orientacao,int codigoBarco)
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
            Campo2[linha+i][coluna] = codigoBarco;
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
            Campo2[linha][coluna+i] = codigoBarco;
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
            Campo2[linha+i][coluna+j] = codigoBarco;
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
void Tabuleiro::Distribui_Barcos(char Campo[][15],int Campo2[][15],int dificuldade)
{
    char V[3]={'H','V','D'};
    int pos;
    if(dificuldade == 1){
        pos = experimental::randint(0,1);
        for(int i=0; i<3; i++){
            Colocar_Barco(Campo,Campo2,'F',V[pos],i);
            Colocar_Barco(Campo,Campo2,'B',V[pos],i+3);
        }
        for(int i=6; i<8; i++){
            Colocar_Barco(Campo,Campo2,'C',V[pos],i);
            Colocar_Barco(Campo,Campo2,'+',V[pos],i+2);
        }
        Colocar_Barco(Campo,Campo2,'P',V[pos],10);
    }
    if(dificuldade == 2){
        for(int i=0; i<3; i++){
            pos = experimental::randint(0,1);
            Colocar_Barco(Campo,Campo2,'F',V[pos],i);
            pos = experimental::randint(0,1);
            Colocar_Barco(Campo,Campo2,'B',V[pos],i+3);
        }
        for(int i=6; i<8; i++){
            pos = experimental::randint(0,1);
            Colocar_Barco(Campo,Campo2,'C',V[pos],i);
            pos = experimental::randint(0,1);
            Colocar_Barco(Campo,Campo2,'+',V[pos],i+2);
        }
        pos = experimental::randint(0,1);
        Colocar_Barco(Campo,Campo2,'P',V[pos],10);
    }
    if(dificuldade == 3){
        for(int i=0; i<3; i++){
            pos = experimental::randint(0,2);
            Colocar_Barco(Campo,Campo2,'F',V[pos],i);
            pos = experimental::randint(0,2);
            Colocar_Barco(Campo,Campo2,'B',V[pos],i+3);
        }
        for(int i=6; i<8; i++){
            pos = experimental::randint(0,2);
            Colocar_Barco(Campo,Campo2,'C',V[pos],i);
            pos = experimental::randint(0,2);
            Colocar_Barco(Campo,Campo2,'+',V[pos],i+2);
        }
        pos = experimental::randint(0,2);
        Colocar_Barco(Campo,Campo2,'P',V[pos],10);
    }
}

//Retorna o inteiro que esta na posicao do tabuleiro de codigos
int Tabuleiro::getCampo_inteiros(int x, int y)
{
    if(Campo_Codigos[x][y]!=-1){
        return(Campo_Codigos[x][y]);
    }
    return -1;
}

void Tabuleiro::Inicia_Campointeiros(int Campo[][15])
{
    //enche todos os espaços com -1
    for(int linha = 0; linha < 15; linha++){
        for(int coluna = 0; coluna < 15; coluna++){
            Campo[linha][coluna] = -1;
        }
    }
}

void Tabuleiro::setMascara(int linha, int coluna)
{
    if(Campo_Codigos[linha][coluna] != -1){
        cout <<"funciona"<<endl;
        Campo_Mascara[linha][coluna] = '0';
    }else{
        cout <<"funciona 2"<<endl;
        Campo_Mascara[linha][coluna] = 'X';
    }
}
