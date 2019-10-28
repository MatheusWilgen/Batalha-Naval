#ifndef BARCOS_H
#define BARCOS_H

#include <iostream>
#include <string>
using namespace std;

class Barco 
{
public:
    Barco();
    Barco(string name,int tam);
    void getBarco();
    void setBarco(string nome, int tam);
    void set_atingido();
       
private:
    int tamanho,vida;
    string nome;
};

#endif