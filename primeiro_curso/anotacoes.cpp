/* ANOTACOES C++

gcc jogo_adivinhacao.cpp -o jogo.out -> COMPILAR O JOGO
cout -> mesma funcao do printf
cin -> mesma funcionalidade do scanf
const int -> masma funcao do #define na linguagem C
srand(time(NULL)); //funcao apra setar numeros aleatorios
const int NUMERO_SECRETO = rand() % 100;  //pega esse numero aletorio divide por 100 e o resto vai estar entre 0 e 99
string -> mesma funcionalidade do char em C, entratanto mais pratica ja que nao tem necessidade de realizar a leitura de um vetor para declarar uma variavel
palavra_secreta.size() -> faz a verificacao do tamanho da palavra secreta
map<char> -> insere um dicionario 
vector<char> chutes_errados; -> declara um vetor mais dinamico
            chutes_errados.push_back(chute); ->insere no final do vector o caracter que se inclui em chutes errados
for(char letra : PALAVRA_SECRETA) -> faz a leitura da palavras secreta char por char, e facilita na producao do programa. (C++11)
            cpp reference funcao -> site para pesquisa de funcionalidade das funcoes
ifstream arquivo;       // inicializa um arquivo externo
    arquivo.open("palavras.txt"); //abre um arquivo externo
arquivo >> quantidade_palavras;     // faz a aleitura da linha 1 e analisa quantas linhas/palavras tem no arquivo



*/