#ifndef _POSICAO_HPP
#define _POSICAO_HPP
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;


typedef struct nova_Matriz{
    int indice;
    string elemento;
}nova_Matriz;


class Posicao{

    private:

    unsigned short int x;
    unsigned short int y;
    Posicao* proximo;

    public:

    Posicao();
    Posicao(unsigned short int x, unsigned short int y);

    void setX(unsigned short int x);
    unsigned short int getX();

    void setY(unsigned short int y);
    unsigned short int getY();

    void setProximo(Posicao* proximo);
    Posicao* getProximo();
};
#endif