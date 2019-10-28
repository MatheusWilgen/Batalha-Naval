#include "Barcos.h"

Barco::Barco(){
    nome = "default";
    tamanho = 0;
    vida = 0;
}

Barco::Barco(string name,int tam)
{
    nome = name;
    vida = tam;
    tamanho = tam;   
}

void Barco::getBarco()
{
    cout<<"tamanho = "<<tamanho<<" vida = "<<vida<<" Nome = "<< nome << endl;
}

void Barco::set_atingido()
{
    if(vida>0){
        vida--;
    }
    if(vida==0){
        cout << nome << " foi Destruido (ツ)"<<endl;
    }
}

void Barco::setBarco(string name, int tam)
{
    nome = name;
    tamanho = tam;
    vida = tam;
}
