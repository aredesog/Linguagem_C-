#include <iostream> // biblioteca padrao para o uso de c++
#include <string.h> // biblioteca para o uso de funcoes de string
#include <map>  //biblioteca para o uso do dicionario map
#include <vector> // biblioteca para o uso de vector, ou vetores mais dinamicos
#include <fstream> //abre e fecha arquivos externos
#include <ctime> // biblioteca de tempo para o rand
#include <cstdlib> //numeros aleatorios

using namespace std;

string palavras_secreta = "MELANCIA";        //variavel global
map<char, bool> chutou; //cria um dicionario para o programa, muito comum na ultilizacao de mapemento de notas de alunos por exemplo
vector<char> chutes_errados; //Declara um vetor dinamico 

bool letra_existe(char chute){      // funciona como uma funcao mas em bool(novidade)
    /*for(int i = 0; i < palavras_secreta.size(); i++) {       //.size faz a verificacao do tamanho da palavra
        if(chute == palavras_secreta[i]) {
            return true;
        }
    }*/
    for(char letra : palavras_secreta){  // Uma simplificao do for de cima ja que ele faz a leitura com amiro facilidade na funcao C++11
        if(chute == letra){
            return true;
        } 
    }    
    return false;
}

bool nao_acertou(){
   for(char letra : palavras_secreta){
    if(!chutou[letra])
    return true;
   }
return false; // se todas as letras ja fora chutasdas a pessoa ja ganhou e, portano na ha necessidade da haver continuidade no jogo
}

bool nao_enforcou(){
    return chutes_errados.size() < 5; //quer dizer que a pessoa nao enforca, ou sej ela tem direito a 5 chutes errados
}

void bemvindo(){
    cout << "*****************************"<< endl;
    cout << " Bem-Vindo ao Jogo da Forca " << endl;
    cout << "****************************" << endl;
}

void imprime_erros(){
     cout << "Chutes errado: ";
        for(char letra : chutes_errados){
            cout << letra << " ";
        }
    cout << endl;
}

void imprime_palavra(){
    for (char letra : palavras_secreta){
            if(chutou [letra]){
            cout << letra << " ";
            } else{
                cout << "_ ";
            }

        }
        cout << endl;
}

void declara_chute(){
    cout << "Seu chute: " << endl;
            char chute;
            cin >> chute;

            chutou[chute] = true;

            if(letra_existe(chute)){
                cout << "Voce acertou, seu chute esta nma palavra!" << endl;
            } else{
                cout << " Voce errou, seu chute nao esta na palavra" << endl;
                chutes_errados.push_back(chute); //insere no final do vector o caracter que se inclui em chutes errados
            }
            cout << endl;
}

vector<string> learquivo(){
    ifstream arquivo;       // inicializa um arquivo externo
    arquivo.open("palavras.txt"); //abre um arquivo externo

    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;     // faz a aleitura da linha 1 e analisa quantas linhas/palavras tem no arquivo

  
    vector<string> palavras_arquivo;

    for(int i = 0; i < quantidade_palavras; i++){
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_arquivo.push_back(palavra_lida);
    }
    
    return palavras_arquivo;
    } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
    exit(0);
    }
}

void sorteia_palavras(){
    vector<string> palavras = learquivo(); // foi criado um vetor para identificar as palavras dentro da funcao le palvras, que contem as emsmas do arquivo externo

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size() ;  //  Sorteia um indice ate o numeor de poalvras -1, ou seja ate o limite maximo

    palavras_secreta = palavras[indice_sorteado];
}

int main(){

    bemvindo();

     learquivo();
     sorteia_palavras();

    while(nao_acertou() && nao_enforcou()){

        imprime_erros();

        imprime_palavra();
        
        declara_chute();
    }

    cout << "FIM DE JOGO"<< endl;
    if (nao_acertou){
    cout << "Voce perdeu, Tente novamente!"<< endl;
    } else{
    cout << "Parabens, Voce acertou!"<< endl;
}
cout << "A palavra secreta era " << palavras_secreta << endl;
}