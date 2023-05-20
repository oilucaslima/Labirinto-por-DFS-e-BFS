#include "randomico.hpp"

void tamanho_e_quantidade(int *tamanho, int *quantidade){

  string tam, quantas;
  ifstream arquivo;

  arquivo.open("dataset/input.data", ios::in);

  if (!arquivo){
    cout << "Erro ao abrir o arquivo." << endl;
  }

  else{
    getline(arquivo, tam, ' ');
    *tamanho = atoi(tam.c_str());

    getline(arquivo, tam, ' ');

    getline(arquivo, quantas, ' ');
    *quantidade = atoi(quantas.c_str());
  }
}

// Função que realiza leitura completa do arquivo input.data
void leitura_arquivo(string **matriz){

  short int aux1 = 0, aux2 = 0;
  string posicao, elemento;

  ifstream arquivo;

  arquivo.open("dataset/input.data", ios::in);

  if (!arquivo){
    cout << "Erro ao abrir o arquivo." << endl;
  }

  else{

    getline(arquivo, posicao, '\n');
    
    while (getline(arquivo, posicao, '\n')){

      if (posicao.empty()){
        
        aux2 = 0;
        aux1 = 0;
      }

      else{
        stringstream aux(posicao);

        while (getline(aux, elemento, ' ')){
          matriz[aux1][aux2] = elemento;
          aux2++;
        }
        aux1++;
        aux2 = 0;
      }
    }
  }
  arquivo.close();
}

// Função que imprimi a matriz
void imprimir(string **matriz, int tamanho){

  short int i, j;

  for(i = 0; i < tamanho; i++){
    for(j = 0; j < tamanho; j++){
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
}

// Função que verifica se não vai acessar uma posição que não existe na matriz e se não é parede
tuple<bool, bool> verificar_possibilidade(string** matriz, unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, unsigned short int direcao){
    
  bool livre=true;
  bool parede=true;

  switch (direcao){

    case 1: //diagonal esquerda acima
      if((linha-1<0) || (coluna-1<0)){ 
        livre = false;
      }
      else if(matriz[linha-1][coluna-1] == "#"){
        parede = false;
      }
    break;

    case 2: //cima
      if((linha-1<0)){ 
        livre = false;
      }
      else if(matriz[linha-1][coluna] == "#"){
        parede = false;
      }
    break;

    case 3: //diagonal direita acima
      if ((linha-1<0) || (coluna+1==tamanho)){
        livre = false;
      }
      else if(matriz[linha-1][coluna+1] == "#"){
        parede = false;
      }   
    break; 

    case 4: //esquerda
      if (coluna-1<0){
        livre = false;
      }
      else if(matriz[linha][coluna-1] == "#"){
        parede = false;
      }
    break;

    case 5: //direita
      if (coluna+1==tamanho){
        livre = false;
      }else if (matriz[linha][coluna+1] == "#"){
        parede = false;
      }
    break;

    case 6: //diagonal esquerda abaixo
      if ((linha+1==tamanho) || (coluna-1<0)){
        livre=false;
      }else if (matriz[linha+1][coluna-1] == "#"){
        parede = false;
      }
    break;

    case 7: //baixo
      if (linha+1==tamanho){
        livre=false;
      }
      else if (matriz[linha+1][coluna] == "#"){
        parede = false;
      }
    break;

    case 8: //diagonal direita abaixo
      if ((linha+1==tamanho) || (coluna+1==tamanho)){
        livre=false;
      }else if (matriz[linha+1][coluna+1] == "#"){
        parede = false;
      }
    break;
    
  }    

  return make_tuple(livre, parede);
}

// Função que trata se encontrar *:
bool verificar_perigo(string** matriz, unsigned short int linha, unsigned short int coluna){

  bool stop=false;
  
  if(matriz[linha][coluna] == "*"){
    matriz[linha][coluna] = "1";
    stop = true;
  }
  return stop;
}

// Função que trata se encontrar a "?"
bool verificar_parada(string** matriz,unsigned short int linha, unsigned short int coluna, int passos){

  bool parada=false;
  
  if(matriz[linha][coluna] == "?"){
    parada = true;
    matriz[linha][coluna] = 'X';
    cout << "\n\n\t====[OBJETIVO ALCANCADO]====\n\n";
    cout << "[Método] = Randômico\n";
    cout << "Passos: " << passos << endl;
    cout << "Coordenada: [" << linha << "][" << coluna << "]\n\n\n";
  }
  return parada;
}

// Função caminhar de forma randômica
void caminhar_randomico(string** matriz, unsigned short int tamanho){
  
  int passos=0;
  unsigned short int linha=0,coluna=0;
  leitura_arquivo(matriz);
  imprimir(matriz, tamanho);
  
  bool verif_parede=false, verif_possibilidade=false, perigo=false, parada_total=false;;
  int direcao = 0;

  while(parada_total == false){

    do{
      direcao = rand()%8+1;
      auto resultado =  verificar_possibilidade(matriz, linha, coluna, tamanho, direcao);
      verif_possibilidade = get<0>(resultado); //verificar se é possivel caminhar ou se irá ser acessada uma posicao que nao existe
      verif_parede = get<1>(resultado); //verificar se é parede
    }while((verif_parede == false) || (verif_possibilidade == false)); //gerar posicao enquanto for parede e nao for possivel andar
    
    switch(direcao){

      case 1: 
        linha--; //diagonal esquerda acima
        coluna--; 
        passos++;
      break;

      case 2: 
        linha--; //cima
        passos++;
      break;

      case 3: 
        linha--; //diagonal direita acima
        coluna++; 
        passos++;
      break;

      case 4: 
        coluna--; //esquerda
        passos++;
      break;

      case 5: 
        coluna++; //direita
        passos++;
      break;

      case 6: 
        linha++; 
        coluna--; //diagonal esquerda abaixo
        passos++;
      break;

      case 7: 
        linha++; //baixo
        passos++;
      break;

      case 8: 
        linha++; 
        coluna++; //diagonal direita abaixo
        passos++;
      break;
    }

    perigo = verificar_perigo(matriz, linha, coluna);
    parada_total = verificar_parada(matriz, linha, coluna, passos);

    if(perigo == true){
      linha = 0;
      coluna = 0;
    }

    matriz[linha][coluna] = "X";
  }

  imprimir(matriz, tamanho);
}