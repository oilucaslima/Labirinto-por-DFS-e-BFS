#define _RANDOMICO_HPP
#include "Posicao.hpp"
#include "Pilha.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <tuple>

using namespace std;

void imprimir(string **matriz, int tamanho);
void tamanho_e_quantidade(int *tamanho, int *quantidade);
void leitura_arquivo(string **matriz);
tuple <bool, bool> verificar_possibilidade(string** matriz, unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, unsigned short int direcao);
bool verificar_perigo(string** matriz, unsigned short int linha, unsigned short int coluna);
bool verificar_parada(string** matriz, unsigned short int linha, unsigned short int coluna, int passos);
void caminhar_randomico(string** matriz, unsigned short int tamanho);
