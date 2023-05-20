#define _PROFUNDIDADE_HPP
#include "Pilha.hpp"
#include "Posicao.hpp"
#include "largura.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <tuple>

using namespace std;

void direita_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei);
void diagonal_direita_abaixo_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei);
void baixo_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei);
void diagonal_esquerda_abaixo_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei);
void esquerda_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, bool &perigo, bool &objetivo, bool &andei);
void diagonal_esquerda_acima_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, bool &perigo, bool &objetivo, bool &andei);
void cima_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, bool &perigo, bool &objetivo, bool &andei);
void diagonal_direita_acima_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei);
void funcao_switch(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, unsigned short int &nova_direcao, bool &andei);
void caminhar_profundidade(nova_Matriz** matriz, unsigned short int tamanho);
void reiniciando_perigo(nova_Matriz** matriz, Pilha* pilha, unsigned short int &l, unsigned short int &c, unsigned short int tamanho,  unsigned short int &nova_direcao, bool &perigo);
void reiniciar_indices2(nova_Matriz** matriz, unsigned short int tamanho);



