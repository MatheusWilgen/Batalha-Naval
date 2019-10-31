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

//Coloca os barcos nas posiçoes que o jogador mandar
//'F' - Fragata 
//'B' - Balizador 
//'C' - Contratorpedeiro
//'+' - Cruzador
//'P' - Porta avioes
void Tabuleiro::Colocar_Barco_JOGADOR(int lin,int col,char Que_barco, char Orientacao,int codigoBarco)
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
    int linha = lin,coluna = col,disponivel = 0;
    //Tratando cada possibilidade de inserir barco

    //Colocando o barco Vertical
    if(Orientacao == 'V'){
        //verificando se nao ha sobreposicao e se a insersao nao sai do campo
        while(disponivel != tamanho_barco){
            disponivel = 0;
            cout << "cuidado com a sobreposicao de navio"<<endl;
            entrada_posicao(&linha,&coluna,tamanho_barco,Orientacao);
            for(int i = 0; i < tamanho_barco; i++){
                if(Campo_Secreto[linha+i][coluna]=='~'){
                    disponivel++;
                }
            }
        }
        
        //tudo ok, insero o barco vertical
        for(int i = 0; i < tamanho_barco; i++){
            Campo_Secreto[linha+i][coluna] = Que_barco;
            Campo_Codigos[linha+i][coluna] = codigoBarco;
        }
    }
    
    //Colocando o barco na horizontal
    if(Orientacao == 'H'){
        //verificando se nao ha sobreposicao
        while(disponivel != tamanho_barco){
            disponivel = 0;
            cout << "cuidado com a sobreposicao de navio"<<endl;
            entrada_posicao(&linha,&coluna,tamanho_barco,Orientacao);
            for(int i = 0; i < tamanho_barco; i++){
                if(Campo_Secreto[linha][coluna + i]=='~'){
                    disponivel++;
                }
            }
        }
        //tudo ok, inserindo o barco horizontal
        for(int i = 0; i < tamanho_barco; i++){
            Campo_Secreto[linha][coluna + i] = Que_barco;
            Campo_Codigos[linha][coluna+i] = codigoBarco;
        }
    }

    //Colocando o barco na diagonal
    if(Orientacao == 'D'){
        //verificando se nao ha sobreposicao
        int i=0,j=0;
        while(disponivel != tamanho_barco){
            disponivel = 0;
            i=0;j=0;
            cout << "cuidado com a sobreposicao de navio"<<endl;
            entrada_posicao(&linha,&coluna,tamanho_barco,Orientacao);
            while(i<tamanho_barco && j<tamanho_barco){
                if(Campo_Secreto[linha+i][coluna+j] == '~'){
                    disponivel++;
                }
                i++;
                j++;
            }
        }
        //Tudo certo, insere o barco na diagonal
        i=0;j=0;
        while(i<tamanho_barco && j<tamanho_barco){
            Campo_Secreto[linha+i][coluna+j] = Que_barco;
            Campo_Codigos[linha+i][coluna+j] = codigoBarco;
            i++;
            j++;
        }
    }
}

//Coloca os barcos em posiçoes aleatorias 
//'F' - Fragata 
//'B' - Balizador 
//'C' - Contratorpedeiro
//'+' - Cruzador
//'P' - Porta avioes
void Tabuleiro::Colocar_Barco(int lin,int col,char Que_barco, char Orientacao,int codigoBarco)
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
    int linha = lin,coluna = col,disponivel = 0;
    //Tratando cada possibilidade de inserir barco

    //Colocando o barco Vertical
    if(Orientacao == 'V'){
        //verificando se nao ha sobreposicao e se a insersao nao sai do campo
        while(disponivel != tamanho_barco){
            disponivel = 0;
            Posicao_correta(&linha,&coluna,tamanho_barco, 'V');
            for(int i = 0; i < tamanho_barco; i++){
                if(Campo_Secreto[linha+i][coluna]=='~'){
                    disponivel++;
                }
            }
        }
        
        //tudo ok, insero o barco vertical
        for(int i = 0; i < tamanho_barco; i++){
            Campo_Secreto[linha+i][coluna] = Que_barco;
            Campo_Codigos[linha+i][coluna] = codigoBarco;
        }
    }
    
    //Colocando o barco na horizontal
    if(Orientacao == 'H'){
        //verificando se nao ha sobreposicao
        while(disponivel != tamanho_barco){
            disponivel = 0;
            Posicao_correta(&linha,&coluna,tamanho_barco, 'H');
            for(int i = 0; i < tamanho_barco; i++){
                if(Campo_Secreto[linha][coluna + i]=='~'){
                    disponivel++;
                }
            }
        }
        //tudo ok, inserindo o barco horizontal
        for(int i = 0; i < tamanho_barco; i++){
            Campo_Secreto[linha][coluna + i] = Que_barco;
            Campo_Codigos[linha][coluna+i] = codigoBarco;
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
                if(Campo_Secreto[linha+i][coluna+j] == '~'){
                    disponivel++;
                }
                i++;
                j++;
            }
        }
        //Tudo certo, insere o barco na diagonal
        i=0;j=0;
        while(i<tamanho_barco && j<tamanho_barco){
            Campo_Secreto[linha+i][coluna+j] = Que_barco;
            Campo_Codigos[linha+i][coluna+j] = codigoBarco;
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
            *linha = experimental::randint(0,15);
            if(15 - *linha >= tamanho_barco){posicao_possivel = true;}
        }
    }
    if(Orientacao == 'H'){
        *linha = experimental::randint(0,14);
        while(posicao_possivel==false){
            //Posicao aleatoria para colocar o barco
            *coluna = experimental::randint(0,14);
            if(15 - *coluna >= tamanho_barco){posicao_possivel = true;}
        }
    }
    if(Orientacao == 'D'){
        while(posicao_possivel==false){
            *coluna = experimental::randint(0,14);
            *linha = experimental::randint(0,14);
            if((15 - *coluna >= tamanho_barco) && (15 - *linha >= tamanho_barco)){posicao_possivel = true;}
        }
    }
}


void Tabuleiro::entrada_posicao(int* linha,int* coluna,int tamanho_barco,char orientacao)
{
    string posicao;
    bool entrada_correta = false;
    *linha = -1;
    *coluna = -1;
    while(entrada_correta == false){
        //tratando a entrada pois é do tipo A2 ou M5
        cin >> posicao;
        *coluna = posicao[0]- 'A';
        if(posicao.length() == 3){
            *linha = ((posicao[1]-'0')*10) + (posicao[2] - '0') -1;
        }else if(posicao.length() == 2){
            *linha = posicao[1] - '0' -1;
        }
        if(*linha>=0 && *linha <= 14 && *coluna >= 0 && *coluna <= 14){
            entrada_correta = true;
        }
        if(Verifica_Colocando_Manual(*linha,*coluna,tamanho_barco,orientacao) == -1){
            entrada_correta = false;
            cout << "Posicao fora do tabuleiro"<<endl;
        }

    }
        
}

//retorna -1 se nao é posicao dentro do tabuleiro 
//retorna 1 se eh posicao dentro do tabuleiro
//retorna 0 caso erro
int Tabuleiro::Verifica_Colocando_Manual(int linha,int coluna,int tamanho_barco,char orientacao)
{
    if(orientacao == 'V'){
        if(15 - linha >= tamanho_barco){
            return 1;
        }
        return -1;
    }
    if(orientacao == 'H'){
        if(15 - coluna >= tamanho_barco){
            return 1;
        }
        return -1;
    }
    if(orientacao == 'D'){
        if((15 - coluna >= tamanho_barco) && (15 - linha >= tamanho_barco)){
            return 1;
        }
        return -1;
    }
    return 0;
}

char Tabuleiro::verifica_orientacao()
{
    string orientacao;
    while(1)
    {
        cin>>orientacao;
        if(orientacao[0]=='H' && orientacao.length()==1)
            break;
        if(orientacao[0]=='D'&& orientacao.length()==1)
            break;
        if(orientacao[0]=='V'&& orientacao.length()==1)
            break;
        cout<<"orientacao incorreta tente denovo"<<endl;
    }
    return orientacao[0];
}

void Tabuleiro::Distribui_Barcos_JOGADOR()
{
    int linha=0,coluna=0;
    char orientacao;
    for(int i=0; i<3; i++){
        system("clear");
        Imprime_Campo();
        cout<< "insira uma orientaçao para a fragata " << i+1 <<" exemplo H - horizontal D - diagonal V - Vertical"<<endl;
        orientacao = verifica_orientacao();
        cout << "insira uma posicao para a fragata " << i+1 <<" exemplo A2 ou M5"<<endl;
        Colocar_Barco_JOGADOR(linha,coluna,'F',orientacao,i);
    }
    for(int i=3; i<6; i++){
        system("clear");
        Imprime_Campo();
        cout<< "insira uma orientaçao para o balizador " << i-2 <<" exemplo H - horizontal D - diagonal V - Vertical"<<endl;
        orientacao = verifica_orientacao();
        cout << "insira uma posicao para o balizador " << i-2 <<" exemplo A2 ou M5"<<endl;
        Colocar_Barco_JOGADOR(linha,coluna,'B',orientacao,i);
    }
    for(int i=6; i<8; i++){
        system("clear");
        Imprime_Campo();
        cout<< "insira uma orientaçao para o contratorpedeiro " << i-5 <<" exemplo H - horizontal D - diagonal V - Vertical"<<endl;
        orientacao = verifica_orientacao();
        cout << "insira uma posicao para o contratorpedeiro " << i-5 <<" exemplo A2 ou M5"<<endl;
        Colocar_Barco_JOGADOR(linha,coluna,'C',orientacao,i);
    }
    for(int i=8; i<10; i++){
        system("clear");
        Imprime_Campo();
        cout<< "insira uma orientaçao para o cruzador " << i-7 <<" exemplo H - horizontal D - diagonal V - Vertical"<<endl;
        orientacao = verifica_orientacao();
        cout << "insira uma posicao para o cruzador " << i-7 <<" exemplo A2 ou M5"<<endl;
        Colocar_Barco_JOGADOR(linha,coluna,'+',orientacao,i);
    }
    system("clear");
    Imprime_Campo();
    cout<< "insira uma orientaçao para o porta aviao exemplo H - horizontal D - diagonal V - Vertical"<<endl;
    orientacao = verifica_orientacao();
    cout << "insira uma posicao para o porta aviao exemplo A2 ou M5"<<endl;
    Colocar_Barco_JOGADOR(linha,coluna,'P',orientacao,10);
}

//Funcao que gerencia a disposicao dos barcos aleatoriamente
void Tabuleiro::Distribui_Barcos(char Campo[][15],int Campo2[][15],int dificuldade)
{
    char V[3]={'H','V','D'};
    int pos;
    if(dificuldade == 1){
        pos = experimental::randint(0,1);
        for(int i=0; i<3; i++){
            Colocar_Barco(-1,-1,'F',V[pos],i);
            Colocar_Barco(-1,-1,'B',V[pos],i+3);
        }
        for(int i=6; i<8; i++){
            Colocar_Barco(-1,-1,'C',V[pos],i);
            Colocar_Barco(-1,-1,'+',V[pos],i+2);
        }
        Colocar_Barco(-1,-1,'P',V[pos],10);
    }
    if(dificuldade == 2){
        for(int i=0; i<3; i++){
            pos = experimental::randint(0,1);
            Colocar_Barco(-1,-1,'F',V[pos],i);
            pos = experimental::randint(0,1);
            Colocar_Barco(-1,-1,'B',V[pos],i+3);
        }
        for(int i=6; i<8; i++){
            pos = experimental::randint(0,1);
            Colocar_Barco(-1,-1,'C',V[pos],i);
            pos = experimental::randint(0,1);
            Colocar_Barco(-1,-1,'+',V[pos],i+2);
        }
        pos = experimental::randint(0,1);
        Colocar_Barco(0,0,'P',V[pos],10);
    }
    if(dificuldade == 3){
        for(int i=0; i<3; i++){
            pos = experimental::randint(0,2);
            Colocar_Barco(-1,-1,'F',V[pos],i);
            pos = experimental::randint(0,2);
            Colocar_Barco(-1,-1,'B',V[pos],i+3);
        }
        for(int i=6; i<8; i++){
            pos = experimental::randint(0,2);
            Colocar_Barco(-1,-1,'C',V[pos],i);
            pos = experimental::randint(0,2);
            Colocar_Barco(-1,-1,'+',V[pos],i+2);
        }
        pos = experimental::randint(0,2);
        Colocar_Barco(-1,-1,'P',V[pos],10);
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
        Campo_Mascara[linha][coluna] = '0';
    }else{
        Campo_Mascara[linha][coluna] = 'X';
    }
}

//retorna -1 se a posiçao ja recebeu um tiro ou 1 se nao recebeu ainda
int Tabuleiro::getCampo_Mascara(int linha,int coluna)
{
    if(Campo_Mascara[linha][coluna] != '~'){
        return -1;
    }
    return 1;
}