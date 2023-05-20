#include "Pilha.hpp"

using namespace std;

Pilha::Pilha(){
    this -> setPrimeiro(NULL);
    this -> setUltimo(NULL);
    this -> setTam_Pilha(0);
    this -> set_Passos(0);
}

Pilha::Pilha(unsigned short int x, unsigned short int y){
    primeiro = new Posicao (x, y);
    ultimo = primeiro;
}

Pilha :: ~Pilha(){
    delete primeiro;
}

void Pilha :: setPrimeiro(Posicao* primeiro){
    this -> primeiro = primeiro;
}
Posicao* Pilha :: getPrimeiro(){
    return this -> primeiro;
}

void Pilha::set_Passos(int passos){
    this->passos = passos;
}
int Pilha::get_Passos(){
    return this -> passos; 
}

void Pilha :: setUltimo(Posicao* ultimo){
    this -> ultimo = ultimo;
}

Posicao* Pilha :: getUltimo(){
    return this -> ultimo;
}

void Pilha :: setTam_Pilha(int tam_Pilha){
    this -> tam_Pilha = tam_Pilha;
}
int Pilha :: getTam_Pilha(){
    return this -> tam_Pilha;
}

bool Pilha :: vazia() {
	return (primeiro == NULL);
}

void Pilha::inserir(Posicao* novo){

    if(vazia()){
        this -> setPrimeiro(novo);
        this -> setUltimo(novo);
        this -> setTam_Pilha(1);
    }
    else{
        novo -> setProximo(primeiro);
        this -> setPrimeiro(novo); 
        this -> setTam_Pilha(getTam_Pilha()+1); 
    } 
}

void Pilha :: imprimir_pilha(){
    
    Posicao* atual = this -> getPrimeiro();
    int i;

    for (i=0; i < this -> getTam_Pilha(); i++){
        cout << "["<<atual->getX()<<","<<atual->getY()<<"]";
        atual = atual -> getProximo();
    }
}

void Pilha :: retirardapilha(){

    Posicao* p = this -> getPrimeiro();
    Posicao *proximo;

    proximo = p -> getProximo();
    this -> setPrimeiro(proximo);
    this -> setTam_Pilha(this -> getTam_Pilha() -1);
    delete p;
}
  

            


