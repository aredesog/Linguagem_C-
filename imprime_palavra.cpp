#include <iostream>
#include <map>
#include <string>


extern std::string palavra_secreta; 
extern std::map<char, bool> chutou;

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            std::cout << letra << " ";
        }
        else{
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}