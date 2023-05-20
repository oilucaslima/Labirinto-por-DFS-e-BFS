#include "profundidade.hpp"

void reiniciando_perigo(nova_Matriz** matriz, Pilha* pilha, unsigned short int &l, unsigned short int &c, unsigned short int tamanho,  unsigned short int &nova_direcao, bool &perigo){
    
    int tam=0, contador=0;
    Posicao* nova;

    l = 0;
    c = 0;
    nova_direcao = 1;
    reiniciar_indices2(matriz,tamanho);
    tam = pilha->getTam_Pilha();

    while(contador<tam){
        pilha->retirardapilha(); //zera a pilha
        contador++;
    } 

    nova = new Posicao(l, c);
    pilha->inserir(nova);
    matriz[l][c].indice=1;
    matriz[l][c].elemento="X";
    perigo = false;
}

void funcao_switch(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, unsigned short int &nova_direcao, bool &andei){

    switch(nova_direcao){

        case 1: //direita
            direita_2(matriz,pilha,l,c,tamanho, perigo, objetivo, andei);
        break;                 

        case 2: //diagonal direita abaixo
            diagonal_direita_abaixo_2(matriz,pilha,l,c,tamanho, perigo, objetivo, andei);
        break;

        case 3: //baixo
            baixo_2(matriz,pilha,l,c,tamanho, perigo, objetivo, andei);
        break; 

        case 4: //diagonal esquerda abaixo
            diagonal_esquerda_abaixo_2(matriz,pilha,l,c,tamanho, perigo, objetivo, andei);
        break; 

        case 5: //esquerda
            esquerda_2(matriz,pilha,l,c, perigo, objetivo, andei);
        break; 

        case 6: //diagonal esquerda acima
            diagonal_esquerda_acima_2(matriz,pilha,l,c, perigo, objetivo, andei);
        break;  

        case 7: //cima
            cima_2(matriz,pilha,l,c, perigo, objetivo, andei);
        break;  

        case 8: //diagonal direita acima
            diagonal_direita_acima_2(matriz,pilha,l,c,tamanho, perigo, objetivo, andei); 
        break;                    
    }
}

void caminhar_profundidade(nova_Matriz** matriz, unsigned short int tamanho){
    
    unsigned short int tam_anterior=0, tam_atual=0, diferenca=0;
    unsigned short nova_direcao = 1,l=0, c=0;
    bool perigo = false, objetivo = false, andei = false;
    Pilha* pilha = new Pilha();
    Posicao* nova;
    
    leitura_arquivo_2(matriz);

    nova = new Posicao(l, c);
    pilha->inserir(nova);
    matriz[l][c].indice=1;
    matriz[l][c].elemento="X";
    // pilha->set_Passos(pilha->get_Passos()+1);

    while(objetivo!=true){

        andei = false;

        if(perigo==true){
            reiniciando_perigo(matriz,pilha,l,c,tamanho,nova_direcao,perigo);
        }
        else{ 
            if(objetivo==false){
                if(nova_direcao<=8){
                    if (nova_direcao==1){
                        tam_anterior = pilha->getTam_Pilha();
                    }
                    funcao_switch(matriz,pilha,l,c,tamanho,perigo,objetivo,nova_direcao,andei);
                    nova_direcao++;
                }
                else{
                    tam_atual = pilha->getTam_Pilha();
                    diferenca = tam_atual-tam_anterior;
                    nova_direcao=1;
                   
                    if(diferenca==0){
                        pilha->retirardapilha();
                        l = pilha->getPrimeiro()->getX();
                        c = pilha->getPrimeiro()->getY();  
                    }
                }
            }
        }
    }
    cout<<endl;

    if(objetivo){
        cout << "\n\n\t====[OBJETIVO ALCANCADO]====\n\n";
        cout << "[Método] = Profundidade\n";
        cout << "Passos: " <<pilha->get_Passos()<<endl;
        cout << "Coordenada: [" << l << "][" << c << "]\n\n\n";
    }

    imprimir3(matriz,tamanho);
    pilha->set_Passos(0);
}

// As funções abaixo de direção verifica:
// se não extrapola os limites da matriz ou se é parede e sai do while
// se não for nada disso, ele contonua seguindo naquela direção até deus quiser

void direita_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
  
    while(objetivo!=true){
        if(c+1==tamanho){
            break;
        }
        else if(matriz[l][c+1].elemento == "#" || matriz[l][c+1].indice==1){
            //cout<<" \n\n aqui ---------------";
            break;
        }
        else{
            c++;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].elemento = "X";
                matriz[l][c].indice=1;
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
    }
}

void diagonal_direita_abaixo_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho,  bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
 
    while(objetivo!=true){
    
        if ((l+1==tamanho) || (c+1==tamanho)){
            break;
        }
        else if(matriz[l+1][c+1].elemento == "#" || matriz[l+1][c+1].indice == 1){
            break;
        }
        else{
            l++;
            c++;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
                
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;

            } 
        }
    }
}

void baixo_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
  
    while(objetivo!=true){

        if(l+1==tamanho){
            break;
        }
        else if(matriz[l+1][c].elemento == "#" || matriz[l+1][c].indice == 1){
            break;
        }
        else{
            l++;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
                break;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
    }
}

void diagonal_esquerda_abaixo_2(nova_Matriz** matriz,Pilha* pilha,unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
 
    while(objetivo!=true){
    
        if ((l+1==tamanho) || (c-1<0)){
            break;
        }
        else if(matriz[l+1][c-1].elemento == "#" || matriz[l+1][c-1].indice == 1){
            break;
        }
        else{
            l++;
            c--;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
    }
}

void esquerda_2(nova_Matriz** matriz, Pilha* pilha,unsigned short int &l, unsigned short int &c, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
  
    while(objetivo!=true){
        if (c-1<0){
            break;
        }
        else if((matriz[l][c-1].elemento == "#") || (matriz[l][c-1].indice == 1)){
            break;
        }
        else{
            c--;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
   }
}

void diagonal_esquerda_acima_2(nova_Matriz** matriz, Pilha* pilha,unsigned short int &l, unsigned short int &c, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
    
    while(objetivo!=true){
  
        if ((l-1<0) || (c-1<0)){ 
            break;
        }
        else if(matriz[l-1][c-1].elemento == "#" || matriz[l-1][c-1].indice == 1){
            break;
        }
        else{
            l--;
            c--;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
    }
}

void cima_2(nova_Matriz** matriz, Pilha* pilha,unsigned short int &l, unsigned short int &c, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;
        
    while(objetivo!=true){
        if((l-1<0)){ 
            break;
        }
        else if(matriz[l-1][c].elemento == "#" || matriz[l-1][c].indice == 1){
            break;
        }
        else{
            l--;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
    }
}

void diagonal_direita_acima_2(nova_Matriz** matriz,Pilha* pilha, unsigned short int &l, unsigned short int &c, unsigned short int tamanho, bool &perigo, bool &objetivo, bool &andei){

    Posicao* nova;

    while(objetivo!=true){
    
        if((l-1<0) || (c+1==tamanho)){
            break;
        }
        else if(matriz[l-1][c+1].elemento == "#" || matriz[l-1][c+1].indice == 1){
            break;
        }
        else{
            l--;
            c++;
            if(matriz[l][c].elemento == "*"){
                matriz[l][c].elemento = "1";
                perigo = true;
                break;
            }
            else if(matriz[l][c].elemento == "?"){
                nova = new Posicao(l, c);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->inserir(nova);
                pilha->set_Passos(pilha->get_Passos()+1);
                objetivo = true;
            }
            else if(matriz[l][c].indice==0){
                nova = new Posicao(l, c);
                pilha->inserir(nova);
                matriz[l][c].indice=1;
                matriz[l][c].elemento="X";
                pilha->set_Passos(pilha->get_Passos()+1);
                andei = true;
            } 
        }
    }
}

void reiniciar_indices2(nova_Matriz** matriz, unsigned short int tamanho){
  for(int i=0; i<tamanho; i++){
    for(int j=0; j<tamanho; j++){
      matriz[i][j].indice = 0;
    }
  }
}
