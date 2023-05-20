#include "randomico.hpp"
#include "largura.hpp"
#include "profundidade.hpp"
#include <chrono>
#include <iomanip>

using namespace std;

int main(){

    int tamanho, quantidade;
    string **matriz;
    nova_Matriz **matriz2;
    srand((unsigned)time(NULL));
    tamanho_e_quantidade(&tamanho, &quantidade);  

    cout<<"\n\n\t      [MATRIZ]\n\n";

    //Alocação dinâmica da matriz
    matriz = new string *[tamanho];
    matriz2 = new nova_Matriz *[tamanho];
    for (int i = 0; i < tamanho; i++){
        matriz[i] = new string[tamanho];
        matriz2[i] = new nova_Matriz[tamanho];
    }

    //RANDOMICO
    chrono::steady_clock::time_point start_randomico = chrono::steady_clock::now();
    caminhar_randomico(matriz, tamanho);
    chrono::steady_clock::time_point end_randomico = chrono::steady_clock::now();
    chrono::duration<double, milli> tempo_randomico = end_randomico - start_randomico;

    //LARGURA
    chrono::steady_clock::time_point start_largura = chrono::steady_clock::now();
    caminhar_largura(matriz2, tamanho);
    chrono::steady_clock::time_point end_largura = chrono::steady_clock::now();
    chrono::duration<double, milli> tempo_largura = end_largura - start_largura;

    //PROFUNDIDADE
    chrono::steady_clock::time_point start_profundidade = chrono::steady_clock::now();
    caminhar_profundidade(matriz2,tamanho);
    chrono::steady_clock::time_point end_profundidade = chrono::steady_clock::now();
    chrono::duration<double, milli> tempo_profundidade = end_profundidade - start_profundidade;
    
    for(int i = 0; i < tamanho; i++){
        delete[]matriz[i];
        delete[]matriz2[i];
    }
    delete[]matriz;
    delete[]matriz2;
    
    cout << "\n\t===[Tempo decorrido]=== \n" << endl;
    cout << "Método Randômico: " << fixed << setprecision(2) << tempo_randomico.count() << " ms"<< endl;
    cout << "Método Busca em Largura: " << fixed << setprecision(2) << tempo_largura.count() << " ms"<< endl;
    cout << "Método Busca em Profundidade: " << fixed << setprecision(2) << tempo_profundidade.count() << " ms"<< endl;
    

    return 0;
}