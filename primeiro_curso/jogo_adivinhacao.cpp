#include <iostream> //biblioteca para entrada e saida
#include <stdlib.h> //biblioteca relacionada a randomico
#include <ctime> // funcao relaciona a tempo

using namespace std; // marcador das funcoes padroes de c++

int main(){

    cout << "**********************************" << endl;
    cout << "* Bem-Vindo ao Jogo de Adivinhacao *"<< endl;
    cout << "**********************************" << endl;

    cout << "Escolha a dificulda do seu jogo:  " << endl;
    cout << "Facil(F) Medio(M) Dificil(D)" << endl;
    
    char dificuldade; 
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade =='F'){
        numero_de_tentativas = 15;
    } else if(dificuldade = 'M'){
        numero_de_tentativas = 10;
    } else if(dificuldade == 'D'){
        numero_de_tentativas = 5;
    }

     srand(time(NULL)); //funcao apra setar numeros aleatorios
    const int NUMERO_SECRETO = rand() % 100;  //pega esse numero aletorio divide por 100 e o resto vai estar entre 0 e 99
    int chute;
    int tentativas = 1;
    bool nao_acertou =  true; // Variaveia booleanas que me diz que houve ou nao acerto
    double pontos = 1000; //mesma coisa do float a unica diferenca e a de que double armazena maior numero de bits

     for(int tentativas = 0; tentativas < numero_de_tentativas; tentativas++) {
    cout << "Tentativa: " << tentativas << endl;
    cout << "Qual seu chute ? " << endl;
    cin >> chute; 

    double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;    //retorna o valor absoluto de uma conta ou seja o modulo
        pontos = pontos - pontos_perdidos
;

    bool acertou = chute == NUMERO_SECRETO;     // declara numero de verdadeiro ou falso!
    bool maior = chute > NUMERO_SECRETO;

    if(acertou){
        cout << "Parabens voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
    } else if(maior){
        cout << "Seu chute foi maior que o numero secreto!" << endl;
    } else {
        cout << "Seu chute foi menor que o numero secreto!" << endl;
    }
}

cout << "Fim de jogo!" << endl;
if(nao_acertou){
cout << "Voce perdeu, Tente novamente!" << endl;
}else{
cout << "Voce acertou o nuemro secreto em" << tentativas << "tentativas!"<< endl;
cout.precision(2); // seta u nuemrod e casa que quer ser selcionada para apresentar no cout
cout << fixed; // em conjunto com o cou a cima funcina da mesma form a que o &.2f na linguagem C
cout << "Sua pontuacao foi de " << pontos << endl;

}
}