#include "largura.hpp"

using namespace std;

void leitura_arquivo_2(nova_Matriz** matriz){

  short int aux1 = 0, aux2 = 0;
  string posicao, aux_elemento;

  ifstream arquivo;

  arquivo.open("dataset/input.data", ios::in);

  if (!arquivo){
    cout << "Erro ao abrir o arquivo." << endl;
  }
  else{
    getline(arquivo, posicao, '\n');
    
    while(getline(arquivo, posicao, '\n')){

      if(posicao.empty()){
        
        aux2 = 0;
        aux1 = 0;
      }

      else{
        stringstream aux(posicao);

        while(getline(aux, aux_elemento, ' ')){
          matriz[aux1][aux2].elemento = aux_elemento;
          matriz[aux1][aux2].indice = 0;
          aux2++;
        }
        aux1++;
        aux2 = 0;
      }
    }
  }
  arquivo.close();
}

void imprimir2(nova_Matriz **matriz, int tamanho){

  short int i, j;

  for(i = 0; i < tamanho; i++){
    for(j = 0; j < tamanho; j++){
      cout << matriz[i][j].indice << " ";
    }
    cout << endl;
  }
}

void imprimir3(nova_Matriz **matriz, int tamanho){

  short int i, j;

  for(i = 0; i < tamanho; i++){
    for(j = 0; j < tamanho; j++){
      cout << matriz[i][j].elemento << " ";
    }
    cout << endl;
  }
}

void direita(nova_Matriz** matriz,unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, bool &livre, bool &repetido){
  if (coluna+1==tamanho){
    livre = false;
  }
  else if ((matriz[linha][coluna+1].indice == 1) || (matriz[linha][coluna+1].indice == 2)){
    repetido = false;
  }
}

void diagonal_direita_abaixo(nova_Matriz** matriz,unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, bool &livre, bool &repetido){
  if ((linha+1==tamanho) || (coluna+1==tamanho)){
    livre=false;
  }
  else if((matriz[linha+1][coluna+1].indice == 1) || (matriz[linha+1][coluna+1].indice == 2)){
    repetido = false;
  }
}

void baixo(nova_Matriz** matriz,unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, bool &livre, bool &repetido){
  if (linha+1==tamanho){
    livre=false;
  }
  else if ((matriz[linha+1][coluna].indice == 1) || (matriz[linha+1][coluna].indice == 2)){
    repetido = false;
  }
}

tuple<bool, bool> verificar_possibilidade2(nova_Matriz** matriz, unsigned short int linha, unsigned short int coluna, unsigned short int tamanho, unsigned short int direcao){
  
  bool livre=true;
  bool repetido=true;

  switch (direcao){
    case 1: //direita
      direita(matriz,linha,coluna,tamanho,livre,repetido);
    break;
    case 2: //diagonal direita abaixo
      diagonal_direita_abaixo(matriz,linha,coluna,tamanho,livre,repetido);
    break;
    case 3: //baixo
      baixo(matriz,linha,coluna,tamanho,livre,repetido);
    break;                  
  }    

  return make_tuple(livre, repetido);
}

void reiniciar_indices(nova_Matriz** matriz, unsigned short int tamanho){
  for(int i=0; i<tamanho; i++){
    for(int j=0; j<tamanho; j++){
      matriz[i][j].indice = 0;
    }
  }
}

void caminhar_largura(nova_Matriz** matriz, unsigned short int tamanho){

  leitura_arquivo_2(matriz);
   
  Fila l;
  unsigned short int linha_atual=0, coluna_atual=0, x=0, y=0, linha_aux=0, coluna_aux=0, direcao=1;
  int new_cont=0, old_cont=0, aux=0, auxiliar=0, contador=0, tamanho_fila=0;
  bool verif_possib=false, verif_repeticao=false, objetivo=false, perigo=false;

  l.add_coordenada(x,y); //adiciona [0,0] na fila
  old_cont=1; //atualiza old_cont=1 pois existe apenas um elemento na fila (contador que controla a quantidade inicial/anterior na fila)

  while(objetivo==false){

    if(perigo==true){ //se tiver achado perigo
      l.add_coordenada(0,0); //adiciona coordenada [0][0] na fila novamente
      old_cont=1; //old_cont=1 pois existe apenas um elemento na fila
      perigo=false; //reinicializa o perigo como falso
    } 
    new_cont=0; //contador que controla a quantidade de vizinhos adicionados atualmente
    aux=0; //inicializa a variavel auxiliadora 

    while((aux<old_cont) && (l.vazia()==false)){  //passa por todos as coordenadas atuais da fila e adiciona seus respectivos vizinhos
      auto posicao = l.obter_elemento_fila(aux); 
      x = get<0>(posicao); 
      y = get<1>(posicao);
      
      while(direcao<=3){ //verifica 3 posicoes (todos os vizinhos existentes = direita, baixo, diagonal direita baixo)

        auto resultado = verificar_possibilidade2(matriz, x, y, tamanho, direcao);
        verif_possib = get<0>(resultado); //verifica se é possivel caminhar ou se irá ser acessada uma posicao que nao existe
        verif_repeticao = get<1>(resultado); //verifica se é uma posicao que já foi adicionada na fila
        
        if((verif_possib==true) && (verif_repeticao==true)){ //se for um vizinho possivel
          switch(direcao){
            case 1: //direita
              l.add_coordenada(x, y+1); //adiciona a coordenada do vizinho do lado direito na fila
              new_cont++; //conta o vizinho adicionado
              matriz[x][y+1].indice = 1; //atualiza o indice da posicao como 1
            break;
            case 2: //diagonal direita abaixo
              l.add_coordenada(x+1, y+1);
              new_cont++;
              matriz[x+1][y+1].indice = 1;
            break;  
            case 3: //baixo
              l.add_coordenada(x+1, y);
              new_cont++;
              matriz[x+1][y].indice = 1;
            break;
          }
        }
        direcao++;
      } 

      direcao=1; //reinicializa a variavel 
      aux++; 
    }
    
    auxiliar=0; //inicializa a variavel auxiliadora 
    while((auxiliar<old_cont) && (perigo==false) && (objetivo==false) && (l.vazia()==false)){ //remove as coordenadas que já tiveram seus vizinhos descobertos e adicionados na fila
      
      auto posicao = l.obter_primeiro_da_fila();
      linha_aux = get<0>(posicao);
      coluna_aux = get<1>(posicao);
      l.remover_coordenada();

      if(matriz[linha_aux][coluna_aux].elemento == "*"){
        linha_atual = linha_aux; //atualiza a posicao da matriz, pois terá que andar
        coluna_atual = coluna_aux;
        matriz[linha_atual][coluna_atual].elemento = "1"; //atualiza o * para 1
        linha_aux=0; //zera as posicoes da matriz
        coluna_aux=0;
        linha_atual=0;
        coluna_atual=0;
        reiniciar_indices(matriz, tamanho); //reinicia os indices da matriz como 0
        tamanho_fila = l.getContador(); //verifica o tamanho da fila
        contador=0; //zera o contador que controla a remoção da fila
        l.set_Passos2(l.get_Passos2()+1);
        while(contador<=tamanho_fila){
          l.remover_coordenada(); //zera a fila
          contador++;
        } 
        perigo = true;
        break;
      }   
      else if(matriz[linha_aux][coluna_aux].elemento == "#"){
        //nao atualiza a linha_atual e coluna_atual, pois não pode caminhar
      } 
      else if(matriz[linha_aux][coluna_aux].elemento == "?"){
        l.set_Passos2(l.get_Passos2()+1);
        matriz[linha_atual][coluna_atual].elemento = "X";
        linha_atual = linha_aux; //atualiza a posicao da matriz, pois terá que andar
        coluna_atual = coluna_aux;
        cout << "\n\n\t====[OBJETIVO ALCANCADO]====\n\n";
        cout << "[Método] = Largura\n";
        cout << "Passos: " << l.get_Passos2()-1 << endl;
        cout << "Coordenada: [" << linha_atual << "][" << coluna_atual << "]\n\n\n";
        l.set_Passos2(0);
        objetivo=true; //atualiza o objetivo como verdadeiro caso achar o ?
      }
      else{
        linha_atual = linha_aux; //atualiza a posicao da matriz, pois terá que andar
        coluna_atual = coluna_aux;
        matriz[linha_atual][coluna_atual].indice = 2; //atualiza o indice da matriz como 2, pois já foi descoberto seus vizinhos e caminhado
        matriz[linha_atual][coluna_atual].elemento = "X";
        l.set_Passos2(l.get_Passos2()+1);
      }
      auxiliar+=1;
    } 

    if((objetivo==false) && (l.vazia()==false)){
      old_cont = new_cont; //agora a quantidade de coordenadas que havia antes foi removida, e será a nova quantidade que foi adicionada
    }  
  }  

  matriz[linha_atual][coluna_atual].elemento = "X";
  
  imprimir3(matriz,tamanho);
}
