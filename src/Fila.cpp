#include "Fila.hpp"
#include <iostream>
#include <string>

using namespace std;

Fila :: Fila(){
    primeiro = NULL;
    ultimo = NULL;
    contador = 0;
    set_Passos2(0);
}

Fila :: Fila(unsigned short int x, unsigned short int y){
    primeiro = new Posicao(x, y);
    ultimo = primeiro;
    contador = 0;
}

Fila :: ~Fila(){
    delete primeiro;
}

void Fila :: setPrimeiro(Posicao* primeiro){
    this -> primeiro = primeiro;
}
Posicao* Fila :: getPrimeiro(){
    return this -> primeiro;
}

void Fila :: setUltimo(Posicao* ultimo){
    this -> ultimo = ultimo;
}
Posicao* Fila :: getUltimo(){
    return this -> ultimo;
}

void Fila::set_Passos2(int passos){
    this->passos = passos;
}
int Fila::get_Passos2(){
    return this -> passos; 
}

void Fila :: setContador(int contador){
    this -> contador = contador;
}
int Fila :: getContador(){
    return this -> contador;
}

bool Fila :: vazia() {
	return (primeiro == NULL);
}

void Fila :: add_coordenada(unsigned short int x, unsigned short int y){

    Posicao* nova_posicao = new Posicao(x, y);

	if(vazia()){
		primeiro = nova_posicao;
		ultimo = nova_posicao;
	}
	else{
		ultimo -> setProximo(nova_posicao);
		ultimo = nova_posicao;
	}
    setContador(getContador()+1);
}

void Fila :: remover_coordenada(){

    if (!vazia()){

        if (primeiro == ultimo){ // apenas um nó na lista
            primeiro = NULL;
            ultimo = NULL;
        } 
        else { // mais de um nó na lista
            Posicao* remover = primeiro;
            primeiro = primeiro->getProximo();
            remover->setProximo(NULL);
        }
        setContador(getContador()-1);
    }
}    

void Fila :: imprimir_fila(){

    Posicao* p = primeiro;

	if(vazia()){
		cout << "\nFila vazia!\n";
        cout << "\nTamanho: " << getContador();
    }
	
	else{
		while(p){
            cout<<"["<<p->getX()<<","<<p->getY()<<"] ";
            p = p-> getProximo();
        }
	}
}

tuple<unsigned short int, unsigned short int> Fila :: obter_elemento_fila(int posicao){

    Posicao* p = primeiro;
    unsigned short int x=0,y=0;
    int cont=0;

	if (!vazia()){
		while(p){
            if(cont == posicao){
                x = p->getX();
                y = p->getY();
                break;
            }
            cont++;
            p = p-> getProximo();
	    }
    }
    return make_tuple(x, y);
}    
 

tuple<unsigned short int, unsigned short int> Fila :: obter_primeiro_da_fila(){

    Posicao* p = primeiro;
    unsigned short int x=0,y=0;

	if (!vazia()){
        x = p->getX();
        y = p->getY();
    }
    
    return make_tuple(x, y);
}  