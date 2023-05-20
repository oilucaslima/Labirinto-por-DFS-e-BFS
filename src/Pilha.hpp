#ifndef _PILHA_HPP
#define _PILHA_HPP
#include <iostream>
#include <string>
#include <tuple>
#include "Posicao.hpp"

using namespace std;

class Pilha{

    private:

    Posicao* primeiro;
    Posicao* ultimo; 
    int tam_Pilha, passos;

    public:

    Pilha(unsigned short int x, unsigned short int y);
    Pilha();
    
    virtual ~Pilha();

    void setPrimeiro(Posicao* primeiro);
    Posicao* getPrimeiro();

    void setUltimo(Posicao* ultimo);
    Posicao* getUltimo(); 

    void setTam_Pilha(int tam_Pilha);
    int getTam_Pilha();

    void set_Passos(int passos);
    int get_Passos();

    bool vazia();

    void inserir(Posicao* novo);

    void imprimir_pilha();
    void retirardapilha();

};
#endif