#ifndef _FILA_HPP
#define _FILA_HPP
#include <iostream>
#include <string>
#include <tuple>
#include "Posicao.hpp"

using namespace std;


class Fila{

    private:

    Posicao* primeiro;
    Posicao* ultimo; 
    int contador,passos;

    public:

    Fila(unsigned short int x, unsigned short int y);
    Fila();
    
    virtual ~Fila();

    void setPrimeiro(Posicao* primeiro);
    Posicao* getPrimeiro();

    void setUltimo(Posicao* ultimo);
    Posicao* getUltimo(); 

    void setContador(int contador);
    int getContador();

    bool vazia();

    void set_Passos2(int passos);
    int get_Passos2();

    void add_coordenada(unsigned short int x, unsigned short int y);
    void remover_coordenada();
    void imprimir_fila();
    tuple<unsigned short int, unsigned short int> obter_elemento_fila(int posicao);
    tuple<unsigned short int, unsigned short int> obter_primeiro_da_fila();

};
#endif