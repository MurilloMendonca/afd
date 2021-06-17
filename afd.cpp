#include "afd.hpp"
#include <iostream>
#include <string>

AFD::AFD(std::string arquivoAFD){
    FileStream a (arquivoAFD);
    estados = a.lineValues();
    alfabeto = a.lineValues();
    for(int estado=0;estado<estados.size();estado++){
        auto aux = a.lineValues();
        std::unordered_map<std::string,std::string> mapaAux;
        for(int i=0;i<alfabeto.size();i++)
        {
            mapaAux.insert(std::pair<std::string,std::string>(alfabeto.at(i),aux.at(i)));
        }
        D.insert(std::pair<std::string,std::unordered_map<std::string,std::string>>(estados.at(estado), mapaAux));
    }
    estadoInicial = a.lineValues().at(0);
    auto finais = a.lineValues();
    for(auto s:finais){
        estadosFinais.insert(s);
    }
    int numeroDePalavrasDeTeste = stoi(a.lineValues().at(0));
    for(int i=0;i<numeroDePalavrasDeTeste;i++){
        palavrasTeste.insert(a.lineValues().at(0));
    }
}

void AFD::mostraAFD(){
    std::cout<<"Tabela de transicoes: \n     ";
    for(auto letra:alfabeto)
        std::cout<<letra<<" ";
    std::cout<<std::endl;
    for(auto letra:alfabeto)
        std::cout<<"____";
    std::cout<<std::endl;
    for (auto d : D) {
        (estadosFinais.find(d.first) != estadosFinais.end())? std::cout<<"*":std::cout<<" ";
        (d.first==estadoInicial)? std::cout<<"+":std::cout<<" ";
        std::cout<<d.first<<"| ";
        for(auto letra:alfabeto)
            std::cout<<d.second[letra]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"\n\n* Estado final\n+ Estado inicial\n";
}

bool AFD::testaPalavra(std::string palavra){
    int p=0;
    std::string estado = estadoInicial;
    while (p<palavra.size()){
        estado=D[estado][palavra.substr(p,1)];
        p++;
    }
    return (estadosFinais.find(estado) != estadosFinais.end());

}

void AFD::realizaTestes(){
    for(auto palavra:palavrasTeste){
        testaPalavra(palavra)?std::cout<<"\nO teste deu certo para a palavra ":std::cout<<"\nO teste deu errado para a palavra ";
        std::cout<<palavra;
    }
    std::cout<<std::endl;
}