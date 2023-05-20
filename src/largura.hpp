#define _LARGURA_HPP
#include "Fila.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>


using namespace std;


void leitura_arquivo_2(nova_Matriz **matriz);
void imprimir2(nova_Matriz **matriz, int tamanho);
tuple<bool, bool> verificar_possibilidade2(nova_Matriz** matriz, unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, unsigned short int direcao);
void caminhar_largura(nova_Matriz** matriz, unsigned short int tamanho);
void direita(nova_Matriz** matriz,unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, bool &livre, bool &repetido);
void diagonal_direita_abaixo(nova_Matriz** matriz,unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, bool &livre, bool &repetido);
void baixo(nova_Matriz** matriz,unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, bool &livre, bool &repetido);
void reiniciar_indices(nova_Matriz** matriz, unsigned short int tamanho);
void imprimir3(nova_Matriz **matriz, int tamanho);
