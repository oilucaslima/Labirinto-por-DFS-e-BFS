#include "Posicao.hpp"
#include <iostream>

using namespace std;

Posicao :: Posicao(unsigned short int x, unsigned short int y){
    this -> setX(x);
    this -> setY(y);
    this -> setProximo(NULL);
}

Posicao :: Posicao (){
    setX(0);
    setY(0);
}

void Posicao :: setX(unsigned short int x){
    this-> x = x;
}
unsigned short int Posicao :: getX(){
    return this-> x;
}

void Posicao :: setY(unsigned short int y){
    this-> y = y;
}
unsigned short int Posicao :: getY(){
    return this-> y;
}

void Posicao :: setProximo(Posicao* proximo){
    this-> proximo = proximo;
}
Posicao* Posicao :: getProximo(){
    return this-> proximo;
}

